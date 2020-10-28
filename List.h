#pragma once
#include "Num.h"
#include "Node.h"
#include "Temp.h"

class Num;
class Node;
class List {
private:
	Node* head;
	int size;
	int fixed_size;
public:
	List();
	List(int size);
	~List();

	int GetSize()const { return size; }
	int GetFixedSize()const { return fixed_size; }
	void SetSize(int size) { fixed_size=size; }
	
	Temp operator[](const int i);

	void push(Num data);
	void pop();
	void clear();

	void Print();
	void PPrint();

	friend class Temp;
	friend class Matrix;
};

