#pragma once
#include <string>
#include <map>
#include "QuadraticEquation.h"

using namespace std;

class student {
public:
	student() {
		name = "No name";
	}
	student(const string& name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
	void setName(const string& name) {
		this->name = name;
	}
	virtual solution ToSolve(equation& value) = 0;
	virtual ~student() {};
private:
	string name;
};

class badStudent : public student {
public:
	badStudent(const string& name) {
		student::setName(name);
	}
	solution ToSolve(equation& value) override;
};

class goodStudent : public student {
public:
	goodStudent(const string& name) {
		student::setName(name);
	}
	solution ToSolve(equation& value) override;
};

class averageStudent : public student {
public:
	averageStudent(const string& name) {
		student::setName(name);
	}
	solution ToSolve(equation& value) override;
};