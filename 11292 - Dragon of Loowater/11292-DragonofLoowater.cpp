#include <bits/stdc++.h>
using namespace std;
int d, c, cabezas[20002], caballeros[20002];
int main()
{
    while (cin >> d >> c, d != 0 && c != 0){
        for (int i = 0; i < d; i++)
            cin >> cabezas[i];
        for (int i = 0; i < c; i++)
            cin >> caballeros[i];
        sort(cabezas, cabezas + d);
        sort(caballeros, caballeros + c);
        int i = 0, j = 0, costo = 0;
        while (i < d && j < c){
            if (caballeros[j] >= cabezas[i]){
                costo += caballeros[j];
                j++;
                i++;
            }
            else{
                j++;
            }
        }
        if (i >= d)
            cout << costo;
        else
            cout << "Loowater is doomed!";
        cout << "\n";
    }
    return 0;
}
