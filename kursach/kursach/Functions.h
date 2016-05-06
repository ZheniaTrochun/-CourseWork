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


void MarshalString(String^, string&);				// зміни типу з String^ до string

void gen(double**, int);								// генерація матриці
void get(RichTextBox^, char*, double**, int);			// зчитування матриці з RichTextBox та запис її до файлу
void getFromFile(char*, double**, int);				// отримання матриці з файлу

void determin(RichTextBox^, RichTextBox^, TextBox^, char*, double**, int);	// перевірка виродженості матриці

bool LU(RichTextBox^, double**, double**, double**, int);			// LU метод
void matrP(double**, int**, int);									// знаходження матриці перестановок
void swap(double**, int**, int, int, int);							// зміна місцями рядочків в матриці
void LUP(RichTextBox^, double **, int**, double**, double**, int);	// LUP метод

bool obraml(RichTextBox^, double**, double**, int);	// метод Обрамлення
double mult1(double*, double*, double**, double**, int);

void revMat(double**, double**, double**, int);		// знаходження оберненої матриці для LU та LUP розкладів

void multmatr(int**, int**, int**, int);			//
void multmatr(double**, double**, int**, int);		// множення матриць
void multmatr(double**, int**, double**, int);		//

void output(RichTextBox^, int**, int);    // Вивід матриці до RichTextBox
void output(RichTextBox^, double**, int);   // Вивід матриці до RichTextBox

