
/****************************************************************************
**              
**              ....................ODEV 3.........................
**				OGRENCI ADI .....................: NAMIK KEMAL ARSU
**				OGRENCI NUMARASI ................: B201200355
**				             
****************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int toplamHesap(int sec, int tane)  // secilen urun ve adedini paremetre olarak alip hesaplamayi yapan fonksiyon
{
    float tutar = 0.00f;    
    if (sec == 1)
    {
        tutar = 14500 * tane;
    }
    if (sec == 2)
    {
        tutar = 499 * tane;
    }
    if (sec == 3)
    {
        tutar = 319 * tane;
    }
    if (sec == 4)
    {
        tutar = 1750 * tane;
    }
    if (sec == 5)
    {
        tutar = 11999 * tane;
    }
    return tutar;
}

class Yazdirma
{
public:
    string kullaniciadi;
    void anaMenu()   //ana menüyü yazan fonksiyon
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "                          ANA MENU                        " << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|     1- Apple Macbook Air :              14500 tl       |" << endl;
        cout << "|     2- Jbl Kulaklik :                   499 tl         |" << endl;
        cout << "|     3- Logitech Klavye & Mouse seti :   319 tl         |" << endl;
        cout << "|     4- Sony Monitor :                   1750 tl        |" << endl;
        cout << "|     5- Msi Pc Kasasi :                  11999 tl       |" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }

    void girisEkrani()  //giris ekraninda bir kere yazdirilan fonksiyon
    {
        cout << "Teknoloji Marketim -> Hosgeldiniz" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Lufen adinizi giriniz : " << endl;
        getline(cin, kullaniciadi);
        cout << endl;
        cout << "Sayin " << kullaniciadi << " asagidaki listeden alisveris yapabilirsiniz" << endl;
    }
};

int main()
{
    //yazdirmak icin aylar diziye atanir
    string month[12] = { "Ocak","Subat","Mart","Nisan","Mayis","Haziran","Temmuz","Agustos","Eylul","Ekim","Kasim","Aralik" };
    float taksit, borc;
    int taksitmiktar = 1;
    int sec, tane;
    char ehsec;

    Yazdirma yazdir;    //yazdirma sinifindan yazdir nesnesi uretilir ve fonksiyonlar cagirilir
    yazdir.girisEkrani();
    yazdir.anaMenu();

    cout << "seciminiz : ";
    cin >> sec;

    //girilen degerin aralikta olup olmadigini kontrol eden dongu
    while (sec < 1 || sec > 5){
        cout << "lutfen gecerli bir deger giriniz" << endl;
        cin >> sec;
    }

    cout << "Adet Sayisi Giriniz : ";
    cin >> tane;

    //tane sayisinin 1den kucuk olma durumunu kontrol eden dongu
    while (tane < 1 ) {
        cout << "tane sayisi 1'den kucuk olamaz" << endl;
        cin >> tane;
    }
    //toplam borcu hesaplayan fonksiyona parametreleri yollanir ve elde edilen deger borc degiskenine atanir
    borc = toplamHesap(sec, tane);
    cout << "Su Anki Toplam Borcunuz : " << borc << endl;
    cout << "Alisverise Devam Etmek Istiyor musunuz? (E-H)" << endl;
    cin >> ehsec;

    //evet hayir secimi sirasinda baska bir karakter girilme durumunu kontrol eden dongu
    while (ehsec != 'h' && ehsec != 'e' && ehsec != 'H' && ehsec != 'E'){
        cout << "Gecersiz Karakter Lutfen e,h,E,H Karakterlerinden Birini Giriniz" << endl;
        cin >> ehsec;
    }
    
    while (ehsec == 'e' || ehsec == 'E'){
        yazdir.anaMenu();
        cout << "seciminiz : ";
        cin >> sec;
        while (sec < 0 || sec > 5) {
            cout << "secimleriniz 1 ve 5 arasinda olmalidir" << endl;
            cin >> sec;
        }

        cout << "adet sayisi giriniz : ";
        cin >> tane;
        borc += toplamHesap(sec, tane);
        cout << "Su anki toplam borcunuz : " << borc << endl;
        cout << "Alisverise devam etmek istiyor musunuz? (E/H)";
        cin >> ehsec;
        while (ehsec != 'e' && ehsec != 'E' && ehsec != 'h' && ehsec != 'H') {
            cout << "gecersiz secim lutfen e,h,E,H karakterlerinden birini giriniz" << endl;
            cin >> ehsec;
        }
    }

    cout << "%18 kdv eklensin mi? (E-H)" << endl;
    cin >> ehsec;
    while (ehsec != 'h' && ehsec != 'e' && ehsec != 'H' && ehsec != 'E') {
        cout << "Gecersiz Karakter Lutfen e,h,E,H Karakterlerinden Birini Giriniz" << endl;
        cin >> ehsec;
    }

    if (ehsec == 'e' || ehsec == 'E') {
        borc = borc + borc / 100 * 18;
        cout << "Toplam Borcunuz : " << borc << endl;
    }
    else {
        cout << "Toplam Borcunuz : " << borc << endl;
    }

    cout << "taksitlendirme yapmak ister misiniz? (E-H)" << endl;
    cin >> ehsec;
    while (ehsec != 'h' && ehsec != 'e' && ehsec != 'H' && ehsec != 'E') {
        cout << "Gecersiz Karakter Lutfen e,h,E,H Karakterlerinden Birini Giriniz" << endl;
        cin >> ehsec;
    }
    if (ehsec == 'E' || ehsec == 'e') {
        cout << "Taksit Sayisini Giriniz (En fazla 12 taksit)" << endl;
        cin >> taksitmiktar;

        while (taksitmiktar < 2 || taksitmiktar > 12) {
            cout << "taksit en fazla 12 en az 2 olmalidir" << endl;
            cin >> taksitmiktar;
        }
        taksit = borc / taksitmiktar;

        cout << "\nAylik odeme tutariniz = " << taksit << " TL" << endl;
        cout << "Odeme cizelgesi : " << endl;
        cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        for (int i = 0; i < taksitmiktar; i++){
            cout << month[i] << setw(5) << " : " << taksit <<  " TL" << endl;
        }
    }
    else{
        taksit = borc;  // dosyaya yazdirirken taksit degiskeni kullanildigi icin burada borc degiskeni taksit degiskenine aktarilmistir
        cout << "\nToplam Odenecek Tutar" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << borc << " TL " << endl;
    }

    //fatura yazma islemi
    ofstream faturayazmak;
    faturayazmak.open("fatura.txt");    //fatura.txt isminde dosya acilir
    if (faturayazmak.is_open()) 
    {
        faturayazmak << "Müşteri Adı \n" << yazdir.kullaniciadi << endl;
        faturayazmak << "\nToplam Borç Tutar : " << borc << endl;
        faturayazmak << "Ödeme Çizelgesi : " << endl;
        faturayazmak << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

        //taksit miktari kadar dongu doner ve alt alta aylik odeme plani yazdirilir
        for (int i = 0; i < taksitmiktar; i++){
            faturayazmak << month[i] << " : " << taksit << " TL" << endl;
        }
        faturayazmak.close();
    }

}

