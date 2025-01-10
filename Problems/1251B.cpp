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
	int q;
	cin >> q;
	int un,ze;
	un = ze = 0;
	int leod =0;
	f(i,0,q){
		string s;
		cin >>s;
		if(sz(s)&1)leod++;
		f(i,0,sz(s)){
			if(s[i]=='1')un++;
			else ze++;
		}
	}
	int od =0;
	if(un&1)od++;
	if(ze&1)od++;
	int su = (un&1) + (ze&1);
	if(leod&1){
		if(su==1)cout <<q<<ln;
		else cout <<q-1<<ln;
	}else{
		if(leod==0){
			if(su >0)cout<<q-1<<ln;
			else cout << q<<ln;
			return;
		}
		if((su==0 or su == 2))cout<< q <<ln;
		else cout << q-1<<ln;
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
