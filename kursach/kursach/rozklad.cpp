#include "rozklad.h"

void matrP(double **A, int **P, int n, int &iteration, int &oper)
{
	for (int j(0); j < n; j++)
	{
		iteration++;
		for (int i = j; i < n; i++)
		{
			iteration++;
			if (A[i][j] > A[j][j]) swap(A, P, j, i, n, iteration, oper);
		}
	}
}

void LUP(RichTextBox^ f, double **A, int**P, double **L, double **U, int n, int &iteration, int &oper)
{
	matrP(A, P, n, iteration, oper);
	LU(f, A, L, U, n, iteration, oper);
	int **A2 = new int *[n];
	for (int i(0); i < n; i++)
	{
		iteration++;
		A2[i] = new int[n];
	}
	int **D = new int *[n];
	for (int i(0); i < n; i++)
	{
		iteration++;
		D[i] = new int[n];
	}

	multmatr(L, U, D, n, iteration, oper);
	multmatr(P, D, A2, n, iteration, oper);
}

void revMat(double **L, double **U, double **R, int n, int &iteration, int &oper)
{
	double s;
	for (int i = n - 1; i >= 0; i--)
	{
		iteration++;
		for (int j = n - 1; j >= 0; j--)
		{
			iteration++;
			s = 0;
			if (i == j)
			{
				for (int k = j + 1; k < n; k++)
				{
					iteration++;
					s += U[j][k] * R[k][j];
					oper += 2;
				}
				R[i][j] = (1 - s) / U[i][j];
				oper += 2;
			}
			if (i < j)
			{
				for (int k = i + 1; k < n; k++)
				{
					iteration++;
					s += U[i][k] * R[k][j];
					oper += 2;
				}
				R[i][j] = (-1)*(s / U[i][i]);
				oper += 2;
			}
			if (i > j)
			{
				for (int k = j + 1; k < n; k++)
				{
					iteration++;
					s += L[k][j] * R[i][k];
					oper += 2;
				}
				R[i][j] = (-1)*s;
				oper++;
			}
		}
	}
}


void swap(double **A, int **B, int x, int y, int n, int &iteration, int &oper)
{
	double temp;
	int temp1;
	for (int i(0); i < n; i++)
	{
		iteration++;
		temp = A[x][i];
		A[x][i] = A[y][i];
		A[y][i] = temp;
		temp1 = B[x][i];
		B[x][i] = B[y][i];
		B[y][i] = temp1;
	}

}

void multmatr(double **L, double **U, int **A2, int n, int &iteration, int &oper)
{
	for (int i = 0; i < n; i++)
	{
		iteration++;
		for (int j = 0; j < n; j++)
		{
			iteration++;
			A2[i][j] = 0;
			for (int k = 0; k < n; k++)
			{
				iteration++;
				A2[i][j] += L[i][k] * U[k][j];
				oper += 2;
			}
		}
	}
}

void multmatr(int **L, int **U, int **A2, int n, int &iteration, int &oper)
{
	for (int i = 0; i < n; i++)
	{
		iteration++;
		for (int j = 0; j < n; j++)
		{
			iteration++;
			A2[i][j] = 0;
			for (int k = 0; k < n; k++)
			{
				iteration++;
				A2[i][j] += L[i][k] * U[k][j];
				oper += 2;
			}
		}
	}
}

void multmatr(double **L, int **U, double **A2, int n, int &iteration, int &oper)
{
	for (int i = 0; i < n; i++)
	{
		iteration++;
		for (int j = 0; j < n; j++)
		{
			iteration++;
			A2[i][j] = 0;
			for (int k = 0; k < n; k++)
			{
				iteration++;
				A2[i][j] += L[i][k] * U[k][j];
				oper += 2;
			}
		}
	}
}


bool LU(RichTextBox^ f, double **A, double **L, double **U, int n, int &iteration, int &oper)
{
	int s;

	for (int i(0); i < n; i++)
	{
		iteration++;
		for (int j(0); j < n; j++)
		{
			iteration++;
			L[i][j] = 0;
			U[i][j] = 0;
			if (i == j) L[i][j] = 1;
		}
	}

	for (int i(0); i < n; i++)
	{
		iteration++;
		U[0][i] = A[0][i];
	}

	for (int i(1); i < n; i++)
	{
		iteration++;
		L[i][0] = A[i][0] / U[0][0];
		oper++;
	}

	for (int i(1); i < n; i++)
	{
		iteration++;
		for (int j = i; j < n; j++)
		{
			iteration++;
			s = 0;
			for (int k(0); k <= (i - 1); k++)
			{
				iteration++;
				s += L[i][k] * U[k][j];
				oper += 2;
			}
			U[i][j] = A[i][j] - s;
			oper++;
		}
		for (int j = i + 1; j < n; j++)
		{
			iteration++;
			s = 0;
			for (int k(0); k <= (i - 1); k++)
			{
				iteration++;
				s += L[j][k] * U[k][i];
				oper += 2;
			}
			L[j][i] = (A[j][i] - s) / U[i][i];
			oper += 2;
		}
	}
	for (int i(0); i < n; i++)
	{
		iteration++;
		if (U[i][i] == 0)
		{
			f->Text = "\tERROR!!!\n\tDiv by 0!!!";
			return false;
		}
	}
	return true;
}