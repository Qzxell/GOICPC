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

vi wasa;
void so(int test){
    int n;
    cin >> n;
    int owo = lower_bound(all(wasa),n) - wasa.begin();
    cout << owo + 1 << ln;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    wasa.pb(1);
    int u = 1;
    while(u < 1e5){
        u = (u+1)*2;
        wasa.pb(u);
    }
    int tt = 1;
    cin >> tt;
    int test = 1;
    while (tt--){
        so(test++);
    }
    return 0;
}
