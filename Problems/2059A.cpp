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
	set<int> a,b;
	f(i,0,n){
		int x;
		cin >> x;
		a.insert(x);
	}
	f(i,0,n){
		int x;
		cin >> x;
		b.insert(x);
	}
	if(sz(b) >= 3){
		cout << "YES" << ln;
		return;
	}
	if(sz(b) == 1 and sz(a) >= 3){
		cout << "YES" << ln;
		return;
	}
	if(sz(b) == 2 and sz(a) >= 2){
		cout << "YES" << ln;
		return;
	}
	cout << "NO" << ln;

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
