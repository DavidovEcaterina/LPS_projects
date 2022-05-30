#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <conio.h>

#define NMAX 100

using namespace std;

void Citire(int &, int &, int[NMAX][NMAX]);

void Afisare(int, int, int[NMAX][NMAX]);

void Minim(int, int, int[NMAX][NMAX]);

void Maxim(int, int, int[NMAX][NMAX]);

void Sortare(int, int, int[NMAX][NMAX]);

void InserareRand(int &, int, int [NMAX][NMAX], int[NMAX]);

void EliminareRand(int &, int, int[NMAX][NMAX], int index);

void Clasificare(int, int, int[NMAX][NMAX]);

void Generare(int, int, int [NMAX][NMAX]);

int main() {
    int a[NMAX][NMAX];
    int n = 3, m = 3, index;
    int optiune;
    Citire(n, m, a);
    do {
        system("cls");
        cout << "Proiect nr.4 elaborat de Davidov Ecaterina" << endl;
        cout << "Tema: Preturile medicamentelor din farmacii" << endl;
        cout << "1. Afisarea tuturor preturilor" << endl;
        cout << "2. Determinarea pretului minim si pozitia lui" << endl;
        cout << "3. Determinarea pretului maxima si pozitia lui" << endl;
        cout << "4. Sortarea notelor (crescator dupa linii)" << endl;
        cout << "5. Inserarea preturilor unei farmacii" << endl;
        cout << "6. Stergerea preturilor unei farmacii" << endl;;
        cout << "7. Clasificare" << endl;
        cout << "8. Generare" << endl;
        cout << "0. Iesire" << endl;
        cout << "\n\n\t Alege o optiune -> ";
        cin >> optiune;
        switch (optiune) {
            case 1:
                cout << "Tabloul de preturi initial:" << endl;
                Afisare(n, m, a);
                break;
            case 2:
                cout << "Tabelul de preturi initial:" << endl;
                Afisare(n, m, a);
                cout << endl;
                Minim(n, m, a);
                break;
            case 3:
                cout << "Tabelul de preturi initial:" << endl;
                Afisare(n, m, a);
                cout << endl;
                Maxim(n, m, a);
                break;
            case 4:
                cout << "Tabelul de preturi initial:" << endl;
                Afisare(n, m, a);
                cout << endl;
                cout << "Am sortat crescator preturile la medicamente din fiecare farmacie" << endl;
                Sortare(n, m, a);
                Afisare(n, m, a);
                cout << endl;
                break;
            case 5:
                int preturiFarmacie[NMAX];
                cout << "Introduceti preturile medicamentelor din farmacia pentru inserare" << endl;
                for (int j = 0; j < m; j++) {
                    cout << "Pretul medicamentului " << j + 1 << ": ";
                    cin >> preturiFarmacie[j];
                }
                InserareRand(n, m, a, preturiFarmacie);
                cout << "Am adaugat farmacia cu preturile introduse" << endl;
                Afisare(n, m, a);
                cout << endl;
                break;
            case 6:
                cout << "Tabelul de preturi initial: " << endl;
                Afisare(n, m, a);
                cout << "Se va sterge farmacia cu numarul de ordine: ";
                cin >> index;
                cout << endl;
                cout << "Tabelul de preturi dupa stergerea farmaciei alese" << endl;
                EliminareRand(n, m, a, index);
                Afisare(n, m, a);
                cout << endl;
                break;
            case 7:
                cout << "Tabelul de preturi initial" << endl;
                Afisare(n, m, a);
                cout << endl;
                Clasificare(n, m, a);
                cout << endl;
                break;
            case 8:
                cout << "Tabelul generat: " << endl;
                Generare(n, m, a);
                Afisare(n, m, a);
                cout << endl;
                break;
        }
        _getch();
    } while (optiune);
    return 0;
}

void Citire(int &n, int &m, int a[NMAX][NMAX]) {
    int varianta;
    int i, j;
    cout << "\n Alege varianta de citire:" << endl;
    cout << "\n 1. De la tastatura";
    cout << "\n 2. Aleator";
    cout << "\n 3. Generat dupa o regula";
    cout << "\n 4. Din fisier";
    cout << "\n\t Varianta aleasa -> ";
    cin >> varianta;
    switch (varianta) {
        case 1:
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    cout << "Pretul medicamentului " << i + 1 << " in farmacia " << j + 1 << ": ";
                    cin >> a[i][j];
                }
            }
            break;
        case 2:
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    a[i][j] = rand() % 7 + 4;
                }
            }
            break;
        case 3:
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    a[i][j] = i % 3 + 8;
                }
            }
            break;
        case 4:
            ifstream fisierPreturi;
            fisierPreturi.open("preturi.in", ios::in);
            if (fisierPreturi.is_open()) {
                fisierPreturi >> n >> m;
                for (i = 0; i < n; i++) {
                    for (j = 0; j < m; j++) {
                        fisierPreturi >> a[i][j];
                    }
                }
            }
            fisierPreturi.close();
            break;
    }
}

void Afisare(int n, int m, int a[NMAX][NMAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(5) << a[i][j] << " ";
        }
        cout << endl;
    }
}

void Minim(int n, int m, int a[NMAX][NMAX]) {
    int min = a[0][0];
    int imin = 0, jmin = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] < min) {
                min = a[i][j];
                imin = i;
                jmin = j;
            }
        }
    }
    cout << "Pretul minim: " << min << endl;
    cout << "Acesta il are medicamentul " << jmin + 1 << " in farmacia " << imin + 1 << endl;
}

void Maxim(int n, int m, int a[NMAX][NMAX]) {
    int max = a[0][0];
    int imax = 0, jmax = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
                imax = i;
                jmax = j;
            }
        }
    }
    cout << "Pretul maxim: " << max << endl;
    cout << "Acesta il are medicamentul " << jmax + 1 << " in farmacia " << imax + 1 << endl;
}

void Sortare(int n, int m, int a[NMAX][NMAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m - j - 1; k++) {
                if (a[i][k] > a[i][k + 1]) {
                    swap(a[i][k], a[i][k + 1]);
                }
            }
        }
    }
}

void InserareRand(int &n, int m, int a[NMAX][NMAX], int note[NMAX]) {
    n++;
    for (int j = 0; j < m; j++) {
        a[n - 1][j] = note[j];
    }
}

void EliminareRand(int &n, int m, int a[NMAX][NMAX], int index) {
    for (int i = index - 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = a[i + 1][j];
        }
    }
    n--;
}

void Clasificare(int n, int m, int a[NMAX][NMAX]) {
    {
        int ieftine, rezonabile, scumpe;
        ieftine = rezonabile = scumpe = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] <= 20) ieftine++;
                else if (a[i][j] <= 100) rezonabile++;
                else if (a[i][j] > 100) scumpe++;
            }
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
    }
}

void Generare(int n, int m, int a[NMAX][NMAX]) {
    for (int j = 0; j < m; j++) {
        a[0][j] = j + 1;
        for (int i = 1; i < n; i++) {
            a[i][j] = a[i - 1][j] + 3;
        }
    }
}
