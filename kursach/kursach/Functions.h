#pragma once

#include "rozklad.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <time.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;


static int operations = 0;

void MarshalString(String^, string&);				// ���a ���� � String^ �� string

void gen(double**, int);								// ��������� �������
bool get(RichTextBox^, char*, double**, int);			// ���������� ������� � RichTextBox �� ����� �� �� �����
void getFromFile(TextBox^, char*, double**);				// ��������� ������� � �����

void determin(RichTextBox^, RichTextBox^, TextBox^, char*, double**, int, int&);	// �������� ����������� �������

void output(RichTextBox^, char*, int**, int);    // ���� ������� �� RichTextBox
void output(RichTextBox^, char*, double**, int);   // ���� ������� �� RichTextBox

