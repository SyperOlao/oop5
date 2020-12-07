#include <windows.h>

#include "Series.h"
#include "AlternatingSeries.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Введите имя файла: " << endl << "> ";
	string filename;
	cin >> filename;

	Series s(filename);
	
	if (s.Sign() == Signs::NonNegative) 
	{
		NonNegativeSeries nns(filename);
		cout << "Ваш ряд знакопостоянный положительный.\n";
		nns.Print(nns.getNumberOfTerms());

		cout << "Сходимость через сумму ряда: " << nns.ConvergenceFile();
		cout << endl;
		cout << "Частичная сумма 3 членов: " << nns.PartialSum(3);
		cout << endl;
	}
	else 
	{
		AlternatingSeries as(filename);
		cout << "Ваш ряд знакопеременный.\n";
		as.Print(as.getNumberOfTerms());

		cout << "Сходимость знакопеременного ряда по Лейбницу: " << as.ConvergenceFile();
		cout << endl;
		cout << "Частичная сумма 3 членов: " << as.PartialSum(3);
		cout << endl;

	}
		
}