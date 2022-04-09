#include <bits/stdc++.h>
using namespace std;
int mochilas[10002], n;
bitset<10002> ocupadas;
vector<vector<int> > combi;
int main()
{
    while(cin >> n, n != 0){
        int res = 0;
        for (int i = 0; i < n; i++){
            cin >> mochilas[i];
        }
        sort(mochilas, mochilas + n);
        reverse(mochilas, mochilas + n);
        for (int i = 0; i < n; i++){
            if (ocupadas[i])
                continue;
            ocupadas.set(i);
            res++;
            int tamAct = mochilas[i];
            vector<int>act;
            act.push_back(mochilas[i]);
            for (int j = i; j < n; j++){
                if (ocupadas[j] || mochilas[j] >= tamAct)
                    continue;
                act.push_back(mochilas[j]);
                tamAct = mochilas[j];
                ocupadas.set(j);
            }
            combi.push_back(act);
            act.clear();
        }
        cout << res << "\n";
        for(vector<int> i : combi){
            for(int j : i){
                cout << j << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        ocupadas.reset();
        combi.clear();
    }
    return 0;
}
