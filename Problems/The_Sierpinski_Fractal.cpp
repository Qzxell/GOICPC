#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<char>  ;
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

vector<vi> fu(int n){
	if(n == 0){
		vector<vi> ret = {{' ', '/', '\\', ' '},{'/', '_', '_', '\\'}};
		return ret;
	}
	vector<vi> late = fu(n-1);
	int nn = sz(late) ;
	int lar = sz(late[0]);
	vector<vi> ret(2*nn,vi(2*lar,' '));
	f(i,0,nn){
		f(j,0,sz(late[0])){
			ret[i][j + lar/2] = late[i][j];
		}
	}
	f(i,0,nn){
		f(j,0,sz(late[0])){
			ret[i+nn][j] = late[i][j];
		}
	}
	f(i,0,nn){
		f(j,0,sz(late[0])){
			ret[i+nn][j+lar] = late[i][j];
		}
	}
	return ret;
}
int ga = 1;
void so(int test){
	int n;
	cin >> n;
        if(n == 0){
                ga = 0;
                return;
        }
	vector<vi> ans = fu(n-1);
	if(test > 1)cout << ln;
	for(auto x: ans){
		int c = 0;
                // sin o con esto, falla
		for(int i = 0 ; i < sz(x) ; i++)if(x[i] != ' ')c = i;
		for(int i = 0 ; i <= c ; i++)cout << x[i];
		cout << ln;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	int test = 1;
	while (ga){
		so(test++);
	}
	return 0;
}
