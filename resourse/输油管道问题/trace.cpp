#include <iostream> 
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
//�ļ����� 
#include <fstream> 

using namespace std;

//��y�����ϵľ����|y-yi| 
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
	//y�������b���� 
	for(int i = 2; i < len;i+=2){
		b[b1++] = data[i];  
	}
	//Ĭ���������� 
	sort(b, b+b1);
	int index = n/2;  
	int instanceB = all(b, index, n);
	cout << "��̾����ǣ�" << instanceB << endl;
	ofstream outFile;
	outFile.open("output.txt", ios::out | ios::trunc);
	outFile << instanceB << endl;
	outFile.close();
	return 0; 
} 
