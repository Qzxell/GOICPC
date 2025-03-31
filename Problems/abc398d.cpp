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
	int n,r,c;
	cin >> n >> r >> c;
	string s;
	ii lle = {r,c};
	cin >> s;

	int time = 0;
	int c = 0;
	int fin = -1;
	ii cur = {0,0};
	while(c < n){
		if(s[c] == 'N')cur.fi--;
		if(s[c] == 'W')cur.se--;
		if(s[c] == 'S')cur.fi++;
		if(s[c] == 'E')cur.se++;
		c++;
		if(cur == lle)fin = c;
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
