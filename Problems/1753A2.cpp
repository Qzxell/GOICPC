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
	int sum =0 ;
	f(i,0,n)cin >> v[i];
	f(i,0,n)sum += v[i];
	if(sum &1){
		cout << -1 << ln;
		return;
	}
	if(sum ==0){
		cout << n << ln;
		f(i,1,n+1)cout << i << ' ' << i << ln;
		return;
	}
	vi vis(n,0);
	int co = n+1;
	if(sum > 0){
		f(i,0,n){
			if(v[i] == 1 and i >= 1 and vis[i-1] == 0){
				vis[i] = co;
				vis[i-1] = co++;
				sum -= 2;
			}
			if(sum == 0)break;
		}
	}else{
		f(i,0,n){
			if(v[i] == -1 and i >= 1 and vis[i-1] == 0){
				vis[i] = co;
				vis[i-1] = co++;
				sum += 2;
			}
			if(sum == 0)break;
		}
	}
	//f(i,0,n)cout << vis[i] << ' ';
	vii ans ;
	f(i,0,n){
		if(vis[i] == 0)ans.pb({i+1,i+1});
		else{
			ans.pb({i+1,i+2});
			i++;
		}
	}
	cout << sz(ans) << ln;
	for(auto x : ans )cout << x.fi << ' ' << x.se << ln;
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
