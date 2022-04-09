#include <iostream>
using namespace std;
int n;
int main()
{
    while(cin >> n, n != 0){
        int apuesta, maxi = -1, act = 0;
        for (int i = 0; i < n; i++){
            cin >> apuesta;
            act += apuesta;
            maxi = max(maxi, act);
            if (act < 0)
                act = 0;
        }
        if (maxi > 0)
            cout << "The maximum winning streak is " << maxi << ".\n";
        else
            cout << "Losing streak.\n";
    }
    return 0;
}
