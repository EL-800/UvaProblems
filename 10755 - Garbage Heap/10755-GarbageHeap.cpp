#include <bits/stdc++.h>
using namespace std;
long long t, a, b, c, basura[22][22][22];
int main()
{
    cin >> t;
    for (long long k = 0; k < t; k++){
        if (k > 0)
            cout << "\n";
        cin >> a >> b >> c;
        for (long long i = 1; i <= a; i++){
            for (long long j = 1; j <= b; j++){
                for (long long l = 1; l <= c; l++){
                    cin >> basura[i][j][l];
                    basura[i][j][l] += basura[i][j - 1][l] + basura[i][j][l - 1] - basura[i][j - 1][l - 1];
                }
            }
        }

        long long toma = 0, maxi = LONG_MIN;
        for (long long iniI = 1; iniI <= b; iniI++){
            for (long long iniJ = 1; iniJ <= c; iniJ++){
                for (long long finI = iniI; finI <= b; finI++){
                    for (long long finJ = iniJ; finJ <= c; finJ++){
                        for (long long p = 1; p <= a; p++){
                            long long act = basura[p][finI][finJ] - basura[p][iniI - 1][finJ] - basura[p][finI][iniJ - 1] + basura[p][iniI - 1][iniJ - 1];
                            toma += act;
                            maxi = max(toma, maxi);
                            if (toma < 0)
                                toma = 0;
                        }
                        toma = 0;
                    }
                }
            }
        }
        cout << maxi << "\n";
    }
    return 0;
}
