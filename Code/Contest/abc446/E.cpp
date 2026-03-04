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

int m,a,b;
bool vis[1005][1005];
bool dp[1005][1005];

int ne(int g1 , int g2){
	return (b*g1 + a*g2)%m;
}
bool rec(int g1,int g2){
	if(g1 % m == 0 or g2 % m == 0)return true;
	if(vis[g1][g2])return dp[g1][g2];
	vis[g1][g2] = 1;
	bool ret = 0;
	ret |= rec(g2,ne(g1,g2));
	return dp[g1][g2] = ret;

}

void so(int test){
	cin >> m >> a >> b;
	int ans = 0;
	forn(i,m)
	forn(j,m){
		ans += rec(i,j);
	}
	cout << m*m - ans << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

