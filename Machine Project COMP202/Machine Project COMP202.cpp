#include <iostream>
#include <conio.h>
#include <iomanip>
#include <time.h>
#include <math.h>
#define w 11 //Number to determine the table width (to easily adjust the table width)
#define x 30 //Number to determine number of students (to easily edit the number of students)
#define y 4 //Number to determine number of exams (to easily edit the number of exams)
using namespace std;

//All functions were called first before int main so that there is no need for prototypes
int getEXAM(int r, int c, int EXAM[x][y])
{
	return EXAM[r][c] = 50 + rand() % 51;
}

float computeFG(int r, int c, float FG[x], int EXAM[x][y])
{
	FG[r] = 0.20 * EXAM[r][0] + 0.30 * EXAM[r][1] + 0.25 * EXAM[r][2] + 0.25 * EXAM[r][3];
	return FG[r];
}

float computeEG(int r, float FG[x], float EG[x])
{
	if (FG[r] >= 96.0 && FG[r] <= 100.0)
	{
		return EG[r] = 1.0;
	}

	else if (FG[r] >= 94.0 && FG[r] < 96.0)
	{
		return EG[r] = 1.25;
	}

	else if (FG[r] >= 92.0 && FG[r] < 94.0)
	{
		return EG[r] = 1.5;
	}

	else if (FG[r] >= 89.0 && FG[r] < 92.0)
	{
		return EG[r] = 1.75;
	}

	else if (FG[r] >= 87.0 && FG[r] < 89.0)
	{
		return EG[r] = 2.0;
	}

	else if (FG[r] >= 84.0 && FG[r] < 87.0)
	{
		return EG[r] = 2.25;
	}

	else if (FG[r] >= 82.0 && FG[r] < 84.0)
	{
		return EG[r] = 2.5;
	}

	else if (FG[r] >= 79.0 && FG[r] < 82.0)
	{
		return EG[r] = 2.75;
	}

	else if (FG[r] >= 75.0 && FG[r] < 79.0)
	{
		return EG[r] = 3.0;
	}

	else if (FG[r] < 75.0)
	{
		return EG[r] = 5.0;
	}

	else
		return EG[r] = 0;
}

void computeEGcount(int EGcount[10], float sortedFG[x])
{
	for (int r = 0; r < x; r++)
	{
		if (sortedFG[10] >= 96.0 && sortedFG[r] <= 100.0)
		{
			EGcount[0]++;
		}

		else if (sortedFG[r] >= 94.0 && sortedFG[r] < 96.0)
		{
			EGcount[1]++;
		}

		else if (sortedFG[r] >= 92.0 && sortedFG[r] < 94.0)
		{
			EGcount[2]++;
		}

		else if (sortedFG[r] >= 89.0 && sortedFG[r] < 92.0)
		{
			EGcount[3]++;
		}

		else if (sortedFG[r] >= 87.0 && sortedFG[r] < 89.0)
		{
			EGcount[y]++;
		}

		else if (sortedFG[r] >= 84.0 && sortedFG[r] < 87.0)
		{
			EGcount[5]++;
		}

		else if (sortedFG[r] >= 82.0 && sortedFG[r] < 84.0)
		{
			EGcount[6]++;
		}

		else if (sortedFG[r] >= 79.0 && sortedFG[r] < 82.0)
		{
			EGcount[7]++;
		}

		else if (sortedFG[r] >= 75.0 && sortedFG[r] < 79.0)
		{
			EGcount[8]++;
		}

		else if (sortedFG[r] < 75.0)
		{
			EGcount[9]++;
		}
	}
}

void displaySorted(int EXAM[x][y], float FG[y], float EG[x])
{
	for (int r= 0; r < x; r++)
	{
		cout << setw(w) << r + 1 << setw(w);

		for (int c = 0; c < y; c++)
		{
			cout << EXAM[r][c] << setw(w);
		}
		cout << fixed << setprecision(2) << FG[r] << setw(w) << EG[r] << endl;
	}
}

void displayEXAM(int EXAM[x][y], float FG[y], float EG[x])
{
	for (int r = 0; r < x; r++)
	{
		cout << setw(w) << r + 1 << setw(w);

		for (int c = 0; c < y; c++)
		{
			cout << EXAM[r][c] << setw(w);
		}
		cout << fixed << setprecision(2) << FG[r] << setw(w) << EG[r] << endl;
	}
}

void swapper(int&array1, int&array2)
{
	float temp = array1;
	array1 = array2;
	array2 = temp;
}

void statswapper(float&array1, float&array2)
{
	float temp = array1;
	array1 = array2;
	array2 = temp;
}

void sortEXAM(int sortedEXAM[x][y])
{
	for (int c = 0; c < y; c++) //switch to the next column
	{
		for (int r = 0; r < x - 1; r++) //to compare numbers up to the number of arrays
		{
			for (int j = 0; j < x - r - 1; j++)
			{
				if (sortedEXAM[j][c] > sortedEXAM[j + 1][c])
					swapper(sortedEXAM[j][c], sortedEXAM[j + 1][c]);
			}
		}
	}
}

void sortSTAT(float sortedSTAT[x], int sizeofarray)
{
	for (int r = 0; r < sizeofarray - 1; r++) //to compare numbers up to the number of arrays
	{
		for (int j = 0; j < sizeofarray - r - 1; j++)
		{
			if (sortedSTAT[j] > sortedSTAT[j + 1])
				statswapper(sortedSTAT[j], sortedSTAT[j + 1]);
		}
	}

}

void computeMEAN(float mean[y], int sortedEXAM[x][y])
{
	for (int c = 0; c < y; c++)
	{
		for (int r = 0; r < x; r++)
		{
			mean[c] += sortedEXAM[r][c];
		}
		mean[c] /= x;
	}
}

void computeMEDIAN(float median[y], int sortedEXAM[x][y])
{
	if (x % 2 != 0)
	{
		for (int c = 0; c < y; c++)
		{
			median[c] = sortedEXAM[(x + 1) / 2][c];
		}
	}

	else
	{
		for (int c = 0; c < y; c++)
		{
			median[c] = (sortedEXAM[(x - 2) / 2][c] + sortedEXAM[x / 2][c]) / 2.0;
		}
	}
}

void computeMODE(int mode[y], int sortedEXAM[x][y], int sizeofarray)
{
	int modecount1;
	int modecount2;
	for (int c = 0; c < y; c++) //switch to the next column
	{
		modecount1 = 0;
		modecount2 = 1;
		for (int pass = 1; pass < sizeofarray; pass++) //to compare numbers up to the number of arrays
		{
			if (sortedEXAM[pass][c] == sortedEXAM[pass-1][c]) //adjacent numbers are the same then add to the count
				modecount2++;

			else //adjacent number is not the same, check
			{
				if (modecount2 > modecount1)
				{
					mode[c] = sortedEXAM[pass - 1][c];
					modecount1 = modecount2;
				}

				else if (modecount2 == modecount1)
				{
					mode[c] = 0;
				}

				modecount2 = 1;
			}
		}
	}
}

void computeSD(int sortedEXAM[x][y], float mean[y], float SD[y])
{
	for (int c = 0; c < y; c++)
	{
		for (int r = 0; r < x; r++)
		{
			SD[c] += pow(sortedEXAM[r][c] - mean[c], 2);
		}
		SD[c] = sqrt(SD[c] / x);	
	}
	
}

int main()
{
	char choice;
	do
	{
		//Initialization of all arrays and variables
		int EXAM[x][y], sortedEXAM[x][y], mode[y] = { 0 }, countMode[y] = { 0 }, EGcount[10] = { 0 };
		float FG[x] = { 0 }, sortedFG[x] = { 0 }, EG[x], sortedEG[x] = { 0 }, mean[y] = { 0 }, median[y] = { 0 }, SD[y] = { 0 }, meanFG = 0;

		srand(time(NULL)); //To generate a new set of random numbers

		cout << "**********************************************************************" << endl;
		cout << setw(w) << left << "Class Record" << endl << endl << setfill(' ');

		cout << setw(w) << left << "Student#" << setw(w) << "Exam 1" << setw(w) << "Exam 2" << setw(w) << "Exam 3" << setw(w) << "Exam 4" << setw(w) << "FG" << "EQ" << endl;

		for (int r = 0; r < x; r++)
		{
			for (int c = 0; c < y; c++)
			{
				getEXAM(r, c, EXAM);
				computeFG(r, c, FG, EXAM);
			}
		}

		for (int r = 0; r < x; r++)
		{
			for (int c = 0; c < y; c++)
			{
				computeEG(r, FG, EG);
			}
		}

		//Loop to copy all EXAM[x][y] to sortedEXAM[x][y]
		for (int r = 0; r < x; r++) 
		{
			for (int c = 0; c < y; c++)
			{
				sortedEXAM[r][c] = EXAM[r][c];
			}
		}

		//Loop to copy all FG[y] to sortedFG[y]
		for (int r = 0; r < x; r++)
		{
			sortedFG[r] = FG[r];
		}

		//Loop to copy all EG[y] to sortedEG[y]
		for (int r = 0; r < x; r++)
		{
			sortedEG[r] = EG[r];
		}

		cout << endl;

		sortEXAM(sortedEXAM);
		sortSTAT(sortedFG, x);
		sortSTAT(sortedEG, x);

		computeMEAN(mean, sortedEXAM);
		computeMEDIAN(median, sortedEXAM);
		computeMODE(mode, sortedEXAM, x);
		computeSD(sortedEXAM, mean, SD);

		displayEXAM(EXAM, FG, EG); //Function to display the Exam, Final Grade and Equivalent Grade

		/*
		//remove this comment to see the SORTED exam
		cout << "Sorted:" << endl;
		displaySorted(sortedEXAM, sortedFG, sortedEG);*/

		for (int r = 0; r < x; r++) //Get Mean of FG
		{
			meanFG += sortedFG[r];
		}

		meanFG /= x;

		cout << endl;

		cout << setw(w) << left << "Mean: "; //Display Mean of each Exam
		for (int c = 0; c < y; c++)
		{
			cout << setw(w) << mean[c];
		}
		cout << meanFG << endl; //Display mean of FG

		cout << setw(w) << left << "Median: "; //Display Median of each Exam
		for (int c = 0; c < y; c++)
		{
			cout << setw(w) << median[c];
		}

		cout << (sortedFG[(x - 2) / 2] + sortedFG[x / 2]) / 2.0 << endl; //Display Median of FG

		cout << setw(w) << left << "Modes: " << setw(w); //Display Modes of each Exam
		for (int c = 0; c < y; c++)
		{
			if (mode[c] != 0)
			{
				cout << setw(w) << mode[c];
			}

			else
			{
				cout << setw(w) << "NONE";
			}
		}

		cout << endl;

		cout << setw(w) << left << "SD: "; //Display Standard Deviation of each Exam
		for (int c = 0; c < y; c++)
		{
			cout << setw(w) << SD[c];
		}

		cout << endl << endl << endl;

		cout << setw(w) << left << "MAX: "; //Display Max of each Exam

		for (int c = 0; c < y; c++)
		{
			cout << setw(w) << sortedEXAM[x - 1][c];
		}

		cout << sortedFG[x - 1] << endl; //Display Max of FG

		cout << setw(w) << left << "MIN: "; //Display Min of each Exam
		for (int c = 0; c < y; c++)
		{
			cout << setw(w) << sortedEXAM[0][c];
		}

		cout << sortedFG[0] << endl << endl << endl; //Display Min of FG

		cout << "Table of Frequency - EQ" << endl; //Display Table of Frequency

		computeEGcount(EGcount, sortedFG);
	
		cout << "1.0 - " << EGcount[0] << endl;
		cout << "1.25 - " << EGcount[1] << endl;
		cout << "1.50 - " << EGcount[2] << endl;
		cout << "1.75 - " << EGcount[3] << endl;
		cout << "2.0 - " << EGcount[4] << endl;
		cout << "2.25 - " << EGcount[5] << endl;
		cout << "2.50 - " << EGcount[6] << endl;
		cout << "2.75 - " << EGcount[7] << endl;
		cout << "3.00 - " << EGcount[8] << endl;
		cout << "5.00 - " << EGcount[9] << endl;

		cout << endl;

		cout << "Do you want to repeat the program? Press y: "; cin >> choice; //User choice to repeat the program

		cout << endl;
	} while (choice == 'Y' || choice == 'y');

	_getch();
	return 0;
}


