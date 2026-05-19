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

int n;
string s;
const int N = 1e2 + 5;
int dp[N][N][N];
int vis[N][N][N];

bool rec(int sum, int l, int r,int tur){// turn 0 : alice
	if(sum < 0)return false;
	if(r - l + 1 != n and sum == 0)
		return dp[sum][l][r] = 1;
	if(l > r)return false;
	if(vis[sum][l][r])return dp[sum][l][r];
	vis[sum][l][r] = 1;
	if(tur){
		bool ret = 1;
		ret &=rec(sum, l+1 ,r , tur^1) ;
		ret &=rec(sum, l ,r-1 , tur^1) ;
		return dp[sum][l][r] = 1;
	}
	bool ret = 0;
	ret |= rec(sum + (s[l] == ')' ? -1 : 1 ), l+1 ,r , tur^1);
	ret |= rec(sum + (s[r] == ')' ? -1 : 1 ), l,r - 1 , tur^1);
	return dp[sum][l][r] = ret;
}

void so(int test){
	cin >> n;
	cin >> s;
	memset(vis, 0, sizeof(vis));
	cout << (rec(0,0,n-1,0) ? "MOnocarcp" : "polica") << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
	cin >> tt;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

