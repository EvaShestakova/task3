#include <iostream>
#include <fstream>
#include "Matrix.h"
#include "List.h"
using namespace std;

class List;

Matrix::Matrix()
{
	m = 0;
	n = 0;
	a = nullptr;
}

Matrix::Matrix(int m, int n)
{
	this->m = m;
	this->n = n;
	a = new List[m];
	for (int i = 0; i < m; i++) {
		a[i] = List(n);
	}
}

Matrix::~Matrix()
{
	if (a != nullptr) {
		for (int i = 0; i < m; i++) {
			a[i].clear();
		}
		delete[] a;
	}
}



List& Matrix::operator[](const int i)
{
	if (i<0 || i>m) throw - 5;
	return(a[i]);
}

Matrix& Matrix::operator=(Matrix& m)
{
	if (a != nullptr) {
		for (int i = 0; i < this->m; i++) {
			a[i].clear();
		}
		delete[] a;
	}
	this->m = m.m;
	this->n = m.n;
	Node* cur;
	a = new List[this->m];
	for (int i = 0; i < this->m; i++) {
		a[i] = List(n);
		cur = m[i].head;
		while (cur != nullptr) {
			a[i].push(cur->data);
			cur = cur->next;
		}
	}
	return *this;
}

void Matrix::Change(int i, int j)
{
	if (i < 0 || i >= m || j < 0 || j >= m)throw - 6;
	Node* temp = a[i].head;
	int t = a[i].size;
	a[i].head = a[j].head;
	a[i].size = a[j].size;
	a[j].head = temp;
	a[j].size = t;
}

void Matrix::Mult(int i, double b)
{
	if (b == 0) {
		a[i].clear();
	}
	else {
		Node* cur = a[i].head;
		while (cur != nullptr) {
			cur->data.z = cur->data.z * b;
			cur = cur->next;
		}
	}
}

List* Matrix::Comb(int i, int j, double a, double b)
{
	if (i < 0 || i >= m || j < 0 || j >= m)throw - 7;
	Matrix temp;
	Node* cur;
	temp.m = m;
	temp.n = n;
	temp.a = new List[m];
	for (int i = 0; i < m; i++) {
		temp.a[i] = List(n);
		cur = this->a[i].head;
		while (cur != nullptr) {
			temp.a[i].push(cur->data);
			cur = cur->next;
		}
	}
	List* res=new List(n);
	temp.Mult(i, a);
	temp.Mult(j, b);
	double c;
	for (int k = 0; k < n; k++) {
		c = temp[i][k] + temp[j][k];
		if (c != 0) {
			Num nn(c, k);
			res->push(nn);
		}
	}
	return res;
}

double* Matrix::Str(int i)
{
	if (i < 0 || i >= m)throw - 7;
	double* res = new double[n];
	Node* cur = a[i].head;
	for (int j = 0; j < n; j++) {
		if (cur == nullptr) {
			res[j] = 0;
		}
		else {
			if (cur->data.J() == j) { res[j] = cur->data.z; cur = cur->next;}
			else { res[j] = 0; }
		}
	}
	return res;
}

double* Matrix::Col(int j)
{
	if (j < 0 || j >= n)throw - 7;
	double* res = new double[m];
	for (int i = 0; i < m; i++) {
		res[i] = a[i][j];
	}
	return res;
}

Matrix::Matrix(ifstream &file)
{
	if (!file.is_open()) {
		std::cout << "Error! Cannot open\n";
		throw - 3;
	}
	long file_size;
	file.seekg(0, ios::end);
	file_size = file.tellg();
	if (file_size == 0) {
		cout << "Empty" << endl; 
		file.close();
		throw - 4;
	}
	else {
		double t;
		file.seekg(0, std::ios::beg);
		file >> m;
		file >> n;
		a = new List[m];
		for (int i = 0; i < m; i++) {
			a[i] = List(n);
			for (int j = 0; j < n; j++) {
				file >> t;
				if (t != 0) {
					Num n(t, j);
					a[i].push(n);
				}
			}
		}
	}

}

void Matrix::Print()
{
	for (int i = 0; i < m; i++) {
		a[i].Print();
	}
}


