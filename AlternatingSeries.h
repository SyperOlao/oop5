#pragma once
#include "Series.h"

class AlternatingSeries : public Series
{
public:

	AlternatingSeries(string filename) :Series(filename) {}
	~AlternatingSeries() {}
	
	Signs Sign() override { return Signs::Alternating; }

	bool ConvergenceFile() override
	{
		bool res = false;

		for (int i = 0; i < numOfTerms - 1 && !res; i++)
			if (abs(terms[i]) < abs(terms[i + 1]))
				res = true;

		if (!res && PartialSum(numOfTerms) < 1)
			return true;
		else
			return false;
	}

};


class NonNegativeSeries : public Series
{
public:

	NonNegativeSeries(string filename) :Series(filename) {}
	~NonNegativeSeries() {}

	Signs Sign() override { return Signs::NonNegative; }

};
