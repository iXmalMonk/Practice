#include<iostream>
#include<time.h>

void LengthArray(int* n)
{
	printf("Введите размер квадратной матрицы [1;100] = ");
	do {
		if (*n < 1 or *n > 100) printf("Введенное значение неверно, попробуйте заного = ");
		scanf_s("%d", n);
	} while (*n < 1 or *n > 100);
}

void FillRandomArray(float array[100][100], int n)
{
	srand(time(NULL));

	int a, b;

	printf("Диапазон случайных чисел [A;B]\n[...,...] = ");
	scanf_s("%d", &a);

	do {
		printf("[%d;...] = ", a);
		scanf_s("%d", &b);
	} while (b < a);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			array[i][j] = rand() % (b - a + 1) + a;
}

void PrintArray(float array[100][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%8.3f", array[i][j]);
		printf("\n");
	}
}

float Task(float array[100][100], int n)
{
	float max = array[0][0];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if ((i >= j) and (n - j + 1 >= i) and (array[i][j] > max)) max = array[i][j];
			if ((i >= j) and (n - j + 1 <= i) and (array[i][j] > max)) max = array[i][j];
		}
	return max;
}

int main()
{
	system("chcp 1251");
	system("cls");

	float array[100][100];
	int n = 1;

	LengthArray(&n);

	FillRandomArray(array, n);

	PrintArray(array, n);

	printf("Max = %f", Task(array, n));
}

// Дана действительная квадратная матрица
// порядка 2n. Найти наибольшее из значений
// элементов, расположенных в заштрихованной части матрицы.