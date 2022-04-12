#include<bits/stdc++.h>

using namespace std;

vector<int> entrada;
vector<int> LIS;

void ImprimeCamino(const vector<int> &c, int act){
    if (act == -1)
        return;
    ImprimeCamino(c, c[act]);
    cout << entrada[act] << "\n";
}

int main(){
    int x;

    while(cin >> x){
        entrada.push_back(x);
    }

    vector<int> camino(entrada.size());

    for (int i = 0; i < (int)entrada.size(); i++){
        int rBusqueda = lower_bound(LIS.begin(), LIS.end(), entrada.at(i),
            [] (const int &a, const int &b){
                return entrada[a] < b;
            }
        ) - LIS.begin();
        if (rBusqueda < (int)LIS.size())
            LIS[rBusqueda] = i;
        else
            LIS.push_back(i);
        camino[i] = rBusqueda?  LIS[rBusqueda - 1] : -1;
    }
    cout << LIS.size() << "\n-\n";
    ImprimeCamino(camino, *(--LIS.end()));
}
