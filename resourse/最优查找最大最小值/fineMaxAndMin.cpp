#include <cstdio>
#include <cmath>
#include <iostream>
#include "limits.h"
using namespace std;
int main(){
	int a[8] = {1, 9, 55, 31, 65, 41, 12, 33};
	int max = INT_MIN;  //���ֵ��Ϊ��С 
	int min = INT_MAX;  //��Сֵ��Ϊ��� 
	int n = 8;          //���鳤�� 
	bool flag = false;	 
	if(n % 2){
		n--;
		flag = true;
	}
	
	//������ϣ���С��һ����min���Ƚϣ��ϴ��һ����max���Ƚ� 
	//�Ƚϴ���Ϊ3*n/2 
	 
	for(int i = 0;i < n-1; i+=2){
		if(a[i] < a[i+1]){
			min = a[i]<min?a[i]:min;
			max = a[i+1]>max?a[i+1]:max; 
		}
		else{
			min = a[i+1]<min?a[i+1]:min;
			max = a[i]>max?a[i]:max;
		}
	}
	
	//����Ǹ�������Ԫ�����Ƚ� 
	 
	if(flag){
		min = a[n]<min?a[n]:min;
		max = a[n]>max?a[n]:max;
	}
	
	cout << "��СֵΪ" << min << endl;
	cout << "���ֵΪ" << max << endl; 
	getchar();
	return 0;
} 
