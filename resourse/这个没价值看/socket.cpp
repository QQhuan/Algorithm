#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <iostream>

int main(){
	double max; //最糟糕的概率 
	double min; //最好情况概率 
	double ave; //平均的袜子数 
	min = 5.0/(5.0*9.0);
	max = 1.0-min;
	ave = 3.0*max+4.0*min;
	printf("最好的情况下概率是%lf\n", max);
	printf("最坏的情况下概率是%lf\n", min);
	printf("平均情况下袜子数是%lf\n", ave);
	getchar(); 
	return 0;
}
