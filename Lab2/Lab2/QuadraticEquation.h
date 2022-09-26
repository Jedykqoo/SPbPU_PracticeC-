#pragma once
#ifndef _QUADRATICEQUATION_H_
#define _QUADRATICEQUATION_H_
#include <iostream>

using namespace std;

void GetCoef(double& a, double& b, double& c);

class solution {
public:
	void PrintSolution();

	solution(int count, double value_x1, double value_x2) {
		numberOfRoots = count;
		x1 = value_x1;
		x2 = value_x2;
	}
	solution() {
		numberOfRoots = 0;
		x1 = 0;
		x2 = 0;
	}

	bool operator== (const solution& toCompare) {
		return ((this->x1 == toCompare.x1) && (this->x2 == toCompare.x2));
	}

private:
	int numberOfRoots;
	double x1;
	double x2;
};

class equation {
public:
	equation() {
		a = b = c = 0;
	}
	equation(double coef_a, double coef_b, double coef_c) {
		a = coef_a;
		b = coef_b;
		c = coef_c;
	}
	solution ToSolve();
	// a * x^2 + b * x + c = 0
private:
	double a;
	double b;
	double c;
};

#endif _QUADRATICEQUATION_H_