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
    cin>> n;
    vi v(n);
    f(i,0,n){
        cin >> v[i];
    }
    int c = 1;
    int def = 0;
    v.pb(1e8);
    f(i,0,n){
        if (v[i] == v[i+1]) {
            c++; 
        }else{
            def = max(def,c);
            c = 1;
        }
    }
    v.pop_back();;

    int p = (n-1)/2;
    vi vv(p);
    int dis = 1e6;
    f(i,0,p){
        vv[i] = (v[i] == v[n-i-1] ? v[i] : dis ) ;
    }
    int ans = 1;
    f(i,0,p-1){
        if (vv[i] == dis) {
            continue; 
        }
        int co = 1;
        if (vv[i] == vv[i+1]) {
            if (co == 1 and i > 0 and (vv[i] == v[i-1] or vv[i] == v[n-i] )  ) {
                co++; 
            }
            co++; 
        }else {
            if (vv[i + 1] == v[i] or vv[i] == v[n-i-1]) {
                co++; 
            }
            ans= max(ans,co);
            co = 1;
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
