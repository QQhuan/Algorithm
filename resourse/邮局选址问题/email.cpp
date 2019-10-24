#include <iostream> 
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
//�ļ����� 
#include <fstream> 

using namespace std;

//��x, y�����ϵľ����, |x-xi|+|y-yi| 
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
	inFile.open(f.c_str(), ios::in);  //���ļ���ȡ 
	while(inFile >> tmp){
		v.push_back(tmp);
	}
	inFile.close();
	for(int i = 0;i < v.size();i++){   //stringת��Ϊint����data�� 
		data[i] = atoi(v[i].c_str() );
	}
	n = data[0];
	
 	int len = v.size();
	int a[n], b[n], a1 = 0, b1 = 0;
	
	//x�������a���� 
	for(int i = 1; i < len;i+=2){
		a[a1++] = data[i];  
	}
	//y�������b���� 
	for(int i = 2; i < len;i+=2){
		b[b1++] = data[i];  
	}
	//Ĭ���������� 
	sort(a, a+a1);
	sort(b, b+b1);
	int index = n/2;  
	int instanceA = all(a, index, n);
	int instanceB = all(b, index, n);
	cout << "��̾����ǣ�" << instanceA+instanceB << endl;
	ofstream outFile;
	outFile.open("output.txt", ios::out | ios::trunc);
	outFile << instanceA+instanceB << endl;
	outFile.close();
	return 0; 
} 
