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
	bool yes = 1;
	int point = -1;
	f(i,0,n)if(s[i] == '0'){
		yes = 0;
		point = i;
		break;
	}
	if(yes ){
		cout << 1 << ' ' << n-1 << ' ' << 2 << ' ' << n << ln;
		return;
	}
	if(point < n/2){
		cout << point + 1<< ' ' << n << ' ' << point + 2 << ' ' << n  << ln;
	}else{
		cout << 1 << ' ' << point + 1 << ' ' << 1 << ' ' << point   << ln;
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
