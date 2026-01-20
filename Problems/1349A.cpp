#include<bits/stdc++.h>

using namespace std;

using ll = long long;

ll fp(int b,int e){
        ll ret = 1;
        while(e){
                if(e&1){
                        ret *= b;
                }
                b = b * b;
                e >>= 1;
        }
        return ret;
}

void so(){
        int n,x,sq;
        cin >> n;
        map<int,vector<int>> div;
        for(int i = 0 ; i < n ; i++){
                cin >> x;
                sq = sqrt(x);

                for(int j = 2 ; j <= sq ;j++){
                        int co = 0;
                        while(x % j == 0){
                                co++;
                                x /= j;
                        }
                        if(co)div[j].push_back(co);
                }
                if(x != 1){
                        div[x].push_back(1);
                }

        }
        ll ans = 1;
        //for(auto [nu,v] : div){
                //cout << nu << '\n';
                //for(auto x : v ){
                        //cout << x << ' ';
                //}
                //cout << '\n';
        //}
        for(auto [nu,v] : div){
                if(v.size() <= n - 2)continue;
                sort(v.begin(),v.end());
                if(v.size() == n-1){
                        ans = ans*fp(nu,v[0]);
                }else{
                        ans = ans*fp(nu,v[1]);
                }
        }
        cout << ans << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        so();
        return 0;
}
