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


void so(int test){
    int n;
    cin >> n;
    vii v(n);
    for(int i = 0 ;i < n; i++){
        cin >> v[i].fi;
    }
    ll su = 0;
    for(int i = 0 ;i < n; i++){
        cin >> v[i].se;
        su += v[i].se;
    }
    sort(all(v));
    ll ans = v[n-1].fi;
    ll cu = 0;
    for(int i = n-1; i >=1;i--){
        cu += v[i].se;
        ll cur = max((1ll)*v[i-1].fi , cu) ;
        ans = min(cur, ans);
    }
    ans = min(ans,su);
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
