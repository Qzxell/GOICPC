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
	int n,m,k;
	cin >> n >> m >> k;
	vector<vi> ap(n+2,vi(m+2,0));
	int w;
	cin >> w;
	vi go(w);
	f(i,0,w)cin >> go[i];
	f(i,1,n+1){
		f(j,1,m+1){
			if(i + k -1 < n+1 and j + k -1 < m + 1){
				ap[i][j] += 1;
				ap[i+k][j] += -1;
				ap[i][j+k] += -1;
				ap[i+k][j+k] += 1;
			}
		}
	}
	f(i,1,n+1){
		f(j,1,m+1){
			ap[i][j] += ap[i][j-1];
		}
	}
	f(j,1,m+1){
		f(i,1,n+1){
			ap[i][j] += ap[i-1][j];
		}
	}
	vi gaa;
	f(i,1,n+1){
		f(j,1,m+1){
			gaa.pb(ap[i][j]);
		}
	}
	sort(rall(gaa));
	sort(rall(go));
	ll ans = 0;
	f(i,0,w){
		ans  += gaa[i]*1ll*go[i];
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
