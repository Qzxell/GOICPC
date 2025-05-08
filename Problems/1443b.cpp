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
        ll a,b;
        cin >> a >> b;
        string s;
        cin >> s;
        int cont = 0;
        int in,fi;
        vii seg;
        f(i,0,sz(s)){
                if(s[i] == '1'){
                        if(cont == 0)in = i;
                        cont++;
                }else if(cont){
                        fi = i-1;
                        seg.pb({in,fi});
                        cont = 0;
                }
        }
        if(cont)seg.pb({in,sz(s)-1});
        if(seg.empty()){
                cout << 0 << ln;
                return;
        }
        ll cost = a;
        f(pos,0,sz(seg) -1){
                int dif = seg[pos+1].fi - seg[pos].se - 1;
                cost += min(dif*1ll*b , a);
        }
        cout << cost << ln;
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
