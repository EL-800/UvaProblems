#include <bits/stdc++.h>
using namespace std;
int n, precalculo[102][102];
int main()
{
    while(cin >> n){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                int x;
                cin >> x;
                precalculo[i][j] = x + precalculo[i][j - 1] + precalculo[i - 1][j] - precalculo[i - 1][j - 1];
            }
        }
        int res = INT_MIN;
        for (int a = 1; a <= n; a++){
            for (int b = 1; b <= n; b++){
                for (int c = a; c <= n; c++){
                    for (int d = b; d <= n; d++){
                        int act = precalculo[c][d] - precalculo[a - 1][d] - precalculo[c][b - 1] + precalculo[a - 1][b - 1];
                        res = max(act, res);
                    }
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}
