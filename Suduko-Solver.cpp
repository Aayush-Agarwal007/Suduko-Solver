#include<iostream>
#include<math.h>
using namespace std;

void Print(int Suduko[][9], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << Suduko[i][j] << " ";
		}
		cout << endl;
	}
}
bool isValid(int Suduko[][9], int i, int j, int num, int n)
{
	for (int x = 0;x < n;x++)
	{
		if (Suduko[i][x] == num)
		{
			return  false;
		}
	}
	for (int x = 0;x < n;x++)
	{
		if (Suduko[x][j] == num)
		{
			return  false;
		}
	}
	int R = sqrt(n);
	int si = i - i % R;
	int sj = j - j % R;
	for (int x = si;x < si + R;x++)
	{
		for (int y = sj;y < sj + R;y++)
		{
			if (Suduko[x][y] == num)
			{
				return false;
			}
		}
	}
	return true;

}
bool SudukoSolver(int Suduko[][9], int i, int j, int n)
{
	if (i == n)
	{
		Print(Suduko, n);
		return true;
	}
	if (j == n)
	{
		return SudukoSolver(Suduko, i+1, 0, n);

	}
	if (Suduko[i][j] != 0)
	{
		return SudukoSolver(Suduko, i, j + 1, n);
	}
	for (int num = 1; num <= 9;num++)
	{
		if (isValid(Suduko, i, j, num, n))
		{
			Suduko[i][j] = num;
			bool SubAns = SudukoSolver(Suduko, i, j + 1, n);
			if (SubAns)
			{
				return true;
			}
			Suduko[i][j] = 0;

		}
	}
	return false;
}
int main()
{
	int n = 9;
	int Suduko[9][9] =
	{
		{5, 0, 0, 0, 0, 0, 0, 8, 0},
		{0, 0, 0, 3, 0, 0, 0, 0, 9},
		{0, 0, 0, 0, 9, 0, 0, 0, 0},
		{0,9, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 3, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 8},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0}
	};
	SudukoSolver(Suduko, 0, 0, n);
	return 0;



}