#include <bits/stdc++.h>
using namespace std;
vector<string>res;
char tableroOrdenado[10][10], tablero[10][10], columna[10];
int indice, t;
bool valido(int fila, int columna){
    for (int i = 0; i < 6; i++){
        if (tableroOrdenado[fila][columna] == tablero[i][columna]){
            return true;
        }
    }
    return false;
}
bool Encontrado(string contra){
    for (string i : res){
        if (i == contra)
            return false;
    }
    return true;
}
void Busqueda(int columna = 0, string contra = ""){
    if (columna >= 5){
        if(Encontrado(contra))
            res.push_back(contra);
        return;
    }
    for (int i = 0; i < 6; i++){
        if (valido(i, columna)){
            Busqueda(columna + 1, contra + tableroOrdenado[i][columna]);
        }
    }
    return;
}
int main()
{
    cin >> t;
    for (int k = 0; k < t; k++){
        cin >> indice;
        for (int i = 0; i < 6; i++){
            for (int j = 0; j < 5; j++){
                cin >> tablero[i][j];
            }
        }
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 6; j++){
                columna[j] = tablero[j][i];
            }
            sort(columna, columna + 6);
            for (int j = 0; j < 6; j++){
                tableroOrdenado[j][i] = columna[j];
            }
        }
        for (int i = 0; i < 6; i++){
            for (int j = 0; j < 5; j++){
                cin >> tablero[i][j];
            }
        }
        Busqueda();
        if (res.size() >= indice)
            cout << res.at(indice - 1) << "\n";
        else
            cout << "NO\n";
        res.clear();
    }
    return 0;
}
