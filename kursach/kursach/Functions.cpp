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

void output(RichTextBox^ f, char *name, int **A, int n)
{
	f->Text = "";

	FILE *fi = freopen(name, "w", stdout);

	cout << n << endl;

	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			f->Text += Convert::ToString(A[i][j]) + "\t";
			cout << A[i][j] << "\t";
		}
		f->Text += "\n";
		cout << endl;
	}
	fclose(fi);
}

void output(RichTextBox^ f, char *name, double **A, int n)
{
	f->Text = "";

	FILE *fi = freopen(name, "w", stdout);

	cout << n << endl;

	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			f->Text += Convert::ToString(round(A[i][j]*1000)/1000.0) + "\t";
			cout << A[i][j] << "\t";
		}
		f->Text += "\n";
		cout << endl;
	}
	fclose(fi);
}

bool get(RichTextBox^ f, char *fileOut, double **A, int n)
{
	string a;

	MarshalString(f->Text, a);

	freopen(fileOut, "w", stdout);
	
	cout << n << endl;

	char *ch = new char[a.length()+1];
	strcpy(ch, a.c_str());

	puts(ch);

	freopen(fileOut, "r", stdin);

	int m;
	cin >> m;
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < n; j++)
		{
			string s;
			cin >> s;
			for (int i(0); i < s.size(); i++)
			{
				if ((s[i] != '-') && (s[i] != '.') && (s[i] != ' ') && (s[i] != '\n') && (s[i] != '\t') && (s[i] != '\0') && !isdigit(s[i]))
				{
					return false;
				}
			}
			A[i][j] = atof(s.c_str());
		}
	}
	return true;
}

void getFromFile(TextBox ^t, char *fileOut, double **A)
{

	freopen(fileOut, "r", stdin);

	int n;
	cin >> n;

	t->Text = "";
	t->Text += n;

	for (int i(0); i < n; i++)
	{

		for (int j(0); j < n; j++)
		{

			cin >> A[i][j];
		}
	}
}

void determin(RichTextBox^ f1, RichTextBox^ f, TextBox^ tB, char *file, double **A, int n, int &iteration)
{
	bool ch;

	int **P;
	double **L, **U;
	ch = get(f, file, A, n);
	
	if (ch == false)
	{
		f1->Text = "ERROR";
		tB->Text = "Вироджена";
		return;
	}
	
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

	int oper = 0;

	LUP(f1, A, P, L, U, n, iteration, oper);

	double det = 1;

	for (int i(0); i < n; i++)
	{
		det *= U[i][i];
	}
	
	if (det == 0) tB->Text = "Вироджена";
	else tB->Text = "Не вироджена";
}