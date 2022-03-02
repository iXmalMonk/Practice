#include <iostream>

int main()
{
	system("chcp 1251");
	system("cls");

	int minus = -1, n = 3, fact = 1;
	double accuracy = 0, x = 0, x_5 = 1, amount = 0, a = 0;

	printf("¬ведите X\nX = ");
	scanf_s("%lf", &x);

	do {
		printf("¬ведите точность\nAccuracy = ");
		scanf_s("%lf", &accuracy);
	} while (accuracy < 0);

	for (int i = 0; i < n; i++)
		x_5 *= x * 5;

	for (int i = 1; i < n; i++)
		fact *= i;

	do {
		a = minus * (x_5 / fact);

		amount += a;

		printf("%i\n", n);

		n++;

		minus *= -1;

		fact *= n - 1;

		x_5 *= x * 5;

	} while (fabs(a) > accuracy);

	printf("Amount = %.5lf", amount);
}

//	inf
//	E		(-1)^n * (5*x)^n / (n - 1)!
//	n = 3