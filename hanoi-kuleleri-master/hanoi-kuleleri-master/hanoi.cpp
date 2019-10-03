#include<iostream>

using namespace std;
int count=0;

void hanoi(char a,char b,char c,int x)
{
  if(x>1)
  {
    hanoi(a,c,b,x-1);
    hanoi(a,b,c,1);
    hanoi(c,b,a,x-1);
  }
  else
  {
    cout<<"Disket "<<a<<" den "<<b<<endl; count++;  
  }
}

int main()
{
  int n;
  cout<<"Disk sayisini giriniz ";
  cin>>n;
  hanoi('A','B','C',n);
  cout<<"\n Yapilan toplam islem sayisi :"<<count;

  return 0;
}
