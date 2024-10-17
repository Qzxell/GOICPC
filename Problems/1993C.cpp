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


void so(int test){
    int n,k;
    cin >> n >> k;
    vi inv_p(2*k + 2, 0) ;
    int ma = 0;
    for(int i =0 ; i < n ;i++){
        int x;
        cin >> x;
        ma = max(ma,x);
        int res = x % k;
        int odd = ((x/k)&1);
        if(odd == 0){
            inv_p[res]++;
            inv_p[res + k]--;
        }else{
            inv_p[res+k]++;
            inv_p[k+k]--;
            inv_p[0]++;
            inv_p[res]--;

        }
    }
    for(int i = 1 ; i < 2*k+2; i++)inv_p[i] += inv_p[i-1];
    bool yes = 0;
    int mod_a = -1;
    int pari = 0;
    int paru = 0;

    for(int i = 0 ; i < 2*k; i++) if( n == inv_p[i]){
        yes = 1;
        mod_a = i%k;
        pari = (i <= k-1 ? 0 : 1);
    }
    if(!yes){
        cout << -1 << ln;
        return;
    }
    while(true){
        if(ma % k == mod_a and pari == ((ma/k)&1) ) {
            cout << ma  << ln;
            return;
        }else ma++;
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
