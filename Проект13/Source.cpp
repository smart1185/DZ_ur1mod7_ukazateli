#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <math.h>
#include <time.h>

using namespace std;

int Prime(int *n);
int LineSearch(int *a, int *key, const int*size);
int BinarSearch(int *a, int *key, const int *size);

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int  N;
	do
	{
		cout << "\t\t----Введите номер задания: ";
		cin >> N;
		cout << endl;
		switch (N)
		{
		case 1:
			/*1.Объявите указатель на целое число, называемое адресом.*/
		{
			int *pointer = NULL, chislo = 1;
			pointer = &chislo;
			printf("число: %d\n", *pointer);
			printf("адрес числа: %p\n", pointer);
		}
		break;

		case 2:
			/*2.Назначьте значение символа 'W' переменной, на которую указывает буквенная указатель.*/
		{
			char *pointer = NULL;
			char simbol = 'W';
			pointer = &simbol;
			printf("символ: %c\n", *pointer);
			printf("адрес символа: %p\n", pointer);
		}
		cout << endl;
		break;

		case 3:
			/*3.Объявить указатель на текстовую строку с сообщением «Hello»*/
		{
			char *pointer = NULL;
			char msg[50] = "Hello";
			pointer = msg;
			cout << "\t";
			for (int i = 0; i < 50; i++)
			{
				printf("%c", *(pointer + i));
			}
		}
		cout << endl;
		break;

		case 4:
			/*4.Написать функцию, которая проверяет, является ли переданное ей число простым? Число называется простым,
			если оно делится без остатка только на себя и на единицу.*/
		{
			int chislo;
			printf("Введите число:\n");
			cin >> chislo;
			if (Prime(&chislo))
			{
				printf("%d - простое число", chislo);
			}
			else printf("%d - составное число", chislo);

		}
		cout << endl;
		break;

		case 5:
			/*5.Написать функцию, реализующую алгоритм линейного поиска заданного ключа в одномерном массиве.*/
		{
			const int size = 10;
			int a[size], key;
			printf("Введите искомый элемент:\n");
			cin >> key;
			printf("Массив:\n");
			for (int i = 0; i < size; i++)
			{
				a[i] = rand() % 20;
				printf("[%d]%d ", i, a[i]);
			}
			cout << endl;
			if (LineSearch(a, &key, &size) == 0)
			{
				printf("Элемент не найден\n");
			}
			else printf("Номер искомого элемента в массиве: %d", LineSearch(a, &key, &size));
		}
		cout << endl;
		break;

		case 6:
			/*6.Написать функцию, реализующую алгоритм бинарного поиска заданного ключа в одномерном массиве.*/
		{
			const int size = 10;
			int a[size], key;
			printf("Введите искомый элемент:\n");
			cin >> key;
			printf("Массив:\n");
			for (int i = 0; i < size; i++)
			{
				a[i] = i;//чтобы не сортировать)))
				printf("[%d]%d ", i, a[i]);
			}
			cout << endl;
			if (BinarSearch(a, &key, &size) == 0)
			{
				printf("Элемент не найден\n");
			}
			else printf("Номер искомого элемента в массиве: %d", BinarSearch(a, &key, &size));
		}
		cout << endl;
		break;

		
		case 7:
			/*8.Каков результат следующего сегмента программы?*/
		{
			int  count = 10, *temp, sum = 0;
			temp = &count;//присваевается адрес переменной count
			*temp = 20; // значению переменной count присваевается 20
			temp = &sum;// присваевается адрес переменной sum
			*temp = count;//значению переменной sum присваевается значение count (20)
			printf("count = %d, *temp = %d, sum = %d\n", count, *temp, sum); //выводит значеия count, *temp(возврат значения хранящегося по адресу) , sum

		}
		cout << endl;
		break;

		default: {cout << "Задания с таким номером не существует" << endl; }
		}
	} while (N > 0 && N < 8);
	cout << "\t\t\t\t\tКОНЕЦ." << endl;
	system("pause");
}


int Prime(int *n)
{
	for (int i = 2; i <= *n / 2; i++)
		if (*n%i == 0)
			return 0;
	return 1;
}

int LineSearch(int *a, int *key, const int *size)
{

	for (int i = 0; i < *size; i++)
		if (a[i] == *key)
			return i;
	return 0;
}

int BinarSearch(int *a, int *key, const int *size)
{
	int left = 0;
	int right = *size;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (*key > a[mid])
			left = mid + 1;
		if (*key < a[mid])
			right = mid - 1;
		if (*key == a[mid])
			return mid;
	}
	return 0;
}