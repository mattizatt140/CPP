#include "stdafx.h"
#include <iostream>
#include <string>

int pow(int b, int e)
{
	if (e < 0)
	{
		std::cout << "Invalid" << std::endl;
		return 0;
	}
	else if (e == 0)
	{
		return 1;
	} else {

		int num = 1;
		for (int i = 0; i < e; i++)
		{
			num *= b;
		}
		
		return num;

	}
	
}



int main()
{
	int answer = pow(5, -2);
	std::cout << answer << std::endl;
}

