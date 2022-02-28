#include<iostream>
#include<time.h>

void FillRandomArrays(float a[], float b[]) // Рандомное заполнение массивов
{
	srand(time(NULL));

	int d1, d2;

	printf("Введите диапазон\n[A;B]\n[...;...] = ");
	scanf_s("%i", &d1);

	do {
		printf("[%i;...] = ", d1);
		scanf_s("%i", &d2);
	} while (d2 < d1);


	for (int i = 0; i < 20; i++)
		a[i] = (rand() % (d2 - d1) + d1) + rand() % 100 / 100.0;

	for (int i = 0; i < 20; i++)
		b[i] = (rand() % (d2 - d1) + d1) + rand() % 100 / 100.0;
}

float Task(float a[], float b[]) // Задание
{
	float amount = 0, numerator = 0, denominator = 0;

	for (int i = 0; i < 20; i++)
	{
		numerator += a[i] * b[i];
		denominator += a[i];
	}
	amount = numerator / denominator;

	return amount;
}

void PrintArrays(float a[], float b[]) // Вывод массивов
{
	printf("A\n");

	for (int i = 0; i < 20; i++)
		printf("[%2i] = %8.3f\n", i + 1, a[i]);

	printf("\nB\n");

	for (int i = 0; i < 20; i++)
		printf("[%2i] = %8.3f\n", i + 1, b[i]);

	printf("\n");
}

int main()
{
	system("chcp 1251");
	system("cls");

	float a[20], b[20], task;

	FillRandomArrays(a, b);

	PrintArrays(a, b);

	task = Task(a, b);

	printf("Task = %f", task);
}

// Даны вещественные массивы {a1, a2, …, a20} и {b1, b2, …, b20}.
// Вычислить a1b1 + a2b2 + ... + a20b20 / a1 + a2 + ... + a20