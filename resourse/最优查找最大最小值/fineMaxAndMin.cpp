#include <cstdio>
#include <cmath>
#include <iostream>
#include "limits.h"
using namespace std;
int main(){
	int a[8] = {1, 9, 55, 31, 65, 41, 12, 33};
	int max = INT_MIN;  //最大值设为最小 
	int min = INT_MAX;  //最小值设为最大 
	int n = 8;          //数组长度 
	bool flag = false;	 
	if(n % 2){
		n--;
		flag = true;
	}
	
	//两两组合，较小的一个跟min作比较，较大的一个跟max作比较 
	//比较次数为3*n/2 
	 
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
	
	//最后那个单独的元素作比较 
	 
	if(flag){
		min = a[n]<min?a[n]:min;
		max = a[n]>max?a[n]:max;
	}
	
	cout << "最小值为" << min << endl;
	cout << "最大值为" << max << endl; 
	getchar();
	return 0;
} 
