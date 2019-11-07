#include<iostream>   
using namespace std;   
  
const int SIZE = 100;   
int a[SIZE][SIZE];   
  
void copy(int n);   
void tournament(int n);   
bool odd(int n);   
void makecopy(int n);   
void copyodd(int n);   
  
int main()   
{   
  
    int n;   
    int i,j;  
	cout << "������Զ��Ա������N:" << endl; 
    cin >> n;   
    tournament(n); 
	cout << "���̰������£�" << endl;  
    if(odd(n))   // nΪ������ż����������ͬ��Ҫ�ֱ���   
    {   //������� 
        for(i = 1; i<=n; i++)   
        {   
            for(j = 1; j<=n+1; j++)   
                if(a[i][j] == n+1)   
                    cout << "0  ";   
                else  
                    cout << a[i][j] << "  " ;   
            cout << endl;   
        }   
    }   
    else  //ż����� 
    {   
        for(i = 1; i<=n; i++)   
        {   
            for(j = 1; j<=n; j++)   
                cout << a[i][j] << "  " ;   
            cout << endl;   
        }   
  
    }   
    getchar(); 
    return 0;   
}   
/**  
  * copy �����Ͻǵݹ�������С���е��������ְ������λ�ó������½ǣ���  
  ���Ͻ�С���е��������ּ�n/2�������λ�ó������½ǣ������½�С���е�  
  �������ְ������λ�ó������Ͻ� *  
  **/  
void copy(int n)       
{   
    int m = n/2;   
    for(int i = 1; i<=m; i++)   
        for(int j = 1; j<=m; j++)   
        {   
            a[i][j+m] = a[i][j] + m;   //�������Ͻ��������Ͻ� 
            a[i+m][j] = a[i][j+m];     //�����ϽǸ��Ƶ����½� 
            a[i+m][j+m] = a[i][j];     //�����ϽǸ��Ƶ����½� 
        }   
}   
  
void tournament(int n)   
{   
    if(n == 1)   
    {   
        a[1][1] = 1;   
        return;   
    }   
    if(odd(n))   
    {   
    	//������pa 
        tournament(n+1);   
        return;   
    }   
    tournament(n/2);   
    makecopy(n);   
}   
  
bool odd(int n)   
{   
    return n & 1;   
}   
  
void makecopy(int n)  //makecopy ��copy�㷨���ƣ�����Ҫ����n/2Ϊ������ż��������   
{   
    if(n/2 > 1 && odd(n/2))    
        copyodd(n);   
    else  
        copy(n);   
}   
  
void copyodd(int n)        // ʵ��n/2Ϊ����ʱ�ĸ���   
{   
    int b[SIZE];   
    int m = n/2;   
    for(int i = 1; i<=m; i++)   
    {   
        b[i] = m+i;        
        b[m+i] = b[i];      
    }   
    for(int i = 1; i<=m; i++)       
    {   
        for(int j=1; j<=m+1; j++)   
        {   
            if(a[i][j] > m)   
            {   
                a[i][j] = b[i];    
                a[m+i][j] = (b[i] + m)%n;   
            }   
            else  
                a[m+i][j] = a[i][j] + m;   
        }   
        for(int j = 2; j<=m; j++)   
        {   
            a[i][m+j] = b[i+j-1];   
            a[b[i+j-1]][m+j] = i;   
        }   
    }   
}  
