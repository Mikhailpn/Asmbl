#include "pch.h"
#include <iostream>
#include <string>
#include  <C:\Users\Михаил\source\repos\LabFour.1\Programm_class.h>
#include <C:\Users\Михаил\source\repos\LabFour.1\Test_programm.h>

using namespace std;
using namespace oper;





int main()
{
	
	const char *Msgs[] = { "1.Add new command","2.Delete command", "3.Find command ", "4.Realize all commands","5.Show all commands" };
	const int NMsgs = sizeof(Msgs) / sizeof(Msgs[0]);

	int* Reg_array = new int[16];
	Programm Prog1;


	int cmd;
	while (1) 
	{
		puts("");
		puts("Commands:");
		for (int t = 0; t < NMsgs; t++)
			puts(Msgs[t]);
		puts("");
		cin >> cmd;
		{
			if (cmd == 1) { Prog1.Add_command(Prog1.Input_command());  continue; }  
			if (cmd == 2) { int addr;  cout << "Enter address: "; cin >> addr; Prog1.Delete_command(addr);  continue; }
			if (cmd == 3) { int addr;  cout << "Enter address: "; cin >> addr; Prog1.Search_command(addr)->Descriptor->output_op();  continue; }
			if (cmd == 4) {  continue; }
			if (cmd == 5) { Prog1.Show_commands(); continue; }
			if ((cmd < 1) || (cmd > 5)) { puts("wrong input"); continue; }
		}
	}



	
};
	
