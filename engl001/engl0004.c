#define _CRT_SECURE_NO_WARNINGS
//#define VAR 1

#include<stdlib.h>
#include<stdio.h>
#include"engl0001.h"
#define VAR 4  // 1  2-���������  3- ������ 4- ������ �-�� �����


int n;
/* getline: ������ ������ � s, ���������� ����� */
void getline(char *, int, FILE *);
void delgetline(char *, int, FILE *);

int main(int argc,const char ** argv, const char** env)
{
	system("chcp 1251 > nul");
	//printf("Hello, World!\n");
	//printf("�������, World - ���!\n");
#if VAR==1
	FILE *mfile = fopen("text1.txt", "wt");//
	system("chcp 1251 > nul");
	printf("Hello, World!\n");
	printf("�������, World - ���!\n");

	//�������� ����� ����� ����������������� �������

	if (!mfile) { perror("text1.txt"); exit(1); };
	fputc('*', mfile);
	fputs("\n �������� ����� ����� ����������������� �������\n Hellow ���! \n", mfile);
	fprintf(mfile, "%d\n", 2016);

	fclose(mfile);
#endif

#if VAR==2
	FILE *mfile = fopen("test0003.txt", "wt");//
	if (!mfile) { perror("test0003.txt"); exit(1); };
	system("chcp 1251 > nul");
	// �� �����
	printf("  ~~ �������, World - ���! ~~\n  ~~ �������� ��������� ����� ����������������� �������  ~~\n");

	printf("  ~~ �������� ��������� ��� ���� �������� �����: ~~\n");





	//����� ������� � ����
	fputc('3', mfile);
	fputs("  engl0003.c �������� ��������� ����� ����������������� �������! \n", mfile);
	fputs("\n Hellow ���! \n", mfile);
	fprintf(mfile, "%d\n", 2016);

	fclose(mfile);
#endif

#if VAR==3
	FILE *mfile = fopen("test0005.dat", "wb");//
	if (!mfile) { perror("test0005.dat"); exit(1); };
	FILE *txtfile = fopen("txt1.txt", "rt");//
	if (!txtfile) { perror("txt1.txt"); exit(1); };
	system("chcp 1251 > nul");
	// �� �����
	printf("  ~~ �������, World - ���! ~~\n  ~~ �������� ��������� ����� ����������������� �������  ~~\n");

	printf("  ~~ �������� ������� �������� ��� ���� � ������� �����: ~~\n");


	struct word all[] =
	{
		{ 1,"go","����" },
		{ 2,"one","���" },
		{ 3,"end","�����" },
		{ 4,"help","������" },
		{ 5,"bug","���" },
		{ 6,"or","���" }

	};
	struct word word1[MAX_WORD1]; // ������ ��� ��� ��������� ����

	n = sizeof all / sizeof *all;  //������ �������
	int *nn = &n;
	//����� ������� � ����
	//fwrite(all,sizeof (all),n,mfile);
	fwrite(nn, sizeof(n), 1, mfile);
	//fputc('4', mfile );
	//fputs("  engl0003.c �������� ��������� ����� ����������������� �������! \n",mfile );
	//fputs("\n Hellow ���! \n",mfile );
	//fprintf(mfile, "%d\n", 2016 );

	fclose(mfile);
#endif


#if VAR==4
	FILE *mfile = fopen(argv[2], "wb");// ���� � ������� ��������� ���� ����-  "test0005.dat"
	if (!mfile) { perror(argv[2]); exit(1); };
	FILE *txtfile = fopen(argv[1], "rt"); // ����� ������� ������-  "txt2.txt"
	if (!txtfile) { perror(argv[1]); exit(1); };
//	system("chcp 1251 > nul");
	// �� �����
	printf("  ~~ ����������, World - ���! ~~\n  ~~ �������� ��������� ����� ����������������� �������  ~~\n");
	printf("  ~~ �������� ������� �������� ��� ���� � ������� �����: ~~\n");


	struct word all[] =      // ���� ��� ��� ��������
	{
		{ 1,"go","����" },
		{ 2,"one","���" },
		{ 3,"end","�����" },
		{ 4,"help","������" },
		{ 5,"bug","���" },
		{ 6,"or","���" },
		{ 7,"no","���" }

	};
	struct word word1[MAX_WORD1]; // ������ ��� ��� ��������� ����
	//--------------------------------------------------------------------------------------------

	char word2[MAX_WORD2];  //������-������ ��������-���� �� ������� ������   ��� ����������
	//�� ���� ������ �������� ������ ������� � � ����� ������ ������ ����� ����� \n ������� ������
	system("chcp 866 > nul");  // ��� ����������� "��������" ������ ������: ������=A0
	//getline(word2, MAX_WORD2, txtfile);
	delgetline(word2, MAX_WORD2, txtfile);  //������ ������ (� ��������� ��������)�� ������ ���� �� �����
	printf("%s \n\n", word2);
	//system("chcp 1251 > nul");

	//------------------------------------------------------------------------------------------------
	n = sizeof all / sizeof *all;  //������ �������
	int *nn = &n;
	//����� ������� � ����
	fwrite(all,sizeof *all,n,mfile);
	//fwrite(nn, sizeof(n), 1, mfile);
	//fputc('4', mfile );
	//fputs("  engl0003.c �������� ��������� ����� ����������������� �������! \n",mfile );
	//fputs("\n Hellow ���! \n",mfile );
	//fprintf(mfile, "%d\n", 2016 );

	fclose(mfile);
#endif
	system("pause");
	//return 0;
} //========================================================================== END main
#if VAR==4
  /* getline: ������ ������ � s, ���������� �� ����� � ������ */
void getline(char * s, int lim, FILE * file_)
{
	int ctemp;  // ��� ���� ���� ���� �� �-��
	int c;  // ��� �������� ���� ���� ���� � ������
	int cprev='\n'; // ��� ����� ������ ���� ���� �� �-�� (�������� ���� ������)
	int	i;  // ������� ������� ������ � �����
	int	m=0;  // ������� ��������  ������ � �����
	//char c;

	ctemp = fgetc(file_);
	for (i = 0; i < lim - 1 && ctemp != EOF; ++i)  // && c != '\n' && c != ' '
	{

		//if ((c == '\n') && (c == ' '))
		if ((ctemp == ' ')||(ctemp == '\n'))  // || (cprev != '\r')
		{ 
			if ((cprev == ' ') || (cprev == '\n'))  // || cprev != '\r'			
			{
				cprev = '\n';
			}
			else
			{
				ctemp = '\n';
				s[m++] = (char)'\n';
				cprev = '\n';
			}
		}
		else
		{
			c = ctemp;
			s[m++] = (char)c;
			cprev = ctemp;
		}
		putchar(c);
		ctemp = fgetc(file_);
	}

	if (ctemp == EOF)
	{
		s[m] = '\0';
		return;
	}
}
/* delgetline: �������! ������ ������ � s, ������� ������� ���������� �� ����� � ��������� � ������ */
void delgetline(char * s, int lim, FILE * file_)
{
	int ctemp;  // ��� ���� ���� ���� �� �-��
	int c = '\n';  // ��� �������� ���� ���� ���� � ������
	int cprev = '\n'; // ��� ����� ������ ���� ���� �� �-�� (�������� ���� ������)
	int	i;  // ������� ������� ������ � �����
	int	m = 0;  // ������� ��������  ������ � �����
				//char c;

	ctemp = fgetc(file_);
	//������� ��������� lim �������� � �����
	for (i = 0; i < lim - 1 && ctemp != EOF; ++i)  // && c != '\n' && c != ' '
	{
		if (c == '\n') //����� ���� ��� ��� ������� � ������ ������� �� ����� ������
		{
			if ((ctemp == ' ') || (ctemp == '\n'))  //  � ����� ��������� - ������ ��� ������� = ���������� ������
			{
					// ������ �� ������ � ������
			}
			else   //  � ����� ��������� - �������� ������-����a = �������� ������
			{
				c = ctemp;
				s[m++] = (char)c;
				cprev = ctemp;
			}
		}
		else  //  �����-����� ���� ��� ��� ������� � ������ �������� ������ (������ ������ �������� ��������-����)
		{
			if ((ctemp == ' ') || (ctemp == '\n'))  //  � ����� ��������� - ������ ��� ������� = ����� ����� � ����� ������
			{
				c = ctemp = '\n';  // ���� �� ???
				s[m++] = (char)'\n';
				cprev = '\n';
			}
			else  //  ��������� ��������� -  ���� �������� ������-����a = ���������� ������
			{
				c = ctemp;
				s[m++] = (char)c;
				cprev = ctemp;
			}
		}
		//putchar(c);  // ��� ���������� ������-�������
		ctemp = fgetc(file_); // ������ ���������
	}
	if (ctemp == EOF)
	{
		s[m] = '\0';
		return;
	}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
}
#endif