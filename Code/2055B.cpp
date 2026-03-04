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
	int n;
	cin >> n;
	vi a(n),b(n);
	f(i,0,n)cin >> a[i];
	f(i,0,n)cin >> b[i];
	int c =0 ;
	int ind = -1;
	f(i,0,n){
		if(b[i] > a[i]){
			c++;
			ind = i;
		}
		if(c > 1 ){
			cout << "NO" << ln;
			return;
		}
	}
	if(c == 0 ) {
		cout << "YES "<<ln;
		return;
	}
	int dif = b[ind] - a[ind];
	f(i,0,n){
		if(i == ind)continue;
		if(b[i] > a[i] - dif){
			cout << "NO" << ln;
			return;
		}
	}
	cout << "YES "<<ln;


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
