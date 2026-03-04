#include<bits/stdc++.h>

using namespace std;

#define ll long long
void so(){
        ll n,k,su = 0,x;
        cin >> n >> k;
        vector<int> s,aux;
        for(int i = 0 ;i < n ; i++){
                cin >> x;
                su += x;
                s.push_back(x);
        }
        ll ans = (k / su)*1ll*n;
        k %= su;
        while(true){
                for(auto x : s){
                        if(x <= k){
                                k -= x;
                                ans ++;
                                aux.push_back(x);
                        }
                }
                s.clear();
                swap(s,aux);
                if(s.empty())break;
                ll acu = 0;
                for(auto x : s){
                        acu += x;
                }
                ans += (k/acu)*1ll*((int)s.size());
                k %= acu;
                if(k ==0)break;
        }
        cout << ans << '\n';

}

int main(){
        so();
        return 0;
}
