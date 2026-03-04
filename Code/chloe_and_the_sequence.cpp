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

ll memo[50];

ll rec(int n,ll pos){
	if(n == 0){
		return 1;
	}
	ll len = memo[n-1];
	if(pos <= len){
		return rec(n-1,pos);
	}
	if(pos == len + 1)return n + 1;
	return rec(n-1,pos-len-1);
}

void so(int test){
	ll n,k;
	cin >> n >> k;

	memo[0] = 1;
	f(i,1,51)memo[i] = 2*memo[i-1] + 1;

	ll ans = rec(n,k);
	cout << ans ;

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
