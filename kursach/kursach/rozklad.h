#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;

bool LU(RichTextBox^, double**, double**, double**, int, int&, int&);			// LU метод
void matrP(double**, int**, int, int&, int&);									// знаходження матриці перестановок
void swap(double**, int**, int, int, int, int&, int&);							// зміна місцями рядочків в матриці
void LUP(RichTextBox^, double **, int**, double**, double**, int, int&, int&);	// LUP метод

void revMat(double**, double**, double**, int, int&, int&);		// знаходження оберненої матриці для LU та LUP розкладів


void multmatr(int**, int**, int**, int, int&, int&);			//
void multmatr(double**, double**, int**, int, int&, int&);		// множення матриць
void multmatr(double**, int**, double**, int, int&, int&);		//