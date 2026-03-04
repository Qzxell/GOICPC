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

map<int,int> m;

void so(int test){
        int n;
        cin >> n;
        vi num;
        f(i,0,n){
                int x;
                cin >> x;
                if(m.count(x) == 0)num.pb(x);
                m[x]++;
        }
        sort(all(num));
        int tam = sz(m);
        int c = 0;
        int ans = 1;
        f(i,0,sz(num)){
                if(m[num[i]] == 1)tam--;
                c++;
                if(tam + ( i < sz(num) - 1? 1 : 0 >= c)ans =c;
                else break;
        }
        cout << ans << ln;
        m.clear();
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
