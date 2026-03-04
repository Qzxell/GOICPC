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
	int ma = 1e5 + 1;
	vi ga[n+1];
	f(i,0,n){
		int x;
		cin >> x;
		f(j,0,x){
			int ow;
			cin >> ow;
			ga[i].emplace_back(ow);
		}
	}
	map<int,double> m1;
	map<int,double> m2;
	double ans = 0;
	f(i,0,n){
		f(j,i+1,n){
			m1.clear();
			m2.clear();
			int le1 = sz(ga[i]);
			int le2 = sz(ga[j]);
			for(auto x : ga[i])m1[x]+= 1.0/le1;
			for(auto x : ga[j])m2[x]+= 1.0/le2;
			double acu = 0;
			for(auto x : m1){
				if(m2.count(x.fi) < 1)continue;
				acu += x.se * m2[x.fi];
			}
			ans = max(acu,ans);
		}
	}
	cout << ans ;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(12);

	int tt = 1;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
