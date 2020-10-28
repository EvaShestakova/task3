#include "List.h"
#include <iostream>
using namespace std;

List::List() {
	size = 0;
	fixed_size = 0;
	head = nullptr;
}

List::List(int size) {
	this->size = 0;
	fixed_size = size;
	head = nullptr;
}

List::~List() {
	clear();
}

void List::push(Num data) {
	if (size >= fixed_size || data.J()>=fixed_size) {
		throw - 1;
	}
	if (head == nullptr) {
		head = new Node(data,nullptr);
	}
	else {
		Node* cur = this->head;
		while (cur->next != nullptr) {
			cur = cur->next;
		}
		cur->next = new Node(data, nullptr);
	}
	size++;
}

void List::pop() {
	Node* temp = head;
	head = head->next;
	delete temp;
	size--;
}

void List::clear()
{
	while (size) {
		pop();
	}
}

void List::Print()
{
	if (fixed_size==0) {
		printf("List is empty");
	}
	else {
		Node* cur = this->head;
		if (cur == nullptr) {
			for (int i = 0; i < fixed_size; i++) {
				cout << 0 << " ";
			}
		}
		else {
			for (int i = 0; i < fixed_size; i++) {
				if (cur->data.J() == i) {
					cout << cur->data.Z() << " ";
					if(cur->next!=nullptr)cur = cur->next;
				}
				else {
					cout << "0 ";
				}
			}
		}
		cout << "\n";
	}
}

void List::PPrint()
{
	Node* cur = this->head;
	while (cur != nullptr) {
		cout << cur->data.Z() << " ";
		cur = cur->next;
	}
}

    Temp List::operator[](int i) {
	if (i >= fixed_size || i<0) {
		throw - 2;
	}
	else {
		return Temp(this, i);
	}
}


