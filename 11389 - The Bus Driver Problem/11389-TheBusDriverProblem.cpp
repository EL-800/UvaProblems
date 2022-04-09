#include <bits/stdc++.h>
using namespace std;
int n, d, r, manana[102], tarde[102];
int main()
{
    while (cin >> n >> d >> r, n != 0 && d != 0 && r != 0){
        for (int i = 0; i < n; i++){
            cin >> manana[i];
        }
        for (int i = 0; i < n; i++){
            cin >> tarde[i];
        }
        sort(manana, manana + n);
        sort(tarde, tarde + n);
        reverse(tarde, tarde + n);
        int extra = 0;
        for (int i = 0; i < n; i++){
            int t_ruta = manana[i] + tarde[i];
            extra += t_ruta > d ? t_ruta - d : 0;
        }
        cout << extra * r << "\n";
    }
    return 0;
}
