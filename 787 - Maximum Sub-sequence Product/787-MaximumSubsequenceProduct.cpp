#include <bits/stdc++.h>
using namespace std;
typedef long long grande;
vector<pair<grande, int> > secuencia;
grande x;
int main()
{
    while (cin >> x){
        if (x !=  -999999)
            secuencia.push_back({x, 0});
        else{
            int n = secuencia.size();
            secuencia.push_back({0, 0});
            for (int i = n - 1; i >= 0; i--){
                if (secuencia[i].first < 0){
                    secuencia[i].second = 1;
                    secuencia[i].second += secuencia[i + 1].second;
                }
                else if (secuencia[i].first > 0)
                    secuencia[i].second += secuencia[i + 1].second;
            }
            grande res = LONG_MIN, act  = 1;
            bool ban = false;
            for (int i = 0; i < n; i++){
                if (secuencia[i].first > 0 || (ban && secuencia[i].first != 0)){
                    act *= secuencia[i].first;
                    ban = false;
                }
                else if (secuencia[i].first == 0)
                    act = 1;
                else{
                    if (secuencia[i].second > 1){
                        act *= secuencia[i].first;
                        ban = true;
                    }
                    else
                        act = 1;
                }
                res = max(act, res);
            }
            cout << res << "\n";
            secuencia.clear();
        }
    }
    return 0;
}
