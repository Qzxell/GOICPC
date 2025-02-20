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

void so(int test){
	int n,m;
	cin >> n >> m;
	vector<string> v(n);
	f(i,0,n)cin >> v[i];
	vector<vector<int>> ps(n + 1,vector<int>(m + 1,0));//falta 1, para los lados
	vector<vector<int>> ps_d(n + 1,vector<int>(m + 1,0));// falta 0 , para el interior
	f(i,1,n+1){
		f(j,1,m+1){
			int va = (v[i-1][j-1] == '0');
			ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + va;
			ps_d[i][j] = (i*j - ps[i][j]);
		}
	}
	auto cal = [&](int i, int j, int x, int y){ return ps[x][y] + ps[i-1][j-1] - ps[x][j-1] - ps[i-1][y]; };//index-1
													      //
	auto cal_d = [&](int i, int j, int x, int y){ return ps_d[x][y] + ps_d[i-1][j-1] - ps_d[x][j-1] - ps_d[i-1][y];};//index-1
															//
	auto fu = [&](int i, int j, int top, int lef){
		int ret = 0;
		ret = cal(i+1,j+2,i+1,j+top-1);
		ret += cal(i+2,j+1,i+lef-1,j+1);
		ret += cal(i+lef,j+2,i+lef,j+top-1);
		ret += cal(i+2,j+top,i+lef-1,j+top);
		ret += cal(i+2,j+2,i+lef-1,j+top-1);
		return ret;
	};
	int ans = 1e9;
	f(i,5,n+1){
		f(j,4,m+1){
			f(x,0,n){
				f(y,0,m){
					if( x + i - 1 >= n or y + j - 1 >= m)continue;
					ans = min(ans,fu(x,y,i,j));
				}
			}
		}
	}
	cout << ans << ln;

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
