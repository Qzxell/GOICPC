#include<bits/stdc++.h>

using namespace std;

void so(){
        int n,m;
        cin >> n >> m;
        int ma[n][m];
        vector<vector<set<int>>> dp(n,vector<set<int>>(m));
        for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < m ; j++){
                        cin >> ma[i][j];
                        if(ma[i][j] == -1)ma[i][j] = 0;
                }
        }
        int lon = n + m - 1;
        if(lon&1){
                cout << "NO\n";
                return;
        }
        dp[0][0].insert(ma[0][0]);
        for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < m ; j++){
                        for(auto x:dp[i][j]){
                                if(j+1 < m){
                                        int va = ma[i][j+1] + x;
                                        if(va <= lon/2)dp[i][j+1].insert(va);
                                }
                                if(i+1 < n){
                                        int va = ma[i+1][j] + x;
                                        if(va <= lon/2)dp[i+1][j].insert(va);
                                }
                        }
                }
        }
        if(dp[n-1][m-1].count(lon/2)){
                cout << "YES\n";
                return;
        }
        cout << "NO\n";
}

int main(){
        int tt;
        cin >> tt;
        while(tt--)so();
        return 0;
}
