#include <iostream>
#include <conio.h>
#include <iomanip>
#include <time.h>
#define w 9
#define x 30
#define y 4
using namespace std;

int getEXAM(int r, int c, int EXAM[x][y])
{
	return EXAM[r][c] = 50 + rand() % 50;
}

float computeFG(int r, int c, float FG[x], int EXAM[x][y])
{
	FG[r] += EXAM[r][c];
	return FG[r];
}

float computeEG(int r, float FG[x], float EG[x], float EGcount[9])
{
	if (FG[r] >= 96.0 && FG[r] <= 100.0)
	{
		EGcount[0]++;
		return EG[r] = 1.0;
	}

	else if (FG[r] >= 94.0 && FG[r] < 96.0)
	{
		EGcount[1]++;
		return EG[r] = 1.25;
	}

	else if (FG[r] >= 92.0 && FG[r] < 94.0)
	{
		EGcount[2]++;
		return EG[r] = 1.5;
	}

	else if (FG[r] >= 89.0 && FG[r] < 92.0)
	{
		EGcount[3]++;
		return EG[r] = 1.75;
	}

	else if (FG[r] >= 87.0 && FG[r] < 89.0)
	{
		EGcount[4]++;
		return EG[r] = 2.0;
	}

	else if (FG[r] >= 84.0 && FG[r] < 87.0)
	{
		EGcount[5]++;
		return EG[r] = 2.25;
	}

	else if (FG[r] >= 82.0 && FG[r] < 84.0)
	{
		EGcount[6]++;
		return EG[r] = 2.5;
	}

	else if (FG[r] >= 79.0 && FG[r] < 82.0)
	{
		EGcount[7]++;
		return EG[r] = 2.75;
	}

	else if (FG[r] >= 75.0 && FG[r] < 79.0)
	{
		EGcount[8]++;
		return EG[r] = 3.0;
	}

	else if (FG[r] < 75.0)
	{
		EGcount[8]++;
		return EG[r] = 5.0;
	}

	else
		return EG[r] = 0;
}

void displayEXAM(int EXAM[x][y], float FG[y], float EG[x])
{
	for (int r= 0; r < 30; r++)
	{
		cout << setw(w) << r + 1 << setw(w);

		for (int c = 0; c < 4; c++)
		{
			cout << EXAM[r][c] << setw(w);
		}
		cout << fixed << setprecision(2) << FG[r] << setw(w) << EG[r] << endl;
	}
	
}

int main()
{
	int EXAM[x][y];
	float FG[x] = { 0 }, EGcount[9] = { 0 }, EG[x];
	srand(time(NULL));

	cout << "Class Record" << endl << endl;

	cout << setw(w) << left << "Student#" << setw(w) << "Exam 1" << setw(w) << "Exam 2" << setw(w) << "Exam 3" << setw(w) << "Exam 4" << setw(w) << "FG" << "EQ" << endl;

	for (int r = 0; r < 30; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			getEXAM(r, c, EXAM);
			computeFG(r, c, FG, EXAM);
			
		}
	}

	for (int r = 0; r < 30; r++)
	{
		FG[r] /= y;
		for (int c = 0; c < 4; c++)
		{
			computeEG(r, FG, EG, EGcount);
		}
	}
	displayEXAM(EXAM, FG, EG);
	
	_getch();
	return 0;
}