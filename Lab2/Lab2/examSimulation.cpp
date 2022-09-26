#include "examSimulation.h"

void exam() {
	int studNum = 20;
	int eqNum = 5;
	string eqFileName = "List of equations.txt";
	string studFileName = "Students list.txt";
	teacher guru(studNum, eqNum);
	guru.getEquation(eqFileName);
	guru.getStudent(studFileName);
	guru.solutionVerification();
	guru.publicationOfResults();
}