#pragma once
#include "Agac.h"
using namespace std;
class Dugum
{
public:

	Dugum * Sonraki;
	Dugum * Onceki;
	string DosyaIsmi;
	Agac * eklenecekAgac;
	void ListeyeEkle(Agac * agac,string DosyaIsmi);
	void ListeYazdir();
	void ListedeAra(string aranacak);
};

