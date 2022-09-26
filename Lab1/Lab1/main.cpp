#include "QuadraticEquation.h"

//Solving a quadratic equation

int main() {
	double a = 0, b = 0, c = 0;
	double &_a = a, &_b = b, &_c = c;

	GetCoef(_a, _b, _c);

	equation example(_a, _b, _c);
	example.ToSolve().PrintSolution();

	return 0;
}