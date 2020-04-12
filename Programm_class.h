#pragma once
#include <C:\Users\Михаил\source\repos\LabFour.1\Operator_class.h>
#include <C:\Users\Михаил\source\repos\LabFour.1\Declare_operator_class.h>
#include <C:\Users\Михаил\source\repos\LabFour.1\Register_operator_class.h>
#include <C:\Users\Михаил\source\repos\LabFour.1\Register-memory_operator_class.h>
#include <C:\Users\Михаил\source\repos\LabFour.1\Transit_operator_class.h>
#include <string>

using namespace oper;
using namespace std;



class Programm
{
protected:
	int Amount_of_commands;
	Command* Command_array;
	int Register_block[16];
	Memory_space* Mem_space;
	int Memory_size;

public:


	Programm()
	{
		Amount_of_commands = 0;
		Command_array = NULL;
		Mem_space = NULL;
		Memory_size = 0;
	}







	int Search_position(Command NC, int* pr)
	{
		




		if (NC.Address < Command_array[0].Address)
		{
			*pr = 0;
			return 0;
		}
		if (NC.Address == Command_array[0].Address)
		{
			*pr = 1;
			return 0;
		}


		if (NC.Address > Command_array[Amount_of_commands].Address)
		{
			*pr = 0;
			return Amount_of_commands;
		}

		if (NC.Address == Command_array[Amount_of_commands].Address)
		{
			*pr = 1;
			return Amount_of_commands;
		}



		for (int i = 0; i < Amount_of_commands-1; i++)
		{
			if ((NC.Address > Command_array[i].Address) && (NC.Address < Command_array[i + 1].Address))
			{
				*pr = 0;
				return i + 1;
			}
			if (NC.Address == Command_array[i].Address)
			{
				*pr = 1;
				return i;
			}
		}
	}



	void Add_command( Command NC)
	{
		int pr;
		
		Command* tmp_arr;

		if(Command_array==NULL)
		{
			Command_array = new Command[1];
			Amount_of_commands = 1;
			Command_array[0] =NC;
			return;

		}

		if (NC.Address < 0)
			NC.Address = Command_array[Amount_of_commands - 1].Address + 10;
		    
        int pos = Search_position(NC, &pr);

		if (pr)
		{
			tmp_arr = new Command[Amount_of_commands];
			for (int i = 0; i < Amount_of_commands; i++)
			{
				if (i == pos)
					tmp_arr[i] = NC;
				else
					tmp_arr[i] = Command_array[i];
			}

		}


		else
		{
			tmp_arr = new Command[Amount_of_commands + 1];
			int j = 0;
			for (int i = 0; i < Amount_of_commands; i++)
			{
				if (j == pos)
				{
					tmp_arr[j] = NC;
					i--;
				}
				else
					tmp_arr[j] = Command_array[i];

				j++;
			}
			if (pos == Amount_of_commands)
				tmp_arr[Amount_of_commands] = NC;

			Amount_of_commands++;

		}


		delete[] Command_array;
		Command_array = tmp_arr;

	}





	void Delete_command(int addr)
	{
		int pos = -1;
		for (int i = 0; i < Amount_of_commands; i++)
			if (Command_array[i].Address == addr)
				pos = i;
		if (pos < 0)
			cout << "No command with this address";
		else
		{
			Command* tmp = new Command[Amount_of_commands - 1];
			for (int i = 0; i < pos; i++)
				tmp[i] = Command_array[i];
			for (int i = pos + 1; i < Amount_of_commands; i++)
				tmp[i-1] = Command_array[i];

			delete[] Command_array;
			Command_array = tmp;
			Amount_of_commands--;

		}
	}


	Command* Search_command(int addr)
	{
		int pos = -1;
		for (int i = 0; i < Amount_of_commands; i++)
			if (Command_array[i].Address == addr)
				pos = i;
		if (pos < 0)
		{
			cout << "No command with this address";
			return NULL;
		}
		else
			return Command_array+pos;
	}




	Command Input_command()              //ДОДЕЛАТЬ !!!
	{
		Command NC{ 0,NULL };
		int addr;
		cout << "Enter address: ";
		cin >> addr;
		if (cin.good())
			NC.Address = addr;
		else
			NC.Address = Command_array[Amount_of_commands - 1].Address + 10;
		cout << endl;


		int choice;
		cout << "Choose operator type:" << endl;
		cout << "1-Register operator" << endl;
		cout << "2-Register-memory operator" << endl;
		cout << "3-Transit operator" << endl;
		cout << "4-Declare operator" << endl;
		cin >> choice;

		if (choice == 1)
		{
			Register_operator* tmp1=new Register_operator;
			tmp1->input_op();
			NC.Descriptor = tmp1;
		}

		if (choice == 2)
		{
			Register_memory_operator* tmp2=new Register_memory_operator;
			tmp2->input_op();
			NC.Descriptor = tmp2;
		}

		if (choice == 3)
		{
			Transit_operator* tmp3=new Transit_operator;
			tmp3->input_op();
			NC.Descriptor = tmp3;
		}


		if (choice == 4)
		{
			Declare_operator* tmp4=new Declare_operator;
			tmp4->input_op();
			NC.Descriptor = tmp4;
		}

		return NC;

	}





	void Show_commands()
	{
		for (int i = 0; i < Amount_of_commands; i++)
		{
			cout << Command_array[i].Address<<" ";
			Command_array[i].Descriptor->output_op();
			cout << endl;
		}
	}





};