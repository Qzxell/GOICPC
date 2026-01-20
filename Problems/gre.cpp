#include<bits/stdc++.h>

using namespace std;

void so(){
        int n,m;
        cin >> n >> m;
        int ma[n+1][m+1];
        int dp_mi[n+1][m+1];
        int dp_ma[n+1][m+1];
        int inf = (1<<30);
        for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < m ; j++){
                        cin >> ma[i][j];
                        if(ma[i][j] == -1)ma[i][j] = 0;
                        dp_mi[i][j] = inf;
                        dp_ma[i][j] = 0;
                }
        }
        int lon = n + m - 1;
        if(lon&1){
                cout << "NO\n";
                return;
        }
        dp_mi[0][0] = ma[0][0];
        dp_ma[0][0] = ma[0][0];
        for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < m ; j++){
                        if(i > 0){
                                dp_mi[i][j] = min(dp_mi[i][j], ma[i][j] + dp_mi[i-1][j]);
                                dp_ma[i][j] = max(dp_ma[i][j], ma[i][j] + dp_ma[i-1][j]);
                        }
                        if(j > 0){
                                dp_mi[i][j] = min(dp_mi[i][j], ma[i][j] + dp_mi[i][j-1]);
                                dp_ma[i][j] = max(dp_ma[i][j], ma[i][j] + dp_ma[i][j-1]);
                        }

                }
        }
        //cout << dp_mi[n-1][m-1] << ' ' << dp_ma[n-1][m-1] << '\n';
        if(dp_mi[n-1][m-1] <= lon/2 and lon/2 <= dp_ma[n-1][m-1]){
                cout << "YES" << '\n';
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
