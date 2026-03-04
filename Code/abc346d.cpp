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
	string s;
	cin >> s;
	vi pr(n);
	f(i,0,n) cin >> pr[i];
	string w1,w2;
	f(i,0,n){
		if(i&1){
			w1 += '0';
			w2 += '1';
		}else{
			w2 += '0';
			w1 += '1';
		}
	}
	int i1 = 0,i2 = 1;
	ll sum1 = 0;
	ll sum2 = 0;
	f(i,0, i1+1 ){
		if(s[i] != w1[i]){
			sum1 += pr[i];
		}
		if(s[i] != w2[i]){
			sum2 += pr[i];
		}
	}
	f(i,i2,n ) {
		if(s[i] != w2[i]){
			sum1 += pr[i];
		}
		if(s[i] != w1[i]){
			sum2 += pr[i];
		}
	}
	ll ans = min(sum1,sum2);
	ll rr,rrr;
	rr = rrr = 0;
	f(i,0,n){
		if(s[i] != w1[i])rr  +=pr[i];
		if(s[i] != w2[i])rrr +=pr[i];
	}
	ans = min(ans,rr);
	ans = min(ans,rrr);
	for(int i = 1 ; i < n ;i++){
		if(s[i] != w2[i]){
			sum1 -= pr[i];
		}
		if(s[i] != w1[i]){
			sum1 += pr[i];
		}
		if(s[i] != w1[i]){
			sum2 -= pr[i];
		}
		if(s[i] != w2[i]){
			sum2 += pr[i];
		}
		ans = min(ans,min(sum1,sum2));
	}
	cout << ans << ln;

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
