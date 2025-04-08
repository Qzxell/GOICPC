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

const int N = 1e5 + 2;
vi freq(N,0);

void so(int test){
	int n,x;
	cin >> n >> x;
	int z;
	f(i,0,n){
		cin >> z;
		freq[z]++;
	}
	ll ans = 0;
	if(x == 0){
		f(i,0,N){
			if((x^i) >= N)continue;
			ans += (freq[i]*1ll*(freq[x^i]-1))/2;
		}
		cout << ans << ln;
		return;
		
	}
	f(i,0,N){
		if((x^i) >= N)continue;
		ans += (freq[i]*1ll*freq[x^i]);
	}
	cout << ans/2;
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
