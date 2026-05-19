#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()
int test = 1;

int n;
string s;
const int N = 6005;
int dp[N][N];
int vis[N][N];
bool ans = 0;

int rec(int l,int r){
	if(l > r)
		return -1;
	if(vis[l][r] == test)return dp[l][r];
	vis[l][r] = test;

	if(((n - (r-l+1))&1) == 0){//Monacrpio
		dp[l][r] = max( rec(l+1,r) + (s[l] == '(' ? -1 : 1) , rec(l,r-1) + (s[r] == '(' ? -1 : 1));
		if(s[l] == ')') dp[l][r] = max(1,dp[l][r]);
		if(s[r] == ')') dp[l][r] = max(1,dp[l][r]);
		return dp[l][r];
	}
	return dp[l][r] = min(rec(l+1,r)  , rec(l,r-1));
}

void so(int test){
	cin >> n;
	cin >> s;
	ans = 0;
	if(s[0] == '(' and rec(1,n-1) >= 1)
		ans = 1;
	if(s[n-1] == '(' and rec(0,n-2) >= 1)
		ans = 1;
	cout << (ans ? "Monocarp" : "Polycarp" ) << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
	cin >> tt;
        while(tt--) so(test++);
        return 0;
}

