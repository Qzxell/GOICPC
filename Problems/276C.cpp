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
        int n,q;
        cin >> n >> q;
        vi v(n);
        vi anti_ps(n+2,0);
        f(i,0,n)cin >> v[i];
        f(i,0,q){
                int l,r;
                cin >> l >> r;
                anti_ps[l]++;
                anti_ps[r+1]--;
        }
        f(i,0,n+1){
                anti_ps[i+1] += anti_ps[i];
        }
        sort(all(v));
        sort(anti_ps.begin()+1,anti_ps.begin()+n+1);
        ll ans = 0;
        f(i,1,n+1){
                ans += (anti_ps[i]*1ll*v[i-1]);
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
