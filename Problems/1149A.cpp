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
        vi fr(3,0);
        f(i,0,n){
                int x;
                cin >> x;
                fr[x]++;
        }
        if(fr[1] == n or fr[2] == n){
                f(i,0,n){
                        cout << (fr[1] == n ? 1 : 2) << ' ';
                }
                cout << ln;
                return;
        }
        cout << 2 << ' ' << 1 << ' ';
        fr[1]--;
        fr[2]--;
        f(k,0,fr[2]){
                cout << 2 << ' ';
        }
        f(k,0,fr[1]){
                cout << 1 << ' ';
        }
        cout << ln;
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
