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
        vi v(n);
        vi fr(101,0);
        vi uni;
        vi vis(101,0);
        f(i,0,n){
                cin >> v[i];
                if(fr[v[i]]==0)uni.pb(v[i]);
                fr[v[i]]++;
        }
        sort(rall(uni));
        int r = 1;
        f(i,0,sz(uni)){
                vis[uni[i]] = r;
                r+= fr[uni[i]];
        }
        f(i,0,n){
                cout << vis[v[i]] << ln;
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
