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
    int n,k;
    cin >> n >> k;
    vi v(n);
    f(i,0,n) cin >> v[i];
    sort(v.rbegin(),v.rend());
    int ans = max(0,k - v[0]);
    f(i,0,n){
        int wa = 0;
        f(j,0,i+1){
            wa += v[j];
        }
        if(wa <= k){
            ans = min (ans, k - wa);
        }
    }
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
