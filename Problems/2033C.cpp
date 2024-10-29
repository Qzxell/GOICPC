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

const int maf = 1e5 +1;
int n;
vi v(maf);
int memo[maf][2];

int fu (int pos , bool sw){
    if(pos == (n)/2 and (n&1)) return 0;
    if(pos == (n-1)/2 and !(n&1)) return (v[pos] == v[pos+1]);
    // 0 y 0
    int w1,w2;
    if(memo[pos][sw] != -1)return memo[pos][sw];
    if(!sw){
        // 0 y 0
        w1 = (v[pos] == v[pos+1]) + (v[n-pos-1] == v[n-pos-2]);
        // 0 y 1
        w2 = (v[n-pos-1] == v[pos+1]) + (v[pos] == v[n-pos-2]);
    }else{
        // 1 y 0
        w1 = (v[pos] == v[n-pos-2]) + (v[n-pos-1] == v[pos+1]);
        // 1 y 1
        w2 = (v[pos] == v[pos+1]) + (v[n-pos-1] == v[n-pos-2]);
    }
    return memo[pos][sw] = min(w1 + fu(pos+1, 0 ) , w2 + fu(pos+1,1));

}
void so(int test){
    cin >> n;
    f(i,0,n)cin >> v[i];
    f(i,0,maf)
        f(j,0,2) memo[i][j] = -1;

    int ans = min(fu(0,1), fu(0,0));
    cout << ans << ln;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    cin >> tt;
    int test = 1;
    while (tt--){
        so(test++);
    }
    return 0;
}
