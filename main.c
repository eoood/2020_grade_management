#include "func.h"

int main()
{
	char ch = NULL;

	choice_menu();

	while (ch != 'q')
	{
		scanf("%c", &ch);
		processMenu(ch);
		fflush(stdin);
	}
	printf("���α׷� ����\n");

	return 0;
}

