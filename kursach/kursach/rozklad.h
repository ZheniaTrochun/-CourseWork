#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;

bool LU(RichTextBox^, double**, double**, double**, int, int&, int&);			// LU �����
void matrP(double**, int**, int, int&, int&);									// ����������� ������� ������������
void swap(double**, int**, int, int, int, int&, int&);							// ���� ������ ������� � �������
void LUP(RichTextBox^, double **, int**, double**, double**, int, int&, int&);	// LUP �����

void revMat(double**, double**, double**, int, int&, int&);		// ����������� �������� ������� ��� LU �� LUP ��������


void multmatr(int**, int**, int**, int, int&, int&);			//
void multmatr(double**, double**, int**, int, int&, int&);		// �������� �������
void multmatr(double**, int**, double**, int, int&, int&);		//