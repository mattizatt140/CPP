#include "stdafx.h"
#include <iostream>




int main()
{
	int b = 5;
	int e = 3;
	int num = 1;
	int answer;

	for (int i = 0; i < e; i++)
	{
		num *= b;
	}

	if (num == 125)
	{
		std::cout << "Code Works" << std::endl;
	}
	else
	{
		std::cout << "Code doesn't work" << std::endl;
	}
}

