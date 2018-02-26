#pragma once
using namespace std;

class logCalc
{
private:
	int _base; // var b
	int _result; // var y
	int _exponent; //var x
	int _answer{ 1 };
public:
	// only Input functions need to be called 
	void SolveForX_Input(); 
	void SolveForX(int _base, int _result); 

	void SolveForB_Input();
	void SolveForB(int _result, int _exponent);
	
	void SolveForY_Input();
	void SolveForY(int _base, int _exponent);
};