/*
 * =====================================================================================
 *
 *       Filename:  CPU.cpp
 *
 *    Description:  The implementation file of the virtual CPU
 *
 *        Version:  1.0
 *        Created:  10/14/14 11:38:51
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Quinton Erasmus
 *
 * =====================================================================================
 */

#include "CPU.h"
#include <iostream>

namespace CPU_4001
{
	CPU::CPU(Memory* p_memory)
	:	m_reserved_address(0),
		m_base_address(1),
		m_address_ceiling(253),
		m_program_counter(m_base_address),
		m_register0(0),
		m_register1(0),
		m_overflow_error(false),
		m_underflow_error(false),
		m_signed_mode(false),
		m_memory(p_memory),
		m_halt(false)
	{
		
	}
	
	CPU::~CPU()
	{
		m_memory = nullptr;
	}
	
	void CPU::Reset()
	{
		m_halt 				= false;
		m_program_counter 	= c_base_address;
		m_overflow_error 	= false;
		m_underflow_error 	= false;
		m_signed_mode 		= false;
	}
	
	const byte& CPU::Fetch()
	{
		byte l_op_code = 0;
		l_op_code = m_memory->Read(m_program_counter);
		++m_program_counter;
		if(m_program_counter > c_address_ceiling)
		{
			Halt();
		}
		return l_op_code;
	}

	void CPU::Halt()
	{
		m_halt = true;
	}

	void CPU::Add()
	{
		m_register0 += m_register1;
	}

	void CPU::Beep()
	{
		std::cout << '\a';
	}

	void CPU::Store()
	{
		//Load the target address into register 1
		m_register1 = m_memory->Read(m_program_counter);
		++m_program_counter;
		m_memory->Write(m_register1, m_register0);
	}

	void CPU::Print()
	{
		//Load the target address into register 1
		m_register1 = m_memory->Read(m_program_counter);
		++m_program_counter;
		m_register0 = m_memory->Read(m_register1);
		//output the register
		std::cout << (int)m_register0 << std::endl;
	}
	
	void CPU::Decode(const byte& p_op_code)
	{
		//Special case: If the system halted in Fetch, we don't decode
		if(m_halt) return;
		
		switch(p_op_code)
		{
			//HALT
			case 0:
				Halt();
				break;
			//Load 0
			case 1:
				m_register0 = m_memory->Read(m_program_counter);
				++m_program_counter;
				break;
			//Load 1
			case 2:
				m_register1 = m_memory->Read(m_program_counter);
				++m_program_counter;
				break;
			//Add
			case 3:
				Add();
				break;
			//Beep
			case 4:
				Beep();
				break;
			//Store Operation
			case 5:
				Store();
				break;
			//Print operation
			case 6:
				Print();
				break;
		}
	}
	void CPU::Run()
	{
		//While we don't get a HALT, GO!!!
		while(!m_halt)
		{
			//Fetch into memory location
			m_memory->Write(c_reserved_address, Fetch());
			//decode from the reserved memory address
			Decode(m_memory->Read(m_reserved_address));
		}
	}
}

