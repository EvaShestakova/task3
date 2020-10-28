#pragma once

class List;
class Temp
{
	 List* s;
	 int i;
public:
	Temp(List* s, int i) { this->s = s; this->i = i; }
	Temp& operator=(double c);
	operator double();
};


