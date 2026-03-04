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
	map<string ,int> m;
	map<int ,string> m_;
	f(i,0,n){
		string s;
		cin >> s;
		m[s] = i;
		m_[i] = s;
	}

	int mt[17][17];
	f(i,0,17)f(j,0,17)mt[i][j] = 0;

	f(i,0,k){
		string a,b;
		cin >> a >> b;
		mt[m[a]][m[b]] = 1;
	}

	vi ind;
	int ma = 0;
	f(mask,0, (1<<n)){
		f(j,0,17)if((mask>>j)&1)ind.pb(j);
		int le = sz(ind);
		bool yes = 1;
		f(i,0,le)f(j,0,le)if(i != j){
			if(mt[ind[i]][ind[j]]){
				yes = 0;
				break;
			}
		}
		if(yes){
			ma = max(ma,sz(ind));
		}
		ind.clear();
	}
	f(mask,0, (1<<n)){
		f(j,0,17)if((mask>>j)&1)ind.pb(j);
		int le = sz(ind);
		bool yes = 1;
		f(i,0,le)f(j,0,le)if(i != j){
			if(mt[ind[i]][ind[j]]){
				yes = 0;
				break;
			}
		}
		if(yes and sz(ind) == ma){
			cout << ma << ln;
			vector<string> sss;
			f(i,0,ma) sss.pb(m_[ind[i]]);
			sort(all(sss));
			for(auto x : sss){
				cout << x<< ln;
			}

			return;
		}
		ind.clear();
	}
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
