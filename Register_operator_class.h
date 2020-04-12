#pragma once
#include <C:\Users\Михаил\source\repos\LabFour.1\Operator_class.h>
using namespace std;
#include <C:\Users\Михаил\source\repos\Lab4STL\command list.h>

extern int Registers[16];
extern Table<string, int> Memory;


class Register_operator :public  Operator
{
protected:

	int Reg1_numb;
	int Reg2_numb;

public:

	Register_operator()
	{
		Label = "";
		Operation_code = "";
		Reg1_numb = 0;
		Reg2_numb = 0;
	}


	Register_operator(string lab,string op,int r1,int r2)
	{
		Label = lab;
		Operation_code = op;
		Reg1_numb = r1;
		Reg2_numb = r2;
	}



	int return_reg1()
	{
		return Registers[Reg1_numb];
	}



	int return_reg2()
	{
		return Registers[Reg2_numb];
	}



	void change_reg1(int value)
	{
		Registers[Reg1_numb] = value;
	}

	void change_reg2(int value)
	{
		Registers[Reg2_numb] = value;
	}




	void input_op(string label, string op_code, int r, string RoM)
	{

		Label = label;
		Operation_code = op_code;
		Reg1_numb = r;
		Reg2_numb = stoi(RoM);

	}


	void output_op()
	{
		if (Label != "NULL")
			cout << Label << " ";
		cout <<  Operation_code<<" "<<Reg1_numb<<" "<<Reg2_numb;
	}






	string Operator_info()
	{
		return "Register_operator";
	}


	int exec()
	{
	   int res = C_t()[Operation_code](return_reg1(), return_reg2());
       change_reg1(res);
	   return 0;
	};
	

	string return_label()
	{
		return Label;
	}



	Register_operator* clone()
	{
		Register_operator* cl = new Register_operator;
		cl->Label = Label;
		cl->Operation_code = Operation_code;
		cl->Reg1_numb = Reg1_numb;
		cl->Reg2_numb = Reg2_numb;
		return cl;
	}



	void save_in_file(ofstream& File)
	{
		File << Operator_info()<<" "<< Label << " " << Operation_code << " " << Reg1_numb << " " << Reg2_numb << endl;
	}

	
	void load_op(ifstream& File)
	{
		File  >> Label>> Operation_code >> Reg1_numb >> Reg2_numb;
	}


};
