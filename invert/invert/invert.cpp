#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Vector2i
{
	int x;
	int y;
};

const int MATRIX_SIZE = 3;

void PrintInvertedMatrix(vector<vector<double>> &invertedMatrix)
{
	cout << "Invert" << endl;
	for (size_t i = 0; i < MATRIX_SIZE; ++i)
	{
		for (size_t j = 0; j < MATRIX_SIZE; ++j)
		{
			cout << setprecision(3) << invertedMatrix[i][j] << " ";
		}
		cout << endl;
	}
}

void InvertingMatrix(vector<vector<double>> &cofactorMatrix, const double &determinant, vector<vector<double>> &invertedMatrix)
{
	for (size_t i = 0; i < MATRIX_SIZE; ++i)
	{
		for (size_t j = 0; j < MATRIX_SIZE; ++j)
		{
			invertedMatrix[i][j] = cofactorMatrix[i][j] / determinant;
		}
	}
}

void DeterminePositionsCellsMatrix(int &firstLine, int &firstColumn, int &secondLine, int &secondColumn, size_t i, size_t j)
{
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

void DeterminantOfTranspoceMatrix(vector<vector<double>> &transpoceMatrix, vector<vector<double>> &cofactorMatrix)
{
	for (size_t i = 0; i < MATRIX_SIZE; ++i)
	{
		for (size_t j = 0; j < MATRIX_SIZE; ++j)
		{
			Vector2i firstCell;
			Vector2i secondCell;
			DeterminePositionsCellsMatrix(firstCell.x, firstCell.y, secondCell.x, secondCell.y, i, j);
			double productFirstDiagonal = transpoceMatrix[firstCell.x][firstCell.y] * transpoceMatrix[secondCell.x][secondCell.y];
			DeterminePositionsCellsMatrix(secondCell.x, firstCell.y, firstCell.x, secondCell.y, i, j);
			double productSecondDiagonal = transpoceMatrix[firstCell.x][firstCell.y] * transpoceMatrix[secondCell.x][secondCell.y];
			cofactorMatrix[i][j] = pow(-1, (i + 1) + (j + 1)) * (productFirstDiagonal - productSecondDiagonal);
		}
	}
}

void MatrixTransposition(vector<vector<double>> &matrix, vector<vector<double>> &transpoceMatrix)
{
	cout << "Trans" << endl;
	for (size_t i = 0; i < MATRIX_SIZE; ++i)
	{
		for (size_t j = 0; j < MATRIX_SIZE; ++j)
		{
			transpoceMatrix[i][j] = matrix[j][i];
			cout << transpoceMatrix[i][j] << " ";
		}
		cout << endl;
	}
}

bool IsDeterminantZero(const double determinant)
{
	if (determinant == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

double DeterminantOfMatrix(const vector<vector<double>> matrix)
{
	double determinant, a, b, c;
	a = (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) * matrix[0][0];
	b = (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) * (-matrix[0][1]);
	c = (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]) * matrix[0][2];
	determinant = a + b + c;
	cout << "Determinant:" << determinant << endl;
	return determinant;
}

void CopyingMatrixFromFile(ifstream &inputFile)
{
	double buffer;
	vector<vector<double>> matrix(MATRIX_SIZE, vector<double>(MATRIX_SIZE));
	vector<vector<double>> transpoceMatrix(MATRIX_SIZE, vector<double>(MATRIX_SIZE));
	vector<vector<double>> cofactorMatrix(MATRIX_SIZE, vector<double>(MATRIX_SIZE));
	vector<vector<double>> invertedMatrix(MATRIX_SIZE, vector<double>(MATRIX_SIZE));
	cout << "Original:" << endl;
	for (size_t i = 0; i < MATRIX_SIZE; ++i)
	{
		for (size_t j = 0; j < MATRIX_SIZE; ++j)
		{
			inputFile >> buffer;
			matrix[i][j] = buffer;
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	inputFile.close();
	if (!IsDeterminantZero(DeterminantOfMatrix(matrix)))
	{
		MatrixTransposition(matrix, transpoceMatrix);
		DeterminantOfTranspoceMatrix(transpoceMatrix, cofactorMatrix);
		InvertingMatrix(cofactorMatrix, DeterminantOfMatrix(matrix), invertedMatrix);
		PrintInvertedMatrix(invertedMatrix);
	}
}

void WorkWithFile(const string &nameFile)
{
	ifstream inputFile(nameFile);
	if (!inputFile.is_open())
	{
		cout << "Happend error with file" << endl;
	}
	else
	{
		CopyingMatrixFromFile(inputFile);
	}
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << "Example: invert.exe matrix.txt" << endl;
	}
	else 
	{
		string nameFile = argv[1];
		WorkWithFile(nameFile);
		
	}
	return 0;
}
