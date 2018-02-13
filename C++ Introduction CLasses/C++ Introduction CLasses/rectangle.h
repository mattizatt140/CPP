#pragma once
class rectangle
{
public:
	
	rectangle()
		: _width{}, _height{}
	{}
	rectangle(int intitial_width, int initial_height)
		: _width{intitial_width}, _height{initial_height}
	{}
	
	void resize(int new_width, int new_height)
	{
		_width = new_width;
		_height = new_height;

	}
	int get_area()
	{
		return _width * _height;
	}
	int get_width() { return _width; }
	int get_height() { return _height; }

private:
	int _width;
	int _height;
};