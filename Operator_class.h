#pragma once
#include <string>
#include <vector>
#include <C:\Users\Михаил\source\repos\Lab4STL\command list.h>
#include <C:\Users\Михаил\source\repos\Lab4STL\templ table.h>
#include <fstream>
using namespace std;



namespace oper
{
	

	string getstr()
	{
		
		string s = "";
		string sum = "";
		char c[1];
		cin.ignore(1);
		while (c[0] != '\n')
		{

			c[0] = cin.get();
			string s = string(c);
			s = s.substr(0, 1);
			if ((s != " ") && (s != "\n"))
				sum += s;
		}
		return sum;

	}



	class Operator
	{

	protected:

		string Label;
		string Operation_code;


	public:


		Operator()
		{
			Label = "";
			Operation_code = "";
		}


		virtual string return_label()
		{
			return Label;
		}


		virtual int exec()
		{
			return 0;
		}



		virtual string Operator_info()
		{
			return "operator type";
		}



		virtual Operator* clone()
		{
			Operator* cl = new Operator;
			cl->Label = Label;
			cl->Operation_code = Operation_code;
			return cl;
		}


		virtual void input_op(string label, string op_code,int r,string RoM)
		{
			Label = label;
			Operation_code = op_code;
		}



		virtual void output_op()
		{
			cout << Label << Operation_code;
		}


		virtual void save_in_file(ofstream& File)
		{

		}

		
		virtual void load_op(ifstream& File)
		{

		}

		
	};



	

}
























