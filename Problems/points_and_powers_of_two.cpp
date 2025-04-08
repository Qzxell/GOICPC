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
	map<ll,bool> m;
	f(i,0,n){
		cin >> v[i];
		m[v[i]] = 1;
	}
	f(i,0,n){
		int num = v[i];
		f(j,0,32){
			ll n1,n2;
			n1 = num + (1<<j);
			n2 = num + (1<<j) + (1<<j);
			if(m.count(n1) and m.count(n2)){
				cout << 3<<ln;
				cout <<num << ' ' << n1 << ' ' << n2 << ln;
				return;
			}
		}
	}
	f(i,0,n){
		int num = v[i];
		f(j,0,32){
			ll n1,n2;
			n1 = num + (1<<j);
			if(m.count(n1)){
				cout << 2<<ln;
				cout <<num << ' ' << n1 << ln;
				return;
			}
		}
	}
	cout << 1 << ln;
	cout << v[0] << ln;

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
