#include <iostream>
#include <iomanip>v
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <fstream>
#include <conio.h>
#define LMAX 180
#define LMAX 180
#define NMAX 20

using namespace std;
int NrCuvinte(char sir[]);
int Lungimea5Litere(char sir[]);
int LitIndicata(char sir[], char litera1, char litera2);
int NumarCuvinte();
int Lungimea5Litere();
int LitIndicataFile(char nume[], char litera1, char litera2);
int TransferCuvinte();
int EliminaCuvinte();
void ViewFisier(char nume[]);

int main()
{
    int optiune, nr;
    char fraza[LMAX]="Ioana merge in parc cu prietenii. Mihai citeste o carte interesanta.";
    do
    {
        system("cls");
        cout << "Proiect nr.5, elaborat de Davidov Ecaterina" << endl;
        cout << "Tema:Sir!" << endl;
        cout << "1.Numar de cuvinte" << endl;
        cout << "2.Cuvintele de lungime cel putin 5 litere dintr-o fraza" << endl;
        cout << "3.Cuvintele, ce contin litera indicata de cel puţin 2 ori " <<endl;
        cout << "4.Numar de cuvinte dintr-un fisier" << endl;
        cout << "5.Cuvintele de lungime cel putin 5 litere dintr-o fraza dintr-un fisier" << endl;
        cout << "6.Cuvintele, ce contin litera indicata de cel puţin 2 ori dintr-un  fisier" << endl;
        cout << "7.Transfer cuvintele de lungime cel putin 5 litere dintr-o fraza" << endl;
        cout << "8.Eliminare cuvinte din fisier" << endl;
        cout << "0.Stop"<< endl;
        cout << "\n\n\t Alege (de la 0 la 9) -> ";
        cin >> optiune;
        switch (optiune)


        {
        case 1:
            cout << "Fraza initiala\n";
            puts(fraza);
            nr = NrCuvinte(fraza);
            cout << "In total sunt " << nr << " cuvinte";
            break;
        case 2:
            cout << "Fraza initiala \n";
            puts(fraza);
            if (NrCuvinte(fraza) != 0)
                Lungimea5Litere(fraza);
            else
                cout << "Nu-s cuvinte";
            break;
        case 3:
            cout << "Fraza initiala:\n";
            puts(fraza);
            char litera1, litera2;
            cout << "Dati literele pentru cautare: ";
            cin >> litera1 >> litera2;
            if ((nr = LitIndicata(fraza, litera1, litera2)) > 0)
                cout << "\n In total " << nr << " cuvinte care contin literele indicate:\n";
            else
                cout << "\n Nu-s cuvinte care contin literele indicate \n";
            break;
        case 4:
             ViewFisier("fraza.txt");
            cout << "\nIn fisier sunt: " << NumarCuvinte() << " cuvinte";
            break;
        case 5:
             cout << "Continutul fisierului: \n";
            ViewFisier("fraza.txt");
            if (NumarCuvinte() != 0)
                cout << "\nIn total " <<  NumarCuvinte() << " cuvinte" << endl;
            else
                ViewFisier("fraza.txt");
            if (NumarCuvinte() != 0)
               cout << "\nIn total " <<  NumarCuvinte() << " cuvinte" << endl;
        case 6:
            ViewFisier("fraza.txt");
            cout << "\n Dati literele cautate ";
            cin >> litera1 >> litera2;
           /* if ((nr = LitIndicataFile("fraza.txt", litera1, litera2)) > 0)
                cout << "\n In total " << nr << " cuvinte care contin literele indicate\n";
            else
                cout << "\n Nu-s cuvinte care contin literele indicate \n";*/
            break;
        case 7:

            break;
        }
        getch();
    }
    while(optiune);
    return 0;
}
int NrCuvinte(char sir[])
{
    char copia[81], *cuvint, fraza[121];
    int n = 0;
    strcpy(copia, fraza);
    if ((cuvint = strtok(copia, " ,.:\n\t-")) == NULL) return 0;
    n = 1;
    while ((cuvint = strtok(NULL, " ,.:\n\t-")) != NULL)
        n++;
    return n;

}
int Lungimea5Litere(char sir[])
{
    char copia1[81], copia2[81], *cuvint;
    int slovo = 0;
    strcpy(copia1, sir);
    strcpy(copia2, sir);
    if ((cuvint = strtok(copia1, " ,.:\n\t-")) == NULL) return 0;
    slovo = strlen(cuvint);
    while ((cuvint = strtok(NULL, " ,.:\n\t-")) != NULL)
    {
        if (strlen(cuvint) > 5)
        {
            slovo = strlen(cuvint);
        }
    }
    cout << "Cuvintele cu lungimea cel putin 5 litere dintr-o fraza: ";
    if ((cuvint = strtok(copia2, " ,.:\n\t-")) == NULL) return 0;
    while ((cuvint = strtok(NULL, " ,.:\n\t-")) != NULL)
    {
        if(strlen(cuvint) <= 5) cout << setw(8) << cuvint << "";
    }

    return 1;
}
int LitIndicata(char sir[], char litera1, char litera2)
{
    char *cuvint, copia[LMAX];
    strcpy(copia, sir);
    int nr = 0;

    if ((cuvint = strtok(copia, ",.!?:\n\t ")) == NULL)
        return 0;
    if ((strchr(cuvint, litera1)) && (strchr(cuvint, litera2)))
    {
        cout << setw(16) << cuvint;
        nr++;
    }
    while ((cuvint = strtok(NULL, ",.!?:\n\t ")) != NULL)
    {
        if ((strchr(cuvint, litera1)) && (strchr(cuvint, litera2)))
        {
            cout << setw(16) << cuvint;
            nr++;
        }
    }
    return nr;
}
int NumarCuvinte()
{
    char fraza[121];
    FILE *f;
    char sir[LMAX];
    int nr = 0;
    f = fopen("fraza.txt", "r");
    while(fgets(fraza, LMAX-1, f) !=NULL)
    nr += NumarCuvinte();
    fclose(f);
    return nr;
}
int Lungimea5Litere()
{
    FILE *f;
    char fraza[LMAX], copia[LMAX], *cuvint;
    f = fopen("fraza.txt", "r");
    while(fgets(fraza, LMAX-1, f) !=NULL)
    {
        strcpy(copia, fraza);
        if ((cuvint = strtok(copia, " ,.:\n\t-")) == NULL) return 0;
        if (strlen(cuvint) > 5) cout << setw(8) << cuvint << " ";
        while ((cuvint = strtok(NULL, " ,.:\n\t-")) != NULL)
            if (strlen(cuvint) > 5) cout << setw(8) << cuvint << " ";
    }
    fclose(f);
    return 1;
}
int LitIndicataFile(char *nume,char litera1, char litera2)
{
    char sir[LMAX];
    FILE *f;
    f = fopen(nume, "r");
    int nr = 0;
    while(fread(sir,sizeof(sir),1,f) != 0)
    {
        nr = LitIndicata(sir, litera1, litera2);

    }
    fclose(f);
    return nr;
}
int TransferCuvinte()
{
    return 1;
}
int EliminaCuvinte()
{
    return 1;
}
void ViewFisier(char nume[])
{
    FILE *f;
    char sir[LMAX];
    f = fopen(nume, "r");
    while (fgets(sir, LMAX - 1, f) != NULL)
    {
        cout << sir;
    }
    fclose(f);
}
