#include<bits/stdc++.h>

using namespace std;

void so(){
    int n, m;
    cin >> n >> m;
    int ma[n][m];
    int dp_mi[n][m];
    int dp_ma[n][m];
    int inf = (1 << 30);
    int ninf = -(1 << 30);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> ma[i][j];
            if(ma[i][j] == -1) ma[i][j] = 0;
            dp_mi[i][j] = inf;
            dp_ma[i][j] = ninf;
        }
    }

    int lon = n + m - 1;
    if(lon & 1){
        cout << "NO\n";
        return;
    }

    dp_mi[0][0] = ma[0][0];
    dp_ma[0][0] = ma[0][0];

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if (i > 0) {
                dp_mi[i][j] = min(dp_mi[i][j], ma[i][j] + dp_mi[i - 1][j]);
                dp_ma[i][j] = max(dp_ma[i][j], ma[i][j] + dp_ma[i - 1][j]);
            }
            if (j > 0) {
                dp_mi[i][j] = min(dp_mi[i][j], ma[i][j] + dp_mi[i][j - 1]);
                dp_ma[i][j] = max(dp_ma[i][j], ma[i][j] + dp_ma[i][j - 1]);
            }
        }
    }
    
    int target = lon / 2;
    if(dp_mi[n - 1][m - 1] <= target && target <= dp_ma[n - 1][m - 1]){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while(tt--) so();
    return 0;
}
