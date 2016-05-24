#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;

bool obraml(RichTextBox^, double**, double**, int, int&, int&);	// метод Обрамлення
double mult1(double*, double*, double**, double**, int, int&, int&);