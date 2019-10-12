#include <cstdio>
#include <iostream>
#include <malloc.h>

#define n 10
using namespace  std;
int main(){
	bool hole[n] = {false};
	int add = 0, num = 0;
	for(int i = 0;i < n;i++)
		hole[i] = false; 
	for(int i = 0;i < 1000;i++){
		num = (num+1+i)%n;
		if(0 == num) num = n;
		hole[num-1] = true;
	}
	for(int i = 0;i < n;i++){
		if(false == hole[i]){
			cout << "��Ѩ " << i+1 << " ��ȫ" << endl; 
		}
	}
	getchar();
	return 0;
} 
