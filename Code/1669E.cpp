#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<int>  ;
#define ln  '\n'
#define ll unsigned long long
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
        vector<string> v(n);
        vector<int> pos(n);
        vector<int> pos_(n);
        map<int,int> m[12];
        map<int,int> m_[12];
        f(i,0,n){
                cin >> v[i];
        }
        f(i,0,n){
                pos[i] = v[i][0] - 'a';
                pos_[i] = v[i][1] - 'a';
        }
        f(i,0,n){
                m[v[i][1] - 'a'][pos[i]]++;
                m_[v[i][0] - 'a'][pos_[i]]++;
        }
        ll ans = 0;
        f(i,0,12){
                ll can = 0;
                ll tot = 0;
                for(auto [a,b] : m[i]) tot += b;
                for(auto [a,b] : m[i]) {
                        can += (tot-b)*1ll*b;
                }
                ans += can;
        }
        f(i,0,12){
                ll can = 0;
                ll tot = 0;
                for(auto [a,b] : m_[i]) tot += b;
                for(auto [a,b] : m_[i]) {
                        can += (tot-b)*1ll*b;
                }
                ans += can;
        }
        cout << ans/2<< ln;
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
