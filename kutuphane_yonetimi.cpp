#include "stdafx.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<locale.h>
using namespace std;

int sayac;
int kitapkontrol;

// Kitap sınıfı oluşturuldu, içinde kitap bilgileri ve yazdırma fonksiyonları bulunuyor
class Kitap
{
public:
    int kitapKodu;
    string kitapAdi, kitapYazariAdi, kitapYazariSoyadi;
    void kitapBilgileriGir();
    void kitapBilgileriYazdir();
};

void Kitap::kitapBilgileriGir()
{
    cout << "Kitap Kodunu Giriniz: ";
    cin >> kitapKodu;
    
    cout << "Kitap Adını Giriniz: ";
    cin >> kitapAdi;
    
    cout << "Kitap Yazar Adını Giriniz: ";
    cin >> kitapYazariAdi;
    
    cout << "Kitap Yazar Soyadını Giriniz: ";
    cin >> kitapYazariSoyadi;
}

void Kitap::kitapBilgileriYazdir()
{
    cout << "Kitap Kodu: " << kitapKodu << endl;
    cout << "Kitap Adı: " << kitapAdi << endl;
    cout << "Kitap Yazarı: " << kitapYazariAdi << " " << kitapYazariSoyadi << endl;
}

// Kitap kontrol sınıfı oluşturuldu
class KitapKontrol
{
public:
    int kitapKod;
    string kitapAd, kitapYazariAd, kitapYazariSoyad;
};

// Kutuphane sınıfı oluşturuldu, kitap ekleme, bulma ve silme fonksiyonları bulunuyor
class Kutuphane
{
public:
    void kitapEkle();
    void kitapBul(int no);
    void kitapSil(int no);
};

void Kutuphane::kitapEkle()
{
    fstream kitapKayit;
    Kitap kitap;
    KitapKontrol kitapKont;
    kitapKayit.open("Kayit.txt", ios::in | ios::app);
    kitap.kitapBilgileriGir();
    while (kitapKayit >> kitapKont.kitapKod >> kitapKont.kitapAd >> kitapKont.kitapYazariAd >> kitapKont.kitapYazariSoyad)
    {
        if (kitapKont.kitapKod == kitap.kitapKodu)
        {
            kitapkontrol++;
            cout << "Kitap mevcut.";
        }
    }
    kitapKayit.close();
    kitapKayit.open("Kayit.txt", ios::out | ios::app);
    if (kitapkontrol == 0)
    {
        kitapKayit << std::left << setw(10) << kitap.kitapKodu
            << setw(20) << kitap.kitapAd <<
            setw(15) << kitap.kitapYazariAd <<
            setw(10) << kitap.kitapYazariSoyadi << endl;

        cout << "Kitap başarıyla eklendi." << endl;
    }
    kitapKayit.close();
}

void Kutuphane::kitapBul(int no)
{
    fstream kitapKayit;
    Kitap kitap;
    kitapKayit.open("Kayit.txt", ios::out | ios::in | ios::app);
    while (kitapKayit >> kitap.kitapKodu >> kitap.kitapAd >> kitap.kitapYazariAd >> kitap.kitapYazariSoyadi)
    {
        if (no == kitap.kitapKodu)
        {
            kitap.kitapBilgileriYazdir();
            sayac++;
        }
    }
    kitapKayit.close();
}

void kitaplariListele()
{
    fstream kitapKayit;
    Kitap kitap;
    kitapKayit.open("Kayit.txt", ios::out | ios::in | ios::app);
    cout << "Kitap Kodu" << "      " << "Kitap Adı" << endl;
    cout << "----------" << "      " << "---------" << endl;
    while (kitapKayit >> kitap.kitapKodu >> kitap.kitapAd >> kitap.kitapYazariAd >> kitap.kitapYazariSoyadi)
    {
        cout << "     " << kitap.kitapKodu << "          " << kitap.kitapAd << endl;
    }
    kitapKayit.close();
}

void Kutuphane::kitapSil(int no)
{
    fstream kitapSil;
    fstream yeniDosya;
    Kitap kitap;
    kitapSil.open("Kayit.txt", ios::out | ios::in | ios::app);
    yeniDosya.open("Kayit1.txt", ios::out | ios::in | ios::app);
    while (kitapSil >> kitap.kitapKodu >> kitap.kitapAd >> kitap.kitapYazariAd >> kitap.kitapYazariSoyadi)
    {
        if (no != kitap.kitapKodu)
        {
            yeniDosya << std::left << setw(10) << kitap.kitapKodu
                << setw(20) << kitap.kitapAd <<
                setw(15) << kitap.kitapYazariAd <<
                setw(10) << kitap.kitapYazariSoyadi << endl;
        }
        else
        {
            sayac++;
        }
    }
    kitapSil.close();
    remove("Kayit.txt");
    yeniDosya.close();
    rename("Kayit1.txt", "Kayit.txt");
}

void anaMenu()
{
    Kutuphane islemler;
    int secim;
    int no;
    int silinecekKitap;
    
    cout << std::left << setw(15) << "                                      DÜZCE ÜNİVERSİTE KÜTÜPHANE OTOMASYONU" << endl;
    cout << "1-) KİTAP EKLE " << endl;
    cout << "2-) KİTAP ARA " << endl;
    cout << "3-) KİTAP SİL " << endl;
    cout << "9-) ÇIKIŞ " << endl;
    cout << "SEÇİMİNİZ.....:";
    cin >> secim;
    switch (secim)
    {
    case 1: kitapkontrol = 0; islemler.kitapEkle(); 	break;
    case 2: sayac = 0;
        system("cls");
        cout << std::left << setw(15) << "                                      DÜZCE ÜNİVERSİTE KÜTÜPHANE OTOMASYONU" << endl;
        kitaplariListele();
        cout << "Bulmak İstediğiniz Kitap Kodunu Giriniz....:"; cin >> no; islemler.kitapBul(no);
        if (sayac == 0)
        {
            cout << "Kitap Bulunamadı";
            int islem = 0;
            cout << endl << "0-Ana Menü" << endl << "9-Çıkış" << endl;
            cin >> islem;
            if (islem == 0)
            {
                system("cls");
                anaMenu();
            }
            else if (islem == 9)
            {
                exit(0);
            }
            else
            {
                cout << "Yanlış Seçim Yaptınız";
            }
            system("cls");
            anaMenu();
        }		break;
    case 3:
        sayac = 0;
        system("cls");
        cout << std::left << setw(15) << "                                      DÜZCE ÜNİVERSİTE KÜTÜPHANE OTOMASYONU" << endl;
        kitaplariListele();
        cout << "Silmek İstediğiniz Kitap Kodunu Giriniz....:"; cin >> silinecekKitap; islemler.kitapSil(silinecekKitap);

        if (sayac == 0)
        {
            cout << "Kitap Bulunamadı";
            int islem = 0;
            cout << endl << "0-Ana Menü" << endl << "9-Çıkış" << endl;
            cin >> islem;
            if (islem == 0)
            {
                system("cls");
                anaMenu();
            }
            else if (islem == 9)
            {
                exit(0);
            }
            else
            {
                cout << "Yanlış Seçim Yaptınız";
            }
            system("cls");
            anaMenu();
        }		break;



    case 9:exit(0); break;
    default:cout << "Yanlış Seçim Yaptınız"; system("cls"); anaMenu();
        break;
    }
}


int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL, "Turkish");
    anaMenu();
    int islem = 0;
    do
    {
        cout << "0-Ana Menü" << endl << "9-Çıkış" << endl;
        cin >> islem;
        if (islem == 0)
        {
            system("cls");
            anaMenu();
        }
        else if (islem == 9)
        {
            exit(0);
        }
        else
        {
            cout << "Yanlış Seçim Yaptınız";
        }
    } while (islem == 0);


    return 0;
}
