#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int X[8] = { 0, 0, 0, 0, 1, 1, 1, 1 };
int Y[8] = { 0, 0, 1, 1, 0, 0, 1, 1 };
int Z[8] = { 0, 1, 0, 1, 0, 1, 0, 1 };
int main()
{
    int n = 8;
    setlocale(LC_ALL, "Russian");
    int x, y, z, f1;
    int* f = new int[n];
    cout << "x|y|z| f1 \n";
    cout << "-------------";
    for (x = 0; x < 2; x++)
    {
        for (y = 0; y < 2; y++)
        {
            for (z = 0; z < 2; z++)
            {
                f1 = 1;
                if (x == 0 && y == 0 && z == 0)
                    f[0] = f1;
                if (x == 0 && y == 0 && z == 1)
                    f[1] = f1;
                if (x == 0 && y == 1 && z == 0)
                    f[2] = f1;
                if (x == 0 && y == 1 && z == 1)
                {
                    f1 = 0;
                    f[3] = f1;
                }
                if (x == 1 && y == 0 && z == 0)
                {
                    f1 = 0;
                    f[4] = f1;
                }
                if (x == 1 && y == 0 && z == 1)
                    f[5] = f1;
                if (x == 1 && y == 1 && z == 0)
                {
                    f1 = 0;
                    f[6] = f1;
                }
                if (x == 1 && y == 1 && z == 1)
                    f[7] = f1;
                cout << "\n" << x << "|" << y << "|" << z << "| " << f1;
            }
        }
    }
    cout << endl;
    cout << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << f[i];
    }
    cout << endl;
    cout << "Метод Квайна:" << endl;
    cout << "СДНФ: ";
    string F = " ";
    string f11 = "";
    string f2 = "";
    string f3 = "";
    string f4 = "";
    string f5 = "";
    string f6 = "";
    string f7 = "";
    string f8 = "";
    int k = 0; // кол-во едениц для сднф
    for (int i = 0; i < 8; i++)
    {
        if (f[i] == 1)
            k++;
    }
    char* ff = new char[k];
    int nom[8];
    for (int i = 0; i < 8; i++)
    {
        nom[i] = 10;
        if (f[i] == 1)
        {
            if (i == 0)
            {
                f11 = "!x!y!z";
                F = F + "!x!y!z";
                nom[i] = i;
            }
            if (i == 1)
            {
                f2 = "!x!yz";
                F = F + "!x!yz";
                nom[i] = i;
            }
            if (i == 2)
            {
                f3 = "!xy!z";
                F = F + "!xy!z";
                nom[i] = i;
            }
            if (i == 3)
            {
                f4 = "!xyz";
                F = F + "!xyz";
                nom[i] = i;
            }
            if (i == 4)
            {
                f5 = "x!y!z";
                F = F + "x!y!z";
                nom[i] = i;
            }
            if (i == 5)
            {
                f6 = "x!yz";
                F = F + "x!yz";
                nom[i] = i;
            }
            if (i == 6)
            {
                f7 = "xy!z";
                F = F + "xy!z";
                nom[i] = i;
            }
            if (i == 7)
            {
                f8 = "xyz";
                F = F + "xyz";
                nom[i] = i;
            }
            if (i <= k)
                F = F + "+";
        }
    }
    cout << F;
    cout << endl;
    cout << endl;
    int x2[8];
    int y2[8];
    int z2[8];
    k = 0;
    for (int i = 0; i < 8; i++)
    {
        if (nom[i] != 10)
        {
            k++;
            //cout << X[nom[i]];
            x2[k] = X[nom[i]];
           // cout << Y[nom[i]];
            y2[k] = Y[nom[i]];
            //cout << Z[nom[i]] << endl;
            z2[k] = Z[nom[i]];
            cout << x2[k];
            cout << y2[k];
            cout << z2[k] << endl;
            
        }
    }
    cout << endl;
    string F2;
    string d1, d2, d3, d4, d5;
    int k2 = 0;
    for (int i = 0; i < k; i++)
    {
        if (x2[i] == x2[i+1] && y2[i] == y2[i+1])
        {
            cout << x2[i];
            cout << y2[i];
            cout << "_" << endl;
            k2++;
            if (x2[i] == 0 && x2[i + 1] == 0 && y2[i] == 0 && y2[i + 1] == 0)
            {
                F2 = F2 + "!x!y+";
                d1 = "!x!y";
            }
            if (x2[i] == 0 && x2[i + 1] == 0 && y2[i] == 1 && y2[i + 1] == 1)
            {
                F2 = F2 + "!xy+";
                d1 = "!xy";
            }
            if (x2[i] == 1 && y2[i] == 0)
            {
                F2 = F2 + "x!y+";
                d1 = "x!y";
            }
            if (x2[i] == 1 && y2[i] == 1)
            {
                F2 = F2 + "xy+";
                d1 = "xy";
            }
        }
        if (y2[i] == y2[i+1] && z2[i] == z2[i+1])
        {
            cout << "_";
            cout << y2[i];
            cout << z2[i] << endl;
            k2++;
            if (y2[i] == 0 && z2[i] == 0)
            {
                F2 = F2 + "!y!z+";
                d2 = "!y!z";
            }
            if (y2[i] == 0 && z2[i] == 1)
            {
                F2 = F2 + "!yz+";
                d2 = "!yz";
            }
            if (y2[i] == 1 && z2[i] == 0)
            {
                F2 = F2 + "y!z+";
                d2 = "y!z";
            }
            if (y2[i] == 1 && z2[i] == 1)
            {
                F2 = F2 + "yz+";
                d2 = "yz";
            }
        }
        if (x2[i] == x2[i + 1] && z2[i] == z2[i + 1])
        {
            cout << x2[i];
            cout << "_";
            cout << z2[i] << endl;
            k2++;
            if (x2[i] == 0 && z2[i] == 0)
            {
                F2 = F2 + "!x!z+";
                d3 = "!x!z";
            }
            if (x2[i] == 0 && z2[i] == 1)
            {
                F2 = F2 + "!xz+";
                d3 = "!xz";
            }
            if (x2[i] == 1 && z2[i] == 0)
            {
                F2 = F2 + "x!z+";
                d3 = "x!z";
            }
            if (x2[i] == 1 && z2[i] == 1)
            {
                F2 = F2 + "xz+";
                d3 = "xz";
            }
        }
        if (x2[i] == x2[i + 2] && y2[i] == y2[i + 2])
        {
            cout << x2[i];
            cout << y2[i];
            cout << "_" << endl;
            k2++;
            if (x2[i] == 0 && y2[i] == 0)
            {
                F2 = F2 + "!x!y+";
                d4 = "!x!y";
            }
            if (x2[i] == 0 && y2[i] == 1)
            {
                F2 = F2 + "!xy+";
                d4 = "!xy";
            }
            if (x2[i] == 1 && y2[i] == 0)
            {
                F2 = F2 + "x!y+";
                d4 = "x!y";
            }
            if (x2[i] == 1 && y2[i] == 1)
            {
                F2 = F2 + "xy+";
                d4 = "xy";
            }
        }
        if (x2[i] == x2[i + 2] && z2[i] == z2[i + 2])
        {
            cout << x2[i];
            cout << "_";
            cout << z2[i] << endl;
            k2++;
            if (x2[i] == 0 && z2[i] == 0)
            {
                F2 = F2 + "!x!z+";
                d5 = "!x!z";
            }
            if (x2[i] == 0 && z2[i] == 1)
            {
                F2 = F2 + "!xz+";
                d5 = "!xz";
            }
            if (x2[i] == 1 && z2[i] == 0)
            {
                F2 = F2 + "x!z+";
                d5 = "x!z";
            }
            if (x2[i] == 1 && z2[i] == 1)
            {
                F2 = F2 + "xz+";
                d5 = "xz";
            }
        }
    }
    F2 = F2.substr(0, F2.size() - 1);
    cout <<"Сокр. ДНФ: " << F2 << endl;
    if (f4.empty() && f5.empty() && f7.empty()) //если пустые
    {
        if (d2.empty() && d4.empty())
        {
            cout << setw(17) << f11 << setw(10) << f2 << setw(10) << f3 << setw(10) << f6 << setw(10) << f8 << endl;
            cout << d1 << setw(10) << "1" << setw(11) << "1" << endl;
            cout << d3 << setw(12) << "1" << setw(21) << "1" << endl;
            cout << d5 << setw(42) << "1" << setw(10) << "1" << endl;
            string FFF = "f = (1||2)1233 = 123";
            cout << FFF << endl;
            FFF = "f = " + d1 + "+" + d3 + "+" + d5;
            cout << FFF << endl;
        }
    }
    delete[]f;
    return 0;
}
