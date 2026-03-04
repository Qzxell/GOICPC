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
	int pp = 0,ss=0;
	f(i,0,n){
		if(s[i] == 'p')pp++;
		if(s[i] == 's')ss++;
	}
	f(i,0,n)if(s[i] == 'p'){
		f(j,i+1,n)if(s[j] == 's'){
			cout << "NO" << ln;
			return;
		}
	}
	int ppp = 0, sss = 0;
	f(i,1,n-1){
		if(s[i] == 'p')ppp++;
		if(s[i] == 's')sss++;
	}
	if(sss == 0 or ppp == 0){
		cout << "YES" << ln;
		return;
	}
	if(sss > 0 and ppp > 0){
		cout << "NO" << ln;
		return;
	}
	cout << "YES" << ln;

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
