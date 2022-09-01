#include "Students.h"

solution badStudent::ToSolve(equation& value) {
	return { 1, 0, 0 };
}

solution goodStudent::ToSolve(equation& value) {
	return value.ToSolve();
}

solution averageStudent::ToSolve(equation& value) {
	if (rand() % 2) {
		return value.ToSolve();
	} 
	else {
		return { 1, 0, 0 };
	}
}