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
    vi a(n);
    vi b(n);

    vector<int> antp(n+1,0);
    vector<ll> ps(n+1,0);// sum until the i-esimo element
    vector<ll> au(n+1,0);
    

    f(i,0,n)cin >> a[i];
    f(i,0,n)cin >> b[i];

    f(i,1,n+1) ps[i] = b[i-1] + ps[i-1];

    for(int i = n-1 ; i >= 0 ; i--){
        int lo = i,lf = n;
        int mid;
        while (lo < lf){
            mid = (lo + lf) / 2;
            if( ps[mid+1] - ps[i] >= a[i]) lf = mid;
            else lo = mid + 1;
        }
        au[lo] += max( 0ll , b[lo] - (ps[lo+1] - ps[i] - a[i]) );

        antp[i] += 1;
        antp[lo] -= 1;
    }
    f(i,1,n+1) antp[i] += antp[i-1];
    f(i,0,n){
        au[i] = antp[i]*1ll*b[i] + au[i];
        //au[i] = antp[i]*1ll*b[i];
        cout << au[i] << ' ';
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
