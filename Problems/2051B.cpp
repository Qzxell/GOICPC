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
	ll n,a,b,c;	
	cin >> n >> a >> b >> c;
	ll sum = a+b+c;
	ll day = ((n)/sum)*3;
	ll res = (n - (n/sum)*sum);
	if(res > 0){
		day++;
		res -=a;
	}
	if(res > 0){
		day++;
		res -=b;
	}
	if(res > 0){
		day++;
		res -=c;
	}
	cout << day << ln;
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