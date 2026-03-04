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

vi rec(int n,int pa){ // pa -> 1 o 2
	if(n == 1){
		vi ga = {1};
		return ga;
	}
	vi ret;
	int c = 0;
	for(int i = pa ; i <= n ; i+=2){
		ret.pb(i);
		c++;
	}
	int uu = pa;
	if( (n&1) and pa == 1) pa = 2;
	else if( (n&1) and pa == 2) pa = 1;
	vi wasa = rec(n - c, pa);
	if(uu == 2){
		for(auto x : wasa)ret.pb(x*2-1);
	}else{
		for(auto x : wasa)ret.pb(x*2);
	}
	return ret;
}

void so(int test){
	int n;	
	cin >> n;
	vi ans = rec(n,2);// number , parity now, order now
	for (auto x : ans ){
		cout << x << ' ';
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
