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
    f(i,0,n)cin >> a[i];
    vi b(n);
    f(i,0,n)cin >> b[i];

    vi dm(n);
    vi dmi(n);


    int aux = 0;
    for (int i = 0 ; i < n;i++){
        if (b[aux] >= a[i]) {
            dmi[i]  = b[aux];
        }else{
            while(b[aux] < a[i])aux++;
            dmi[i] = b[aux];
        }
    }
    int cur = b.back();
    dm[n-1] = cur;
    for (int i = n-1 ; i >= 1;i--){
        if(b[i-1] >= a[i] ){
            dm[i-1] = cur;
        }else{
            cur = b[i-1];
            dm[i-1] = cur;
        }
    }
    f(i,0,n)cout << dmi[i] - a[i] << ' ';
    cout << ln;
    f(i,0,n)cout << dm[i] - a[i] << ' ';
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
