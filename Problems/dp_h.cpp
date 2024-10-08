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

const int fa =  1002;
const int mod = 1e9 + 7;
string gri[fa];
int dp[fa][fa];

int f(int i,int j){
    if (dp[i][j] != -1) {
        return dp[i][j]; 
    }
    if (i == 0 and j == 0) {
        return 1; 
    }
    if (i < 0 or j < 0) {
        return 0; 
    }
    ll re = 0;
    if (i - 1 >= 0 and gri[i-1][j] == '.') {
        re = (re + f(i-1,j))%mod;
    }
    if (j-1 >= 0 and gri[i][j-1] == '.') {
        re = (f(i,j-1) + re)%mod;
    }
    return  dp[i][j] = re;
}

void so(){
    int n,m;
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++){
        cin >> gri[i]; 
    }
    cout << f(n-1,m-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0 ; i < fa; i++){
        for (int j = 0 ; j < fa ; j++){
            dp[i][j] = -1;
        }
        
    }

    int tt = 1;
    while (tt--){
        so();
    }
    return 0;
}
