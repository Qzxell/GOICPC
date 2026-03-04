#include<bits/stdc++.h>
#define ln '\n'
#define ll long long
#define pb push_back
#define vii vector<pair<int,int>>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

const int ga = 2e5 + 2;
int v[ga];
int n;

int dp(int x, vi & memo){
    if (x >= n) {
        return 0; 
    }
    if (memo[x+1] == -1) {
        memo[x+1] = dp(x+1,memo); 
    }
    if (v[x] + x < n) {
        if (memo[x+v[x]+1] == -1) {
            memo[x + v[x] + 1] = dp(x+v[x]+1,memo); 
        }
        return min(memo[x+v[x]+1], 1 + memo[x+1]) ;
    }
    return 1 + memo[x+1];
}
void so(){
    cin >> n;
    vector<int> memo(n+2,-1);
    for(int i = 0;i < n;i++){
        cin >> v[i] ;
    }
    int ans = dp(0,memo);
    cout << ans << ln;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        so();
    }

    return 0;
}
