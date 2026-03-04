#include<bits/stdc++.h>

using namespace std;

void so(){
        //cout << "--------------------------------" << '\n';
        int n,k;
        cin >> n >> k;
        int b[n],c[n];
        int tam = 1e3 + 1,inf = (1<<30);
        vector<int> dp_(tam,inf);
        dp_[1] = 0;
        for(int i = 1; i < tam;i++){
                for(int j = 1; j <= i;j++){
                        int nu = i + i /j;
                        if(nu >= tam)continue;
                        dp_[nu] = min(dp_[nu],dp_[i] + 1);
                }
        }

        for(int i = 0 ; i < n ; i++){
                cin >> b[i];
                b[i] = dp_[b[i]];
                //cout << b[i] << ' ' ;
        }
        //cout << '\n';

        for(int i = 0 ; i < n ; i++){
                cin >> c[i];
        }
        vector<int> dp(k+1,0);
        set<int> s;
        s.insert(0);
        for(int i = 0 ; i < n ; i++){
                int nu = b[i],n_nu,scor;
                vector<pair<int,int>> up;
                for(auto x :s){
                        n_nu = x + nu;
                        scor = dp[x] + c[i];
                        if(n_nu <= k){
                                up.push_back({n_nu,scor});
                        }
                }
                for(auto [w,co] : up){
                        dp[w] = max(dp[w],co);
                        s.insert(w);
                }
        }
        int ans = 0;
        for(int i = 0 ; i <= k ;i++){
                ans = max(ans,dp[i]);
        }
        //for(int i = 0 ; i <= k ;i++){
                //if(dp[i] == ans){
                        //cout << i << ' ';
                //}
        //}
        //cout << '\n';
        cout << ans << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt;
        cin >> tt;
        while(tt--)so();
        return 0;
}
