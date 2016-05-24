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

void MarshalString(String^, string&);				// змінa типу з String^ до string

void gen(double**, int);								// генерація матриці
bool get(RichTextBox^, char*, double**, int);			// зчитування матриці з RichTextBox та запис її до файлу
void getFromFile(TextBox^, char*, double**);				// отримання матриці з файлу

void determin(RichTextBox^, RichTextBox^, TextBox^, char*, double**, int, int&);	// перевірка виродженості матриці

void output(RichTextBox^, char*, int**, int);    // Вивід матриці до RichTextBox
void output(RichTextBox^, char*, double**, int);   // Вивід матриці до RichTextBox

