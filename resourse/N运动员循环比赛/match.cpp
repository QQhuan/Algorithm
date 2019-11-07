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
	cout << "请输入远动员的数量N:" << endl; 
    cin >> n;   
    tournament(n); 
	cout << "赛程安排如下：" << endl;  
    if(odd(n))   // n为奇数和偶数输出情况不同，要分别考虑   
    {   //奇数情况 
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
    else  //偶数情况 
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
  * copy 将左上角递归计算出的小块中的所有数字按其相对位置抄到右下角，将  
  右上角小块中的所有数字加n/2后按其相对位置抄到左下角，将左下角小块中的  
  所有数字按其相对位置抄到右上角 *  
  **/  
void copy(int n)       
{   
    int m = n/2;   
    for(int i = 1; i<=m; i++)   
        for(int j = 1; j<=m; j++)   
        {   
            a[i][j+m] = a[i][j] + m;   //根据左上角生成右上角 
            a[i+m][j] = a[i][j+m];     //将右上角复制到左下角 
            a[i+m][j+m] = a[i][j];     //将左上角复制到右下角 
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
    	//奇数，pa 
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
  
void makecopy(int n)  //makecopy 与copy算法类似，但是要区分n/2为奇数或偶数的情形   
{   
    if(n/2 > 1 && odd(n/2))    
        copyodd(n);   
    else  
        copy(n);   
}   
  
void copyodd(int n)        // 实现n/2为奇数时的复制   
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
