#include <bits/stdc++.h>
using namespace std;
int n, d, t;
pair<char, int> rocas[102];
int main()
{
    cin >> t;
    for (int k = 0; k < t; k++){
        cin >> n >> d;
        for (int i = 0; i < n; i++){
            char tipo, basura;
            int dis;
            cin >> tipo >> basura >> dis;
            rocas[i] = {tipo, dis};
        }
        int res = 0, act = 0;
        bool tomar = true;
        for (int i = 0; i < n; i++){
            if (rocas[i].first == 'B'){
                res = max(res, rocas[i].second - act);
                act = rocas[i].second;
            }
            else{
                if (tomar){
                    res = max(res, rocas[i].second - act);
                    act = rocas[i].second;
                    rocas[i].first = 'X';
                    tomar = false;
                }
                else{
                    tomar = true;
                }
            }
        }
        res = max(res, d - act);
        act = d;
        for (int i = n - 1; i >= 0; i--){
            if (rocas[i].first == 'B'){
                res = max(res, act - rocas[i].second);
                act = rocas[i].second;
            }
            else if(rocas[i].first == 'S'){
                res = max(res, act - rocas[i].second);
                act = rocas[i].second;
            }
        }
        res = max(res, act);
        cout << "Case " << k + 1 << ": " <<res << "\n";
    }
    return 0;
}
