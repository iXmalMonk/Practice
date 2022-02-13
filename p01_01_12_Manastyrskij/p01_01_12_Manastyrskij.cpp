// ƒан массив вещественных случайных чисел (размер массива определ€ет пользователь,
// но в диапазоне [3;20]). ќпределить произведение и результат делени€ всех чисел массива.

#include<iostream>
#include<time.h>

int InputLengthArray()
{
	int length = 0;
	do {
		printf("¬ведите размер [3;20] = ");
		scanf_s("%i", &length);
	} while (length < 3 or length > 20);

	return length;
}

void FillArrayRandom(double array[], int length)
{
	srand(time(NULL));

	for (int i = 0; i < length; i++)
		array[i] = 100000.0 / rand();
}

void PrintArray(double array[], int length)
{
	for (int i = 0; i < length; i++)
		printf("array[%2i] = %7.3lf\n", i + 1, array[i]);
}

double CompositionArray(double array[], int length)
{
	double composition = 1;
	for (int i = 0; i < length; i++)
		composition *= array[i];
	return composition;
}

double ParticularArray(double array[], int length)
{
	double particular = array[0];
	for (int i = 1; i < length; i++)
		particular /= array[i];
	return particular;
}

int main()
{
	system("chcp 1251");
	system("cls");

	const int N = 20;
	double array[N], composition = 0, particular = 0;
	int length = 0;

	length = InputLengthArray();
	printf("\n");
	FillArrayRandom(array, length);
	PrintArray(array, length);
	printf("\n");
	composition = CompositionArray(array, length);
	printf("Composition = %.3lf\n\n", composition);
	particular = ParticularArray(array, length);
	printf("Particular = %.3lf\n\n", particular);

}