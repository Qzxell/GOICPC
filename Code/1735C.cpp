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

vi leder(26,-1);
int papi(int v) {
    if (leder[v] == v)
        return v; 
    return leder[v] = papi(leder[v]);
}

void so(int test){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vi son(26,-1);
        vi vis(26,0);
        f(i,0,26)leder[i] = i;
        vi ans(n);
        int co = 0;
        f(i,0,n){
                if(son[s[i]-'a'] == -1){
                        f(j,0,26)if(!vis[j] and papi(j) != papi(s[i]-'a') and s[i]-'a' != j){
                                son[s[i]-'a'] = j;
                                leder[j] = papi(s[i] - 'a');
                                vis[j] = 1;
                                co++;
                                break;
                        }
                }
                if(son[s[i] -'a'] == -1){
                        f(j,0,26)if(!vis[j])son[s[i]-'a'] = j;
                }
                ans[i] = son[s[i] - 'a'];
        }
        f(i,0,n)cout << (char)(ans[i] + 'a') ;
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
