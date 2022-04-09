#include <bits/stdc++.h>
using namespace std;
int num,maxi, act,arre[100000];
int verf(int pos, int fini){
    set<int> tru;
    int cont=0;
    for(int j=pos;j<fini;j++){
        if(tru.find(arre[j]) == tru.end()){tru.insert(arre[j]);cont++;}
        else{break;}
    }
    tru.clear();
    return cont;
}
int main(){
    cin>>num;
    for(int i=0;i<num;i++)
        {cin>>arre[i];}
    for(int i=0;i<num;i++){
        act = verf(i,num);
        if(act>maxi){maxi=act;}
    }
    cout<<maxi;
    return 0;
}
