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
	vi v(n);
	int c = 0;
	f(i,0,n) cin >> v[i];

	int lo = 0,lf = n-1;
	while(v[lo] == 0)lo++;
	while(v[lf] == 0)lf--;
	if(lo > lf){
		cout << 0 <<ln;
		return;
	}
	f(i,lo,lf+1)if(v[i] == 0)c++;

	if(c == 0 ){
		cout << 1 << ln;
		return;
	}else {
		cout << 2 << ln;
		return;
	}

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