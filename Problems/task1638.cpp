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
#define f(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a) for(ll i = (ll)a - 1; i >= (ll)b; i--)

const int N = 1e4 + 2;
int n;
const int mod = 1e9 + 7;
vector<string> M(N);
int memo[N][N];

int dp(int x ,int y){
    if(x < 0 or y < 0) return 0;
    if(M[x][y] == '*')return 0;
    if(x == 0 and y == 0) return 1; 
    if(memo[x][y] != -1) return memo[x][y];
    
    int ret = (dp(x-1,y) + dp(x,y-1))%mod;
    return memo[x][y] = ret;
}

void so(int test){
    cin >> n;

    f(i,0,n)cin >> M[i];
    
    int ans = dp(n-1,n-1);
    cout << ans ;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    memset(memo,-1,sizeof(memo));
    int test = 1;
    while (tt--){
        so(test++);
    }
    return 0;
}
