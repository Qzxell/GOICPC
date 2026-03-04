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
        vi ans(10,0);
        int n,d;
        cin >> n >> d;
        if(d == 5)ans[5] = 1;
        if(d%3 == 0 or n >= 3){
                ans[3 ] = 1;
        }
        if(d%9 == 0 or n >= 6){
                ans[9] = 1;
        }
        if(d % 3 == 0 and n >= 3){
                ans[9] = 1;
        }
        if(n >= 3 or d == 7){
                ans[7] = 1;
        }
        ans[1] = 1;
        for(int i = 1 ; i < 10;i+=2){
                if(ans[i])cout << i << ' ';
        }
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


