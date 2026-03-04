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

int n,m,k,mf;
string s;
const int N = 2e5 + 1;
const int M = 11;

int memo[N][M];

int fu(int pos, int jum){// donde estas? - cuanto saltaste? - de que estado viniste?
	if(memo[pos][jum]!= -1)return memo[pos][jum];
	if(pos >= n)return 0;
	if(s[pos] == 'C')return mf;
	if(s[pos] == 'W'){
		return memo[pos][jum] = 1 + fu(pos+1,0);
	}
	int ret = mf;
	f(i,1,m+1){
		ret = min(ret,fu(pos+i,i));
	}
	return memo[pos][jum]= ret;
}// retorna cuanto nadaste

void so(int test){
	cin >> n >> m>> k;
	cin >> s;
	fill(&memo[0][0], &memo[0][0] + N * M , -1); // Inicializa todo con -1
	mf = k + 1;
	int ans = mf;
	f(i,1,m+1){
		ans = min(ans,fu(i-1,i));
	}
	cout << (ans <= k? "YES": "NO") << ln;
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
