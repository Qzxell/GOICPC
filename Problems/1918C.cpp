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
#define fer(i, a, b) for(ll i = (ll)a ; i >= (ll)b; i--)

void so(int test){
    ll a,b,r;
    cin >> a >> b >> r;
    ll mas = (a^b);
    auto fu = [](ll x){
        fer(i,62,0){
            cout << ((x>>i)&1) ;
        }
        cout << ln;
    };
    ll mas_a = (mas & a);
    ll mas_b = (mas & b);
    int point = -1;
    for(int i = 0 ; i < 62 ; i++){
        if ((mas >> i)&1 and (1<<i) <= r) {
            point = i; 
        }
    }
    if (point == -1) {
        cout << abs((a^0) - (b^0)) << ln;
        return;
    }
    ll ans = 1e18;
    ll x = 0;
    // case a mayor -> a cede todos sus 1 (bits prendidos), sin que pierda la caracteristica de ser mayor
    fer(i,point,0)if((mas_a>>i)&1 and x + (1<<i) <= r ){
        x += (1<<i) ;
    }
    ans = min(ans, abs((a^x)-(b^x) ));
    x = 0;
    // case : b mayor -> b cede todos sus 1 (bits prendidos)
    fer(i,point,0)if((mas_b>>i)&1 and x + (1<<i) <= r ){
        x += (1<<i) ;
    }
    ans = min(ans, abs((a^x)-(b^x) ));
    cout << ans << ln; }


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