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

const int N = 102;
string s;
vector<string> bag[N];
int memo[N][N];

int dp(int pos, int ind){
	if(ind < 0 )return 0;
	if(pos < 0)return N+2;
	if(memo[pos][ind] != 0) return memo[pos][ind];
	int ret = dp(pos - 1 , ind);
	for(auto st : bag[pos]){
		int le = sz(st);	
		if(le - 1 > ind) continue;
		int in = ind - le +1;
		int y = 1;
		f(i,in,in + le){
			if(s[i] != st[i - in]){
				y=0;
				break;
			}
		}
		if(!y)continue;
		ret = min(ret,1 + dp(pos-1,ind-le));
	}
	return memo[pos][ind] = ret;
}

void so(int test){
	cin >> s;
	int b;
	cin >> b;
	f(i,0,b){
		int c;
		cin >> c;
		f(j,0,c){
			string k;
			cin >> k;
			bag[i].pb(k);
		}
	}
	int le = sz(s);
	ll ans = dp(b-1,le-1);
	if(ans > b)cout << -1  << ln;
	else cout << ans << ln;
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
