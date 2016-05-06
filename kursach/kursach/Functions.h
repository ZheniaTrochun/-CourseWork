#pragma once

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


void MarshalString(String^, string&);				// ���� ���� � String^ �� string

void gen(double**, int);								// ��������� �������
void get(RichTextBox^, char*, double**, int);			// ���������� ������� � RichTextBox �� ����� �� �� �����
void getFromFile(char*, double**, int);				// ��������� ������� � �����

void determin(RichTextBox^, RichTextBox^, TextBox^, char*, double**, int);	// �������� ����������� �������

bool LU(RichTextBox^, double**, double**, double**, int);			// LU �����
void matrP(double**, int**, int);									// ����������� ������� ������������
void swap(double**, int**, int, int, int);							// ���� ������ ������� � �������
void LUP(RichTextBox^, double **, int**, double**, double**, int);	// LUP �����

bool obraml(RichTextBox^, double**, double**, int);	// ����� ����������
double mult1(double*, double*, double**, double**, int);

void revMat(double**, double**, double**, int);		// ����������� �������� ������� ��� LU �� LUP ��������

void multmatr(int**, int**, int**, int);			//
void multmatr(double**, double**, int**, int);		// �������� �������
void multmatr(double**, int**, double**, int);		//

void output(RichTextBox^, int**, int);    // ���� ������� �� RichTextBox
void output(RichTextBox^, double**, int);   // ���� ������� �� RichTextBox

