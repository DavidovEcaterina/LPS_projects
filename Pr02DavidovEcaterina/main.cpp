#include <iostream>
#include <iomanip>

using namespace std;

/*
1.Calculam numarul de cifre
2.Verificam proprietatea
*/

int NrCifre(long a)
{
    int kol = 0;
    while (a > 0)
    {
        a /= 10;
        kol++;
    }
    return kol;
}

long power(long a, long b)
{
    long prod = 1;
    for (long i = 1; i <= b; i++)
    {
        prod *= a;
    }
    return prod;
}

bool Armstrong(long nr)
{
    long sum = 0, cf, col = NrCifre(nr);
    long number = nr;
    while (number > 0)
    {
        cf = number % 10;
        sum += power(cf, col);
        number /= 10;
    }
    return (sum == nr);
}
int NumereArmstrongInterval(int a, int b)
{
    int contor = 0;
    for(int i = a; i <= b; i++)
    {
        if(Armstrong(i))
        {
            contor++;
            cout  << setw(16) << i;
         }
    }
    return contor;
}
void AfiseazaNumereArmstrong(int n)
{
    long i = 1;
    while(n > 0)
    {
        if(Armstrong(i))
        {
            cout << setw(16)<< i;
            n--;
        }
        i++;
    }
}
bool Prim(int n)
{
    if(n <= 1)return false;
    for(int i = 2; i <= n / 2; i++)
    {
        if(n % i == 0 ) return false;
    }
    return true;
}
void NumereArmstrongPrimeInterval(int a, int b)
{
    for(int i = a; i <= b; i++)
    {
        if(Armstrong(i)&&Prim(i))
        {
            cout << setw(16) << i;
        }
    }
}
int main()
{
    cout << "Proiect nr.2 elaborat de Davidov Ecaterina" << endl;
    cout << "Tema: Numere Armstrong" << endl;
    long nr = 371;
    cout << "Introduceti un numar: ";
    //cin >> nr;
    Armstrong(nr) ? cout << nr << " este numar Armstrong" << endl : cout << nr << " nu este numar Armstrong" << endl;
    int x = 1, y = 15000;
    cout << "Introduceti limita inferioara: ";
    //cin >> x;
    cout << "Introduceti limita superiora: ";
    //cin >> y;
    cout << "Numerele Armstrong din intervalul [" << x << ";" << y << "]: " <<endl;
    int contor = NumereArmstrongInterval(x, y);
    if (contor > 0)
        cout << "\n Total: " << contor << " numere Armstrong";
    else
         cout << "\n Nu-s numere Armstrong";
    int num = 16;
    cout << "\nIntroduceti numarul de numere Armstrong dorit: " << endl;
    //cin >> num;
    cout << "Primele " << num << " numere Armstrong: " << endl;
    AfiseazaNumereArmstrong(num);
    cout << "\nNumerele ArmstrongPrime din intervalul [" << x << ";" << y << "]: " <<endl;
    NumereArmstrongPrimeInterval(x, y);
    return 0;
}
