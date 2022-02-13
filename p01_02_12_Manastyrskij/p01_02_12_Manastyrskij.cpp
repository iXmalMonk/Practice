// ƒан массив. ѕереписать его элементы в другой массив такого же размера следующим образом:
// сначала должны идти все отрицательные элементы, а затем все остальные.
// »спользовать только один проход по исходному массиву.

#include<iostream>

int InputLengthArray()
{
	int length = 0;

	do {
		printf("–азмер массива [1;100] = ");
		scanf_s("%i", &length);
	} while (length < 1 or length > 100);

	return length;
}

void FillArrayFromKeyboard(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%2i = ", i + 1);
		scanf_s("%i", &array[i]);
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

void ChoiceFillArray(int array[], int length)
{
	int choice = 0;

	do {
		printf("1. Keyboard 2. Random = ");
		scanf_s("%i", &choice);

		switch (choice)
		{
		case 1:
			FillArrayFromKeyboard(array, length);
			break;
		case 2:
			FillArrayRandom(array, length);
			break;

		default: printf("Error!\n");
		}
	} while (choice != 1 and choice != 2);
}

void PrintArray(int array[], int length)
{
	for (int i = 0; i < length; i++)
		printf("%2i | %3i\n", i + 1, array[i]);
}

void TaskArray(int array[], int array_2[], int length)
{
	int temp = 0, temp_2 = length - 1;
	for (int i = 0; i < length; i++)
	{
		if (array[i] < 0)
		{
			array_2[temp] = array[i];
			temp++;
		}
		else
		{
			array_2[temp_2] = array[i];
			temp_2--;
		}
	}
}

int main()
{
	system("chcp 1251");
	system("cls");

	const int N = 100;
	int array[N], array_2[N], length = 0;

	length = InputLengthArray();
	ChoiceFillArray(array, length);
	PrintArray(array, length);
	printf("\n");
	TaskArray(array, array_2, length);
	PrintArray(array_2, length);
}