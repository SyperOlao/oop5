#include "Series.h"

Series::Series(string filename)
{
	ifstream file(filename);

	double temp;
	int num;
	file >> num;

	numOfTerms = num;
	terms = new double[numOfTerms];

	num = 0;
	while (file >> temp)
	{
		terms[num] = temp;
		num++;
	}

}

Series::Series(int num)
{
	numOfTerms = num;
	terms = new double[numOfTerms];
}

Signs Series::Sign()
{
	bool flag = false;
	for (int i = 0; i < numOfTerms && !flag; i++)
		if (terms[i] < 0)
			flag = true;

	if (flag)
		return Signs::Alternating;
	else
		return Signs::NonNegative;
}

bool Series::ConvergenceFile()
{
	if (PartialSum(numOfTerms) < 1)
		return true;
	else
		return false;
}

double Series::PartialSum(int k)
{
	double sum = 0;
	for (int i = 0; i < k; i++)
		sum += terms[i];
	return sum;
}

void Series::Print(int k)
{
	for (int i = 0; i < k; i++)
		cout << terms[i] << ' ';

	cout << endl;
}

void Series::Multiply(int k)
{
	for (int i = 0; i < numOfTerms; i++)
		terms[i] *= k;
}



//void CreatingSeriesFromFile(string filename)
//{
//	ifstream file(filename);
//	double denominator = 1, numerator = 1;
//	bool denom = false;

//	char tmp;
//	for (int i = 0; i < numOfTerms; i++)
//	{
//		while (file >> tmp)
//		{
//			if (!denom && tmp != '/')
//			{
//				int num = 0;
//				while (tmp >= '0' && tmp <= '9')
//				{
//					num *= 10;
//					num += tmp - '0';
//					file >> tmp;
//				}



//			}
//			if (tmp == '/')
//				denom = true;
//			else
//				if (denom)
//				{
//					denominator;
//				}

//		}
//	}


//}