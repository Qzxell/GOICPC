#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<ll>  
#define fi first
#define se second
#define f(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a) for(ll i = (ll)a - 1; i >= (ll)b; i--)
const int INF = -1e9;

void so(int test){
    int n , x;
    cin >> n >> x;
    vi v(n);
    f(i,0,n)cin >> v[i];
    vi dis(n+1,INF);
    vi ans(n+1,0);

    f(i,0,n){
        ll su = 0;
        f(j, i ,n) {
            su += v[j];
            int le = j - i +1; 
            dis[le] = max(1ll*dis[le] , su);
        }
    }
    f(i,0,n+1){
        int le_cur = i;
        f(j,0,n+1){
            ll su = dis[i];
            su += min(i,j)*1ll*x;
            ans[j] = max(1ll*ans[j], su);
        }
    }

    f(i,0,n+1)cout << ans[i] << ' ';
    cout << ln;
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
