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

const int N = 501;
const int mod = 1e9 + 7;
int memo[150000][N];

ll fu(int space,int pos){
	if(memo[space][pos] != -1) return memo[space][pos];
	if(pos <= 0)return 0 ;
	if(space == 0){
		return 1;
	}
	ll ret = 0;
	ret += (ret + fu(space, pos -1))%mod;
	if(space >= pos)ret =( ret +  fu(space - pos,pos-1))%mod;
	return memo[space][pos] = ret;
}
void so(int test){
	memset(memo, -1, sizeof(memo));
	int n;
	cin >> n;
	ll su = (n*(n+1))/2;
	if(su &1){
		cout << 0 << ln;
		return;
	}
	ll ans = fu(su/2,n);
	cout <<ans ;

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
