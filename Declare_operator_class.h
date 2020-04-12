#pragma once
#include <C:\Users\Михаил\source\repos\LabFour.1\Operator_class.h>
#include <C:\Users\Михаил\source\repos\Lab4STL\templ table.h>
#include <string>
using namespace std;
using namespace oper;

extern int Registers[16];
extern Table<string, int> Memory;

class Declare_operator :public  Operator
{
protected:
	int operand;
	string  Data_Id;



public:


	Declare_operator* clone()
	{
		Declare_operator* cl = new Declare_operator;
		cl->Label = Label;
		cl->Operation_code = Operation_code;
		cl->operand = operand;
		cl->Data_Id = Data_Id;
		return cl;
	}




	Declare_operator()
	{
		Label = "";
		Operation_code = "";
		operand = 0;
		Data_Id = "";
	}


	Declare_operator(string lab, string code, int op, string id)
	{
		Label = lab;
		Operation_code = code;
		operand = op;
		Data_Id = id;
	}

	string return_label()
	{
		return Label;
	}

	int exec()
	{
		pair<string, int> np;
		np.first = Data_Id;
		np.second = operand;
		Memory.insert(np);
		return 0;
	};


	void input_op(string label, string op_code, int oper, string lab)
	{
		Label = label;
		Operation_code = op_code;
		cin>>operand;
		cin>>Data_Id;
	}


	void output_op()
	{
		if (Label != "NULL")
			cout << Label << " ";
		cout << Operation_code << " " << operand << " " << Data_Id;

	}


	string Operator_info()
	{
		return "Declare_operator";
	}



	int return_id_value()
	{
		return Memory.find(Data_Id)->second;

	}




	void change_id_value(int new_id_value)
	{
		Memory.find(Data_Id)->second= new_id_value;
	}




	void save_in_file(ofstream& File)
	{
		File <<Operator_info()<<" "<< Label << " " << Operation_code << " " << operand << " " << Data_Id << endl;
	}


	void load_op(ifstream& File)
	{
		File >> Label >> Operation_code >> operand >> Data_Id;
	}


};