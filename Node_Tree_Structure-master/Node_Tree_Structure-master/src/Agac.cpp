#include "Agac.h"
#include <iostream>




void Agac::AgacEkle(string eklenecek, Agac * agac)
{
	Agac * eklenecekAgac = new Agac();
	//eger agac null ise ekleme ilk ekleme islemi gerceklesecek
	if (agac == NULL)
	{
		eklenecekAgac->kelime = eklenecek;
		eklenecekAgac->psol = NULL;
		eklenecekAgac->psag = NULL;
		agac = eklenecekAgac;

	}
	//agacta kelime var isede agactaki deger ile eklenecek degeri karsilastirip saga ya da sola ekleme yapiyoruz
	else if (kelime.compare(eklenecek) > 0) {
		//yaprak dugume ulasana kadar fonksiyonu yeniden cagiriyoruz
		if (psol != NULL)
			return psol->AgacEkle(eklenecek, psol);

		eklenecekAgac->kelime = eklenecek;
		eklenecekAgac->psol = NULL;
		eklenecekAgac->psag = NULL;
		psol = eklenecekAgac;

	}
	//saga ekleme islemi
	else if (kelime.compare(eklenecek) < 0) {
		//yaprak dugume ulasana kadar fonksiyonu yeniden cagiriyoruz
		if (psag != NULL)
			return psag->AgacEkle(eklenecek, psag);

		eklenecekAgac->kelime = eklenecek;
		eklenecekAgac->psol = NULL;
		eklenecekAgac->psag = NULL;
		psag = eklenecekAgac;

	}
}

void Agac::AgactaAra(Agac * aranacak, string aranan,string dosyaIsmi)
{
	//agac bos ise fonksiyon sonlanacak
	if (aranacak == NULL)
	{
		return;
	}
	else {
		//yaprak dugume kadar arama yapilacak 
		if (aranacak->psol != NULL && aranacak->kelime != aranan) 	
				return AgactaAra(aranacak->psol, aranan, dosyaIsmi);
			
		//yaprak dugume kadar arama yapilacak 
		if (aranacak->psag != NULL && aranacak->kelime != aranan) 
			return AgactaAra(aranacak->psag, aranan, dosyaIsmi);

	}
	//yaprak dugume kadar ulasip Null degerini almamýs ise ve kelime bulunuyorsa bu if bloguna girip
	//dosya ismini yazacaktir.
	if (aranacak->kelime == aranan)
	{
		cout << dosyaIsmi << " icerisinde bulunmustur" << endl;
	}
}

void Agac::AgacYaz(Agac * agac)
{
	//agac bos ise hata mesajý verip fonksiyon son bulacak
	if (agac == NULL)
	{
		return;
	}
	//agacta veriler var ise in-order sira ile yazdiracak
	AgacYaz(agac->psol);
	cout << agac->kelime << " ";
	AgacYaz(agac->psag);


}

