#include<iostream>
#include<time.h>

const int ROWS = 100, COLS = 100;

void LengthArray(int* r_p, int* c_p) // Размер массива
{
	printf("Введите количество строк [1;100] = ");

	do {
		if (*r_p < 1 or *r_p > 100) printf("Введенное значение не соответствует диапазону\nВведите заного количество строк [1;100] = ");
		scanf_s("%i", r_p);
	} while (*r_p < 1 or *r_p > 100);

	printf("Введите количество столбцов [1;100] = ");

	do {
		if (*c_p < 1 or *c_p > 100) printf("Введенное значение не соответствует диапазону\nВведите заного количество столбцов [1;100] = ");
		scanf_s("%i", c_p);
	} while (*c_p < 1 or *c_p > 100);
}

void FillRandomArray(float array[ROWS][COLS], int* r_p, int* c_p) // Рандомное заполнение массива
{
	srand(time(NULL));

	for (int i = 0; i < *r_p; i++)
		for (int j = 0; j < *c_p; j++)
			array[i][j] = rand() % 150 + rand() % 100 / 100.0;
}

void PrintArray(float array[ROWS][COLS], int* r_p, int* c_p) // Вывод массива
{
	for (int i = 0; i < *r_p; i++)
	{
		for (int j = 0; j < *c_p; j++)
			printf("%8.3f ", array[i][j]);
		printf("\n");
	}
}

float * Task(float array[ROWS][COLS], int* r_p, int* c_p, float a[]) // Задание
{

	for (int i = 0; i < *r_p; i++)
	{
		double amount = 0;
		for (int j = 0; j < *c_p; j++)
			amount += array[i][j];
		a[i] = amount;
	}

	return a;
}

void PrintA(float a[], int *r_p) // Вывод массива из задания
{
	for (int i = 0; i < *r_p; i++)
		printf("%3d = %8.3f\n", i + 1, a[i]);
}

int main()
{
	system("chcp 1251");
	system("cls");

	float array[ROWS][COLS], a[ROWS];
	int r = 1, c = 1;

	LengthArray(&r, &c);

	FillRandomArray(array, &r, &c);

	PrintArray(array, &r, &c);

	Task(array, &r, &c, a);

	PrintA(a, &r);
}

// Сформировать вещественную матрицу A
// размера m[x]n, элементы которой являются
// случайными числами из отрезка[0; 150]. Получить массив B(из m элементов), каждый
// элемент Bi которого равен сумме элементов i-й строки матрицы A.
