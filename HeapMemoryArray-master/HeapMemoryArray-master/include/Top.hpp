#ifndef Top_hpp
#define Top_hpp
#include<fstream>
#include<string>
#include<iostream>
#include <cstring>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

/**
* @assignment 2.Ödev
* @date 10.07.2018
* @number B151210308 / B141210092
* @author ÝLHAN EMÝR(b151210308@sakarya.edu.tr) ve BÜÞRANUR KOÇ (B141210092@sakarya.edu.tr)
*/


using namespace std;
class Top{
	
	public:
	void yazdir(int dizi[],int *uzunluk,int *p)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		std::cout<<"Liste elemanlari:"<<std::endl;;
		for(int i=0;i<*uzunluk+1;i++)
			{
			SetConsoleTextAttribute(hConsole,i);
        	std::cout<<"["<<i<<"]"<<" - "<<(p+i)<<std::endl;;
			}
		SetConsoleTextAttribute(hConsole, 7);
		std::cout<<"Yazdirma islemi tamamlandi."<<std::endl;;
	}
	
	void swap(int *a, int *b)
	{
		int t; 
		t = *a; 
		*a = *b; 
		*b = t; 
	}
	void terscevir(int dizi[],int *uzunluk,int *p)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		int *temp1, *temp2, *gecici;
		int *yedekp;
		int birinciindis, ikinciindis;
		
		std::cout<<"1. indisi giriniz : ";
		cin>>birinciindis;
		std::cout<<"2. indisi giriniz : ";
		cin>>ikinciindis;
		temp1 = p + birinciindis;
		temp2 = p + ikinciindis;
				
		gecici = temp1;
		temp1 = temp2;
		temp2 = gecici;
		
		for(int i=0;i< *uzunluk+1;i++)
		{
			if( i != birinciindis && i != ikinciindis)
			{
				yedekp = p+i;
				SetConsoleTextAttribute(hConsole, i);
				std::cout<<std::endl<<"["<<i<<"]"<<" - "<<yedekp;
			}
			else if(i == birinciindis)
			{
				yedekp = temp1;
				SetConsoleTextAttribute(hConsole, i);
				std::cout<<std::endl<<"["<<i<<"]"<<" - "<<temp1;
			}
			else if(i == ikinciindis)
			{
				SetConsoleTextAttribute(hConsole, i);
				std::cout<<std::endl<<"["<<i<<"]"<<" - "<<temp2<<std::endl;;
			}
			
			SetConsoleTextAttribute(hConsole, 7);
		}
		std::cout<<std::endl<<"indislerin adres bilgileri degisti."<<std::endl;;
	}
	
};

#endif
