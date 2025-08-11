#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main(){
    multiset<int> a;
    multiset<int> b;
    int t,n,k,aux1;
    bool chino=true;
    cin>>t;
    for(int i=0;i<t;i++){
        chino=true;
        cin>>n>>k;
        a.clear();
        b.clear();
        for(int j=0;j<n;j++){
            cin>>aux1;
            aux1=aux1%k;
            if(aux1>k/2){aux1=(aux1-k)*-1;}
            a.insert(aux1);
        }
        for(int j=0;j<n;j++){
            cin>>aux1;
            aux1=aux1%k;
            if(aux1>k/2){aux1=(aux1-k)*-1;}
            b.insert(aux1);
        }
        bool chino = 1;
        for(auto x : a){
                if(a.count(x) != b.count(x)){
                        chino = 0;
                        break;
                }
        }
        cout << (chino ? "YES" : "NO") << '\n';
}
return 0;
 
 
}
