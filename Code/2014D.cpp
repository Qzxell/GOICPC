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


void so(){
    int n,d,k;
    cin >> n >> d >> k;
    int l,r;
    vi st(n+1,0);
    vi end(n+1,0);
    for (int i = 0 ; i < k ; i++){
        cin >> l >> r;
        st[l]++;
        end[r]++;
    }
    vi memo(n+1,0);

    int cum = 0;
    for (int i = 1 ; i <= d ; i++){
        cum += st[i];
    }
    memo[1] = cum;
    for (int i = 2 ; i <= n-d+1 ; i++){
        int uwu = memo[i-1];
        uwu -= end[i-1];
        uwu += st[i+d-1];
        memo[i] = uwu;
    }
    int mi = 1e9;
    int ma = 0;
    int ansm,ansb;
    for (int i = 1 ; i <= n-d+1 ; i++){
        if (memo[i] > ma) {
            ansb = i; 
            ma = memo[i];
        }
        if (memo[i] < mi ) {
            ansm = i; 
            mi = memo[i];
        }
    }
    cout << ansb << ' ' << ansm << ln;;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--){
        so();
    }
    return 0;
}
