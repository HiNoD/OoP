#include "stdafx.h"
#include "fstream"
#include "iostream"
#include "string"
#include <iomanip>  

using namespace std;

void DeterminantOriginalMatrix(float matrix[][3], bool & zeroDeterminant, float & determinant)
{
	float a, b, c;
	a = (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) * matrix[0][0];
	b = (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) * (-matrix[0][1]);
	c = (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]) * matrix[0][2];
	determinant = a + b + c;
	if (determinant == 0)
	{
		zeroDeterminant = true;
	}
}

void TransposeOfTheOriginalMatrix(float matrix[][3], float transpoceMatrix[][3])
{
	float buffer;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			buffer = matrix[i][j];
			transpoceMatrix[i][j] = matrix[j][i];
			transpoceMatrix[j][i] = buffer;
		}
	}
}

void DeterminantOfTranspoceMatrix(float matrix[][3], float cofactorMatrix[][3])
{
	cofactorMatrix[0][0] = matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1];
	cofactorMatrix[0][1] = -(matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]);
	cofactorMatrix[0][2] = matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0];
	cofactorMatrix[1][0] = -(matrix[0][1] * matrix[2][2] - matrix[0][2] * matrix[2][1]);
	cofactorMatrix[1][1] = matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0];
	cofactorMatrix[1][2] = -(matrix[0][0] * matrix[2][1] - matrix[0][1] * matrix[2][0]);
	cofactorMatrix[2][0] = matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1];
	cofactorMatrix[2][1] = -(matrix[0][0] * matrix[1][2] - matrix[0][2] * matrix[1][0]);
	cofactorMatrix[2][2] = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

void InvertingMatrix(float matrix[][3], float determinant, float invertedMatrix[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			invertedMatrix[i][j] = matrix[i][j] / determinant;
		}
	}
}

void PrintMatrix(float invertedMatrix[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << setprecision(3) << invertedMatrix[i][j] << '\t';
		}
		cout << endl;
	}
}

void OperatingRoom(char *argv[])
{
	string inputFileName = argv[1];
	ifstream inputFile(inputFileName);

	if (!inputFile.is_open())
	{
		cout << "Happened error with opening file" << endl;
	}
	else
	{
		const int N = 3, M = 3;
		bool zeroDeterminant= false;
		float originalMatrix[N][M], transpoceMatrix[N][M], invertedMatrix[N][M], cofactorMatrix[N][M], determinant = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				inputFile >> originalMatrix[i][j];
			}
		}
		DeterminantOriginalMatrix(originalMatrix, zeroDeterminant, determinant);
		if (!zeroDeterminant)
		{
			TransposeOfTheOriginalMatrix(originalMatrix, transpoceMatrix);
			DeterminantOfTranspoceMatrix(transpoceMatrix, cofactorMatrix);
			InvertingMatrix(cofactorMatrix, determinant, invertedMatrix);
			PrintMatrix(invertedMatrix);
		}
		else
		{
			cout << "This matrix does not have an inverted matrix" << endl;
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				originalMatrix[i][j] = 0;
				transpoceMatrix[i][j] = 0;
				invertedMatrix[i][j] = 0;
				cofactorMatrix[i][j] = 0;
			}
		}
		inputFile.close();
	}
}

void PrintHelp()
{
	cout << "Example: invert.exe matrix_file" << endl;
}

int main(int argc, char * argv[])
{
	if (argc < 2)
	{
		PrintHelp();
	}
	else if(argc > 2)
	{
		cout << "Too many arguments" << endl;
		PrintHelp();
	}
	else
	{
		OperatingRoom(argv);
	}
    return 0;
}

