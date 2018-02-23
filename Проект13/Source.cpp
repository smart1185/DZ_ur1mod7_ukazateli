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
		cout << "\t\t----������� ����� �������: ";
		cin >> N;
		cout << endl;
		switch (N)
		{
		case 1:
			/*1.�������� ��������� �� ����� �����, ���������� �������.*/
		{
			int *pointer = NULL, chislo = 1;
			pointer = &chislo;
			printf("�����: %d\n", *pointer);
			printf("����� �����: %p\n", pointer);
		}
		break;

		case 2:
			/*2.��������� �������� ������� 'W' ����������, �� ������� ��������� ��������� ���������.*/
		{
			char *pointer = NULL;
			char simbol = 'W';
			pointer = &simbol;
			printf("������: %c\n", *pointer);
			printf("����� �������: %p\n", pointer);
		}
		cout << endl;
		break;

		case 3:
			/*3.�������� ��������� �� ��������� ������ � ���������� �Hello�*/
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
			/*4.�������� �������, ������� ���������, �������� �� ���������� �� ����� �������? ����� ���������� �������,
			���� ��� ������� ��� ������� ������ �� ���� � �� �������.*/
		{
			int chislo;
			printf("������� �����:\n");
			cin >> chislo;
			if (Prime(&chislo))
			{
				printf("%d - ������� �����", chislo);
			}
			else printf("%d - ��������� �����", chislo);

		}
		cout << endl;
		break;

		case 5:
			/*5.�������� �������, ����������� �������� ��������� ������ ��������� ����� � ���������� �������.*/
		{
			const int size = 10;
			int a[size], key;
			printf("������� ������� �������:\n");
			cin >> key;
			printf("������:\n");
			for (int i = 0; i < size; i++)
			{
				a[i] = rand() % 20;
				printf("[%d]%d ", i, a[i]);
			}
			cout << endl;
			if (LineSearch(a, &key, &size) == 0)
			{
				printf("������� �� ������\n");
			}
			else printf("����� �������� �������� � �������: %d", LineSearch(a, &key, &size));
		}
		cout << endl;
		break;

		case 6:
			/*6.�������� �������, ����������� �������� ��������� ������ ��������� ����� � ���������� �������.*/
		{
			const int size = 10;
			int a[size], key;
			printf("������� ������� �������:\n");
			cin >> key;
			printf("������:\n");
			for (int i = 0; i < size; i++)
			{
				a[i] = i;//����� �� �����������)))
				printf("[%d]%d ", i, a[i]);
			}
			cout << endl;
			if (BinarSearch(a, &key, &size) == 0)
			{
				printf("������� �� ������\n");
			}
			else printf("����� �������� �������� � �������: %d", BinarSearch(a, &key, &size));
		}
		cout << endl;
		break;

		
		case 7:
			/*8.����� ��������� ���������� �������� ���������?*/
		{
			int  count = 10, *temp, sum = 0;
			temp = &count;//������������� ����� ���������� count
			*temp = 20; // �������� ���������� count ������������� 20
			temp = &sum;// ������������� ����� ���������� sum
			*temp = count;//�������� ���������� sum ������������� �������� count (20)
			printf("count = %d, *temp = %d, sum = %d\n", count, *temp, sum); //������� ������� count, *temp(������� �������� ����������� �� ������) , sum

		}
		cout << endl;
		break;

		default: {cout << "������� � ����� ������� �� ����������" << endl; }
		}
	} while (N > 0 && N < 8);
	cout << "\t\t\t\t\t�����." << endl;
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