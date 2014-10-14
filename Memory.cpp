/*
 * =====================================================================================
 *
 *       Filename:  Memory.cpp
 *
 *    Description:  Implementation file for our virtual CPU
 *
 *        Version:  1.0
 *        Created:  10/14/14 11:24:55
 *       Revision:  none
 *       Compiler:  any - just use the 2011 c++ standards
 *
 *         Author:  Quinton Erasmus
 *
 * =====================================================================================
 */
//#include "stdafx.h"
#include "Memory.h"

namespace CPU_4001
{
	Memory::Memory() : 	m_max_address(255),
						m_memory_space(new byte[m_max_address])
	{
		Clear();
	}

	Memory::~Memory()
	{
		if(m_memory_space != nullptr)
		{
			delete [] m_memory_space;
			m_memory_space = nullptr;
		}
	}
	
	void Memory::Clear()
	{
		for(byte i = 0 ; i < m_max_address ; ++i)
		{
			m_memory_space[i] = 0;
		}
	}
	
	const byte& Memory::Read(const byte& p_address)
	{
		return m_memory_space[p_address];
	}

	void Memory::Write(const byte& p_address, const byte& p_value)
	{
		m_memory_space[p_address] = p_value;
	}
}

