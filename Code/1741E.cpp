#include<bits/stdc++.h>

using namespace std;

void so(){
        int n;
        cin >> n;
        vector<int> v(n);
        vector<bool> dp(n+1,0);
        vector<vector<int>> in(n);
        for(int i = 0 ; i < n ; i++){
                cin >> v[i];
                if(i - v[i] >= 0)in[i-v[i]].push_back(i);
        }
        dp[0] = 1;
        for(int i = 0 ; i < n ; i++)if(dp[i]){
                for(auto x : in[i]){
                        dp[x+1] = 1;
                }
                if(i+v[i]+1 <= n)dp[i+v[i]+1] = 1;
        }
        cout << (dp[n] ? "YES" : "NO") << '\n';

}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt;
        cin >> tt;
        while(tt--)so();
        return 0;
}
