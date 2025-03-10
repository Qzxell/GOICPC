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
	ll n,x,k;
	cin >> n >> x >> k;
	string s;
	cin >> s;
	bool yes = 1;
	int ans = 0;
	f(i,0,n){
		if(s[i] == 'L')x--;
		if(s[i] == 'R')x++;
		k--;
		if(x == 0){
			yes = 0;
			ans++;
			break;
		}
	}
	if(yes){
		cout << 0 << ln;
		return;
	}
	int end = 1;
	int c = 0;
	f(i,0,n){
		if(s[i] == 'L')x--;
		if(s[i] == 'R')x++;
		c++;
		if(x == 0){
			end = 0;
			break;
		}
	}
	if(end){
		cout << 1 << ln;
		return;
	}
	cout << k/c + 1 << ln;




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
