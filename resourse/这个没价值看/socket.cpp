#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <iostream>

int main(){
	double max; //�����ĸ��� 
	double min; //���������� 
	double ave; //ƽ���������� 
	min = 5.0/(5.0*9.0);
	max = 1.0-min;
	ave = 3.0*max+4.0*min;
	printf("��õ�����¸�����%lf\n", max);
	printf("�������¸�����%lf\n", min);
	printf("ƽ���������������%lf\n", ave);
	getchar(); 
	return 0;
}
