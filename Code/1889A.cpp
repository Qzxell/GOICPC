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

string s;
vi ans;

int rec(string s,int index){
        int le = sz(s);
        if(le == 0)return 0;
        if(s[0] != s[le-1]){
                if(le == 2)return 0;
                return rec(s.substr(1,le-2),index+1);
        }
        if(s[0] == '1'){
                ans.pb(index);
                return  1 + rec("01" + s,index);
        }
        ans.pb(index + le);
        return rec(s + "01",index) + 1;
}

void so(int test){
	int n;
        cin >> n;
        cin >> s;
        if(n&1){
                cout << -1 << ln;
                return;
        }
        bool yes = 1;
        f(i,0,n)if(s[i] == s[n-i-1]) yes = 0;
        if(yes){
                cout << 0 << ln;
                return;
        }
        int cont_u = 0;
        f(i,0,n)if(s[i] == '1')cont_u++;
        if(cont_u != n - cont_u){
                cout << -1 << ln;
                return;
        }
        int anss = rec(s,0);
        cout << anss << ln;
        for(auto x : ans)cout << x << ' ';
        cout << ln;
        ans.clear();

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
