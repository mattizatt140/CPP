#pragma once
class math
{
	public:
	int add(int a, int b)
	{
		return (a + b);
	}
	int sub(int a, int b)
	{
		return (a - b);
	}
	int multi(int a, int b)
	{
		return (a * b);
	}
	double divide(int a, int b)
	{
		return a / (1.0 * b);
	}
	long int exp(int b, int e)
	{
		long int answer = 1;
		for (int i = 0; i < e; i++)
		{
			answer *= b;
		}
		return answer;
	}
};