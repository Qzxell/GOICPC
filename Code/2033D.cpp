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

void so(int test){
    int n;
    cin >> n;
    vi v(n);
    vector<ll> pp(n+1,0);
    ll dist = 1e11;
    f(i,0,n)cin >> v[i];
    f(i,1,n+1)pp[i] = pp[i-1] + v[i-1];

    map<ll,bool> m;
    ll cur = 0;
    int point_last = 0;
    m[0] = 1;

    int ans =0;
    f(i,0,n){
        cur += v[i]     ;
        if (m.count(cur) > 0 and m[cur]) {
            ans++;
            f(j,point_last,i+2) m[pp[j]]=0;
            point_last = i;
        }
        m[cur] = 1;
    }

    cout << ans <<ln;


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
