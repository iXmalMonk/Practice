#include "header.h"

#include <iostream>

int main()
{
	srand(time(NULL));

	printf("%i\n", RandomNumber(1, 5));

	SetConsoleColor(5);
	printf("%i\n", RandomNumber(1, 5));
	SetConsoleColor(7);

	return 0;
}