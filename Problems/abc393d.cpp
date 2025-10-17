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
        int n;
        cin >> n;
        string s;
        cin >> s;
        vi pos;
        ll sum = 0;
        f(i,0,n)if(s[i] == '1'){
                sum += (i);
                pos.pb(i);
        }
        ll cur = 0;
        vector<ll> pref(n+1,0);
        vector<ll> suf(n+1,0);
        int last = 0 ;
        f(i,0,sz(pos)){
                cur += (pos[i] - 1 - last)*1ll*i;
                pref[i] = cur;
                last = pos[i];
        }
        cur = 0;
        last = 0;
        for(int i = sz(pos) -1 , cant = 0 ; i >= 0 ; i--,cant++){
                cur += (last - pos[i] - 1)*1ll*(cant);
                suf[i] = cur;
                last = pos[i];
        }
        ll ans = LLONG_MAX;
        f(i,0,sz(pos)){
                ans = min(ans, pref[i] + suf[i]);
        }
        cout << ans << ln;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
