#include<bits/stdc++.h>

using namespace std;

using ll = long long;

void so(){
        ll n,x;
        cin >> n >> x;
        auto b = [&](ll n, int i)->bool{
                return ((n>>i)&1);
        };
        if(n == x and x == 0){
                cout << 0 << '\n';
                return;
        }
        if(x == n){
                cout << n << '\n';
                return;
        }
        if(x == 0){
                int ind = -1;
                for(int i = 0 ; i < 62; i++){
                        if((n>>i)&1)ind = i;
                }
                cout << (1ll<<(ind+1)) << '\n';
                return;
        }

        int lo = -1;
        ll res = 0;
        for(int i = 0 ; i < 63; i++){
                if(b(x,i) and !b(n,i)){
                        cout << -1 << '\n';
                        return;
                }
                if(b(x,i)){
                        if(lo == -1)lo = i;
                }
                if(lo != -1){
                        if(b(x,i) != b(n,i)){
                                cout << -1 << '\n';
                                return;
                        }
                        if(b(x,i))res |= (1ll<<i);
                }
        }
        for(int i = lo -1 ; i >= 0; i--){
                if(b(n,i) and !b(x,i)){
                        if(i == lo -1 ){
                                cout << -1 << '\n';
                                return;
                        }
                        res |= (1ll<<(i+1));
                        break;
                }
        }
        cout << res << '\n';

}

int main(){
        int tt;
        cin >> tt;
        while(tt--)so();
        return 0;
}
