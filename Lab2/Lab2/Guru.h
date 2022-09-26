#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Students.h"
#include "QuadraticEquation.h"

using namespace std;

class teacher {
public:
	teacher(int numberOfStudents, int numberOfEquations) {
		this->numberOfStudents = numberOfStudents;
		this->numberOfEquations = numberOfEquations;
	}
	int get_numberOfStudents() {
		return this->numberOfStudents;
	}
	int get_numberOfEquations() {
		return numberOfEquations;
	}
	void addEquation(double a, double b, double c) {
		equation eq(a, b, c);
		equations.push_back(eq);
	}
	void getStudent(string fileName);
	void getEquation(string fileName);
	void solutionVerification();
	void publicationOfResults();
private:
	int numberOfStudents;
	int numberOfEquations;
	vector <equation> equations;
	map <student*, int> testResults;
};
