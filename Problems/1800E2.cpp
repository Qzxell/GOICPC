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
    string a,b;
    cin >> a >> b;
    if(k <= n/2){
        sort(all(a));
        sort(all(b));
        cout << ( a==b?"YES" : "NO") << ln;
    }else{
        string ap,bp;
        for(int i = max(0,n-k) ; i < min(n,k) ; i++){
            ap += a[i];
            bp += b[i];
            a[i] ='$';
            b[i] ='$';
        }
        if (ap != bp) {
            cout << "NO"  << ln;
            return;
        }
        sort(all(a));
        sort(all(b));
        cout << ( a==b?"YES" : "NO") << ln;
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
