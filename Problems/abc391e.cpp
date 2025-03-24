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

const int N = 2e6;
string s;
vector<vi> dp(N,vi(15,-1));
vi pot(15);
int to;

int re(int lex, int ord){
	if(!ord)return dp[lex][ord] = (s[lex] == '1' ? 1:0);
	int su = 0;
	int le = pot[ord];
	su += re(lex,ord-1);
	su += re(lex+le/3,ord-1);
	su += re(lex+2*le/3,ord-1);
	return dp[lex][ord] = (su >= 2? 1 : 0);
}
int swa(int x,int ord){
	if(ord == 0)return ((s[x] == '1' ? 1:0) == to ? 0 : 1);
	int a,b,c;
	int le = pot[ord];
	int su = 0;
	a = dp[x][ord-1];
	b = dp[x+le/3][ord-1];
	c = dp[x+2*le/3][ord-1];
	su = a+b+c;
	int wa = (to == 1 ? su : 3 - su );
	if(wa >= 2)return 0;
	vi vv;
	if(a != to)vv.pb(swa(x, ord-1));
	if(b != to)vv.pb(swa(x + le / 3, ord-1));
	if(c != to)vv.pb(swa(x + 2*le / 3 , ord-1));
	sort(all(vv));
	if(wa == 0){
		return vv[0] + vv[1];
	}else if (wa == 1){
		return vv[0];
	}

	return 0;

}

void so(int test){
	int n;
	cin >> n;
	cin >> s;
	s = '1' + s;
	pot[0] = 1;
	f(i,1,14)pot[i] = pot[i-1]*3;

	to = 1 - re(1,n);
	int ans = swa(1,n);
	cout << ans;
	
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
