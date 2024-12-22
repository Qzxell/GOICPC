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
	string wa = "abacaba";
	int ind = 0;
	int con = 0;
	for(int i = 0 ; i + 6 < n;i++){
		bool yes = 1;
		for(int j = i ;j < i+7;j++){
			if(s[j] == '?')continue;
			if(wa[j-i] != s[j]){
				yes = 0;
				break;
			}
		}
		if(yes){
			ind = i;
			con++;
		}
	}
	if(con == 1){
		f(i,0,n)if(s[i] == '?') s[i] = 'p';
		f(i,ind,ind + 7){
			s[i] = wa[i-ind];
		}
		cout << "YES" << ln;
		cout << s << ln;
		return;
	}
	cout << "NO" << ln;

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
