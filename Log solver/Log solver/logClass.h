#pragma once
using namespace std;

class logCalc
{
public:
	int b;
	int y;
	int _answer{ 1 };

	void _log(int _base, int _result)
	{
		for (int i = 1; i < 20; i++)
		{
			_answer *= _base;
			if ( _answer == _result)
			{
				cout << "log" << _base << "(" << _result << ")";
				cout << " = " << i << endl;
				cout << "x = " << i << endl;
				break;
			}
			else if (_answer > _result)
			{
				cout << "This application only solves for integer exponents" << endl;
				break;
			}
		}
	}

	void _logSolve()
	{
		cout << "Logarithm Calculator:" << endl;
		
		cout << endl;
		cout << endl;

		cout << "Using the format {log(b)(y) = x}" << endl;
		cout << "Input variables 'b' and 'y' to solve for 'x' (integers only)" << endl;
		
		cout << endl;
		
		cout << "Input 'b': ";
		cin >> b;
		cout << "Input 'y': ";
		cin >> y;

		logCalc *plogCalc = new logCalc;
		plogCalc->_log(b, y);
	}

	void _log1(int _base, int _result)
	{
		for (int i = 1; i < 20; i++)
		{
			_answer *= _base;
			if (_answer == _result)
			{
				cout << "log" << _base << "(" << _result << ")";
				cout << " = " << i << endl;
				cout << "x = " << i << endl;
				break;
			}
			else if (_answer > _result)
			{
				cout << "This application only solves for integer exponents" << endl;
				break;
			}
		}
	}

	void _logSolve1()
	{
		cout << "Input 'b': ";
		cin >> b;
		cout << "Input 'y': ";
		cin >> y;

		logCalc *plogCalc = new logCalc;
		plogCalc->_log1(b, y);
	}
};