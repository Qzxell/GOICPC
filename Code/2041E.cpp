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
	int len= 5;
	swap(n,m);
	if(n==m){
		cout << 1 << ln;
		cout << n << ln;
		return;
	}
	vi ans(5);
	ans[2] = n;
	int lle = m*5;
	int sum =n;
	cout << 5<< ln;
	if(n < m ){
		if( n >= 0){
			ans[0] = 0;
			ans[1] = 0;
		}else{
			ans[0] = n;
			ans[1] = n;
			sum += 2*n;
		}
		int re = lle - sum;
		ans[3]=re/2;
		ans[4] = re - re/2;
		f(i,0,5)cout<<ans[i] <<' ';
		cout<<ln;
	}else{
		if(n <= 0){
			ans[3] = ans[4] = 0;
		}else{
			ans[3] = ans[4] = n;
			sum += 2*n;
		}
		int re = lle -sum;
		ans[1] = re/2;
		ans[0] = re - re/2;
		f(i,0,5)cout<<ans[i] <<' ';
		cout<<ln;
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
