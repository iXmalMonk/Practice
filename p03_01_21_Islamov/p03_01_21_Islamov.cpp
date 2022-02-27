#include<iostream>

char* Task(char* str)
{
	char temp[256];
	int i = 0, j = 0;

	printf("Введите строку = ");
	
	gets_s(temp);

	while (i < 256)
	{
		if ((temp[i] >= 'а' and temp[i] <= 'я') or (temp[i] >= 'А' and temp[i] <= 'Я') or (temp[i] >= '0' and temp[i] <= '9'))
		{
			str[j] = temp[i];
			j++;
		}
		if (temp[i + 1] == ' ')
		{
			str[j] = ' ';
			break;
		}
		i++;
	}

	for (int k = j; k < 256; k++)
	{
		str[k] = temp[++i];
	}

	return str;
}

int main()
{
	system("chcp 1251");
	system("cls");

	char str[256];

	Task(str);

	printf("Ответ = %s", str);
}

// Дана строка. Группы символов, разделенные одним или несколькими пробелами и не
// содержащие пробелов внутри себя, будем
// называть словами. Удалить из первого слова
// все символы, не являющиеся латинскими
// буквами.