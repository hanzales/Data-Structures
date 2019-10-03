#pragma once
#include <string>
using namespace std;
class Agac
{
public:

	Agac * psol;
	Agac * psag;
	string kelime;
	void AgacEkle(string eklenecek, Agac * agac);
	void AgactaAra(Agac* aranacak, string aranan, string dosyaIsmi);
	void AgacYaz(Agac * agac);
};

