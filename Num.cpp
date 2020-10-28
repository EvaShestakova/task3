#include "Num.h"

Num::Num() {
	z = 0; 
	j = 0; 

}
Num::Num(double z, int j) { 
	this->z = z; this->j = j;
}

double Num::Z()const {
	return z;
}
int Num::J()const {
	return j;
}