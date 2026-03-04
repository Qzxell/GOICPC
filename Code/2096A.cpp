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
        vi vis(n+1,0);
        vi ans(n,-1);
        int c = 1;
        int cc = n;
        for( int i = sz(s) -1 ; i >= 0 ; i--){
                if(s[i] == '<'){
                        ans[i+1] = c;
                        vis[c] = 1;
                        c++;
                }else{
                        ans[i+1] = cc--;
                        vis[ans[i+1]] = 1;
                }
        }
        c = n;
        vis[0] = 1;
        int uni = -1;
        f(i,0,n+1)if(!vis[i])uni  = i;
        ans[0] = uni;
        f(i,0,n)cout << ans[i] << ' ';
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
