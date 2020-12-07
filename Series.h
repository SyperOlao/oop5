#pragma once

#include <iostream>

#include <fstream>

using namespace std;

enum class Signs {
	NonNegative,
	Alternating
};

class Series
{
protected:

	int numOfTerms;
	double* terms;

public:

	Series(string filename);
	Series(int num);

	~Series() { delete[] terms; }

	int getNumberOfTerms() { return numOfTerms; }
	double* getTerms() { return terms; }

	virtual Signs Sign();

	virtual bool ConvergenceFile();
	double PartialSum(int k);

	void Print(int k);

	void Multiply(int k);

};

