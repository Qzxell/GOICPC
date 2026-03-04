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

bool yes = 1;
void so(int test){
        int c,n;
        cin >> c >> n;
        if(c == n and c == 0){
                yes = 0;
                return;
        }
        vi v(n);
        vi lugar(n+1,-1);
        f(i,0,n){
                cin >> v[i];
        }
        int aux = 0;
        f(i,0,n){
                aux += v[i];
                aux %= c;
                if(lugar[aux] != -1){
                        f(j,lugar[aux] + 1 , i+1){
                                cout << j+1 << ' ';
                        }
                        cout << ln;
                        return;
                }
                lugar[aux] = i;
                if(aux == 0){
                        f(j,0,i+1){
                                cout << j+1  << ' ';
                        }
                        cout << ln;
                        return;
                }
        }
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	int test = 1;
	while (yes){
		so(test++);
	}
	return 0;
}
