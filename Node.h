#pragma once
#include "Num.h"

class Num;

class Node
{
public:
	Node* next;
	Num data;
	Node(Num data, Node* next);
};

