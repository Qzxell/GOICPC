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

int n;
const int fa = 504;
int v[fa];
int dp[fa][fa];

int f(int l,int r){
    if (l >r)return 0;
    if (l == r) {
        return 1; 
    }
    if (~dp[l][r]) {
        return dp[l][r]; 
    }
    int re = 1 + f(l+1,r);
    if (v[l] == v[l+1]) {
        re = min(re, 1 + f(l+2,r)); 
    }
    for (int i = l+2 ; i <= r ; i++){
        if (v[l] == v[i]) {
            re = min(re, f(l+1,i-1) + f(i+1,r)); 
        }
    }
    return dp[l][r] = re;
}

void so(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> v[i];
    }
    cout << f(0,n-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0 ; i < 502 ; i++){
        for (int j = 0 ; j < 502 ; j++){
            dp[i][j] = -1;
        }
    }

    int tt = 1;
    while (tt--){
        so();
    }
    return 0;
}
