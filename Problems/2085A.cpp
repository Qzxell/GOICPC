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
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        if(k == 0){
                f(i,0,n/2){
                        if(s[i] > s[n-i-1]){
                                cout << "NO" << ln;
                                return;
                        }
                        else if(s[i] == s[n-i-1])continue;
                        else{
                                cout << "YES" << ln;
                                return;
                        }
                }
                cout << "NO" << ln;
                return;
        }
        int c = 1;
        f(i,1,n){
                if(s[i] == s[i-1] ){
                        c++;
                }
        }
        if(c==n){
                cout << "NO" << ln;
                return;
        }
        cout << "YES" << ln;
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
