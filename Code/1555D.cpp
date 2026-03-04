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
	int n,q;
	cin >> n >> q;
	string s;	
	cin >> s;
	vi v(n);
	f(i,0,n) v[i] = s[i] - 'a';
	vector<vi> v1(3, vi(n+1,0));
	vector<vi> v2(3, vi(n+1,0));
	vi oh = {2,1,0};
	f(j,1,n+1){
		v1[0][j] = (j % 3 != v[j-1] ? 1 : 0 ) ;
		v1[1][j] = ((j + 1 )%3!= v[j-1] ? 1 : 0);
		v1[2][j] = ((j + 2)%3!= v[j-1] ? 1 : 0);
		v2[0][j] = (oh[j%3]     != v[j-1] ? 1 : 0);
		v2[1][j] = (oh[(j+1)%3]  != v[j-1] ? 1 : 0);
		v2[2][j] = (oh[(j+2)%3]  != v[j-1] ? 1 : 0);
	}
	f(i,1,n+1){
		v1[0][i] += v1[0][i-1];
		v1[1][i] += v1[1][i-1];
		v1[2][i] += v1[2][i-1];
		v2[0][i] += v2[0][i-1];
		v2[1][i] += v2[1][i-1];
		v2[2][i] += v2[2][i-1];
	}
	f(i,0,q){
		int l,r;
		cin >> l >> r;
		int ans = min({
			v1[0][r] - v1[0][l-1],
			v1[1][r] - v1[1][l-1],
			v1[2][r] - v1[2][l-1],
			v2[0][r] - v2[0][l-1],
			v2[1][r] - v2[1][l-1],
			v2[2][r] - v2[2][l-1]
				});
		cout << ans  << ln;
	}

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
