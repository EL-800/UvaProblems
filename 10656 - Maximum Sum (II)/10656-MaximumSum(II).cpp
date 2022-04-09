#include <bits/stdc++.h>
using namespace std;
int n, secuencia[1002];
bool ceros, pendejada;
int main()
{
    while(cin >> n, n != 0){
        ceros = true;
        pendejada = true;
        for (int i = 0; i < n; i++){
            cin >> secuencia[i];
            if(secuencia[i] != 0)
                ceros = false;
        }
        if (ceros){
            cout << 0 << "\n";
            continue;
        }
        for (int i = 0; i < n; i++){
            if (secuencia[i] != 0){
                if (pendejada){
                    cout << secuencia[i];
                    pendejada = false;
                }
                else
                    cout << " " << secuencia[i];
            }
        }
        cout << "\n";
    }
    return 0;
}
