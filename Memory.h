/*
 * =====================================================================================
 *
 *       Filename:  Memory.h
 *
 *    Description:  Virtual CPU memory.h
 *
 *        Version:  1.0
 *        Created:  10/14/14 11:18:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quinton Erasmus
 *
 * =====================================================================================
 */
#ifndef CPU_MEMORY
#define CPU_MEMORY
namespace CPU_4001
{
	//Because C++ doesn't work directly in byte sized memory as numbers, we'll use
	//the byte sized character type as our byte of memory.
	typedef unsigned char byte;

	class Memory
	{
		public:
			//A constant that we'll use to define the maximum address we can read/write
			const byte m_max_address;
			Memory();
			~Memory();
			void Clear();
			const byte& Read(const byte& p_address);
			void Write(const byte& p_address, const byte& p_value);
		private:
			byte *m_memory_space;
	};
}
#endif

