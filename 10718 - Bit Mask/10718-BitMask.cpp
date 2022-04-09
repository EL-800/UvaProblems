#include <bits/stdc++.h>
using namespace std;
unsigned int n, l, r;
int main()
{
    while(cin >> n >> l >> r){
        unsigned int res = 0;
        for (int i = 31; i >= 0; i--){
            if (res + (1 << i) - 1 < l)
                res += (1 << i);
            else if (!(n & (1 << i)) && res + (1 << i) <= r)
                res += (1 << i);
        }
        cout << res << "\n";
    }
    return 0;
}
