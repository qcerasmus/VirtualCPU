/*
 * =====================================================================================
 *
 *       Filename:  CPU.h
 *
 *    Description:  Header file for the virtual CPU
 *
 *        Version:  1.0
 *        Created:  10/14/14 11:32:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quinton Erasmus
 *
 * =====================================================================================
 */

#ifndef CPU_PROCESSOR_H
#define CPU_PROCESSOR_H

#include "Memory.h"
namespace CPU_4001 
{ 
	class CPU
	{
		public:
			const byte m_reserved_address;
			const byte m_base_address;
			const byte m_address_ceiling;
		private:
			byte m_program_counter;
			byte m_register0;
			byte m_register1;
			bool m_overflow_error;
			bool m_underflow_error;
			bool m_signed_mode;
			bool m_halt;
			Memory* m_memory;
			const byte Fetch();
			void Decode(const byte& p_op_code);
			void Halt();
			void Add();
			void Beep();
			void Store();
			void Print();
		public:
			CPU(Memory* p_memory);
			~CPU();
			void Reset();
			void Run();
	};
}
#endif

