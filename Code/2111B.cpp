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
        int n,m;
        cin >> n >> m;
        int a,b;
        a = 1;
        b= 2;
        f(i,2,n){
                int c = a + b;
                a = b;
                b = c;
        }
        int ancho,largo,alto;
        ancho = largo = b;
        alto = a + b;
        f(i,0,m){
                int w,h,l;
                cin >> w >> l >> h;
                if(ancho <= w and largo <= l and alto <= h){
                        cout << 1 ;
                        continue;
                }
                if(alto <= w and ancho <= l and largo <= h){
                        cout << 1 ;
                        continue;
                }
                if(alto <= l and ancho <= w and largo <= h){
                        cout << 1 ;
                        continue;
                }


                cout << 0 ;
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
