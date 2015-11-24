/*/////////////////////////////////////////////////////////////////////////////
///@file LinkListStack.hpp													///
///@author Jeff Goymerac 153 sec a											///
///@this file impliments the LinkedList Stack 								///
///																			///
/// 																		///
/////////////////////////////////////////////////////////////////////////////*/

#include <iomanip>
#include <iostream>
#include <string>
#include "LinkedListStack.hpp"

#include "abstractstack.h"

using namespace std;

int main()
{
	LLStack<int> Q;
	string input = "";
	int q = 0,
		r = 0, 
		t=0, 
		s = 0;
	
	
	
		do{
			try{
				cin >> input;
				if (input == "+")
				{


					q = Q.top();
					Q.pop();
					r = Q.top();
					Q.pop();
					s = q + r;
					Q.push(s);

				}
				else if (input == "-")
				{
					Q.subtract();
				}
				else if (input == "*")
				{
					Q.multiply();
				}
				else if (input == "/")
				{
					Q.divide();
				}
				else if (input == "%")
				{
					Q.mod();
				}
				else if (input == "sum")
				{
					Q.sum();
				}
				else if (input == "prod")
				{
					Q.prod();
				}
				else if (input == "#")
				{
					Q.print();
				}
				else if (input == "$")
				{
					Q.clear();
				}
				else if (input == "!")
				{
					Q.negative();
				}

				else
				{
					t = atoi(input.c_str());
					Q.push(t);
				}

			}
			catch (string s)
			{
				cout << s;
			}
			



		} while (input != "@");
			
			Q.clear();


			return 0;




	}
	



