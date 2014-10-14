/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Start point where we use the CPU
 *
 *        Version:  1.0
 *        Created:  10/14/14 12:03:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quinton Erasmus
 *
 * =====================================================================================
 */

#include <iostream>
#include "Memory.h"
#include "CPU.h"

using namespace std;
using namespace CPU_4001;

int main()
{
	cout << "Initializing Memory" << endl;
	Memory *memory = new Memory();
	cout << "Ready" << endl;
	cout << "Memory Size: " << (int)memory->m_max_address << endl;
	memory->Write(1,1);
	memory->Write(2,1);

	memory->Write(3,2);
	memory->Write(4,2);
	
	//Adding
	memory->Write(5,3);
	
	//Store to 12
	memory->Write(6, 5);
	memory->Write(7, 12);
	
	//Print 12
	memory->Write(8,6);
	memory->Write(9, 12);

	//Beeping
	memory->Write(10,4);

	//Halting
	memory->Write(11, 0);

	cout << "Creating a CPU instance" << endl;
	CPU* cpu = new CPU(memory);
	cout << "Complete" << endl;
	
	delete cpu, memory;
}
