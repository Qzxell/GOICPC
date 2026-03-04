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
	set<int> ans;
	f(i,0,sz(s)-2){
		string ga ;
		if(i+4 < sz(s)){
			ga += s[i];
			ga += s[i+1] ;
			ga += s[i+2];
			ga += s[i+3];
			ga += s[i+4];
			if(ga == "twone"){
				ans.insert(i+3);
				i+=3;
				continue;
			}
		}
		ga ="";
		ga += s[i];
		ga += s[i+1] ;
		ga += s[i+2];
		if(ga=="one")ans.insert(i+2);
		if(ga=="two")ans.insert(i+2);
	}
	cout <<sz(ans)<<ln;
	for(auto x :ans)cout << x <<' ';

	cout<< ln;
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
