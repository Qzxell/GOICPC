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
        string s,t;
        cin >> s >> t;
        string a,b;
        a = s; b = t;
        sort(all(a));
        sort(all(b));
        if(a != b){
                cout << "NO" << ln;
                return;
        }
        string ga1,ga2;
        f(i,0,n){
                if(s[i] != 'b')ga1 += s[i];
                if(t[i] != 'b')ga2 += t[i];
        }
        if(ga1 != ga2) cout << "NO" ;
        else cout << "YES";
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
