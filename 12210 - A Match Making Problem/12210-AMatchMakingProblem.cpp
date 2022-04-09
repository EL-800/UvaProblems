#include <bits/stdc++.h>
using namespace std;
int b, s, x, caso;
int main()
{
    while (cin >> b >> s, b != 0 && s != 0){
        int menor = INT_MAX;
        for (int i = 0; i < b; i++){
            cin >> x;
            menor = min(x, menor);
        }
        for (int i = 0; i < s; i++)
            cin >> x;
        cout << "Case " << ++caso << ": ";
        if (b - s > 0)
            cout << b - s << " " << menor << "\n";
        else
            cout << 0 << "\n";
    }
    return 0;
}
