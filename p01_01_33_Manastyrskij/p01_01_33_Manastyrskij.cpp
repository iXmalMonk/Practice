// Дан массив из 15 целых чисел. 
// Элементы массива – случайные числа из диапазона [-10;10].
// Найти y=x1-x2+x3-...-x14+x15.

#include<iostream>

void FillArrayRandom(int array[], int N)
{
	srand(time(NULL));

	for (int i = 0; i < N; i++)
		array[i] = rand() % 21 - 10;
}

void PrintArray(int array[], int N)
{
	for (int i = 0; i < N; i++)
		printf("%3i\n", array[i]);
}

int MinusArray(int array[], int N)
{
	int y = array[0], x = -1;

	for (int i = 1; i < N; i++)
	{
		array[i] *= x;
		y += array[i];
		x *= -1;
	}
	return y;
}

int main()
{
	const int N = 3;
	int array[N];

	FillArrayRandom(array, N);
	PrintArray(array, N);
	printf("Y = %i", MinusArray(array, N));
}
