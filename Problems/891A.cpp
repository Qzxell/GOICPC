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
	f(i,0,n)cin >> v[i];
	int u = 0;
	bool yes = 1;
	int dis = n + 2;
	f(i,0,n){
		if(v[i] == 1)u++;
		int wasa = v[i];
		int j = i  ;
		while(j < n){
			wasa = __gcd(wasa,v[j]);
			if(wasa == 1){
				yes = 0;
				break;
			}
			j++;
		}
		if(wasa == 1)dis = min((int)dis,(int)(j - i) - 1);
	}
	if(u){
		cout << n - u ;
		return;
	}
	if(yes)cout << -1 ;
	else cout << n + dis;
	


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
