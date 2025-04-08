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
	vi ab(26,1);
	int ans = 0;
	bool yes = 0;
	f(i,0,n){
		char acc;
		cin >> acc;
		string ga;
		cin >> ga;
		if(acc == '!'){
			if(yes) ans++;
			vi aux(26,0);
			f(j,0,sz(ga)){
				aux[ga[j]-'a'] = 1;
			}
			f(j,0,26)if(ab[j] != 0) ab |= aux[j];
			int c = 0;
			f(j,0,26)c += ab[j];
			if( c <= 1) yes = 1;
		}else if(acc == '.'){
			vi aux(26,1);
			f(j,0,sz(ga)){
				aux[ga[j]-'a'] = 0;
			}
			f(j,0,sz(ga)){
				ab[j] &= aux[j];
			}
			int c = 0;
			f(j,0,26)c += ab[j];
			if( c <= 1) yes = 1;
		}else{
			char uu = ga[0];
			ab[uu-'a'] = 0;

		}


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
