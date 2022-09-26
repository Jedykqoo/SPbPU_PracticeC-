#include "QuadraticEquation.h"

solution equation::ToSolve() {
	double x1 = 0, x2 = 0;

	if (a == 0) {
		if (b == 0) {
			if (c == 0) {
				return { -1, 0, 0 };
			}
			return { 0, 0, 0 };
		}
		x1 = x2 = -c / b;

		return { 1, x1, x2 };
	}

	double D = b * b - 4 * a * c;

	if (D < 0) {
		return { 0, 0, 0 };
	}
	x1 = (-b + sqrt(D)) / (2 * a);
	x2 = (-b - sqrt(D)) / (2 * a);

	return { 2, x1, x2 };
}

void solution::PrintSolution() {
	if (numberOfRoots == 0) {
		cout << "This equation has no roots" << endl;
	}
	else if (numberOfRoots == 1) {
		cout << "Root:\t" << x1 << endl;
	}
	else if (numberOfRoots == 2) {
		cout << "Roots:\t" << x1 << "\t" << x2 << endl;
	}
	else {
		cout << "Some error :)" << endl;
	}
}

void GetCoef(double& a, double& b, double& c) {
	cout << "Coefficients for quadratic equation : \n" << "a * x^2 + b * x + c = 0\n" << endl;

	cin >> a >> b >> c;
}