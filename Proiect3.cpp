#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Aparat
{
public:
    int *capacitateRezervorML;
    string tip;
    string culoare;
    string brand;
    const int numarBauturi;
    static int TVA;

    Aparat() : numarBauturi(2)
    {
        capacitateRezervorML = new int(1000);
        tip = "Espressor";
        culoare = "Negru";
        brand = "Nespresso";
    }

    Aparat(int capacitate) : numarBauturi(3)
    {
        capacitateRezervorML = new int(capacitate);
        tip = "Filtru";
        culoare = "Argintiu";
        brand = "Philips";
    }

    Aparat(int capacitate, string t, string c, string b, int nrB) : numarBauturi(nrB)
    {
        capacitateRezervorML = new int(capacitate);
        tip = t;
        culoare = c;
        brand = b;
    }

    static int calculeazaPretCuTVA(int pret)
    {
        return pret + pret * TVA / 100;
    }

    void afisare()
    {
        cout << "Aparat: " << brand << ", tip: " << tip
             << ", culoare: " << culoare
             << ", capacitate: " << *capacitateRezervorML
             << ", nr bauturi: " << numarBauturi << endl;
    }
};

int Aparat::TVA = 19;

class Cana
{
public:
    int *capacitateML;
    string material;
    string culoare;
    string brand;
    const int temperaturaMax;
    static int garantieLuni;

    Cana() : temperaturaMax(200)
    {
        capacitateML = new int(250);
        material = "Ceramica";
        culoare = "Rosu";
        brand = "Ikea";
    }

    Cana(int capacitate) : temperaturaMax(300)
    {
        capacitateML = new int(capacitate);
        material = "Sticla";
        culoare = "Transparent";
        brand = "Tescoma";
    }

    Cana(int capacitate, string m, string c, string b, int tmax)
        : temperaturaMax(tmax)
    {
        capacitateML = new int(capacitate);
        material = m;
        culoare = c;
        brand = b;
    }

    static bool rezistaLaTemperatura(int temp, int limita)
    {
        return temp <= limita;
    }

    void afisare()
    {
        cout << "Cana: " << brand << ", material: " << material
             << ", culoare: " << culoare
             << ", capacitate: " << *capacitateML
             << ", tempMax: " << temperaturaMax << endl;
    }
};

int Cana::garantieLuni = 12;

class Servetele
{
public:
    int *numarDeServetele;
    int straturi;
    string culoare;
    const int dimensiuneLaturaCM;
    static int dimensiuneStandard;

    Servetele() : dimensiuneLaturaCM(4)
    {
        numarDeServetele = new int(50);
        straturi = 2;
        culoare = "Alb";
    }

    Servetele(int nr) : dimensiuneLaturaCM(5)
    {
        numarDeServetele = new int(nr);
        straturi = 3;
        culoare = "Albastru";
    }

    Servetele(int nr, int s, string c, int dim)
        : dimensiuneLaturaCM(dim)
    {
        numarDeServetele = new int(nr);
        straturi = s;
        culoare = c;
    }

    static int calculeazaPacheteNecesare(int total, int perPachet)
    {
        return (total + perPachet - 1) / perPachet;
    }

    void afisare()
    {
        cout << "Servetele: " << culoare
             << ", nr: " << *numarDeServetele
             << ", straturi: " << straturi
             << ", dimensiune latura: " << dimensiuneLaturaCM << endl;
    }
};

int Servetele::dimensiuneStandard = 10;

int main()
{
    cout << "APARATE:\n";
    Aparat Aparat1;
    Aparat Aparat2(1500);
    Aparat Aparat3(1800, "Capsule", "Alb", "Krups", 5);

    Aparat1.afisare();
    Aparat2.afisare();
    Aparat3.afisare();

    cout << "\n CANI:\n";
    Cana Cana1;
    Cana Cana2(300);
    Cana Cana3(350, "Metal", "Negru", "Fox", 350);

    Cana1.afisare();
    Cana2.afisare();
    Cana3.afisare();

    cout << "\n SERVETELE \n";
    Servetele Servetele1;
    Servetele Servetele2(80);
    Servetele Servetele3(120, 4, "Verde", 6);

    Servetele1.afisare();
    Servetele2.afisare();
    Servetele3.afisare();

    return 0;
}
