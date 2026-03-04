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
    vii v(n);
    vii up;
    vii dow;
    f(i,0,n)cin >> v[i].fi;
    f(i,0,n)cin >> v[i].se;
    f(i,0,n) {
        if (v[i].fi > v[i].se){
        up.pb(v[i]);
        }else dow.pb(v[i]);
    }
    int au = -1e6;
    int ans = 0;
    f(i,0,sz(up)){
        ans += up[i].fi;
        au = max(au,up[i].se);
    }
    f(i,0,sz(dow)){
        ans += dow[i].se;
        au = max(au,dow[i].fi);
    }
    cout << ans + au << ln;
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
