#include "Varfuncr.h"

void main() {
	std::cout << ivarparm(3, 2, 4, 5) << std::endl;
	std::cout << svarparm(2, 3, 2) << std::endl;
	std::cout << fvarparm(1.5, 2.0, 3.5, 4.0, FLT_MAX) << std::endl;
	std::cout << dvarparm(1.5, 2.5, 5.5, 7.0, DBL_MAX) << std::endl;
}