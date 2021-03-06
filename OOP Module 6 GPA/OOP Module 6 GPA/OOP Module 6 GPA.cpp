// OOP Module 6 GPA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Weapon
{
protected:
	int strength;
	char type;
public:
	int modified;

	int return_strength()
	{
		return strength;
	}

	char return_type()
	{
		return type;
	}

	void setPower(int val)
	{
		strength = val;
		return;
	}
};

class Rock : public Weapon
{

public:
	Rock()
	{
		type = 'r';
	}
	bool battle(Weapon w)
	{
		switch (w.return_type()) {
		case 'p':
			w.modified = (w.return_strength() * 2);
			this->modified = (this->strength / 2);
			break;
		case 's':
			w.modified = (w.return_strength() / 2);
			this->modified = (this->strength * 2);
			break;
		}
		if (this->modified > w.modified) { return true; }
		else { return false; }
	}
};

class Paper : public Weapon
{

public:
	Paper()
	{
		type = 'p';
	}
	bool battle(Weapon w)
	{
		switch (w.return_type()) {
		case 's':
			w.modified = (w.return_strength() * 2);
			this->modified = (this->strength / 2);
			break;
		case 'r':
			w.modified = (w.return_strength() / 2);
			this->modified = (this->strength * 2);
			break;
		}
		if (this->modified > w.modified) { return true; }
		else { return false; }
	}
};

class Scissors : public Weapon
{

public:
	Scissors()
	{
		type = 's';
	}
	bool battle(Weapon w) {
		switch (w.return_type()) {
		case 'r':
			w.modified = (w.return_strength() * 2);
			this->modified = (this->strength / 2);
			break;
		case 'p':
			w.modified = (w.return_strength() / 2);
			this->modified = (this->strength * 2);
			break;
		}
		if (this->modified > w.modified) { return true; }
		else { return false; }
	}
};

int main() {
		Rock rock; Paper paper; Scissors scissors;
		int power;
		cout << "Rock: "; cin >> power; rock.setPower(power);
		cout << "Paper: "; cin >> power; paper.setPower(power);
		cout << "Scissor: "; cin >> power; scissors.setPower(power);
		cout << rock.battle(paper) << paper.battle(scissors) << scissors.battle(rock) << endl;
}