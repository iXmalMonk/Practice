// ��� ���������� ������ �� 15 ���������. ����������� � �������� �������:
// �) ��������, ������������� ����� ������ � ������� ���������� (�.�. � ������� �� �������);
// �) ��������, ������������� ����� k-� � s-� ���������� (�.�. � (k + 1)-�� �� (s-1)-�).
// �������� k � s �������� � ����������, k < s;
// �) ��������, ������������� ����� ������������ � ����������� ����������, ������� ��.

#include<iostream>

void FillArrayFromKeyboard(int array[], int N)
{
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		printf("%2i = ", i);
		scanf_s("%i", &array[i]);
	}
}

void PrintArray(int array[], int N)
{
	for (int i = 0; i < N; i++)
		printf("%2i | %3i\n", i, array[i]);
}

void TaskArrayA(int array[], int N)
{
	int k = 3, s = 9, temp;

	for (int i = 0; i < (s - k) / 2 + (s - k) % 2; i++)
	{
		temp = array[i + k];
		array[i + k] = array[s - i];
		array[s - i] = temp;
	}
}

void TaskArrayB(int array[], int N)
{
	int k, s, temp;

	printf("\n[0;14]\n");

	do {
		printf("[...;...] = ");
		scanf_s("%i", &k);
	} while (k < 0 or k > 14);

	do {
		printf("[%i;...] = ", k);
		scanf_s("%i", &s);
	} while (k > s or s > 14);

	printf("[%i;%i]\n", k, s);

	for (int i = 0; i < (s - k) / 2 + (s - k) % 2; i++)
	{
		temp = array[i + k];
		array[i + k] = array[s - i];
		array[s - i] = temp;
	}
}

void TaskArrayC(int array[], int N)
{
	int k = 0, s = 0, temp, k2 = array[0], s2 = array[0];



	for (int i = 0; i < N; i++)
	{
		if (k2 > array[i])
		{
			k2 = array[i];
			k = i;
		}
		if (s2 < array[i])
		{
			s2 = array[i];
			s = i;
		}
	}

	for (int i = 0; i < (s - k) / 2 + (s - k) % 2; i++)
	{
		temp = array[i + k];
		array[i + k] = array[s - i];
		array[s - i] = temp;
	}
}

void FillArrayRandom(int array[], int length)
{
	srand(time(0));
	int a, b;
	printf("[A, B]\nA = ");
	scanf_s("%i", &a);
	do {
		printf("B = ");
		scanf_s("%i", &b);
	} while (b < a);
	for (int i = 0; i < length; i++)
		array[i] = rand() % (b - a + 1) + a;
}

void ChoiceFillArray(int array[], int N)
{
	int choice = 0;

	do {
		printf("1. Keyboard 2. Random = ");
		scanf_s("%i", &choice);

		switch (choice)
		{
		case 1:
			FillArrayFromKeyboard(array, N);
			break;
		case 2:
			FillArrayRandom(array, N);
			break;

		default: printf("Error!\n");
		}
	} while (choice != 1 and choice != 2);
}

void ChoiceArray(int array[], int N)
{
	int choice = 0;

	do {
		printf("1. A 2. B 3. C = ");
		scanf_s("%i", &choice);

		switch (choice)
		{
		case 1:
			TaskArrayA(array, N);
			break;
		case 2:
			TaskArrayB(array, N);
			break;
		case 3:
			TaskArrayC(array, N);
			break;

		default: printf("Error!\n");
		}
	} while (choice != 1 and choice != 2 and choice != 3);
}

int main()
{
	system("chcp 1251");
	system("cls");

	const int length = 15;
	int array[length];


	ChoiceFillArray(array, length);
	printf("\n");
	PrintArray(array, length);
	printf("\n");
	ChoiceArray(array, length);
	printf("\n");
	PrintArray(array, length);
}