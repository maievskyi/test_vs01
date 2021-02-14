#define _CRT_SECURE_NO_WARNINGS
//#define VAR 1

#include<stdlib.h>
#include<stdio.h>
#include"engl0001.h"
#define VAR 4  // 1  2-текстовый  3- бинарн 4- разбор ф-ла постр


int n;
/* getline: читает строку в s, возвращает длину */
void getline( char * , int, FILE * );

int main()
{
//system("chcp 1251 > nul");
//printf("Hello, World!\n");
//printf("Здорово, World - Мир!\n");
#if VAR==1
FILE *mfile = fopen("text1.txt","wt");//
system("chcp 1251 > nul");
printf("Hello, World!\n");
printf("Здорово, World - Мир!\n");

//создание текст файла последовательного доступа

if (!mfile) {perror("text1.txt"  ); exit(1); };
fputc('*', mfile );
fputs("\n создание текст файла последовательного доступа\n Hellow МИР! \n",mfile );
fprintf(mfile, "%d\n", 2016 );

fclose(mfile);
#endif

#if VAR==2
FILE *mfile = fopen("test0003.txt","wt");//
if (!mfile) {perror("test0003.txt"  ); exit(1); };
system("chcp 1251 > nul");
// на экран
printf("  ~~ Здорово, World - Мир! ~~\n  ~~ Создание бинарного файла последовательного доступа  ~~\n");

printf("  ~~ Создание структуры для слов ивыводна экран: ~~\n");





//далее заносим в файл
fputc('3', mfile );
fputs("  engl0003.c создание бинарного файла последовательного доступа! \n",mfile );
fputs("\n Hellow МИР! \n",mfile );
fprintf(mfile, "%d\n", 2016 );

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
FILE *mfile = fopen("test0005.dat","wb");//
if (!mfile) {perror("test0005.dat"  ); exit(1); };
FILE *txtfile = fopen("txt2.txt", "rt");//
if (!txtfile) { perror("txt2.txt"); exit(1); };
system("chcp 1251 > nul");
// на экран
printf("  ~~ Здорово, World - Мир! ~~\n  ~~ Создание бинарного файла последовательного доступа  ~~\n");

printf("  ~~ Создание массива структур для слов и выводна экран: ~~\n");


struct word all[]=
{
	{1,"go","идти" },
	{2,"one","раз" },
	{3,"end","также" },
	{4,"help","помощь" },
	{5,"bug","жук" },
	{6,"or","или" }
	
};	
struct word word1[MAX_WORD1]; // массив СТР ДЛЯ СЧИТАННЫХ СЛОВ
char word2[MAX_WORD2];  //массив дря разбора текста
getline(word2, MAX_WORD2, txtfile);
printf("\n\n%s \n\n", word2);
n = sizeof all / sizeof *all ;  //размер массива
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
system("pause");
    //return 0;
} //========================================================================== END main
#if VAR==4
/* getline: читает строку в s, возвращает по слову в строке */
void getline(char * s, int lim, FILE * file_)
{
	int c, i;
	//char c;

	c = fgetc(file_);
	for (i = 0; i < lim - 1 && c != EOF ; ++i)  // && c != '\n' && c != ' '
	{
		
		//if ((c == '\n') && (c == ' '))
		if (c == ' ')
		{
			s[i] = (char)'\n';
		}
		else s[i] = c;
		c = fgetc(file_);
	}
	/*if (c == '\n') {
		s[i] = c;
		++i;
	}*/
	
	if (c == EOF)
	{
		s[i] = '\0';
		return ;
	}
}
#endif