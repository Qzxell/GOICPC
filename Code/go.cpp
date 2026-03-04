#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<int>  ;
#define ln  '\n'
#define ll long long
#define pb push_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

void so(int test){
        ll n;
        cin >> n;
        vi primes = {2,3,5,7,11,13,17,19,23,29,31,37,39,41} ;
        ll ans = 0;
        const int mod = 1e9 + 7;
        ll con = 1;
        ll takes = 0;
        int prev = 1;
        for (int x = 1;x < 50;x++) {
                ll wasa = (n - (n/con) - takes);
                takes = (n- n/con);
                //cout << wasa << ' ';
                ans = (prev*1ll*(wasa) + ans)%mod;
                prev = x;
                con = (x*1ll*con)/gcd(x,con);
                //cout << con << ' ';
        }
        //cout << ln;
        cout << ans << ln;
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int tt = 1;
        int test = 1;
        cin >> tt;
        while (tt--){
                so(test++);
        }
        return 0;
}



