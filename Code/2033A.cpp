#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second
#define f(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a) for(ll i = (ll)a - 1; i >= (ll)b; i--)

void so(int test){
    int n;
    cin >> n;
    int k ,s;
    k = s = 0;

    int c = 1;
    while(true){
        if (c&1 ) {
            if (k - 2*(c) + 1 < -n) {
                cout << "Sakurako\n" ;
                return;
            }
            k -= (2*c -1 );
        }else{
            if (k + (2*c) - 1 > n) {
                cout << "Kosuke\n" ;
                return;
            }
            k += (2*c -1);
        }
        c++;
    }
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
