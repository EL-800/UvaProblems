#include <bits/stdc++.h>
using namespace std;
int t, n;
char campo[102];
int main()
{
    cin >> t;
    for (int k = 0; k < t; k++){
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> campo[i];
        int i = 0, espantapajaros = 0;
        while (i < n){
            if (campo[i] == '#')
                i++;
            else{
                espantapajaros++;
                i += 3;
            }
        }
        cout << "Case " << k + 1<< ": " << espantapajaros << "\n";
    }
    return 0;
}
