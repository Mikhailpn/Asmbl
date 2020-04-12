#pragma once
#include <C:\Users\Михаил\source\repos\LabFour.1\Operator_class.h>
#include <string>
using namespace oper;
extern int Registers[16];
extern Table<string, int> Memory;



class Register_memory_operator :public  Operator
{
protected:
	int Reg_numb;
	string  Id;


public:


	Register_memory_operator* clone()
	{
		Register_memory_operator* cl = new Register_memory_operator;
		cl->Label = Label;
		cl->Operation_code = Operation_code;
		cl->Id = Id;
		cl->Reg_numb = Reg_numb;
		return cl;
	}




	Register_memory_operator()
	{
		Label = "";
		Operation_code = "";
		Reg_numb = 0;
		Id = "";
	}



	Register_memory_operator(string lab,string op,int rn,string id)
	{
		Label = lab;
		Operation_code = op;
		Reg_numb = rn;
		Id = id;
	}


	

	string Operator_info()
	{
		return "Register-memory_operator";
	}


	int exec()
	{
		int res = C_t()[Operation_code](Registers[Reg_numb], return_id_value());
		change_reg(res);
		return 0;
	}



	string return_label()
	{
		return Label;
	}

	void input_op(string label, string op_code, int r, string RoM)
	{
		

		Label = label;
		Operation_code = op_code;
		Reg_numb = r;
		Id = RoM;
	}



	void output_op()
	{
		if (Label != "NULL")
			cout << Label << " ";
		cout <<  Operation_code << " " << Reg_numb << " " << Id;
	}



	int return_reg()
	{
		return Registers[Reg_numb];
	}

	void change_reg(int value)
	{
		Registers[Reg_numb] = value;
	}





	int return_id_value()
	{
		return  Memory.find(Id)->second;
	}


	void change_id_value( int new_id_value)
	{
		Memory.find(Id)->second= new_id_value;
	}


	void save_in_file(ofstream& File)
	{
		File << Operator_info() << " " << Label << " " << Operation_code << " " << Reg_numb<< " " <<Id<< endl;
	}



	void load_op(ifstream& File)
	{
		File >> Label >> Operation_code >> Reg_numb>> Id;
	}


};