#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cstdint>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

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

const int fa = 1e5 + 2;
vector<vi> grf(fa);
int dp[fa];

int f(int node){
    if (~dp[node]) {
        return dp[node]; 
    }
    if (grf[node].empty()) {
        return 0; 
    }
    int re = 0;
    for( auto x : grf[node]){
        re = max(re , 1 +f(x));
    }
    return dp[node] = re;
}
void so(){
    int n,ed;
    for (int i = 0 ; i < fa ; i++){
        dp[i] = -1; 
    }
    cin >> n >> ed;
    int ans = 0;
    for (int i = 0 ; i < ed ; i++){
        int a,b;
        cin >> a >> b;
        grf[a].pb(b);
    }
    int ma = 0;
    for (int i = 1 ; i <= n ; i++){
        if (dp[i] == -1) {
            ma = max(ma,f(i)); 
        }else ma = max(ma,dp[i]);
    }
    cout << ma;

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    while (tt--){
        so();
    }
    return 0;
}
