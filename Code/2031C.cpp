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
    if (n%2 == 0) {
        for(int i = 1 ; i <= n ; i+=2) {
            cout << (i +1)/2<<  ' ' << (i+1)/2 << ' ';
        }
        cout << ln;
    }else{
       if (n < 27){
            cout << -1 << ln;
            return;
        } 
        cout << 5 << ' ';
        for(int i = 1 ; i <= 4;i++){
            cout << i << ' ' << i << ' ';
        }
        cout << 5 << ' ';
        for(int i = 8 ; i <= 13;i++){
            cout << i << ' ' << i << ' ';
        }
        cout << 6 << ' ';
        cout << 7 << ' ' << 7 << ' ' << 5 << ' ' << 6 << ' ';
        n -= 27;
        for(int i = 1 ; i <= (n)/2 ; i++ ) {
            cout << i+13<<  ' ' << i + 13<< ' ';
        }
        cout << ln;

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
