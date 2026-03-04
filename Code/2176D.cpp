#include<bits/stdc++.h>

using namespace std;

void so(){
        int n;
        cin >> n;
        if(n==0){
                cout << "YES\n";
                return;
        }
        int t = 31 - __builtin_clz(n);
        long long num = n;
        for(int lon = t ; lon <= t + t + 2 ; lon++){
                bool yes = 1;
                for(int i = 0 ; i <= lon ; i++){
                        if(((num>>i)&1) ^ ((num>>(lon-i))&1)){
                                yes = 0;
                                break;
                        }
                }
                if((lon + 1)&1){
                        if((num>>((lon+2)/2 - 1))&1){
                                yes = 0;
                        }
                }
                if(yes){
                        cout << "YES\n";
                        return;
                }
        }
        cout << "NO\n";
        return;
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt;
        cin >> tt;
        while(tt--)so();
        return 0;
}
