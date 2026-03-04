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

ll p = 257;
ll m = 1e9 + 9;

void so(int test){
        int k;
        string s,bad;
        cin >> s >> bad >> k;

        int n = sz(s);
        vi ps_bad(n+1,0);

        vector<ll> p_pow(n+1,1);
        vector<ll> h(n+1,0);

        f(i,1,n+1){
                ps_bad[i] = ps_bad[i-1] + (bad[s[i-1]-'a'] == '0');
                p_pow[i] = (p_pow[i-1] *1ll* p ) %m;
                h[i] = (h[i-1] + (s[i-1]-'a'+1)*p_pow[i-1]) % m;
        }

        ll cnt = 0;

        f(l,1,n+1){
                set<ll> hs;
                f(i,0,n-l+1){
                        ll cur_h = (h[i+l] - h[i] + m ) %m;
                        cur_h = ( cur_h * p_pow[n-i-1])%m;
                        if(ps_bad[i+l] - ps_bad[i] <= k){
                                hs.insert(cur_h);
                        }
                }
                cnt += sz(hs);
        }
        cout << cnt << ln;
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
