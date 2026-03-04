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
        vi papi(n);
        f(i,0,n)cin >> v[i];

        papi[0] = 0;
        f(i,1,n){
                if(v[i] == v[i-1])papi[i] = papi[i-1];
                else papi[i] = i;
        }
        ll ans = (1ll<<62);
        f(i,0,n){
                ll score = v[i]*1ll*i;
                int pu = upper_bound(all(papi),papi[i]) - papi.begin();
                score += v[i]*1ll*(n-pu);
                ans = min(ans,score);
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
