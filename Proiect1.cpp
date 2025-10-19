#include <iostream>

using namespace std;

struct Carte
{
    char *autor;
    int nrPagini;
};

void afisareCarte(Carte c)
{
    cout << endl
         << "Cartea scrisa de" << " " << c.autor << " are " << c.nrPagini << " pagini.";
}

int suma()
{
    int suma = 0;
    int dimensiune = 4;
    int vector[] = {17, 29, 45, 78};

    for (int i = 0; i < dimensiune; i++)
    {
        suma = suma + vector[i];
    }

    return suma;
}

void afisareVector(int *vector, int dim)
{
    cout << endl
         << "Afisare vector:";
    for (int i = 0; i < dim; i++)
    {
        // la afisare este foarte utila transmiterea prin valoare. In special la functiile care nu necesita modificarea valorii
        cout << endl
             << "vector[" << i << "]:" << vector[i];
    }
    cout << endl;
}

int pozitieMaxim(int *vector, int dim)
{
    int pozMaxim = 0;

    for (int i = 1; i < dim; i++)
    {
        if (vector[pozMaxim] < vector[i])
        {
            pozMaxim = i;
        }
    }

    return pozMaxim;
}

void stergereMaximDePePozitie(int *&vector, int &dim, int pozitie)
{
    int *vectorAux = new int[dim - 1];

    int j = 0;

    for (int i = 0; i < dim; i++)
    {
        if (i != pozitie)
        {
            vectorAux[j] = (vector)[i];
            j++;
        }
    }
    delete[] (vector);
    (dim)--;

    vector = vectorAux;
}

int main()
{
    cout << endl
         << "Primul seminar de POO";

    Carte carte;
    carte.nrPagini = 250;
    carte.autor = new char[strlen("Popescu") + 1];
    // strcpy_s(carte.autor,strlen("Popescu")+1, "Popescu");
    strcpy(carte.autor, "Popescu");

    afisareCarte(carte);

    delete[] carte.autor;

    int sumaCalculata = suma();

    cout << endl
         << "Suma calculata este: " << sumaCalculata << endl;

    // char *adresa;
    // char buffer[50];

    // cout << endl
    //      << "Adresa este: ";
    // cin>>buffer;
    // cin.getline(buffer, 50);
    // adresa = new char[strlen(buffer) + 1];
    // // strcpy_s(adresa, strlen(buffer+1), buffer);
    // strcpy(adresa, buffer);

    // cout << endl
    //      << "adresa citita este: " << adresa << endl;
    // delete[] adresa;

    int *vector;
    int dim = 3;
    vector = new int[dim];
    for (int i = 0; i < dim; i++)
    {
        cout << endl
             << "vector[" << i << "]=";
        cin >> vector[i];
    }

    afisareVector(vector, dim);

    cout << endl
         << "Pozitia pe care se afla maximul este: " << pozitieMaxim(vector, dim) << endl;

    stergereMaximDePePozitie(vector, dim, 1);

    afisareVector(vector, dim);
}

// TEMA modificare stergereMaximrDePePozitie si in loc sa transmit prin pointer ci prin REFERINTA.