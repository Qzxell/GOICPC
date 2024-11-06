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
    int n,x;
    cin >> n >> x;
    vi v(n);
    vector<ll> p(n+1,0);
    vi ans(n+1,0);
    f(i, 0 , n) cin >> v[i];

    f(i, 1 , n+1) p[i] = p[i-1] + v[i-1];

    f(i, 0 , n){
        f(j, i+1 , n){
            int l = i-j+1; 
            ll su = p[j+1] - p[i];
            su += x*l;
            ans[l] 

        }
    }


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
