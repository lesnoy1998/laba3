
#include <iostream>
#include <locale.h>
#include <string>

#include "Vector10.h"
#include "Norma.h"
#include "Complex.h"
#include "Matrix2x2.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	Norma* array1[3]; //сам массив производных от класса
	int ar11[3] = { 0, 0, 0 };
	FILE* fl;
	fl = fopen("base.txt", "r");
	cout << "Брать данные из файла или вручную?\n1-файл\n2-вручную\n";
	int n2;
	cin >> n2;
	char str[20];
	if (n2 == 1)
	{
		if (fl == NULL) { printf("File ne obnarujen"); }
		else
		{
			fgets(str, 20, fl);
			int tmp1, tmp2;
			tmp1 = atoi(str);
			fgets(str, 20, fl);
			tmp2 = atoi(str);
			if ((tmp1 != 0) && (tmp2 != 0)) { ar11[0] = 1; array1[0] = new Complex(tmp1, tmp2);}
			int ar[10], cnt; cnt = 0;
			for (int i = 0; i < 10; i++)
			{
				fgets(str, 20, fl);
				ar[i] = atoi(str);
				if (ar[i] == 0) { cnt++; }
			}
			if (cnt != 10) {array1[1] = new Vector10(ar[0], ar[1], ar[2], ar[3], ar[4], ar[5], ar[6], ar[7], ar[8], ar[9]); ar11[1] = 1;}
			cnt = 0; int ar1[4];
			for (int i = 0; i < 4; i++)
			{
				fgets(str, 20, fl);
				ar1[i] = atoi(str);
				if (ar1[i] == 0) { cnt++; }
			}
			if (cnt != 4){array1[2] = new Matrix2x2(ar1[0], ar1[1], ar1[2], ar1[3]);ar11[2] = 1;}
			fclose(fl);
		}
	}
	
	
	
	while (1) {
		while (1)
		{
			cout << "Какой производный от нормы класс вы хотите создать?\n1-Complex 4islo\n2-Vector10el\n3-matrix2x2el\n4-далее\n5-сохранить в файл\n";
			int n;
			cin >> n;
			if (n == 1)
			{
				cout << "\nВаш выбор - комплексное число. Введите a и b:\n";
				int a, b;
				cin >> a >> b;
				array1[0] = new Complex(a, b);
				ar11[0] = 1;

			}
			else if (n == 2)
			{
				cout << "\nВаш выбор - Вектор. Введите 10 его элементов:\n";
				int a[10];
				for (int i = 0; i < 10; i++) { cin >> a[i]; }
				array1[1] = new Vector10(a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
				ar11[n - 1] = 1;

			}
			else if (n == 3)
			{
				cout << "\nВаш выбор - матрица 2х2. Введите a1, а2 и b1, b2:\n";
				int a1, a2, b1, b2;
				cin >> a1 >> a2 >> b1 >> b2;
				array1[2] = new Matrix2x2(a1, a2, b1, b2);
				ar11[n - 1] = 1;
			}
			else if (n == 4)
			{
				break;
			}
			else if (n == 5)
			{
				fl = fopen("base.txt", "w");
				char str1[200];
				char *tempstr = new char[100];
				char* tempstr2 = new char[100];
				char* tempstr3 = new char[100];
				if (ar11[0] != 0) { tempstr = array1[0]->saveToStr(tempstr); } else { sprintf(tempstr, "0\n0"); }
				if (ar11[1] != 0) { tempstr2 = array1[1]->saveToStr(tempstr2); }
				else { sprintf(tempstr2, "0\n0\n0\n0\n0\n0\n0\n0\n0\n0"); }
				if (ar11[2] != 0) { tempstr3 = array1[2]->saveToStr(tempstr3); }
				else { sprintf(tempstr3, "0\n0\n0\n0"); }

				sprintf(str1, "%s\n%s\n%s", tempstr, tempstr2, tempstr3);


				delete[] tempstr; delete[] tempstr2; delete[] tempstr3;
				fputs(str1, fl);
				fclose(fl);
			}
			else
			{
				for (int i = 0; i < 3; i++)
				{
					if (ar11[i] != 0)
					{
						delete array1[i];
					}
				}
				return 0;
			}
		}

		while (1)
		{
			cout << "\nЧто вы хотите сделать?\n1-Показать значения\n2-Изменить значения\n3-удалить\n4-вызвать функцию нормы\n";
			int n;
			cin >> n;
			if (n == 1)
			{
				cout << "\nС каким классом работаем?\n1-Complex\n2-vect\n3-mtrx\n";
				cin >> n;
				if (ar11[n - 1] == 0) { cout << "\nнету\n"; continue; }
				array1[n - 1]->show();
			}
			else if (n == 2)
			{
				

				cout << "\nС каким классом работаем?\n1-Complex\n2-vect\n3-mtrx\n";
				cin >> n;
				if (ar11[n - 1] == 0) { cout << "\nнету\n"; continue; }
				cout << "\nСтарые значения таковы:\n";
				array1[n - 1]->show();
				cout << "\nВведите новые\n";
				if (n == 1)
				{
					delete array1[n - 1];
					cout << "\nВаш выбор - комплексное число. Введите a и b:\n";
					int a, b;
					cin >> a >> b;
					array1[0] = new Complex(a, b);
				}
				else if (n == 2)
				{
					delete array1[n - 1];
					cout << "\nВаш выбор - Вектор. Введите 10 его элементов:\n";
					int a[10];
					for (int i = 0; i, 10; i++) { cin >> a[i]; }
					array1[1] = new Vector10(a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
				}
				else if (n == 3)
				{
					delete array1[n - 1];
					cout << "\nВаш выбор - матрица 2х2. Введите a1, а2 и b1, b2:\n";
					int a1, a2, b1, b2;
					cin >> a1 >> a2 >> b1 >> b2;
					array1[2] = new Matrix2x2(a1, a2, b1, b2);
				}
			}
			else if (n == 3)
			{
				
				cout << "\nС каким классом работаем?\n1-Complex\n2-vect\n3-mtrx\n";
				cin >> n;
				if (ar11[n - 1] == 0) { cout << "\nнету\n"; continue; }
				delete array1[n - 1];
				cout << "\nУдалено успешно\n";
				ar11[n - 1] = 0;
			}
			else if (n == 4)
			{
				
				cout << "\nС каким классом работаем?\n1-Complex\n2-vect\n3-mtrx\n";
				cin >> n;
				if (ar11[n - 1] == 0) { cout << "\nнету\n"; continue; }
				cout << "Рузультат = " << array1[n - 1]->func_norm();
			}
			else
			{
				break;
			}
		}


	}



	for (int i = 0; i < 3; i++)
	{
		if (ar11[i] != 0)
		{
			delete array1[i];
		}
	}
}
