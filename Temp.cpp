#include "Temp.h"
#include "List.h"
#include <iostream>
class List;

Temp& Temp::operator=(double c) {
	if (i >= s->GetFixedSize() || i < 0)throw - 3;
	Node* cur = s->head;
	if (cur == nullptr) {
		Num n(c, i);
		s->push(n);
	}
	else {
		while (cur != nullptr) {
			if (cur->data.j == i) {
				cur->data.z = c;
				return*this;
			}
			if (cur->data.j > i) {
				Num n(c, i);
				Node* temp = cur;
				s->head = new Node(n, temp);
				s->size++;
				//printf("tt\n");
				return*this;
			}
			if (cur->next != nullptr) {
				if (cur->data.j < i && cur->next->data.j > i) {
					Num n(c, i);
					Node* temp = cur->next;
					cur->next = new Node(n, temp);
					s->size++;
					return*this;
				}
			}
			else {
				if (cur->data.j < i) {
					Num n(c, i);
					cur->next = new Node(n, nullptr);
					s->size++;
					return*this;
				}
			}
			cur = cur->next;
		}
	}
}


Temp::operator double() {
	if (i >= s->GetFixedSize() || i < 0)throw - 2;
	Node* cur = s->head;
	while (cur!=nullptr) {
		if (cur->data.j==i) {
			return cur->data.z;
		}
		cur = cur->next;
	}
	return 0;
}