#include <windows.h>

#include "Series.h"
#include "AlternatingSeries.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "������� ��� �����: " << endl << "> ";
	string filename;
	cin >> filename;

	Series s(filename);
	
	if (s.Sign() == Signs::NonNegative) 
	{
		NonNegativeSeries nns(filename);
		cout << "��� ��� ��������������� �������������.\n";
		nns.Print(nns.getNumberOfTerms());

		cout << "���������� ����� ����� ����: " << nns.ConvergenceFile();
		cout << endl;
		cout << "��������� ����� 3 ������: " << nns.PartialSum(3);
		cout << endl;
	}
	else 
	{
		AlternatingSeries as(filename);
		cout << "��� ��� ���������������.\n";
		as.Print(as.getNumberOfTerms());

		cout << "���������� ���������������� ���� �� ��������: " << as.ConvergenceFile();
		cout << endl;
		cout << "��������� ����� 3 ������: " << as.PartialSum(3);
		cout << endl;

	}
		
}