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
        int n,k;
        cin >> n >> k;
        vi l(n),r(n);
        f(i,0,n) cin >> l[i];
        f(i,0,n) cin >> r[i];
        ll ans = 0;
        f(i,0,n){
                ans += max(l[i],r[i]); 
                l[i] = min(l[i],r[i]);
        }
        sort(rall(l));
        f(i,0,min(n,k-1)) ans += l[i];
        ans ++;
        cout << ans<<ln;
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
