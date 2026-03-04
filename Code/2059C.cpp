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
	vector<vi> v(n,vi(n));
	f(i,0,n)
		f(j,0,n)
			cin >> v[i][j];

	vi vis(n+1,0);
	vi dis(n+1,0);
	vi num;
	f(j,0,n){
		int ga = 0;
		for(int k = n-1; k >= 0;k--){
			if(v[j][k] != 1)break;
			ga++;
		}
		num.pb(ga);
	}
	int ans = 1;
	for(auto x : num){
		if(x == ans)ans++;
	}


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
