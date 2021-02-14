//вторая фиксация в локальный репоз
//первая фиксация в локальный репоз
//
//
#ifndef ENGL0001_H
#define ENGL0001_H
#define EN 8 //размер англ текста в структ word
#define RU 8 //размер рус текста в структ word
#define MAX_WORD 4 //размер массива структ word
#define MAX_WORD1 100 //размер массива структ word
#define MAX_WORD2 10000 //размер массива  word2
struct word       // стр для хранения слов с переводом и др.
{
	int id;
	char en[EN];
	char ru[RU];
};
#endif