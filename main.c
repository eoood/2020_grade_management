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
	printf("프로그램 종료\n");

	return 0;
}

