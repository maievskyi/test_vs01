//int main()
//{
//	printf("hellow world!\n");
//}
#define _CRT_SECURE_NO_WARNINGS
#define VAR 1

#include<stdlib.h>
#include<stdio.h>
#include"engl0001.h"
#define VAR 1

int main()
{
#if VAR==1
FILE *mfile = fopen("test0002.txt","wt");//
system("chcp 1251 > nul");
printf("Hello, World!\n");
printf("Здорово, World - Мир!\n");

//
//создание бинарного файла последовательного доступа

if (!mfile) {perror("test0002.txt"  ); exit(1); };
fputc('2', mfile );
fputs("  0002 создание бинарного файла последовательного доступа! \n",mfile );
fputs("\n Hellow МИР! \n",mfile );
fprintf(mfile, "%d\n", 2016 );

fclose(mfile);
#endif

system("pause");
    //return 0;
}