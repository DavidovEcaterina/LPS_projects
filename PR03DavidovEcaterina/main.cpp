#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>

#define NMAX 100
#define COST_MAX 1000
#define COST_MIN 2

using namespace std;

int Citire(int n, int a[]);

void Afisare(int n, int a[], char s[]);

void Afisare(int n, int a[], char b[10][20]);

int Minimum(int n, int a[]);

int Maximum(int n, int a[]);

float Media(int n, int a[]);

int Sortare(int n, int a[]);

int Rotire(int n, int a[], int nr);

int Adaugare(int &n, int a[], int val);

int Adaugare(int &n, int a[], int val, char);

int Adaugare(int &n, int a[], int val, int p);

int Adaugare(int &n, int a[], int val, int p, char);

int Cautare(int n, int a[], int val);

int Stergere(int &n, int a[], int val);

int Clasificare(int n, int a[]);

int Generare(int n, int a[]);

bool Perfect(int n);

int main() {
    int key;
    int n = 10;
    int ncaut;
    int valadaug;
    int adaugkey;
    int pozitia;
    int med[NMAX] = {10, 20, 30, 21, 15, 45, 61, 19, 27, 49, 57, 87};
    char nume[][20] = {"cel mai ieftin", "costul mediu", "cel mai scump"};
    do {
        cout << "Proiect nr.3 elaborat de Davidov Ecaterina" << endl;
        cout << "Tema: Medicamente din farmacie" << endl;
        cout << "Numarul de medicamente: ";
        cin >> n;
    } while (n <= 0);
    Citire(n, med);
    do {
        system("cls");
        cout << "Proiect nr.3 elaborat de Davidov Ecaterina" << endl;
        cout << "Tema: Medicamente din farmacie" << endl;
        cout << "\n1. Cel mai ieftin si cel mai scump medicament";
        cout << "\n2. Media preturilor medicamentelor";
        cout << "\n3. Aranjarea preturilor in ordine crescatoare";
        cout << "\n4. Rotirea la stanga";
        cout << "\n5. Adaugarea pretului unui medicament";
        cout << "\n6. Stergerea pretului unui medicament";
        cout << "\n7. Clasificare";
        cout << "\n8. Generarea unui tabel";
        cout << "\n0. Stop";
        cout << "\n\n\t Optiunea aleasa -> ";
        cin >> key;
        switch (key) {
            case 1:
                Afisare(n, med, "de medicamente initial");
                cout << "\nCel mai ieftin medicament este la pretul de" << Minimum(n, med) << "lei";
                cout << "\nCel mai scump medicament este: " << Maximum(n, med) << "lei";
                break;
            case 2:
                Afisare(n, med, "de medicamente inital");
                cout << "\nPretul mediu al medicamentelor este: " << Media(n, med) << endl;
                break;
            case 3:
                Afisare(n, med, "de preturi inital");
                Sortare(n, med);
                Afisare(n, med, "de preturi aranjat crescator");
                break;
            case 4:
//Katea:
                int nr;
                cout << "Numarul de rotiri: ";
                cin >> nr;
                Afisare(n, med, "de preturi inital");
                Rotire(n, med, nr);
                Afisare(n, med, "de preturi dupa rotire");
                break;
            case 5:
                if (n >= NMAX) {
                    cout << "Out of range\n";
                    break;
                    //goto Katea;
                }
                do {
                    cout << "Pretul de adaugat: ";
                    cin >> valadaug;
                } while (valadaug < COST_MIN || valadaug > COST_MAX);
                do {
                    cout << "Elementul va fi adaugat: ";
                    cout << "\n1. La inceput";
                    cout << "\n2. La sfarsit";
                    cout << "\n3. Inainte de pozitia indicata";
                    cout << "\n4. Dupa pozitia indicata";
                    cout << "\n\n\t Alegeti de la 1 la 4 -> ";
                    cin >> adaugkey;
                } while (adaugkey > 4 || adaugkey < 1);
                Afisare(n, med, "initial");
                switch (adaugkey) {
                    case 1:
                        Adaugare(n, med, valadaug);
                        // Inceput
                        break;
                    case 2:
                        Adaugare(n, med, valadaug, 'K'); // Capat
                        break;
                    case 3:
                        do {
                            cout << "Indicati pozitia dorita: ";
                            cin >> pozitia;
                        } while (pozitia > n - 1);
                        Adaugare(n, med, valadaug, pozitia); // Inaite de p
                        break;
                    case 4:
                        do {
                            cout << "Indicati pozitia dorita: ";
                            cin >> pozitia;
                        } while (pozitia > n - 1);
                        Adaugare(n, med, valadaug, pozitia, 'N'); // Dupa p
                        break;
                }
                Afisare(n, med, "de preturi dupa adaugare");
                break;
            case 6:
                int valcaut;
                Afisare(n, med, "de preturi initial");
                cout << "\nValoarea care trebuie stearsa: ";
                cin >> ncaut;
                valcaut = Cautare(n, med, ncaut);
                if (valcaut != -1)
                    cout << "Elementul se afla pe pozitia: " << valcaut;
                else
                    cout << "Nu exista acest element";
                Stergere(n, med, valcaut);
                Afisare(n, med, "de preturi dupa stergere");
                break;
            case 7:
                Afisare(n, med, "de preturi initial");
                Clasificare(n, med);
                break;
            case 8:
                Generare(5, med);
                Afisare(5, med, "de numere perfecte generat");
                break;
        }
        // Katea: cout << "It's ok. Press any key to continue";
        getch();
    } while (key);

    return 0;
}

int Citire(int n, int a[]) {
    int key;
    int i;
    cout << "De unde citim: ";
    cout << "\n1. De la tastatura";
    cout << "\n2. De generat aleator";
    cout << "\n3. De generat intr-un mod special";
    cout << "\n4. Din fisier";
    cout << "\n5. Implicit";
    cout << "\n\n\t Alege -> ";
    cin >> key;
    for (i = 0; i < n; i++)
        switch (key) {
            case 1: {
                cout << "Costul medicamentul cu nr. " << i + 1 << ": ";
                cin >> a[i];
            }
                break;
            case 2:
                a[i] = rand() % (COST_MAX-COST_MIN+1) + COST_MIN;
               // a[i] = rand() % 150 + 50;
                break;
            case 3:
                a[i] = i % 3 + 50;
                break;
        }


    return 1;

}

void Afisare(int n, int a[], char s[]) {
    cout << "\nTabloul " << s << " \n";
    for (int i = 0; i < n; i++)
        cout << setw(8) << a[i];
    cout << endl;
}

void Afisare(int n, int a[], char b[10][20]) {
    cout << "\nTabloul de valori \n";
    for (int i = 0; i < n; i++)
        cout << setw(8) << a[i];
    cout << endl;
}

int Minimum(int n, int a[]) {
    int aux = a[0];
    if (n <= 0) return 0;
    for (int i = 1; i < n; i++)
        if (a[i] < aux) aux = a[i];
    return aux;
}

int Maximum(int n, int a[]) {
    int aux = a[0];
    if (n <= 0) return 0;
    for (int i = 1; i < n; i++)
        if (a[i] > aux) aux = a[i];
    return aux;
}

float Media(int n, int a[]) {
    float aux = 0;
    if (n <= 0) return 0;
    for (int i = 1; i < n; i++)
        aux += a[i];
    aux /= n;
    return aux;
}

int Sortare(int n, int a[]) {
    int k = 0, aux;
    bool change;
    do {
        change = false;
        k++;
        for (int i = 0; i < n - k; i++)
            if (a[i] > a[i + 1]) {
                aux = a[i];
                a[i] = a[i + 1];
                a[i + 1] = aux;
                change = true;
            }
    } while (change);
    return 1;
}

int Rotire(int n, int a[], int k) {
    // stanga
    for (int l = 0; l < k; l++) {
        for (int j = 0; j < 1; j++) {
            int temp = a[0];
            for (int i = 0; i < n - 1; i++) {
                a[i] = a[i + 1];
            }
            a[n - 1] = temp;
        }
    }
    return 1;
}

int Adaugare(int &n, int a[], int val) // La inceput
{
    for (int i = n; i > 0; i--) {
        a[i] = a[i - 1];
    }
    a[0] = val;
    n++;
    return 1;
}

int Adaugare(int &n, int a[], int val, char) // La capat
{

    a[n++] = val;
    return 1;
}

int Adaugare(int &n, int a[], int val, int p) // Innainte de pozitia p
{
    n++;
    for (int i = n; i > p; i--)
        a[i] = a[i - 1];
    a[p] = val;

    return 1;
}

int Adaugare(int &n, int a[], int val, int p, char) // Dupa pozitia p
{
    n++;
    for (int i = n; i > p; i--)
        a[i] = a[i - 1];
    a[p + 1] = val;

    return 1;
}

int Cautare(int n, int a[], int val) {
    for (int i = 0; i < n; i++)
        if (a[i] == val)
            return i;
    return -1;
}

int Stergere(int &n, int a[], int val) {
    if (val != -1) {
        for (int i = val; i <= n; i++) {
            a[i] = a[i + 1];
        }
    }
    n--;
    return 1;
}

int Clasificare(int n, int a[]) {
    int ieftine, rezonabile, scumpe;
    ieftine = rezonabile = scumpe = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= 20) ieftine++;
        else if (a[i] <= 100) rezonabile++;
        else if (a[i] > 100) scumpe++;
    }
    if (ieftine) cout << "Sunt " << ieftine << " medicamente ieftine (0-20 lei)" << endl;
    else
        cout << "Nu sunt medicamente ieftine (0-20 lei)" << endl;
    if (rezonabile) cout << "Sunt " << rezonabile << " medicamente la pret rezonabil (20-100 lei)" << endl;
    else
        cout << "Nu sunt medicamente la pret rezonabil (20-100 lei)" << endl;
    if (scumpe) cout << "Sunt " << scumpe << " medicamente scumpe (>100lei)" << endl;
    else
        cout << "Nu sunt medicamente scumpe" << endl;
    return 1;
}

int Generare(int n, int a[]) {
    for (int num = 1, contor = 0; contor < n; num++)
        if (Perfect(num)) {
            a[contor] = num;
            contor++;
        }
    return 1;
}

bool Perfect(int n) {
    int d, s = 1;
    for (d = 2; d <= n / 2; d++)
        if (n % d == 0)
            s += d;
    return n == s;
}
