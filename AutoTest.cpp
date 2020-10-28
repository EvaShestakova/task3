#include "Matrix.h"
#include "List.h"
int AutoTest() {
	Matrix m(1,1);
	if (m[0][0] == 0) {
		return 1;
	}
	else return 0;
}