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
        vector<string> s(n),t(n);
        f(i,0,n)cin >> s[i];
        f(i,0,n)cin >> t[i];
        auto dif = [&] (){
                int cont = 0;
                f(i,0,n)
                        f(j,0,n)
                                if(s[i][j] != t[i][j])cont++;
                return cont;
        };
        vector<string> temp = s;
        auto rotate = [&] (){
                f(i,0,n){
                        f(j,0,n){
                                temp[j][n-i-1] = s[i][j];
                        }
                }
                swap(temp,s);
        };
        int ans = 1e9;
        f(i,0,4){
                ans = min(ans,dif() + (int)i);
                rotate();
        }
        cout << ans ;
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
