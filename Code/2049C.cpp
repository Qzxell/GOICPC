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
	int n,x,y;
	cin >> n >> x >> y;
	vi v(n,-1);
	y -= x;
	int rot = x;
	if( n== 3){
		cout << 2 << ' ' << 1 << ' ' << 0 << ln;
		return;
	}
	if( y == 1 or y == n-1){
		for(int i = 0 ; i < n ;i++){
			 v[i] = (i&1 ? 1 : 0 ) ;
		}
		if(n&1)v[n-1] = 2;
		f(i,0,n)cout << v[i] << ' ';
		cout << ln;
		return;
	}
	v[0] = 1;
	v[1] = 2;
	v[n-1] = 2;
	v[y] = 0;
	auto fil = [&] (int l,int r ){
		int le = r - l -1;
		if(le&1){
			int c = (l == 1 ? 1 : 0);
			for(int i = l+1 ; i < r ; i++){
				if(c&1) v[i] = 1;
				else v[i] = 0;
				c++;
			}
		}else{
			int c = (l == 1 ? 1 : 0);
			for(int i = l+1 ; i < r ; i++){
				if(c&1) v[i] = 1;
				else v[i] = 0;
				c++;
			}
			v[r-1] = 2;
		}
	};
	fil(1,y);
	fil(y,n-1);
	rotate(v.begin(), v.begin() + n- x + 1 , v.end());
	for(int x : v ) cout << x << ' ';
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
