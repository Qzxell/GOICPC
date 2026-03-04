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

const int ga = 101;
const int fa = 1e5 +1 ;
int V[ga];
int W[ga];
ll memo[fa][ga];

ll fu( int space , int cur ){
    if(cur == -1 ) return 0;
    if(memo[space][cur] != 0) return memo[space][cur];
    int w = W[cur];
    int v = V[cur];
    ll ret = fu(space,cur-1);
    if  ( space >= w ) ret = max(fu(space-w,cur-1) + v ,ret);
    return memo[space][cur] = ret;
}

void so(int test){
    int n,w;
    cin >> n >> w;
    f(i,0,n){
        cin >> W[i] >> V[i];
    }
    ll ans = fu(w,n-1);
    cout << ans << ln;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    int test = 1;
    while (tt--){
        so(test++);
    }
    return 0;
}
