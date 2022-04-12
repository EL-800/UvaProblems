#include <bits/stdc++.h>

using namespace std;

typedef bool (*Comparador)(const int&, const int&);

int CalculaLS(const vector<pair<int, int> > &edificios, const Comparador &cmp) {
    int n = edificios.size(), max_anch = 0;
    vector<pair<int, int> > LIS(n, make_pair(1, 0));
    for (int i = 0; i < n; i++) {
        LIS[i].second = edificios[i].second;
        for (int j = 0; j < i; j++) {
            if (cmp(edificios[j].first, edificios[i].first))
                continue;
            int tam = LIS[j].first + 1;
            if (tam >= LIS[i].first)
                LIS[i].second = max(LIS[i].second, LIS[j].second + edificios[i].second);
            /*if (tam > LIS[i].first) {
                LIS[i].second = LIS[j].second + edificios[i].second;
                LIS[i].first = tam;
            }*/
        }
        max_anch = max(max_anch, LIS[i].second);
    }
    return max_anch;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, n;
    vector<pair<int, int> > edificios;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        cin >> n;
        edificios.assign(n, make_pair(0, 0));
        for (int i = 0; i < n; i++)
            cin >> edificios[i].first;
        for (int i = 0; i < n; i++)
            cin >> edificios[i].second;
        int asc = CalculaLS(edificios, 
            [](const int &a, const int &b) {
                return a >= b;
            }
        );
        int des = CalculaLS(edificios,
            [](const int &a, const int &b) {
                return a <= b;
            }
        );   
        cout << "Case " << c << ". ";
        if (asc >= des)
            cout << "Increasing (" << asc << "). Decreasing (" << des << ").\n";
        else
            cout << "Decreasing (" << des << "). Increasing (" << asc << ").\n";
    }
    return 0;
}
