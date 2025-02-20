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

int n,a,b;
string s;
ll dp(int pos,int st){
	if(pos == n){
		if(st == 0){ return a + b; }
		else return 2*a + b;
	}
	if(st == 0 and (s[pos] == '1' ))return (1ll<<62);
	if(st == 0 and pos -1 >= 0 and (s[pos-1] == '1' ))return (1ll<<62);
	if(st == 1){
		return min(dp(pos+1, st^1) + b + 2*a, dp(pos+1,st) + 2*b + a);
	}
	return min(dp(pos+1, st^1) + 2*b + 2*a, dp(pos+1,st) + b + a);
}
void so(int test){
	cin >> n >> a >> b;
	cin >> s;
	ll ans = dp(0,0);
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
