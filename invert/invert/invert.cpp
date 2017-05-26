// OOP_Lab1_Part3.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "fstream"
#include "iostream"
#include "string"
#include <iomanip>  
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void DeterminantOriginalMatrix(float matrix[][3], bool & zeroDeterminant, float & determinant)
const int MATRIX_SIZE = 3;

struct Vector2i
{
	int x;
	int y;
};

typedef double Matrix[MATRIX_SIZE][MATRIX_SIZE];

bool ReadMatrixFromFile(Matrix(&sourceMatrix), const string &fileName)
{
	ifstream inputFile(fileName);
	if (inputFile)
	{
		for (size_t i = 0; i < MATRIX_SIZE; ++i)
		{
			for (size_t j = 0; j < MATRIX_SIZE; ++j)
			{
				inputFile >> sourceMatrix[i][j];
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

double FindDeterminantMatrix(Matrix(&sourceMatrix), bool &matrixDegenerate)
{
	float a, b, c;
	a = (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) * matrix[0][0];
	b = (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) * (-matrix[0][1]);
	c = (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]) * matrix[0][2];
	determinant = a + b + c;
	if (determinant == 0)
	double determinantSourceMatrix = ((sourceMatrix[0][0] * pow(-1, 1 + 1) * (sourceMatrix[1][1] * sourceMatrix[2][2] -
		sourceMatrix[2][1] * sourceMatrix[1][2])) +
		(sourceMatrix[1][0] * pow(-1, 2 + 1) * (sourceMatrix[0][1] * sourceMatrix[2][2] -
			sourceMatrix[2][1] * sourceMatrix[0][2])) +
			(sourceMatrix[2][0] * pow(-1, 3 + 1) * (sourceMatrix[0][1] * sourceMatrix[1][2] -
				sourceMatrix[1][1] * sourceMatrix[0][2])));
	if (determinantSourceMatrix == 0)
	{
		zeroDeterminant = true;
		matrixDegenerate = true;
	}
	return determinantSourceMatrix;
}

void TransposeOfTheOriginalMatrix(float matrix[][3], float transpoceMatrix[][3])
void TransposeMatrix(Matrix(&sourceMatrix), Matrix(&cofactorsMatrix))
{
	float buffer;
	for (int i = 0; i < 3; i++)
	for (size_t i = 0; i < MATRIX_SIZE; ++i)
	{
		for (int j = 0; j < 3; j++)
		for (size_t j = 0; j < MATRIX_SIZE; ++j)
		{
			buffer = matrix[i][j];
			transpoceMatrix[i][j] = matrix[j][i];
			transpoceMatrix[j][i] = buffer;
			sourceMatrix[j][i] = cofactorsMatrix[i][j];
		}
	}
}

void DeterminantOfTranspoceMatrix(float matrix[][3], float cofactorMatrix[][3])
void DeterminePositionsCellsMatrix(int &firstLine, int &firstColumn, int &secondLine, int &secondColumn, size_t i, size_t j)
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
	firstLine = (i == 0) ? 1 : 0;
	firstColumn = (j == 0) ? 1 : 0;

	if (i == 2)
	{
		secondLine = 1;
	}
	else if (i < 2)
	{
		secondLine = 2;
	}
	if (j == 2)
	{
		secondColumn = 1;
	}
	else if (j < 2)
	{
		secondColumn = 2;
	}
}

void InvertingMatrix(float matrix[][3], float determinant, float invertedMatrix[][3])


void CalculationMatrixCofactors(const Matrix(&sourceMatrix), Matrix(&cofactorsMatrix))
{
	for (int i = 0; i < 3; i++)
	for (size_t i = 0; i < MATRIX_SIZE; ++i)
	{
		for (int j = 0; j < 3; j++)
		for (size_t j = 0; j < MATRIX_SIZE; ++j)
		{
			invertedMatrix[i][j] = matrix[i][j] / determinant;
			Vector2i firstCell;
			Vector2i secondCell;
			DeterminePositionsCellsMatrix(firstCell.x, firstCell.y, secondCell.x, secondCell.y, i, j);
			double productFirstDiagonal = sourceMatrix[firstCell.x][firstCell.y] * sourceMatrix[secondCell.x][secondCell.y];
			DeterminePositionsCellsMatrix(secondCell.x, firstCell.y, firstCell.x, secondCell.y, i, j);
			double productSecondDiagonal = sourceMatrix[firstCell.x][firstCell.y] * sourceMatrix[secondCell.x][secondCell.y];
			cofactorsMatrix[i][j] = pow(-1, (i + 1) + (j + 1)) * (productFirstDiagonal - productSecondDiagonal);
		}
	}
}

void PrintMatrix(float invertedMatrix[][3])
void InvertMatrix(Matrix(&sourceMatrix), const double determinantSourceMatrix)
{
	for (int i = 0; i < 3; i++)
	for (size_t i = 0; i < MATRIX_SIZE; ++i)
	{
		for (int j = 0; j < 3; j++)
		for (size_t j = 0; j < MATRIX_SIZE; ++j)
		{
			cout << setprecision(3) << invertedMatrix[i][j] << '\t';
			sourceMatrix[i][j] = (1.0 / determinantSourceMatrix) * sourceMatrix[i][j];
		}
		cout << endl;
	}
}

void PrintHelp()
void FindInverseMatrix(Matrix(&sourceMatrix), bool &matrixDegenerate)
{
	cout << "Example: invert.exe matrix_file" << endl;
	double determinateSourceMatrix = FindDeterminantMatrix(sourceMatrix, matrixDegenerate);
	if (!matrixDegenerate)
	{
		Matrix cofactorsMatrix;
		CalculationMatrixCofactors(sourceMatrix, cofactorsMatrix);
		TransposeMatrix(sourceMatrix, cofactorsMatrix);
		InvertMatrix(sourceMatrix, determinateSourceMatrix);
	}
}

int main(int argc, char * argv[])


void OutputInConsole(const Matrix(&sourceMatrix), const bool &matrixDegenerate)
{
	if (argc < 2)
	if (matrixDegenerate)
	{
		PrintHelp();
		cout << "������� �������� �����������\n";
		return;
	}
	else if(argc > 2)

	for (size_t i = 0; i < MATRIX_SIZE; ++i)
	{
		cout << "Too many arguments" << endl;
		PrintHelp();
		for (size_t j = 0; j < MATRIX_SIZE; ++j)
		{
			cout << sourceMatrix[i][j] << " ";
		}
		if (i != MATRIX_SIZE - 1)
		{
			cout << "\n";
		}
	}
}

bool CheckNumberArguments(int argc)
{
	if (argc != 2)
	{
		std::cout << "Error! Usage invert.exe <matrixfile1>." << std::endl;
		return false;
	}
	else
	{
		string inputFileName = argv[1];
		ifstream inputFile(inputFileName);
		return true;
	}
}

		if (!inputFile.is_open())
void FillMatrix(const Matrix(&sourceMatrix))
{
	std::string outputFileName = "out.txt";
	ofstream outputFile;
	outputFile.open(outputFileName);
	for (size_t i = 0; i < MATRIX_SIZE; ++i)
	{
		for (size_t j = 0; j < MATRIX_SIZE; ++j)
		{
			cout << "Happened error with opening file" << endl;
			outputFile << sourceMatrix[i][j] << " ";
		}
		outputFile << "\n";
	}
}

enum STATUS_CODE { ALL_IS_OK = 0, PROGRAM_ERROR = 1, CANT_READ_FILE = 2 };

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "rus");
	bool matrixDegenerate = false;
	if (!CheckNumberArguments(argc))
	{
		return STATUS_CODE::PROGRAM_ERROR;
	}
	Matrix sourceMatrix;;
	string inputFileName = argv[1];
	if (ReadMatrixFromFile(sourceMatrix, inputFileName))
	{
		FindInverseMatrix(sourceMatrix, matrixDegenerate);
		OutputInConsole(sourceMatrix, matrixDegenerate);
		if (!matrixDegenerate)
		{
			return STATUS_CODE::ALL_IS_OK;
		}
		else
		{
			const int N = 3, M = 3;
			bool zeroDeterminant = false;
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
			std::cout << "��������� �� ���������." << std::endl;
			return STATUS_CODE::PROGRAM_ERROR;
		}
	}
    return 0;
	else
	{
		return STATUS_CODE::CANT_READ_FILE;
	}
}

