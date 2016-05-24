
#include "Functions.h"
#include "rozklad.h"
#include "obramlennia.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <time.h>

#pragma warning(disable : 4996)

namespace kursach {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	int iteration = 0;
	int operations = 0;

	int **P;
	double **A, **L, **U, **Arev, **Arev1;
	int n = 0;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(25, 43);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 43);
			this->button1->TabIndex = 0;
			this->button1->Text = L"LU";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(25, 106);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(120, 44);
			this->button2->TabIndex = 1;
			this->button2->Text = L"LUP";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(25, 167);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(121, 46);
			this->button3->TabIndex = 2;
			this->button3->Text = L"����������";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->Location = System::Drawing::Point(13, 229);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(148, 20);
			this->textBox1->TabIndex = 3;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(13, 323);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(66, 25);
			this->button4->TabIndex = 4;
			this->button4->Text = L"�����������";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(227, 43);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(254, 146);
			this->richTextBox1->TabIndex = 5;
			this->richTextBox1->Text = L"";
			this->richTextBox1->WordWrap = false;
			// 
			// richTextBox2
			// 
			this->richTextBox2->BackColor = System::Drawing::Color::White;
			this->richTextBox2->Location = System::Drawing::Point(227, 229);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->Size = System::Drawing::Size(254, 146);
			this->richTextBox2->TabIndex = 6;
			this->richTextBox2->Text = L"";
			this->richTextBox2->WordWrap = false;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(96, 323);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(65, 25);
			this->button5->TabIndex = 7;
			this->button5->Text = L"³������";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::Window;
			this->textBox2->Location = System::Drawing::Point(12, 297);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(148, 20);
			this->textBox2->TabIndex = 8;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(53, 354);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(64, 21);
			this->button6->TabIndex = 9;
			this->button6->Text = L"������";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(40, 255);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(92, 26);
			this->button7->TabIndex = 10;
			this->button7->Text = L"��������";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(563, 414);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

		string s;

		MarshalString(textBox2->Text, s);

		for (int i(0); i < s.size(); i++)
		{
			if (!isdigit(s[i]))
			{
				richTextBox2->Text = "ERROR";
				return;
			}
		}

		if ((textBox2->Text == "") || (Convert::ToInt32(textBox2->Text) <= 0))
		{
			richTextBox2->Text = "ERROR";
			return;
		}

		n = Convert::ToInt32(textBox2->Text);

		determin(richTextBox2, richTextBox1, textBox1, "file.txt", A, n, iteration);

		if (textBox1->Text == "���������")
		{
			richTextBox2->Text = "\tERROR!!!\n\tDet = 0!!!";
			return;
		}

		bool ch = get(richTextBox1, "file.txt", A, n);

		if (!ch)
		{
			richTextBox2->Text = "ERROR";
			return;
		}

		Arev = new double*[n];

		for (int i = 0; i < n; i++)
		{
			Arev[i] = new double[n];
		}
		bool check;

		iteration = 0;
		operations = 0;
		double t1 = clock();
		
		check = obraml(richTextBox2, A, Arev, n, iteration, operations);
		
		double t2 = clock();

		if (!(check))
		{
			richTextBox2->Text = "\tERROR!!!\n\tDiv by 0!!!";
			return;
		}

		char *name = "����������.txt";

		output(richTextBox2, name, Arev, n);
		
		FILE *f = freopen(name, "a", stdout);
		
		richTextBox2->Text += "\nʳ������ �������� = " + iteration + "\n";
		cout << "\nʳ������ �������� = " << iteration << "\n";
		richTextBox2->Text += "\nʳ������ ������������ �������� = " + operations + "\n";
		cout << "\nʳ������ ������������ �������� = " << operations << "\n";
		richTextBox2->Text += "\n��� ������ = " + (double)(t2 - t1) / CLOCKS_PER_SEC + "\n";
		cout << "\n��� ������ = " << (double)(t2 - t1) / CLOCKS_PER_SEC << "\n";
		fclose(f);

	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		/*
		string s;

		MarshalString(textBox2->Text, s);

		for (int i(0); i < s.size(); i++)
		{
			if (!isdigit(s[i]))
			{
				richTextBox2->Text = "ERROR";
				return;
			}
		}

		if ((textBox2->Text == "") || (Convert::ToInt32(textBox2->Text) <= 0))
		{
			richTextBox2->Text = "ERROR";
			return;
		}

		n = Convert::ToInt32(textBox2->Text);
		*/
		FILE *f = freopen("file.txt", "r", stdin);

		int n;
		cin >> n;
		fclose(f);
		textBox2->Text = "";
		textBox2->Text += n;

		A = new double*[n];

		for (int i = 0; i < n; i++)
		{
			A[i] = new double[n];
		}
	
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				A[i][j] = 0;
			}
		}
		
		getFromFile(textBox2, "file.txt", A);

		output(richTextBox1, "file.txt", A, n);
		determin(richTextBox2, richTextBox1, textBox1, "file.txt", A, n, iteration);
	}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

	srand(time(NULL));

	string s;

	MarshalString(textBox2->Text, s);

	for (int i(0); i < s.size(); i++)
	{
		if (!isdigit(s[i]))
		{
			richTextBox2->Text = "ERROR";
			return;
		}
	}

	if ((textBox2->Text == "") || (Convert::ToInt32(textBox2->Text) <= 0))
	{
		richTextBox2->Text = "ERROR";
		return;
	}
	n = Convert::ToInt32(textBox2->Text);

	A = new double*[n];

	for (int i = 0; i < n; i++)
	{
		A[i] = new double[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = 0;
		}
	}

	gen(A, n);

	output(richTextBox1, "file.txt", A, n);
	determin(richTextBox2, richTextBox1, textBox1, "file.txt", A, n, iteration);
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	
	string s;

	MarshalString(textBox2->Text, s);

	for (int i(0); i < s.size(); i++)
	{
		if (!isdigit(s[i]))
		{
			richTextBox2->Text = "ERROR";
			return;
		}
	}

	if ((textBox2->Text == "") || (Convert::ToInt32(textBox2->Text) <= 0))
	{
		richTextBox2->Text = "ERROR";
		return;
	}

	n = Convert::ToInt32(textBox2->Text);


	A = new double*[n];

	for (int i = 0; i < n; i++)
	{
		A[i] = new double[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = 0;
		}
	}

	bool ch = get(richTextBox1, "file.txt", A, n);

	if (!ch)
	{
		richTextBox2->Text = "ERROR";
		return;
	}

	determin(richTextBox2, richTextBox1, textBox1, "file.txt", A, n, iteration);
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	string s;

	MarshalString(textBox2->Text, s);

	for (int i(0); i < s.size(); i++)
	{
		if (!isdigit(s[i]))
		{
			richTextBox2->Text = "ERROR";
			return;
		}
	}

	if ((textBox2->Text == "") || (Convert::ToInt32(textBox2->Text) <= 0))
	{
		richTextBox2->Text = "ERROR";
		return;
	}

	n = Convert::ToInt32(textBox2->Text);


	if (n == 0) richTextBox2->Text = "ERROR";
	else
	{
		

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


		Arev = new double*[n];

		for (int i = 0; i < n; i++)
		{
			Arev[i] = new double[n];
		}

		determin(richTextBox2, richTextBox1, textBox1, "file.txt", A, n, iteration);
		

		if (textBox1->Text == "���������")
		{
			richTextBox2->Text = "\tERROR!!!\n\tDet = 0!!!";
			return;
		}
		bool ch = get(richTextBox1, "file.txt", A, n);
		
		if (!ch)
		{
			richTextBox2->Text = "ERROR";
			return;
		}

		bool check;

		iteration = 0;
		operations = 0;
		double t1 = clock();

		check = LU(richTextBox2, A, L, U, n, iteration, operations);

		if (!(check))
		{
			richTextBox2->Text = "\tERROR!!!\n\tDiv by 0!!!";
			return;
		}

		revMat(L, U, Arev, n, iteration, operations);
		
		double t2 = clock();
		
		char *name = "LU.txt";

		output(richTextBox2, name, Arev, n);
		
		FILE *f = freopen(name, "a", stdout);
		
		richTextBox2->Text += "\nʳ������ �������� = " + iteration + "\n";
		cout << "\nʳ������ �������� = " << iteration << "\n";
		richTextBox2->Text += "\nʳ������ ������������ �������� = " + operations + "\n";
		cout << "\nʳ������ ������������ �������� = " << operations << "\n";
		richTextBox2->Text += "\n��� ������ = " + (double)(t2 - t1) / CLOCKS_PER_SEC + "\n";
		cout << "\n��� ������ = " << (double)(t2 - t1) / CLOCKS_PER_SEC << "\n";
		fclose(f);
	}
	
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	string s;

	MarshalString(textBox2->Text, s);

	for (int i(0); i < s.size(); i++)
	{
		if (!isdigit(s[i]))
		{
			richTextBox2->Text = "ERROR";
			return;
		}
	}

	if ((textBox2->Text == "") || (Convert::ToInt32(textBox2->Text) <= 0)) 
	{
		richTextBox2->Text = "ERROR";
		return;
	}

	n = Convert::ToInt32(textBox2->Text);

	bool ch = get(richTextBox1, "file.txt", A, n);

	if (!ch)
	{
		richTextBox2->Text = "ERROR";
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


	Arev = new double*[n];

	for (int i = 0; i < n; i++)
	{
		Arev[i] = new double[n];
	}

	Arev1 = new double*[n];

	for (int i = 0; i < n; i++)
	{
		Arev1[i] = new double[n];
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

	iteration = 0;
	operations = 0;
	double t1 = clock();

	LUP(richTextBox2, A, P, L, U, n, iteration, operations);

	if (textBox1->Text == "���������")
	{
		richTextBox2->Text = "\tERROR!!!\n\tDet = 0!!!";
		return;
	}

	revMat(L, U, Arev, n, iteration, operations);

	multmatr(Arev, P, Arev1, n, iteration, operations);
	double t2 = clock();

	char *name = "LUP.txt";

	output(richTextBox2, name, Arev1, n);
	FILE *f = freopen(name, "a", stdout);
	richTextBox2->Text += "\nʳ������ �������� = " + iteration + "\n";
	cout << "\nʳ������ �������� = " << iteration << "\n";
	richTextBox2->Text += "\nʳ������ ������������ �������� = " + operations + "\n";
	cout << "\nʳ������ ������������ �������� = " << operations << "\n";
	richTextBox2->Text += "\n��� ������ = " + (double)(t2 - t1) / CLOCKS_PER_SEC + "\n";
	cout << "\n��� ������ = " << (double)(t2 - t1) / CLOCKS_PER_SEC << "\n";
	fclose(f);

}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {

	string s;

	MarshalString(textBox2->Text, s);

	for (int i(0); i < s.size(); i++)
	{
		if (!isdigit(s[i]))
		{
			richTextBox2->Text = "ERROR";
			return;
		}
	}

	if ((textBox2->Text == "") || (Convert::ToInt32(textBox2->Text) <= 0))
	{
		richTextBox2->Text = "ERROR";
		return;
	}

	n = Convert::ToInt32(textBox2->Text);

	determin(richTextBox2, richTextBox1, textBox1, "file.txt", A, n, iteration);

}
};
}
