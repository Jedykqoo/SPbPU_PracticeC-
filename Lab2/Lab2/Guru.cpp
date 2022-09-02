#include "Guru.h"
#include <fstream>
#include <iostream>

// Будем брать студентов из списка и "случайно" делать из них Хороших/Плохих/Средних
void teacher::getStudent(string fileName) {
	ifstream F(fileName);
	string name;
	int num = get_numberOfStudents();
	cout << "num = " << num << endl;
	for (int i = 0; i < num; i++) {
		F >> name;
		if (i % 3 == 0) {
			//cout << name << " is goodStudent" << endl;
			testResults.insert(make_pair(new goodStudent(name), 0));
		} 
		else if(i % 3 == 1) {
			//cout << name << " is badStudent" << endl;
			testResults.insert(make_pair(new badStudent(name), 0));
		}
		else {
			//cout << name << " is averageStudent" << endl;
			testResults.insert(make_pair(new averageStudent(name), 0));
		}
	}
	F.close();
}

void teacher::getEquation(string fileName) {
	ifstream F(fileName);
	double a, b, c;
	for (int i = 0; i < get_numberOfStudents(); i++) {
		F >> a >> b >> c;
		addEquation(a, b, c);
	}
	F.close();
}

void teacher::solutionVerification() {
	solution corrSolution, studSolution;
	for (auto current = testResults.begin(); current != testResults.end(); current++) {
		for (int i = 0; i < get_numberOfEquations(); i++) {
			corrSolution = equations[i].ToSolve();
			studSolution = current->first->ToSolve(equations[i]);
			if (corrSolution == studSolution) {
				current->second++;
			}
		}
	}
}

void teacher::publicationOfResults() {
	cout << "Results:" << endl;
	for (auto current = testResults.begin(); current != testResults.end(); current++) {
		cout << current->first->getName() << "\t" << current->second << endl;
	}
}