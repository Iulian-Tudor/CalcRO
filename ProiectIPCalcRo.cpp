#include <iostream>
#include <cstring>
#include <stdio.h>
#include <vector>
#pragma warning (disable : 4996)

using namespace std;

vector<string> masc{ "", "un" };
vector<string> fem{ "", "o", "doua" };
vector<string> cifr{ "zero","unu", "doi", "trei", "patru", "cinci", "sase", "sapte", "opt", "noua" };
vector<string> zeci{ "zece", "unsprezece", "doisprezece", "treisprezece", "paisprezece", "cincisprezece","saisprezece", "saptesprezece", "optsprezece", "nouasprezece" };
vector<string> dzeci{ "", "", "douazeci", "treizeci", "patruzeci", "cincizeci", "sasezeci", "saptezeci", "optzeci", "nouazeci" };

string nameForNumber(long number) {
    if (number < 10) {
        return cifr[number];
    }
    else if (number < 20) {
        return zeci[number - 10];
    }
    else if (number < 100) {
        return dzeci[number / 10] + ((number % 10 != 0) ? " si " + nameForNumber(number % 10) : "");
    }
    else if (number < 200) {
        return fem[number / 100] + " suta" + ((number % 100 != 0) ? " " + nameForNumber(number % 100) : "");
    }
    else if (number < 300) {
        return fem[number / 100] + " sute" + ((number % 100 != 0) ? " " + nameForNumber(number % 100) : "");
    }
    else if (number < 1000) {
        return nameForNumber(number / 100) + " sute" + ((number % 100 != 0) ? " " + nameForNumber(number % 100) : "");
    }
    else if (number < 2000) {
        return fem[number / 1000] + " mie" + ((number % 1000 != 0) ? " " + nameForNumber(number % 1000) : "");
    }
    else if (number < 3000) {
        return fem[number / 1000] + " mii" + ((number % 1000 != 0) ? " " + nameForNumber(number % 1000) : "");
    }
    else if (number < 20000) {
        return nameForNumber(number / 1000) + " mii" + ((number % 1000 != 0) ? " " + nameForNumber(number % 1000) : "");
    }
    else if (number < 1000000) {
        return nameForNumber(number / 1000) + " de mii" + ((number % 1000 != 0) ? " " + nameForNumber(number % 1000) : "");
    }
    else if (number < 2000000) {
        return masc[number / 1000000] + " milion" + ((number % 1000000 != 0) ? " " + nameForNumber(number % 1000000) : "");
    }
    else if (number < 3000000) {
        return fem[number / 1000000] + " milioane" + ((number % 1000000 != 0) ? " " + nameForNumber(number % 1000000) : "");
    }
    else if (number < 20000000) {
        return nameForNumber(number / 1000000) + " milioane" + ((number % 1000000 != 0) ? " " + nameForNumber(number % 1000000) : "");
    }
    else if (number < 1000000000) {
        return nameForNumber(number / 1000000) + " de milioane" + ((number % 1000000 != 0) ? " " + nameForNumber(number % 1000000) : "");
    }
    else if (number < 2000000000) {
        return masc[number / 1000000000] + " miliard" + ((number % 1000000000 != 0) ? " " + nameForNumber(number % 1000000000) : "");
    }
    else if (number < 3000000000) {
        return fem[number / 1000000000] + " miliarde" + ((number % 1000000000 != 0) ? " " + nameForNumber(number % 1000000000) : "");
    }
    else if (number < 20000000000) {
        return nameForNumber(number / 1000000000) + " miliarde" + ((number % 1000000000 != 0) ? " " + nameForNumber(number % 1000000000) : "");
    }
    else if (number < 1000000000000) {
        return nameForNumber(number / 1000000000) + " de miliarde" + ((number % 1000000000 != 0) ? " " + nameForNumber(number % 1000000000) : "");
    }
   
}

int cuvantcheie(char* s1, char* s2)
{
    if (strstr(s1, s2))
        return true;
    return false;
}

bool cautareadunare(char* s1)
{
    char adunare[6][20] = { "suma","adunarii","plus","sumei","adunat","adunarea" };
    for (int i = 0;i < 6;i++)
    {
        if (cuvantcheie(s1, adunare[i]))
        {
            return true;
        }

    }
    return false;
}

bool cautarescadere(char* s1)
{
    char scadere[6][20] = { "diferenta","scaderii","minus","diferentei","scazut","scaderea" };
    for (int i = 0;i < 6;i++)
    {
        if (cuvantcheie(s1, scadere[i]))
        {
            return true;
        }

    }
    return false;
}

bool cautareinmultire(char* s1)
{
    char inmultire[6][20] = { "produsul","inmultirii","ori","produsului","inmultit","inmultirea" };
    for (int i = 0;i < 6;i++)
    {
        if (cuvantcheie(s1, inmultire[i]))
        {
            return true;
        }

    }
    return false;
}

bool cautareimpartire(char* s1)
{
    char impartire[4][20] = { "catul","impartirii","impartit","impartirea" };
    for (int i = 0;i < 4;i++)
    {
        if (cuvantcheie(s1, impartire[i]))
        {
            return true;
        }

    }
    return false;
}

void eroare(char* s1)
{
    if (!(cautareadunare(s1) || cautareimpartire(s1) || cautareinmultire(s1) || cautarescadere(s1)))

        cout << "\n" << "Eroare: Propozitia nu contine niciun operator." << "\n";
}


void cifre(char* p, int& oprd, int& pred) // de la 0 la 9
{
    char cuvant[100];
    strcpy(cuvant, "zero");
    if (strcmp(p, cuvant) == 0)
        pred = pred + 0;

    strcpy(cuvant, "unu");
    if (strcmp(p, cuvant) == 0)
        pred = pred + 1;
    strcpy(cuvant, "doi");

    if (strcmp(p, cuvant) == 0)
        pred = pred + 2;
    strcpy(cuvant, "doua");

    if (strcmp(p, cuvant) == 0)
        pred = pred + 2;
    strcpy(cuvant, "trei");

    if (strcmp(p, cuvant) == 0)
        pred = pred + 3;
    strcpy(cuvant, "patru");

    if (strcmp(p, cuvant) == 0)
        pred = pred + 4;
    strcpy(cuvant, "cinci");

    if (strcmp(p, cuvant) == 0)
        pred = pred + 5;
    strcpy(cuvant, "sase");

    if (strcmp(p, cuvant) == 0)
        pred = pred + 6;
    strcpy(cuvant, "sapte");

    if (strcmp(p, cuvant) == 0)
        pred = pred + 7;
    strcpy(cuvant, "opt");

    if (strcmp(p, cuvant) == 0)
        pred = pred + 8;
    strcpy(cuvant, "noua");

    if (strcmp(p, cuvant) == 0)
        pred = pred + 9;

}

void zecimale(char* p, int& oprd, int& pred) // de la 10 la 99
{
    char cuvant[100];
    short int hit = 0;
    strcpy(cuvant, "zece");
    if (strcmp(p, cuvant) == 0)
    {
        pred = pred + 10;
        hit = 1;
    }

    strcpy(cuvant, "unsprezece");
    if (strcmp(p, cuvant) == 0)
    {
        pred = pred + 11;
        hit = 1;
    }

    strcpy(cuvant, "doisprezece");
    if (strcmp(p, cuvant) == 0)
    {
        pred = pred + 12;
        hit = 1;
    }

    strcpy(cuvant, "treisprezece");
    if (strcmp(p, cuvant) == 0)
    {
        pred = pred + 13;
        hit = 1;
    }

    strcpy(cuvant, "paisprezece");
    if (strcmp(p, cuvant) == 0)
    {
        pred = pred + 14;
        hit = 1;
    }

    strcpy(cuvant, "cincisprezece");
    if (strcmp(p, cuvant) == 0)
    {
        pred = pred + 15;
        hit = 1;
    }

    strcpy(cuvant, "saisprezece");
    if (strcmp(p, cuvant) == 0)
    {
        pred = pred + 16;
        hit = 1;
    }

    strcpy(cuvant, "saptesprezece");
    if (strcmp(p, cuvant) == 0)
    {
        pred = pred + 17;
        hit = 1;
    }

    strcpy(cuvant, "optsprezece");
    if (strcmp(p, cuvant) == 0)
    {
        pred = pred + 18;
        hit = 1;
    }

    strcpy(cuvant, "nouasprezece");
    if (strcmp(p, cuvant) == 0)
    {
        pred = pred + 19;
        hit = 1;
    }

    strcpy(cuvant, "douazeci");
    if (strcmp(p, cuvant) == 0)
    {
        pred = pred + 20;
        hit = 1;
    }

    strcpy(cuvant, "treizeci");
    if (strcmp(p, cuvant) == 0)
    {
        pred = pred + 30;
        hit = 1;
    }

    strcpy(cuvant, "patruzeci");
    if (strcmp(p, cuvant) == 0)
    {
        pred = pred + 40;
        hit = 1;
    }

    strcpy(cuvant, "cincizeci");
    if (strcmp(p, cuvant) == 0)
    {
        pred = pred + 50;
        hit = 1;
    }

    strcpy(cuvant, "saizeci");
    if (strcmp(p, cuvant) == 0)
    {
        pred = pred + 60;
        hit = 1;
    }

    strcpy(cuvant, "saptezeci");
    if (strcmp(p, cuvant) == 0)
    {
        pred = pred + 70;
        hit = 1;
    }

    strcpy(cuvant, "optzeci");
    if (strcmp(p, cuvant) == 0)
    {
        pred = pred + 80;
        hit = 1;
    }

    strcpy(cuvant, "nouazeci");
    if (strcmp(p, "nouazeci") == 0)
    {
        pred = pred + 90;
        hit = 1;
    }

    if (hit == 0)
        cifre(p, oprd, pred);
}

void sute(char* p, int& oprd, int& pred, int& mid) // de la 100 la 999
{
    char cuvant[100];
    int hit = 0;
    strcpy(cuvant, "suta");
    if (strcmp(p, cuvant) == 0)
    {
        mid = 100;
        hit = 1;
        pred = 0;
    }
    strcpy(cuvant, "sute");
    if (strcmp(p, cuvant) == 0)
    {
        mid = pred * 100;
        hit = 1;
        pred = 0;
    }

    if (hit == 0)
        zecimale(p, oprd, pred);
}

void mii(char* p, int& oprd, int& pred, int& mid) // de la 1000 la 999999
{
    char cuvant[100];
    int hit = 0;
    strcpy(cuvant, "mie");
    if (strcmp(p, cuvant) == 0)
    {
        oprd = oprd + 1000;
        hit = 1;
    }
    strcpy(cuvant, "mii");
    if (strcmp(p, cuvant) == 0 && mid != 0 || strcmp(p, cuvant) == 0 && pred != 0)
    {
        if (pred != 0)
        {
            mid = mid + pred;
            pred = 0;
        }
        oprd = oprd + mid * 1000;
        mid = 0;
        hit = 1;
    }
    if (hit == 0)
        sute(p, oprd, pred, mid);
}

void milioane(char* p, int& oprd, int& pred, int& mid) // de la 1000000 la 999999999
{
    char cuvant[100];
    int hit = 0;
    strcpy(cuvant, "milion");
    if (strcmp(p, cuvant) == 0)
    {
        oprd = oprd + 1000000;
        hit = 1;
    }
    strcpy(cuvant, "milioane");
    if ((strcmp(p, cuvant) == 0 && mid != 0) || (strcmp(p, cuvant) == 0 && pred != 0))
    {
        if (pred != 0)
        {
            mid = mid + pred;
            pred = 0;
        }
        oprd = oprd + mid * 1000000;
        hit = 1;
        mid = 0;
    }
    if (hit == 0)
        mii(p, oprd, pred, mid);
}

void convertor() 
{
    int oprd = 0, pred = 0, mid = 0;
    int oprd1 = 0, oprd2 = 0;
    float rez = 0;
    float a=0, b=0;
    float r = 0, rest = 0;
    char propozitie[100], * p, sep[] = " ", aux[100];
    cout <<"\n"<<"Introduceti propozitia : " << endl;
    cin.getline(propozitie, 100);
    strcat(aux, propozitie);
    p = strtok(propozitie, sep);
    while (p)
    {
        if ((strcmp(p, "cu") == 0) || (strcmp(p, " , ") == 0) || (strcmp(p, "la") == 0) || (strcmp(p, "ori") == 0) || (strcmp(p, "minus") == 0) || (strcmp(p, "scazut") == 0) || (strcmp(p, "plus") == 0) || (strcmp(p, "adunat")==0))
        {
            if (pred != 0)
                oprd = oprd + pred;
            if (mid != 0)
                oprd = oprd + mid;
            oprd1 = oprd;
            oprd = 0;
            pred = 0;
            mid = 0;

        }
        milioane(p, oprd, pred, mid);

        p = strtok(NULL, sep);
    }
    if (pred != 0)
    {
        oprd = oprd + pred;

    }
    if (mid != 0)
    {
        oprd = oprd + mid;

    }
    oprd2 = oprd;
    eroare(aux);
    if (cautareadunare(aux))
    {
        rez = oprd1 + oprd2;
        cout << "\n" << "Rezultatul este: " << nameForNumber(rez) << endl;
    }

    if (cautarescadere(aux))
    {
        rez = oprd1 - oprd2;
        if (rez>=0)
            cout << "\n" << "Rezultatul este: " << nameForNumber(rez) << endl;
        else
            cout << "\n" << "Eroare:Rezultatul este negativ." << endl;
      
    }

    if (cautareinmultire(aux))
    {
        rez = oprd1 * oprd2;
        cout << "\n" <<"Rezultatul este: " << nameForNumber(rez) << endl;
    }

    if (cautareimpartire(aux) && oprd2 > 0)
    {
        rez = oprd1 / oprd2;
        if(oprd1%oprd2==0)
        cout << "\n" << "Rezultatul este: " << nameForNumber(rez) << endl;
        else
        {
            a = oprd1;
            b = oprd2;
            r = (float)(a / b);
            cout << "\n" << "Rezultatul este: " << nameForNumber(rez) <<" virgula "<< nameForNumber((r - rez) * 10)<<endl;
        }

    }
    else if (cautareimpartire(aux) && oprd2 == 0)
    {
        cout << "\n" << "Calcul imposibil" << endl;
    }

    convertor();
}
int main()
{
    convertor();
    return 0;

}
