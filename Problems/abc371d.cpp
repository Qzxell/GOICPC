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
#define vl vector<ll>  
#define fi first
#define se second


void so(){
    int n;
    cin >> n;
    vi x(n);
    vl ps(n+1,0);
    vi p(n);
    for(int &j :x)cin >> j;
    for(int &j :p)cin >> j;
    for (int i = 1; i <= n; ++i) {
        ps[i] = ps[i-1] + p[i-1]; 
    }
    int q;
    cin >> q;
    for(int i =0 ; i < q; i ++){
        int l,r;
        cin >> l >> r;
        int posi = lower_bound(all(x),l) - x.begin();
        int posf = upper_bound(all(x),r) - x.begin();
        posf--;
        if (posf < posf or posf < 0 or posi < 0) {
            cout << 0 << ln;
            continue;
        }
        cout << ps[posf+1] - ps[posi] << ln;


        
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    while (tt--){
        so();
    }
    return 0;
}

