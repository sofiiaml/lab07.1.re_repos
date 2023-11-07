#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;



void Create(int** y, const int rowCount, const int colCount, const int Low,
	const int High, int rowIndex) {
	if (rowIndex == rowCount)
		return;
	for (int i = 0; i < colCount; i++) {
		y[rowIndex][i] = Low + rand() % (High - Low + 1);
	}
	Create(y, rowCount, colCount, Low, High, rowIndex + 1);
}


void Print(int** y, const int rowCount, const int colCount, int rowIndex) {
	if (rowIndex == rowCount)
		return;
	for (int j = 0; j < colCount; j++)
		cout << setw(4) << y[rowIndex][j];
	cout << endl;
	Print(y, rowCount, colCount, rowIndex + 1);
}

void Change(int** y, const int row1, const int row2, const int colCount, int j) {
	if (j == colCount) {
		return;
	}
	int tmp = y[row1][j];
	y[row1][j] = y[row2][j];
	y[row2][j] = tmp;
	Change(y, row1, row2, colCount, j + 1);
}

void Sort(int** y, const int rowCount, const int colCount, int i0) {
	if (i0 == rowCount - 1)
		return;
	for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
		if ((y[i1][0] > y[i1 + 1][0])
			||
			(y[i1][0] == y[i1 + 1][0] &&
				y[i1][1] > y[i1 + 1][1])
			||
			(y[i1][0] == y[i1 + 1][0] &&
				y[i1][1] == y[i1 + 1][1] &&
				y[i1][3] > y[i1 + 1][3]))
			Change(y, i1, i1 + 1, colCount, 0);
	Sort(y, rowCount, colCount, i0 + 1);
}

void Calc(int** y, const int rowCount, const int colCount, int& sum, int& count, int i) {
	if (i == rowCount)
		return;
	for (int j = 0; j < colCount; j++)
		if (y[i][j] % 2 != 0 || !(y[i][j] % 3 == 0))
		{
			sum += y[i][j];
			count++;
			y[i][j] = 0;
		}
	Calc(y, rowCount, colCount, sum, count, i + 1);

}
int main()
{
	srand((unsigned)time(NULL));
	int Low = 11;
	int High = 64;
	int rowCount = 8;
	int colCount = 5;
	int** y = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		y[i] = new int[colCount];
	Create(y, rowCount, colCount, Low, High, 0);
	cout << "Array:";cout << endl;
	Print(y, rowCount, colCount, 0);
	cout << "Sort Array:"; cout << endl;
	Sort(y, rowCount, colCount, 0);
	Print(y, rowCount, colCount, 0);
	

	int sum = 0;
	int count = 0;
	Calc(y, rowCount, colCount, sum, count, 0);
	cout <<setw(4) << "S = " << sum << endl;
	cout <<setw(4) << "k = " << count << endl;
	cout << "Changed Array:"; cout << endl;
	Print(y, rowCount, colCount, 0);
	for (int i = 0; i < rowCount; i++)
		delete[] y[i];
	delete[] y;
	return 0;
}

