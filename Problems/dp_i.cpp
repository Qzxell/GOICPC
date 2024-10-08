#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second

const int fa = 3002;
double v[fa] ;
double dp[fa][fa];

double f(int n, int up){
    if (n == 0 and up == 0) {
        return 1.0; 
    }
    if (n == 0 )  return 0; 
    if (up == 0) {
        return (1.0 - v[n])*f(n-1,up); 
    }
    if (dp[n][up] != -1) {
        return dp[n][up]; 
    }
    return dp[n][up] = f(n-1,up)*(1.0-v[n]) + f(n-1,up-1)*(1.0)*(v[n]+ 1.0 - 1.0);
}


void so(){
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        cin >> v[i]; 
    }
    for (int i = 1 ; i <= n ; i++){
        double u = f(n,i);
    }
    double ans = 0;
    for (int i = (n+1)/2 ; i <= n ; i++){
        ans += dp[n][i];    
    }
    cout << ans ;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    for (int i = 0 ; i < fa ; i++){
        for (int j = 0 ; j < fa; j++){
            dp[i][j] = -1; 
        } 
    }

    int tt = 1;
    while (tt--){
        so();
    }
    return 0;
}
