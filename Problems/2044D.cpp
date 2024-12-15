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
#define sz(v) = ((int)(v).size())
#define all(v) = (v).begin(),(v).end()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

void so(int test){
    int n;
    cin >> n;
    vi v(n);
    f(i,0,n)cin >> v[i];
    vi freq(n+1,0);
    vi ans(n,-1);
    f(i,0,n){
        if (freq[v[i]] == 0) {
            ans[i] = v[i];
            freq[v[i]]++;
        }
    }
    int ind = 1;
    f(i,0,n)if(ans[i] == -1){
        while(freq[ind] != 0){
            ind++;
        }
        ans[i] = ind;
        ind++;
    }
    f(i,0,n)cout << ans[i]<< ' ';
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
