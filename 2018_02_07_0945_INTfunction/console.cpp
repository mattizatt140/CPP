#include "stdafx.h"
#include <iostream>
#include <string>

string _answer;
int _num;



void pow(int b, int e)
{
	if (e < 0)
	{
		_answer = "Invalid";
		_num = 0;
		//std::cout << "Invalid" << std::endl;
		//return 0;
	}
	else if (e == 0)
	{
		_num = 1;
		
	} else {

		int num = 1;
		for (int i = 0; i < e; i++)
		{
			num *= b;
		}
		
		//return num;
		_num = num;
	}
	
}




int main()
{
	
	pow(5,-2);
	//int answer = pow(5, -2);
	//std::cout << answer << std::endl;
	
	if(_num == 0){
		std::cout << _answer +  << std::endl;
	} else {
		
		std::cout << _answer + " " + _num << std::endl;
		
	}
	
	
}

