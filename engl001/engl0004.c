#define _CRT_SECURE_NO_WARNINGS
//#define VAR 1

#include<stdlib.h>
#include<stdio.h>
#include"engl0001.h"
#define VAR 4  // 1  2-текстовый  3- бинарн 4- разбор ф-ла постр


int n;
/* getline: читает строку в s, возвращает длину */
void getline(char *, int, FILE *);
void delgetline(char *, int, FILE *);

int main(int argc,const char ** argv, const char** env)
{
	system("chcp 1251 > nul");
	//printf("Hello, World!\n");
	//printf("Здорово, World - Мир!\n");
#if VAR==1
	FILE *mfile = fopen("text1.txt", "wt");//
	system("chcp 1251 > nul");
	printf("Hello, World!\n");
	printf("Здорово, World - Мир!\n");

	//создание текст файла последовательного доступа

	if (!mfile) { perror("text1.txt"); exit(1); };
	fputc('*', mfile);
	fputs("\n создание текст файла последовательного доступа\n Hellow МИР! \n", mfile);
	fprintf(mfile, "%d\n", 2016);

	fclose(mfile);
#endif

#if VAR==2
	FILE *mfile = fopen("test0003.txt", "wt");//
	if (!mfile) { perror("test0003.txt"); exit(1); };
	system("chcp 1251 > nul");
	// на экран
	printf("  ~~ Здорово, World - Мир! ~~\n  ~~ Создание бинарного файла последовательного доступа  ~~\n");

	printf("  ~~ Создание структуры для слов ивыводна экран: ~~\n");





	//далее заносим в файл
	fputc('3', mfile);
	fputs("  engl0003.c создание бинарного файла последовательного доступа! \n", mfile);
	fputs("\n Hellow МИР! \n", mfile);
	fprintf(mfile, "%d\n", 2016);

	fclose(mfile);
#endif

#if VAR==3
	FILE *mfile = fopen("test0005.dat", "wb");//
	if (!mfile) { perror("test0005.dat"); exit(1); };
	FILE *txtfile = fopen("txt1.txt", "rt");//
	if (!txtfile) { perror("txt1.txt"); exit(1); };
	system("chcp 1251 > nul");
	// на экран
	printf("  ~~ Здорово, World - Мир! ~~\n  ~~ Создание бинарного файла последовательного доступа  ~~\n");

	printf("  ~~ Создание массива структур для слов и выводна экран: ~~\n");


	struct word all[] =
	{
		{ 1,"go","идти" },
		{ 2,"one","раз" },
		{ 3,"end","также" },
		{ 4,"help","помощь" },
		{ 5,"bug","жук" },
		{ 6,"or","или" }

	};
	struct word word1[MAX_WORD1]; // массив СТР ДЛЯ СЧИТАННЫХ СЛОВ

	n = sizeof all / sizeof *all;  //размер массива
	int *nn = &n;
	//далее заносим в файл
	//fwrite(all,sizeof (all),n,mfile);
	fwrite(nn, sizeof(n), 1, mfile);
	//fputc('4', mfile );
	//fputs("  engl0003.c создание бинарного файла последовательного доступа! \n",mfile );
	//fputs("\n Hellow МИР! \n",mfile );
	//fprintf(mfile, "%d\n", 2016 );

	fclose(mfile);
#endif


#if VAR==4
	FILE *mfile = fopen(argv[2], "wb");// файл в котором сохранять базу слов-  "test0005.dat"
	if (!mfile) { perror(argv[2]); exit(1); };
	FILE *txtfile = fopen(argv[1], "rt"); // текст который читать-  "txt2.txt"
	if (!txtfile) { perror(argv[1]); exit(1); };
//	system("chcp 1251 > nul");
	// на экран
	printf("  ~~ Здоровоооо, World - Мир! ~~\n  ~~ Создание бинарного файла последовательного доступа  ~~\n");
	printf("  ~~ Создание массива структур для слов и выводна экран: ~~\n");


	struct word all[] =      // темп стр для проверки
	{
		{ 1,"go","идти" },
		{ 2,"one","раз" },
		{ 3,"end","также" },
		{ 4,"help","помощь" },
		{ 5,"bug","жук" },
		{ 6,"or","или" },
		{ 7,"no","нет" }

	};
	struct word word1[MAX_WORD1]; // массив СТР ДЛЯ СЧИТАННЫХ СЛОВ
	//--------------------------------------------------------------------------------------------

	char word2[MAX_WORD2];  //массив-строка символов-букв из разбора текста   при заполнении
	//из него должны выкинуты пустые символы и в новой строке каждое слово через \n перевод строки
	system("chcp 866 > nul");  // для правильного "парсинга" текста наприм: пробел=A0
	//getline(word2, MAX_WORD2, txtfile);
	delgetline(word2, MAX_WORD2, txtfile);  //разбор текста (с удалением пробелов)на строку слов по слову
	printf("%s \n\n", word2);
	//system("chcp 1251 > nul");

	//------------------------------------------------------------------------------------------------
	n = sizeof all / sizeof *all;  //размер массива
	int *nn = &n;
	//далее заносим в файл
	fwrite(all,sizeof *all,n,mfile);
	//fwrite(nn, sizeof(n), 1, mfile);
	//fputc('4', mfile );
	//fputs("  engl0003.c создание бинарного файла последовательного доступа! \n",mfile );
	//fputs("\n Hellow МИР! \n",mfile );
	//fprintf(mfile, "%d\n", 2016 );

	fclose(mfile);
#endif
	system("pause");
	//return 0;
} //========================================================================== END main
#if VAR==4
  /* getline: читает строку в s, возвращает по слову в строке */
void getline(char * s, int lim, FILE * file_)
{
	int ctemp;  // для счит кода симв из ф-ла
	int c;  // для передачи счит кода симв в массив
	int cprev='\n'; // для запом предыд кода симв из ф-ла (удаления пуст строки)
	int	i;  // счётчик позиций знаков в файле
	int	m=0;  // счётчик индексов  знаков в файле
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
/* delgetline: РАБОЧАЯ! читает строку в s, удаляет пробелы возвращает по слову с переносом в строке */
void delgetline(char * s, int lim, FILE * file_)
{
	int ctemp;  // для счит кода симв из ф-ла
	int c = '\n';  // для передачи счит кода симв в массив
	int cprev = '\n'; // для запом предыд кода симв из ф-ла (удаления пуст строки)
	int	i;  // счётчик позиций знаков в файле
	int	m = 0;  // счётчик индексов  знаков в файле
				//char c;

	ctemp = fgetc(file_);
	//перебор кличества lim символов в файле
	for (i = 0; i < lim - 1 && ctemp != EOF; ++i)  // && c != '\n' && c != ' '
	{
		if (c == '\n') //после того как был записан в массив переход на новую строку
		{
			if ((ctemp == ' ') || (ctemp == '\n'))  //  и новый считанный - пробел или переход = пропускать печать
			{
					// ничего не вводим в массив
			}
			else   //  и новый считанный - печатный символ-буквa = начинать печать
			{
				c = ctemp;
				s[m++] = (char)c;
				cprev = ctemp;
			}
		}
		else  //  иначе-после того как был записан в массив печатный символ (начата строка печатных символов-букв)
		{
			if ((ctemp == ' ') || (ctemp == '\n'))  //  и новый считанный - пробел или переход = конец слова и новая строка
			{
				c = ctemp = '\n';  // надо ли ???
				s[m++] = (char)'\n';
				cprev = '\n';
			}
			else  //  очередной считанный -  тоже печатный символ-буквa = продолжать печать
			{
				c = ctemp;
				s[m++] = (char)c;
				cprev = ctemp;
			}
		}
		//putchar(c);  // для моментальн вывода-отладки
		ctemp = fgetc(file_); // читаем следующий
	}
	if (ctemp == EOF)
	{
		s[m] = '\0';
		return;
	}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
}
#endif