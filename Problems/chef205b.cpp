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
        int pa = 0;
        int impar = 0;
        vi v(n+1);
        f(i,1,n+1){
                cin >> v[i];
                if(v[i] == 1 and (i&1))impar = 1;
                if(v[i] == 1 and (i%2==0))pa = 1;
        }
        f(i,1,n+1){
                if(v[i] == 2 and (i&1)){
                        if(impar)continue;
                        cout << "Yes" << ln;
                        return;
                }
                if(v[i] == 2 and (i%2 == 0)){
                        if(pa)continue;
                        cout << "Yes" << ln;
                        return;
                }
        }
        cout << "No" << ln;

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
