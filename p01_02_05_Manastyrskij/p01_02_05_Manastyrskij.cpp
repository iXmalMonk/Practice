// Дан массив вещественных чисел.
// а) Каждый элемент, больший 10, заменить на его квадратный корень
// б) Все элементы массива с четными номерами заменить на их абсолютную величину.

#include<iostream>

int InputLengthArray()
{
	int length = 0;

	do {
		printf("Размер массива [1;100] = ");
		scanf_s("%i", &length);
	} while (length < 1 or length > 100);

	return length;
}

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
	for (int i = 0; i < N; i++)
		if (array[i] > 10) array[i] = sqrt(array[i]);
}

void TaskArrayB(int array[], int N)
{
	for (int i = 0; i < N; i++)
		if (i % 2 == 0)
			if (array[i] < 0) array[i] = -array[i];
}

void FillArrayRandom(int array[], int length)
{
	srand(time(0));
	int a, b;
	printf("\n[A, B]\n\nA = ");
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
		printf("1. A 2. B = ");
		scanf_s("%i", &choice);

		switch (choice)
		{
		case 1:
			TaskArrayA(array, N);
			break;
		case 2:
			TaskArrayB(array, N);
			break;

		default: printf("Error!\n");
		}
	} while (choice != 1 and choice != 2);
}

int main()
{
	system("chcp 1251");
	system("cls");

	const int N = 100;
	int array[N], length;

	length = InputLengthArray();
	ChoiceFillArray(array, length);
	printf("\n");
	PrintArray(array, length);
	printf("\n");
	ChoiceArray(array, length);
	printf("\n");
	PrintArray(array, length);
}