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

const int N = 2e5 + 5;

vector<vi> divi(N);

void init(){
        f(i,1,N){
                for(int j = i ; j < N ; j += i){
                        divi[j].pb(i);
                }
        }
}

void so(int test){
        int n;
        cin >> n;
        vi frec(N,0);
        int ans = 0;
        vi cons;
        f(i,0,n){
                int num;
                cin >> num;
                vi aux;
                f(j,0,sz(divi[num])){
                        frec[divi[num][j]]++;
                        if( ans < frec[divi[num][j]] and frec[divi[num][j]] <= i){
                                ans = frec[divi[num][j]];
                        }
                        if(frec[divi[num][j]] == i+1){
                                aux.pb(divi[num][j]);
                        }
                }
                for(auto x : cons){
                        if( ans < frec[x] and frec[x] <= i){
                                ans = frec[x];
                        }
                }
                swap(aux,cons);
                cout << ans << ' ';
        }
        cout << ln;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
        init();

	int tt = 1;
	cin >> tt;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
