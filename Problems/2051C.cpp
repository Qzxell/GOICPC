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
	int n,m,k;
	cin >> n >> m >> k;
	vi lis(m);
	vi q(k);
	vi wasa(n+1,0);
	f(i,0,m)cin >> lis[i];
	f(i,0,k){
		cin >> q[i];
		wasa[q[i]] ++;
	}

	if( k < n-1){
		f(i,0,m)cout << 0 ;
		cout << ln;
		return;
	}
	if( k== n){
		f(i,0,m)cout << 1;
		cout << ln;
		return;
	}
	if( k == n-1){
		int nose = -1;
		f(i,1,n+1)if(wasa[i] == 0)nose = i;
		f(i,0,m){
			if(nose == lis[i])cout << 1 ;
			else cout << 0;
		}
		cout << ln;
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
