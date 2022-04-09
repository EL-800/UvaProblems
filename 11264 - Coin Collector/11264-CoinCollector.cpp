#include <bits/stdc++.h>
using namespace std;
int n, t, monedas[1002];
int main()
{
    cin >> t;
    for (int k = 0; k < t; k++){
        cin >> n;
        int sumaAct = 0, tomados = 0;
        for (int i = 0; i < n; i++){
            cin >> monedas[i];
        }
        monedas[n] = INT_MAX;
        for (int i = 0; i < n; i++){
            if (sumaAct + monedas[i] < monedas[i + 1]){
                sumaAct += monedas[i];
                tomados++;
            }
        }
        cout << tomados << "\n";
    }
    return 0;
}
