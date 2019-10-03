
#include "Dugum.h"
#include<dirent.h>
#include<iostream>
#include<string>
#include<fstream>

//dizinIslem methodu protatip tanimlama
bool DizinIslem();

using namespace std;

int main()
{
	Dugum * liste = new Dugum;
	//girilen yol hatali ise program kapanacak
	if (!DizinIslem())
		return 0;

	while (true)
	{
		system("cls");
		int cevap = 0;
		cout << "1-Arama Yap" << endl;
		cout << "2-Listele" << endl;
		cout << "3-Cikis" << endl;
		cout << ">";
		cin >> cevap;

		if (cevap == 1)
		{
			string aranan;
			cout << endl << "Aramak istediginiz kelime = ";
			cin >> aranan;
			cout << endl;
			liste->ListedeAra(aranan);
			cout << endl;
			system("pause");
		}
		else if (cevap == 2)
		{
			cout << endl;
			liste->ListeYazdir();
			system("pause");

		}
		else {
			return 0;
		}
	}

}


bool DizinIslem()
{
	//dosya islemleri icin tanimlamalar yapildi
	Dugum * liste = new Dugum;
	string yol;
	DIR *dp;
	struct dirent *dosya;

	//dosya yolu alindi disaridan
	cout << "Bir klasor yolu girin = ";
	cin >> yol;

	//eger girilen dosya yolu eksik veya hatali ise hata mesajý verilecek ve fonksiyon bitecektir
	if ((dp = opendir(yol.c_str())) == NULL)
	{
		cout << "Girdiginiz Yol Eksik Ya da Hatalidir." << yol << endl;
		system("pause");
		return false;
	}
		//girilen dizindeki dosyalar okunacak
		while (dosya = readdir(dp))
		{
			string ara = dosya->d_name;
			//dizinde bulunan dosyalardan sadece uzantisi txt olanlari almak icin if blogu olusturduk
			//dizinden ilk once . daha sonra .. degerleri gelecegi icin dosya ismininin uzunlugunun 4 ten buyuk olma 
			//sarti koyduk
			if (ara.length() > 4 &&  ara.substr(ara.length() - 4, ara.length()) == ".txt")
			{
					string dosya_kelime = "";

					ifstream Oku;
					//girilen yoldaki dosya ismine erismek icin yolu dosya ismine ekledik
					string tamYol = yol + "\\" + dosya->d_name;
					Oku.open(tamYol);
					//her txt dosyasi icin yeni bir agac olusturduk
					Agac * agac = new Agac();
					//dosyadaki veriler son bulana kadar okuma islemi yaptik
					while (Oku.eof()==false)
					{
						//bir txt dosyasini okuyup ordaki verileri o txt dosyasinin agacina ekledik
						Oku >> dosya_kelime;
						agac->AgacEkle(dosya_kelime, agac);
					}
					//en sonunda olusan agaci dosya ismiyle birlikte listeye ekledik
					liste->ListeyeEkle(agac, dosya->d_name);
					//okudugumuz dosyayi kapattik
					Oku.close();
				}
			}
		//dizini kapattik
		closedir(dp);
		//ve true dondurduk
		return true;
}
