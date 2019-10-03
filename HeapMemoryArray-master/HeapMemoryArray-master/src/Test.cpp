#include <iostream>
#include"Top.hpp"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include<fstream>
#include<string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
/**
* @assignment 2.Ödev
* @date 10.07.2018
* @number B151210308 / B141210092
* @author ÝLHAN EMÝR(b151210308@sakarya.edu.tr) ve BÜÞRANUR KOÇ (B141210092@sakarya.edu.tr)
*/

using namespace std;
   
	int main(int argc, char** argv) {
	int elemansayisi;
	std::cout<<"Dizi Boyutu:";
	cin>>elemansayisi;
	int *Elemanlar = new int[elemansayisi];	
	Top t;
	int *p= Elemanlar;
		int secim;
		do{
		std::cout<<"1. Diziyi Yazdir\n";
		std::cout<<"2. Yer Degistir\n";
		std::cout<<"3. Cikis\n";
		std::cout<<">>";
		cin>>secim;
		
		delete[] Elemanlar;
		
		switch(secim){
			case 1: {
			t.yazdir(Elemanlar,&elemansayisi,p);
		 	break;
	  }
			case 2: {
		 	t.terscevir(Elemanlar,&elemansayisi,p);
			break;
	  }
			case 3:{
			exit(0);
			break;
	  }
	 default: 
	  {
		
			break;
	  }
	
		}

	}
	while(secim!=3);
	return 0;
}

