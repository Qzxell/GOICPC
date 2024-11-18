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
    vi od;
    vi ev;

    if (n <= 4) {
       cout << -1 << ln; 
       return;
    }
    f(i,1,n+1){
        if (i&1) {
            od.pb(i);   
        }else{
            ev.pb(i);
        }
    }
    if (ev[sz(ev)-1] % 3 == 0) {
        swap(od[0],od[1]) ;
    }else if (ev[sz(ev)-1] % 3 == 1) {
        swap(od[0],od[2]) ;
    }
    for(int i : ev)cout << i << ' ';
    for(int i : od)cout << i << ' ';
    cout << ln;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt =1;
    cin >> tt;
    int test = 1;
    while (tt--){
        so(test++);
    }
    return 0;
}
