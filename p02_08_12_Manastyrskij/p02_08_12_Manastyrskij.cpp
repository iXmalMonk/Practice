#include <iostream>
#include <time.h>

const int ROWS = 100, COLS = 100;

void LengthArray(int &r, int &c)
{
	system("cls");

	printf("Введите количество строк [1;100]\n");

	do {
		printf("[...] = ");
		scanf_s("%d", &r);
	} while (r < 1 or r > ROWS);

	printf("Введите количество столбцов [1;100]\n");

	do {
		printf("[...] = ");
		scanf_s("%d", &c);
	} while (c < 1 or c > COLS);
}

void FillArrayRandom(double array[ROWS][COLS], int r, int c)
{
	srand(time(NULL));

	int choice = 0, a = 0, b = 0;

	system("cls");

	printf("Диапазон случайных чисел [A;B]\n[...,...] = ");
	scanf_s("%d", &a);

	do {
		printf("[%d;...] = ", a);
		scanf_s("%d", &b);
	} while (b < a);

	do {
		system("cls");

		printf("[%d;%d]\n[1] = Целые числа\n[2] = Вещественные числа ([B] + 0.[...])\n[...] = ", a, b);
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					array[i][j] = rand() % (b - a + 1) + a;
			break;
		case 2:
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					array[i][j] = (rand() % (b - a + 1) + a) + rand() % 100 / 100.0;
			break;
		}
	} while (choice != 1 and choice != 2);
}

void FillArrayTXT(double array[ROWS][COLS], int &r, int &c)
{
	FILE* f;
	if (fopen_s(&f, "array.txt", "rt") != 0) exit(404);
	fscanf_s(f, "%d %d", &r, &c);
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			fscanf_s(f, "%lf ", &array[i][j]);
	fclose(f);
}

void FillArrayBIN(double array[ROWS][COLS], int& r, int& c)
{
	FILE* f;
	if (fopen_s(&f, "array.bin", "rb") != 0) exit(404);
	fread(&r, sizeof(int), 1, f);
	fread(&c, sizeof(int), 1, f);
	for (int i = 0; i < r; i++)
		fread(array[i], sizeof(double), c, f);
	fclose(f);
}

void WriteArrayBIN(double array[ROWS][COLS], int r, int c)
{
	FILE* f;
	if (fopen_s(&f, "array.bin", "wb") != 0) exit(404);
	fwrite(&r, sizeof(int), 1, f);
	fwrite(&c, sizeof(int), 1, f);
	for (int i = 0; i < r; i++)
		fwrite(array[i], sizeof(double), c, f);
	fclose(f);
}

void PrintArray(double array[ROWS][COLS], int r, int c)
{
	printf("\n");

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			printf("%8.3lf", array[i][j]);
		printf("\n");
	}
}

void MenuWriteArrayBIN(double array[ROWS][COLS], int r, int c)
{
	int choice = 0;
	printf("\n\tSave Array In BIN\n[1] = Да\n[2] = Нет\n");
	do {
		printf("[...] = ");
		scanf_s("%i", &choice);
		switch (choice)
		{
		case 1:
			WriteArrayBIN(array, r, c);
			break;
		}
	} while (choice != 1 and choice != 2);

	system("cls");

	PrintArray(array, r, c);
}

int ArrayTASK_8_A(double array[ROWS][COLS], int r, int c)
{
	int N = 0;
	for (int i = 0; i < c; i++)
	{
		int counter = 0;
		for (int j = 0; j < r; j++)
			if (array[j][i] == 0) counter++;
		if (counter >= 2)
		{
			N = i;
			return N;
		}
	}

	return -1;
}

// Определить номер первого из столбцов, содержащих как минимум два нулевых элемента (оформить в виде функции)

void ArrayTASK_8_B(double array[ROWS][COLS], int r, int c) //---
{
	double tempArray[ROWS];

	for (int i = 0; i < r; i++)
	{
		double amount = 0;
		for (int j = 0; j < c; j += 2)
			if (array[i][j] < 0) amount += array[i][j];
		tempArray[i] = amount;
	}
	
	for (int i = 0; i < r; i++)
		for (int j = i + 1; j < r; j++)
			if (tempArray[i] < tempArray[i + 1])
				for (int k = 0; k < c; k++)
				{
					double temp = array[i][k];
					array[i][k] = array[j][k];
					array[j][k] = temp;
				}
}

// Характеристикой строки целочисленной матрицы назовем сумму её отрицательных четных элементов. 
// Переставляя строки заданной матрицы, расположить их в соответствии с убыванием их
// характеристик (оформить в виде процедуры)


double* ArrayTASK_12_A(double array[ROWS][COLS], int r, int c, double arr[ROWS], int& ar) // pointer
{
	for (int i = 0; i < r; i++)
	{
		int counter = 0;
		for (int j = 0; j < c; j++)
			if (array[i][j] < 0) counter++;
		if (counter > 1)
		{
			double amount = 1;
			for (int j = 0; j < c; j++)
				amount *= array[i][j];
			arr[i] = amount;
			ar++;
		}
	}
	return arr;
}

// Определить произведение элементов в тех строках, которые содержат 
// более одного отрицательного элемента (оформить в виде функции)

void PrintArrayTASK_12_A(double array12A[], int ROWS12A)
{
	for (int i = 0; i < ROWS12A; i++)
		printf("Amount[%d] = %3.3lf\n", i + 1, array12A[i]);
}

void ArrayTASK_12_B(double array[ROWS][COLS], int r, int c)
{
	double tempArray[ROWS];

	for (int i = 0; i < r; i++)
	{
		double amount = 0;
		for (int j = 1; j < c; j += 2)
			if (array[i][j] < 0) amount += array[i][j];
		tempArray[i] = amount;
	}

	for (int i = 0; i < r; i++)
		for (int j = i + 1; j < r; j++)
			if (tempArray[i] < tempArray[i + 1])
				for (int k = 0; k < c; k++)
				{
					double temp = array[i][k];
					array[i][k] = array[j][k];
					array[j][k] = temp;
				}
}

// Характеристикой строки целочисленной матрицы назовем сумму её
// отрицательных нечетных элементов.Переставляя строки заданной
// матрицы, расположить их в соответствии с ростом их характеристик
// (оформить в виде процедуры).

void FillMenu(double array[ROWS][COLS], int& r, int& c)
{
	int choice = 0;
	printf("\tFill Array\n[1] = RANDOM\n[2] = TXT\n[3] = BIN\n");
	do {
		printf("[...] = ");
		scanf_s("%i", &choice);
		switch (choice)
		{
		case 1:
			LengthArray(r, c);
			FillArrayRandom(array, r, c);
			system("cls");
			PrintArray(array, r, c);
			MenuWriteArrayBIN(array, r, c);
			break;
		case 2:
			FillArrayTXT(array, r, c);
			system("cls");
			PrintArray(array, r, c);
			MenuWriteArrayBIN(array, r, c);
			break;
		case 3:
			FillArrayBIN(array, r, c);
			PrintArray(array, r, c);
			break;
		}
	} while (choice != 1 and choice != 2 and choice != 3);
}

void TASKMenu(double array[ROWS][COLS], int r, int c)
{
	int choice = 0, N = 0, ROWS12A = 0;
	double array12A[ROWS];

	printf("\n\tTask Array\n[1] = 8_A\n[2] = 8_B\n[3] = 12_A\n[4] = 12_B\n");
	do {
		printf("[...] = ");
		scanf_s("%i", &choice);
		switch (choice)
		{
		case 1:
			N = ArrayTASK_8_A(array, r, c);
			if (N == -1) printf("Такого столбца нет!");
			else printf("N = %d", N);
			break;
		case 2:
			ArrayTASK_8_B(array, r, c);
			PrintArray(array, r, c);
			break;
		case 3:
			ArrayTASK_12_A(array, r, c, array12A, ROWS12A);
			PrintArrayTASK_12_A(array12A, ROWS12A);
			break;
		case 4:
			ArrayTASK_12_B(array, r, c);
			PrintArray(array, r, c);
			break;
		}
	} while (choice != 1 and choice != 2 and choice != 3 and choice != 4);
}

int main()
{
	system("chcp 1251");
	system("cls");

	double array[ROWS][COLS];
	int r = 0, c = 0;

	FillMenu(array, r, c);
	TASKMenu(array, r, c);
}