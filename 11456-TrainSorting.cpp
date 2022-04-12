#include<bits/stdc++.h>

using namespace std;

void HazLDS(const vector<int> &entrada, vector<int> &LDS){
    int n = entrada.size();
    LDS.resize(n, 1);
    for (int i = LDS.size() - 1; i >= 0; i--){
        for (int j = 0; j < i; j++){
            if (entrada[j] > entrada[i])
                LDS[j] = max(LDS[j], LDS[i] + 1);
        }
    }
}

void HazLIS(const vector<int> &entrada, vector<int> &LIS){
    int n = entrada.size();
    LIS.resize(n, 1);
    for (int i = LIS.size() - 1; i >= 0; i--){
        for (int j = 0; j < i; j++){
            if (entrada[j] < entrada[i])
                LIS[j] = max(LIS[j], LIS[i] + 1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t, n, res;
    vector<int> entrada;
    vector<int> LDS;
    vector<int> LIS;

    cin >> t;
    while(t--){
        res = 0;
        entrada.clear();
        LDS.clear();
        LIS.clear();
        cin >> n;
        while(n--){
            int x;
            cin >> x;
            entrada.push_back(x);
        }
        HazLDS(entrada, LDS);
        HazLIS(entrada, LIS);
        for (int i = 0; i < (int)LIS.size(); i++)
            res = max(res, LIS[i] + LDS[i] - 1);
        cout << res << "\n";
    }
    return 0;
}
