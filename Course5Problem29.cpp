#include <iostream>
#include <cstdlib>

using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

int RandomNumber(int From, int To)
{

	int RandomNum = rand() % (To - From + 1) + From;

	return RandomNum;
}

bool CheckPrime(int Number)
{

	int m = round(Number / 2);

	for (int i = 2; i <= m; i++)
	{
		if (Number % i == 0)
		{
			return false;
		}
	}

	return true;

}

void FillArrayWithRandomNumbers(int Arr[], int& ArrayLength)
{

	cout << "Enter number of elements you want to fill the array with\n";
	cin >> ArrayLength;

	for (int i = 0; i <= ArrayLength - 1; i++)
	{
		Arr[i] = RandomNumber(1, 10);
	}

}

void CopyPrimeArrayElementsToOtherArray(int Arr1[], int Arr2[], int ArrayLength, int& Array2Length)
{
	int Counter = 0;
	for (int i = 0; i <= ArrayLength - 1; i++)
	{
		if (CheckPrime(Arr1[i]))
		{
			Arr2[Counter] = Arr1[i];
			Counter++;
		}
	}

	Array2Length = Counter;
}

void PrintArray(int Arr[], int ArrayLength)
{

	for (int i = 0; i <= ArrayLength - 1; i++)
		cout << Arr[i] << " ";

	cout << "\n";
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr1[100], Array1Length = 0;

	FillArrayWithRandomNumbers(Arr1, Array1Length);

	int  Arr2[100], Array2Length = 0;
	CopyPrimeArrayElementsToOtherArray(Arr1, Arr2, Array1Length, Array2Length);

	cout << " Array 1 elements :";
	PrintArray(Arr1, Array1Length);

	cout << " Array 2 elements (only prime numbers) :";
	PrintArray(Arr2, Array2Length);


}