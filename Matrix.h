#pragma once
#include <iostream>
using namespace std;

class List;

class Matrix
{
private:
	int m, n;
	List* a;
public:
	Matrix();
	Matrix(int m, int n);
	Matrix(ifstream &file);
	~Matrix();

	int GetM() { return m; };
	int GetN() { return n; };

	List& operator[](const int i);
	Matrix& operator=(Matrix& m);
	
	void Change(int i, int j);
	void Mult(int i, double b);
    List* Comb(int i, int j, double a, double b);
	double* Str(int i);
	double* Col(int j);

	void Print();
};

int AutoTest();