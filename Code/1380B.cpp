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
	string s;
	cin >> s;
	vi v(27,0);
	f(i,0,sz(s))v[s[i]-'A']++;
	int ma = 0;
	int po = 0;
	f(i,0,27){
		if(ma < v[i]){
			po = i;
			ma = v[i];
		}
	}
	if(po == 'R' - 'A'){
		f(i,0,sz(s))cout << 'P' ;
	}else if(po == 'S' - 'A'){
		f(i,0,sz(s))cout << 'R' ;
	}else {
		f(i,0,sz(s))cout << 'S' ;
	}
	cout << ln;


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
