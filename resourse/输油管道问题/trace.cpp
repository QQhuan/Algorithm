#include <iostream> 
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
//文件操作 
#include <fstream> 

using namespace std;

//求y方向上的距离和|y-yi| 
int all(int a[], int mid, int len){
	int num = 0;
	for(int i = 0;i < len;i++){
		num += abs(a[i]-a[mid]);
	}
	return num;
}
int main(){
	int data[1000];
	int n;
	vector<string> v;
	string tmp;
	ifstream inFile;
	string f = "input.txt"; 
	inFile.open(f.c_str(), ios::in);  //打开文件读取 
	while(inFile >> tmp){
		v.push_back(tmp);
	}
	inFile.close();
	for(int i = 0;i < v.size();i++){   //string转化为int放入data中 
		data[i] = atoi(v[i].c_str() );
	}
	n = data[0];
	
 	int len = v.size();
	int a[n], b[n], a1 = 0, b1 = 0;
	//y坐标放入b数组 
	for(int i = 2; i < len;i+=2){
		b[b1++] = data[i];  
	}
	//默认升序排序 
	sort(b, b+b1);
	int index = n/2;  
	int instanceB = all(b, index, n);
	cout << "最短距离是：" << instanceB << endl;
	ofstream outFile;
	outFile.open("output.txt", ios::out | ios::trunc);
	outFile << instanceB << endl;
	outFile.close();
	return 0; 
} 
