#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

int INF = (1<<30);

void so(int test){
	int n;
	cin >> n;
	vii v(n);
	forn(i,n){
		cin >> v[i].fi;
		v[i].se = i;
	}
	sort(all(v));

	vector<vi> dp(n+5,vi(3,-1));//estoy aca, q hago?

	dp[0][0] = 0;
	forsn(i,0,n-1){
		forn(j,3)if(dp[i][j] != -1){
			dp[i+1][min(2,j+1)] = max(dp[i+1][min(2,j+1)],dp[i][j]);
			if(j == 2 and i+1 < n){
				dp[i+1][0] = max(dp[i+1][0],dp[i][j] + v[i+1].fi - v[i].fi);
			}
		}
	}
	int curr_j = 2; 
    
	vi romp; 

	romp.push_back(n-1);
	dforn(i, n) {
		if (i == 0) break;

		int prev_i = i - 1;
		bool ok = 0;

		if (curr_j == 0) {
			int val_salto = v[i].fi - v[prev_i].fi;
			&&

			if (dp[i][0] != -1 and dp[prev_i][2] != -1 and 
				dp[i][0] == dp[prev_i][2] + val_salto) {
				romp.push_back(prev_i);
				curr_j = 2; 
				ok = true;
			}
		}
		if (!ok) {

			if (curr_j == 2) {
				if (dp[prev_i][2] != -1 and dp[i][2] == dp[prev_i][2]) {
					curr_j = 2; // nos quedamos en 2
				} else if (dp[prev_i][1] != -1 and dp[i][2] == dp[prev_i][1]) {
					curr_j = 1; // veniamos de 1
				}
			}
			else if (curr_j == 1) {
				if (dp[prev_i][0] != -1 && dp[i][1] == dp[prev_i][0]) {
					curr_j = 0;
				}
			}
		}

	}

	vi ans(n);
	reverse(all(romp));
	int ind = 0;
	int co = 1;
	forn(i,n){
		int id = v[i].se;
		if(i <= romp[ind]){
			ans[id] = co;
		}
		if(i == romp[ind]){
			ind++;
			co++;
		}
	}
	cout << v[n-1].fi - v[0].fi - dp[n-1][2] << ' ' << co-1<< '\n';
	forn(i,n)cout << ans[i] << ' ';
	cout << '\n';

}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}
