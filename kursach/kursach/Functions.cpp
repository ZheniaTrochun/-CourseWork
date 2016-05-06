#include "Functions.h"
#include <string>
#include <iostream>

#pragma warning(disable : 4996)


void MarshalString(String ^ s, string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

void gen(double **A, int n)
{
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			A[i][j] = rand() % 41 - 20;
		}
	}
}

bool LU(RichTextBox^ f, double **A, double **L, double **U, int n)
{
	int s;



	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			L[i][j] = 0;
			U[i][j] = 0;
			if (i == j) L[i][j] = 1;
		}
	}

	for (int i(0); i < n; i++)
	{
		U[0][i] = A[0][i];
	}

	for (int i(1); i < n; i++)
	{
		L[i][0] = A[i][0] / U[0][0];
	}

	for (int i(1); i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			s = 0;
			for (int k(0); k <= (i - 1); k++)
			{
				s += L[i][k] * U[k][j];
			}
			U[i][j] = A[i][j] - s;
		}
		for (int j = i + 1; j < n; j++)
		{
			s = 0;
			for (int k(0); k <= (i - 1); k++)
			{
				s += L[j][k] * U[k][i];
			}
			L[j][i] = (A[j][i] - s) / U[i][i];
		}
	}
	for (int i(0); i < n; i++)
	{
		if (U[i][i] == 0)
		{
			f->Text = "\tERROR!!!\n\tDiv by 0!!!";
			return false;
		}
	}
	return true;
}

void output(RichTextBox^ f, int **A, int n)
{
	f->Text = "";

	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			f->Text += Convert::ToString(A[i][j]) + "\t";
		}
		f->Text += "\n";
	}
}

void output(RichTextBox^ f, double **A, int n)
{
	f->Text = "";

	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			f->Text += Convert::ToString(A[i][j]) + "\t";
		}
		f->Text += "\n";
	}
}

void swap(double **A, int **B, int x, int y, int n)
{
	double temp;
	int temp1;
	for (int i(0); i < n; i++)
	{
		temp = A[x][i];
		A[x][i] = A[y][i];
		A[y][i] = temp;
		temp1 = B[x][i];
		B[x][i] = B[y][i];
		B[y][i] = temp1;
	}

}

void multmatr(double **L, double **U, int **A2, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			A2[i][j] = 0;
			for (int k = 0; k < n; k++)
				A2[i][j] += L[i][k] * U[k][j];
		}
}

void multmatr(int **L, int **U, int **A2, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			A2[i][j] = 0;
			for (int k = 0; k < n; k++)
				A2[i][j] += L[i][k] * U[k][j];
		}
}

void multmatr(double **L, int **U, double **A2, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			A2[i][j] = 0;
			for (int k = 0; k < n; k++)
				A2[i][j] += L[i][k] * U[k][j];
		}
}

void matrP(double **A, int **P, int n)
{
	for (int j(0); j < n; j++)
	{
		for (int i = j; i < n; i++)
		{
			if (A[i][j] > A[j][j]) swap(A, P, j, i, n);
		}
	}
}


void LUP(RichTextBox^ f, double **A, int**P, double **L, double **U, int n)
{
	matrP(A, P, n);
	LU(f, A, L, U, n);
	int **A2 = new int *[n];
	for (int i(0); i < n; i++)
	{
		A2[i] = new int[n];
	}
	int **D = new int *[n];
	for (int i(0); i < n; i++)
	{
		D[i] = new int[n];
	}

	multmatr(L, U, D, n);
	multmatr(P, D, A2, n);
}

void revMat(double **L, double **U, double **R, int n)
{
	double s;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			s = 0;
			if (i == j)
			{
				for (int k = j + 1; k < n; k++)
				{
					s += U[j][k] * R[k][j];
				}
				R[i][j] = (1 - s) / U[i][j];
			}
			if (i < j)
			{
				for (int k = i + 1; k < n; k++)
				{
					s += U[i][k] * R[k][j];
				}
				R[i][j] = (-1)*(s / U[i][i]);
			}
			if (i > j)
			{
				for (int k = j + 1; k < n; k++)
				{
					s += L[k][j] * R[i][k];
				}
				R[i][j] = (-1)*s;
			}
		}
	}
}

bool obraml(RichTextBox^ f, double **A, double **R, int n)
{
	double a;
	double *u, *v, *r, *q;
	double s;
	double **b;
	double *m = new double[n - 1];
	u = new double[n - 1];
	v = new double[n - 1];
	r = new double[n - 1];
	q = new double[n - 1];
	b = new double*[n - 1];
	for (int i(0); i < n - 1; i++)
		b[i] = new double[n - 1];

	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			R[i][j] = 0;
		}
	}


	for (int i(0); i < n; i++)
	{
		for (int j(0); j < i; j++)
		{
			v[j] = A[i][j];
			u[j] = A[j][i];
		}
		if (i > 0)
		{
			a = mult1(v, u, R, A, i);
		}
		else a = A[0][0];
		if (a == 0)
		{
			f->Text = "\tERROR!!!\n\tDiv by 0!!!";
			return false;
		}
		for (int j(0); j < i; j++)
		{
			s = 0;
			for (int k(0); k < i; k++)
			{
				s += R[j][k] * u[k];
			}


			r[j] = ((-1)*s) / a;
		}


		for (int j(0); j < i; j++)
		{
			s = 0;
			for (int k(0); k < i; k++)
			{
				s += v[k] * R[k][j];
			}
			q[j] = ((-1)*s) / a;
		}

		for (int j(0); j < i; j++)
		{
			s = 0;
			for (int k(0); k < i; k++)
			{
				s += R[j][k] * u[k];
			}
			m[j] = s;
		}

		for (int j(0); j < i; j++)
		{
			for (int k(0); k < i; k++)
			{
				b[j][k] = m[j] * q[k];
			}
		}

		for (int j(0); j < i; j++)
		{
			for (int k(0); k < i; k++)
			{
				R[j][k] = R[j][k] - b[j][k];
			}
		}
		for (int j(0); j < i; j++)
		{
			R[i][j] = q[j];
			R[j][i] = r[j];
		}
		R[i][i] = 1 / a;
	}
	return true;
}

double mult1(double *v, double *u, double **A, double **B, int k)
{
	double a = 0, s;
	double *m = new double[k];
	for (int i(0); i < k; i++)
	{
		s = 0;
		for (int j(0); j < k; j++)
		{
			s += v[j] * A[j][i];
		}
		m[i] = s;
	}
	s = 0;
	for (int i(0); i < k; i++)
	{
		s += m[i] * u[i];
	}

	a = B[k][k] - s;
	return a;
}

void get(RichTextBox^ f, char *fileOut, double **A, int n)
{
	string a;

	MarshalString(f->Text, a);

	freopen(fileOut, "w", stdout);

	char *ch = new char[a.length()+1];
	strcpy(ch, a.c_str());

	puts(ch);

	freopen(fileOut, "r", stdin);

	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			cin >> A[i][j];
		}
	}
	
}

void getFromFile(char *fileOut, double **A, int n)
{

	freopen(fileOut, "r", stdin);

	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			cin >> A[i][j];
		}
	}
}

void determin(RichTextBox^ f1, RichTextBox^ f, TextBox^ tB, char *file, double **A, int n)
{
	int **P;
	double **L, **U;
	get(f, file, A, n);

	L = new double*[n];

	for (int i = 0; i < n; i++)
	{
		L[i] = new double[n];
	}

	U = new double*[n];

	for (int i = 0; i < n; i++)
	{
		U[i] = new double[n];
	}


	P = new int*[n];

	for (int i = 0; i < n; i++)
	{
		P[i] = new int[n];
	}
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			P[i][j] = 0;
		}
	}
	for (int i(0); i < n; i++)
	{
		P[i][i] = 1;
	}

	LUP(f1, A, P, L, U, n);

	double det = 1;

	for (int i(0); i < n; i++)
	{
		det *= U[i][i];
	}

	
	if (det == 0) tB->Text = "Вироджена";
	else tB->Text = "Не вироджена";

	
}