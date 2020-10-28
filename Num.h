#pragma once
class Num
{
	double z;
	int j;
public:
	Num();
	Num(double z, int j);
	double Z()const;
	int J()const;

	friend class Temp;
	friend class Matrix;
};

