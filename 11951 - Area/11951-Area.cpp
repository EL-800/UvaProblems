#include <bits/stdc++.h>
using namespace std;
int n, m, k, t;
long long cuartos[102][102];
int main()
{
    cin >> t;
    for (int c = 1; c <= t; c++){
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> cuartos[i][j];
                cuartos[i][j] += cuartos[i - 1][j] + cuartos[i][j - 1] - cuartos[i - 1][j - 1];
            }
        }
        int mejorA = 0, precio = 0;
        for (int inii = 1; inii <= n; inii++){
            for (int inij = 1; inij <= m; inij++){
                for (int fini = inii; fini <= n; fini++){
                    for (int finj = inij; finj <= m; finj++){
                        long long act = cuartos[fini][finj] - cuartos[fini][inij - 1] - cuartos[inii - 1][finj] + cuartos[inii - 1][inij - 1];
                        int area = (fini - inii + 1) * (finj - inij + 1);
                        if (act > k)
                            break;
                        if (area > mejorA){
                            mejorA = area;
                            precio = act;
                        }
                        else if (area == mejorA && act < precio)
                            precio = act;
                    }
                }
            }
        }
        cout << "Case #" << c << ": " << mejorA << " " << precio << "\n";
    }
    return 0;
}
