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

int n,m,x;
set<int> ans;
const int N = 1e3 + 2;
vector<pair<int,char>> al(N);
vi v(N);
bool vis[N][N];

void dp(int pos,int est){
	if(pos == m){
		ans.insert(est+1);
		return;
	}
	if(vis[pos][est])return;
	vis[pos][est] = 1;
	char dir = al[pos].se;
	int pas = al[pos].fi;
	if(dir == '?'){
		dp(pos+1, ( est + pas)%n);
		dp(pos+1, ( n +n +  est - pas)%n);
		return;
	}
	if(dir == '0'){
		dp(pos+1, ( est + pas)%n);
		return;
	}
	dp(pos+1, ( n +n +  est - pas)%n);
	return;
}

void so(int test){
	ans.clear();
	cin >> n >> m >> x;
	f(i,0,m+1)
		f(j,0,n+1)
			vis[i][j] = 0;

	f(i,0,m){
		int pas;
		char dir;
		cin >> pas >> dir;
		al[i] = {pas,dir};
	}
	dp(0,x-1);
	cout << sz(ans) << ln;
	for(auto x : ans)cout << x << ' ';
	cout << ln;
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
