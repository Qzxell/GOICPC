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
    int n,k;
    cin >> n >> k;
    vi v(n);
    int c = 0;
    int ind = 0;
    f(i,0,n){
        cin >> v[i];
    }
    f(i,0,n){
        ind = i +1;
        c = 0;
        f(j,0,n)if(i != j){
            if((k + k + abs(v[i] - v[j])) % k ){
                c++;
            }
        }
        if(c == n-1){
                cout << "YES" << ln;
                cout << i+1 << ln;
                return;
        }
    }
    cout << "NO" << ln;
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
