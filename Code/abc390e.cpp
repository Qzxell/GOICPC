#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using viii = vector<pair<ii,int>>  ;
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


const int N = 5004;
const int inf = - 2e9;
int dp[4][N][N];
int M[4][N];

void so(int test){
	int n,x;
	cin >> n >> x;
	viii v(n+1);//index 1
	f(i,1,n+1){
		int vt,a,c;
		cin >> vt >> a >> c;
		v[i].fi = {vt,a};
		v[i].se = c;
	}
	f(i,1,4){
		f(j,1,x+1)dp[i][0][j] = inf;
		f(k,1,n+1){
			f(j,1,x+1){
				if(v[k].fi.fi != i){
					dp[i][k][j] = dp[i][k-1][j];
				}else{
					if(v[k].fi.se <= j){
						dp[i][k][j] = max(
							dp[i][k-1][j-v[k].se]+ v[k].fi.se,
							dp[i][k-1][j]
							);
					}else{
						dp[i][k][j] = dp[i][k-1][j];
					}
				}
			}
		}
	}
	M[1][0] = dp[1][n][0];
	M[2][0] = dp[2][n][0];
	M[3][0] = dp[3][n][0];
	f(i,1,4){
		f(j,1,x+1)M[i][j] = max(dp[i][n][j],M[i][j-1]);
	}
	int s1,s2,s3;
	int ans = -1;
	s1 =s2 = s3 = 0;
	while(s1 + s2 + s3 <= x){
		ans = max(ans,min({M[1][s1],M[2][s2],M[2][s3]}));
		if(s1 <= s2 and s1 <= s3)s1++;
		else if(s2 <= s1 and s2 <= s3)s2++;
		else if(s3 <= s1 and s3 <= s2)s3++;
	}
	cout << ans ;



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
