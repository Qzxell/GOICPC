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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    random_device rd;  
    mt19937 gen(rd()); 

    int owo = (rng() %1000)+1;
    cout << owo << ln;
    f(i,0,owo){
        int l = (rng() % 1000 ) +1;
        int r = (rng() % 1000 ) +l;
        int c = (rng()% 1000) *10;
        cout << l << ' ' << r << ' ' << c << ln;
    }


    return 0;
}

