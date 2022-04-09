#include <bits/stdc++.h>
using namespace std;
int t, n, m, matriz[152][152];
int main()
{
    cin >> t;
    for (int p = 0; p < t; p++){
        cin >> n;
        for (int i = 1; i <= 150; i++){
            for (int j = 1; j <= 150; j++){
                matriz[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                cin >> matriz[i][j];
                matriz[i][j + n] = matriz[i][j];
                matriz[i + n][j] = matriz[i][j];
                matriz[i + n][j + n] = matriz[i][j];
            }
        }
        m = n * 2;
        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= m; j++){
                matriz[i][j] += matriz[i][j - 1] + matriz[i - 1][j] - matriz[i - 1][j - 1];
            }
        }
        int res = INT_MIN;
        for (int iniy = 1; iniy <= n; iniy++){
            for (int inix = 1; inix <= n; inix++){
                for (int finy = iniy; finy <= (n + iniy - 1); finy++){
                    for (int finx = inix; finx <= (n + inix - 1); finx++){
                        int act = matriz[finy][finx] - matriz[iniy - 1][finx] - matriz[finy][inix - 1] + matriz[iniy - 1][inix - 1];
                        res = max(act, res);
                    }
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}
