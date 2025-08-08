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
        vi v(n);
        vi G(n);
        f(i,0,n)cin >> v[i];
        sort(all(v));
        ll ans = 0;

        if(v[0] == v[n-1]){
                cout << n/2 << ln;
                return;
        }
        for(int i = n-1; i >=0 ;i--){
                ans = max(ans, G[i]*1ll*(i+1));
                int in = lower_bound(all(v),v[i]) - v.begin();
                if(in-1 < 0)continue;
                in--;
                G[in] += G[i] + 1;
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
