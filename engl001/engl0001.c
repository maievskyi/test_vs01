//int main()
//{
//	printf("hellow world!\n");
//}
#define _CRT_SECURE_NO_WARNINGS
//#define VAR 1

#include<stdlib.h>
#include<stdio.h>
#include"engl0001.h"
#define VAR 2

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

#if VAR==2;
FILE *mfile = fopen("test0002.txt","wt");//
if (!mfile) {perror("test0002.txt"  ); exit(1); };
system("chcp 1251 > nul");
// на экран
printf("Здорово, World - Мир!\n создание бинарного файла последовательного доступа\n");

//в файл
fputc('2', mfile );
fputs("  engl0001.c создание бинарного файла последовательного доступа! \n",mfile );
fputs("\n Hellow МИР! \n",mfile );
fprintf(mfile, "%d\n", 2016 );

fclose(mfile);
#endif
system("pause");
    //return 0;
}