#include "func.h"

Student std[20];
Student std_dest[20];
Student temp;
int len = 0;

void choice_menu() //�޴�
{
	printf("          �������� ���α׷� \n\n");
	printf("---------------M E N U---------------\n\n");
	printf("1.�л� ���� �Է� \n\n");
	printf("2.�л��� �ش� ���� ���� ��� \n\n");
	printf("3.n��° �л��� ���� ��� \n\n");
	printf("4.�л��� ��� ��� \n\n");
	printf("5.�� �Էµ� �л� �� ��� \n\n");
	printf("6.��ü �л����� ��� \n\n");
	printf("7.��ü �л� ������ ��� \n\n");
	printf("8.�л� ������ ���� \n\n");
	printf("9.�л� ���� ���� \n\n");
	printf("10.�ؽ�Ʈ ���Ϸ� ������ ���� \n\n");
	printf("�޴��� �Է��ϼ���('q' �Է½� ����): ");
}

void menu_1() //�޴�1 ����(�̸�, ����, ����, ����)�� �Է¹޾� ����� ���� ����
{
	int i;

	printf("�л������� �Է��ϼ���.\n");

	for (i = len; i < len + 1; i++)
	{
		printf("�̸�: ");
		scanf("%s", std[i].name);
		do {
			printf("�����(0~100�� �Է�): ");
			scanf("%d", &std[i].kor);
			if (std[i].kor < 0 || std[i].kor > 100)
			{
				printf("�Է� ����!! ������ ���Է��ϼ���.\n");
			}
		} while (std[i].kor < 0 || std[i].kor > 100);

		do {
			printf("�����(0~100�� �Է�): ");
			scanf("%d", &std[i].eng);
			if (std[i].eng < 0 || std[i].eng > 100)
			{
				printf("�Է� ����!! ������ ���Է��ϼ���.\n");
			}
		} while (std[i].eng < 0 || std[i].eng > 100);

		do {
			printf("���м���(0~100�� �Է�): ");
			scanf("%d", &std[i].math);
			if (std[i].math < 0 || std[i].math > 100)
			{
				printf("�Է� ����!! ������ ���Է��ϼ���.\n");
			}
		} while (std[i].math < 0 || std[i].math > 100);

		std[i].average = (std[i].kor + std[i].eng + std[i].math) / 3;
	}
	len++;
	printf("\n\n");
	printf("�޴� �Է�('q' �Է½� ����): ");
}

void menu_2() //2. �̸��� ������ �Է� �޾� �ش� �л��� �ش� ���� ������ ���
{
	char name[20];
	char subject[20];
	int i, j;

	printf("�л��̸� �Է�: ");
	scanf("%s", name);
	printf("���� �Է�(kor, eng, math): ");
	scanf("%s", subject);

	for (i = 0; i < len; i++)
	{
		if (!strcmp(name, std[i].name))
		{
			if (!strcmp(subject, "kor"))
			{
				printf("[ %s ]�л��� ���� ���� ����: %d \n", name, std[i].kor);
			}
			else if (!strcmp(subject, "eng"))
			{
				printf("[ %s ]�л��� ���� ���� ����: %d \n", name, std[i].eng);
			}
			else if (!strcmp(subject, "math"))
			{
				printf("[ %s ]�л��� ���� ���� ����: %d \n", name, std[i].math);
			}
		}
	}
	printf("\n\n");
	printf("�޴� �Է�('q' �Է½� ����): ");
}

void menu_3() //3. �Է��� ������ �Է¹޾� ����� ��� ( 3�� �Է��ϸ� ���� ° �л��� ������ ���)
{
	int num;

	printf("[ n ]��° �л� �Է�: ");
	scanf("%d", &num);

	printf("[ %d ]��° �л��̸�:%s  ����:%d  ����:%d  ����:%d  ���:%f \n",
		num, std[num - 1].name, std[num - 1].kor, std[num - 1].eng, std[num - 1].math, std[num - 1].average);
	printf("\n\n");
	printf("�޴� �Է�('q' �Է½� ����): ");
}

void menu_4() //4. �̸��� �Է� ������ ����, ����, ����, ����� ���
{
	char name[20];
	int i;

	printf("�л� �̸� �Է�:");
	scanf("%s", name);

	for (i = 0; i < len; i++)
	{
		if (!strcmp(name, std[i].name))
		{
			printf("[ %s ]�л� -> ����:%d  ����:%d  ����:%d  ���:%f \n", std[i].name, std[i].kor, std[i].eng, std[i].math, std[i].average);
		}
	}
	printf("\n\n");
	printf("�޴� �Է�('q' �Է½� ����): ");
}

void menu_5() //5. �Էµ� �л��� ������� �л� �� ���
{
	printf("�� �Է� �� �л� ��: [ %d ]��\n\n", len);

	printf("�޴� �Է�('q' �Է½� ����): ");
}

void menu_6() //6. ��ü �л��� ��ü ����� ���� ���
{
	int i;

	printf("��ü �л� ���� ���\n");
	for (i = 0; i < len; i++)
	{
		printf("[ %d ]�� �л� �̸�:%s  ����:%d  ����:%d  ����:%d  ���:%f \n",
			i + 1, std[i].name, std[i].kor, std[i].eng, std[i].math, std[i].average);
	}
}

void menu_7() //7. ��ü �л��� ��ü ����� ���� ���������� ���
{
	int i, j;

	for (i = 0; i < len; i++)
	{
		std_dest[i] = std[i];
	}

	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (std[i].average < std[j].average)
			{
				temp = std_dest[j];
				std_dest[j] = std_dest[i];
				std_dest[i] = temp;
			}
		}
	}

	printf("��ü �л� ��� ���\n");
	for (i = 0; i < len; i++)
	{
		printf("[ %d ]�� �̸�:%s  ����:%d  ����:%d  ����:%d  ���:%f \n",
			i + 1, std_dest[i].name, std_dest[i].kor, std_dest[i].eng, std_dest[i].math, std_dest[i].average);
	}

	printf("\n\n");
	printf("�޴� �Է�('q' �Է½� ����): ");
}

void menu_8() //8. ����� �л��� �����͸� �����ϴ� ���
{
	char name[20];
	char subject[20];
	int i, j;

	printf("���� ������ �л� �̸� �Է�:");
	scanf("%s", name);
	printf("������ ����(kor, eng, math �� �Է�):");
	scanf("%s", subject);

	for (i = 0; i < len; i++)
	{
		if (!strcmp(name, std[i].name))
		{
			if (!strcmp(subject, "kor"))
			{
				printf("���� ����:");
				scanf("%d", &std[i].kor);
			}
			if (!strcmp(subject, "eng"))
			{
				printf("���� ����:");
				scanf("%d", &std[i].eng);
			}
			if (!strcmp(subject, "math"))
			{
				printf("���� ����:");
				scanf("%d", &std[i].math);
			}
			std[i].average = (double)(std[i].kor + std[i].eng + std[i].math) / 3; //��� ����
		}
	}
	printf("������ �Ϸ�Ǿ����ϴ�.\n");
	printf("\n\n");
	printf("�޴� �Է�('q' �Է½� ����): ");
}

void menu_9() //9. ������ �л��� �����ϴ� ���
{
	char name[20];
	int i, j;

	printf("������ �л� �̸� �Է�:");
	scanf("%s", name);

	for (i = 0; i < len; i++)
	{
		if (!strcmp(name, std[i].name))
		{
			for (j = i + 1; j < len; j++) {
				std[j] = std[j + 1];
			}
		}
	}
	len--;
	printf("������ �Ϸ�Ǿ����ϴ�.\n");
	printf("\n\n");
	printf("�޴� �Է�('q' �Է½� ����): ");
}


void processMenu(char choice)
{
	switch (choice)
	{
	case '1': //1. ����(�̸�, ����, ����, ����)�� �Է¹޾� ����� ���� ����
		menu_1();
		break;

	case '2': //2. �̸��� ������ �Է� �޾� �ش� �л��� �ش� ���� ������ ���		
		menu_2();
		break;

	case '3': //3. �Է��� ������ �Է¹޾� ����� ��� ( 3�� �Է��ϸ� ���� ° �л��� ������ ���)
		menu_3();
		break;

	case '4': //4. �̸��� �Է� ������ ����, ����, ����, ����� ���
		menu_4();
		break;

	case '5': //5. �Էµ� �л��� ������� �л� �� ���
		menu_5();
		break;

	case '6': //6. ��ü �л��� ��ü ����� ���� ���
		menu_6();
		break;

	case '7': //7. ��ü �л��� ��ü ����� ���� ���������� ���
		menu_7();
		break;

	case '8': //8. ����� �л��� �����͸� �����ϴ� ���
		menu_8();
		break;

	case '9': //9. ������ �л��� �����ϴ� ���
		menu_9();
		break;

	case '0': //10. �ؽ�Ʈ ���Ͽ� ����� �����͸� �о ������ �����ϴ� ���

		break;
	}
}