//������ �������� � ��������� �����
//������ �������� � ��������� �����
//
//
#ifndef ENGL0001_H
#define ENGL0001_H
#define EN 8 //������ ���� ������ � ������ word
#define RU 8 //������ ��� ������ � ������ word
#define MAX_WORD 4 //������ ������� ������ word
#define MAX_WORD1 100 //������ ������� ������ word
#define MAX_WORD2 10000 //������ �������  word2
struct word       // ��� ��� �������� ���� � ��������� � ��.
{
	int id;
	char en[EN];
	char ru[RU];
};
#endif