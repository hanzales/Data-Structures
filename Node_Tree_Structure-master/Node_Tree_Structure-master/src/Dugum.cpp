#include "Dugum.h"
#include <iostream>

using namespace std;


//cift yonlu bagli listenin ilk dugumunu gosterecek
Dugum * kok = new Dugum();



void Dugum::ListeyeEkle(Agac * agac, string DosyaIsmi)
{
	//ilk derlemede olusan kok dugumu null oldugundan liste bos iken kok dugume ekleme yapacagiz
	if (kok == NULL)
	{
		//yeni bir dugum olusturduk
		Dugum * Yeni = new Dugum;
		//olusan dugum ilk dugum oldugundan sonrasi ve oncesi null olmalidir
		Yeni->Sonraki = NULL;
		Yeni->Onceki = NULL;
		//olusturdugumuz dugumun icerisindeki agac parametre olarak gelen agaca esitlendi
		Yeni->eklenecekAgac = agac;
		//ayni sekilde dosya ismide dugumun dosya ismine atandi
		Yeni->DosyaIsmi = DosyaIsmi;
		//olustturdugumuz ve verileri yerlestirdigimiz bu dugum ilk dugum olan koke atandý
		//kok artýk null degil bir sonraki dugum eklemede bu if blogunu es gececektir.
		kok = Yeni;
	}
	else {
		//dugumde en az bir tane dugum ve icerisinde eleman oldugundan artýk bu else blogu islemleri uygulanacak

		//kok bizim icin degerli oldugundan gecici adinda degisken olusturup kokun adresini ona atadik (kopyaladik)
		Dugum * gecici = kok;

		//eklenecek dugumu bulana kadar olusan gecici dugumu ilerleyecek ve eklenmesi gereken yeri isaret edecek
		while (gecici->Sonraki != NULL)
		{
			gecici = gecici->Sonraki;
		}

		//yukarda yapilan islemleri tekrarladik
		Dugum * Yeni = new Dugum;
		Yeni->Sonraki = NULL;
		Yeni->eklenecekAgac = agac;
		Yeni->DosyaIsmi = DosyaIsmi;
		gecici->Sonraki = Yeni;
		//ek olarak bu kisimda eklenecek dugumun onceki dugumu eklenmeden onceki son dugumu isaret etmektedir.
		Yeni->Onceki = gecici;

	}
}

Dugum * d1 = kok;
void Dugum::ListeYazdir()
{
	//kok degeri bos ise liste bos demektir donguden cikiyor
	if (d1 == NULL)
		return;

	while (d1 != NULL)
	{
		//dosya ismini yazdiracak
		cout << d1->DosyaIsmi << endl;
		//dugumdeki agac uzerinden AgacYaz fonksiyonunu cagirdik orda yazdirilacak
		d1->eklenecekAgac->AgacYaz(d1->eklenecekAgac);
		cout << endl;
		//bir sonraki dugum içerisindeki agaci yazdirmak icin d1 degiskeni d1'in sonraki dugumune esitlendi
		d1 = d1->Sonraki;
	}
	//d1 nesnesinin adresini yeniden en listenin ilk dugumune esitledik
	//bir daha ki bu fonksiyonu cagirista bastan baslasin diye
	d1 = kok;
}
Dugum * d2 = kok;

void Dugum::ListedeAra(string aranacak)
{
	while (d2 != NULL)
	{
		d2->eklenecekAgac->AgactaAra(d2->eklenecekAgac, aranacak, d2->DosyaIsmi);
		d2 = d2->Sonraki;
	}
	d2 = kok;
}
