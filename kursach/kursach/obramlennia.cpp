#include "obramlennia.h"

bool obraml(RichTextBox^ f, double **A, double **R, int n, int &iteration, int &oper)
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
	{
		iteration++;
		b[i] = new double[n - 1];
	}

	for (int i(0); i < n; i++)
	{
		iteration++;
		for (int j(0); j < n; j++)
		{
			iteration++;
			R[i][j] = 0;
		}
	}


	for (int i(0); i < n; i++)
	{
		iteration++;
		for (int j(0); j < i; j++)
		{
			iteration++;
			v[j] = A[i][j];
			u[j] = A[j][i];
		}
		if (i > 0)
		{
			a = mult1(v, u, R, A, i, iteration, oper);
		}
		else a = A[0][0];
		if (a == 0)
		{
			f->Text = "\tERROR!!!\n\tDiv by 0!!!";
			return false;
		}
		for (int j(0); j < i; j++)
		{
			iteration++;
			s = 0;
			for (int k(0); k < i; k++)
			{
				iteration++;
				s += R[j][k] * u[k];
				oper += 2;
			}


			r[j] = ((-1)*s) / a;
			oper += 2;
		}


		for (int j(0); j < i; j++)
		{
			iteration++;
			s = 0;
			for (int k(0); k < i; k++)
			{
				iteration++;
				s += v[k] * R[k][j];
				oper += 2;
			}
			q[j] = ((-1)*s) / a;
			oper += 2;
		}

		for (int j(0); j < i; j++)
		{
			iteration++;
			s = 0;
			for (int k(0); k < i; k++)
			{
				iteration++;
				s += R[j][k] * u[k];
				oper += 2;
			}
			m[j] = s;
		}

		for (int j(0); j < i; j++)
		{
			iteration++;
			for (int k(0); k < i; k++)
			{
				iteration++;
				b[j][k] = m[j] * q[k];
				oper++;
			}
		}

		for (int j(0); j < i; j++)
		{
			iteration++;
			for (int k(0); k < i; k++)
			{
				iteration++;
				R[j][k] = R[j][k] - b[j][k];
				oper++;
			}
		}
		for (int j(0); j < i; j++)
		{
			iteration++;
			R[i][j] = q[j];
			R[j][i] = r[j];
		}
		R[i][i] = 1 / a;
		oper++;
	}
	return true;
}

double mult1(double *v, double *u, double **A, double **B, int k, int &iteration, int &oper)
{
	double a = 0, s;
	double *m = new double[k];
	for (int i(0); i < k; i++)
	{
		iteration++;
		s = 0;
		for (int j(0); j < k; j++)
		{
			iteration++;
			s += v[j] * A[j][i];
			oper += 2;
		}
		m[i] = s;
	}
	s = 0;
	for (int i(0); i < k; i++)
	{
		iteration++;
		s += m[i] * u[i];
		oper += 2;
	}

	a = B[k][k] - s;
	oper++;
	return a;
}