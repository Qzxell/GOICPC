#include<bits/stdc++.h>
#define ln '\n'
#define pb push_back
#define vii vector<pair<int,int>>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

void so(){
    int n,s,m;
    cin >> n >> s >> m;//m min of the day
    vii v(n);

    for (int i = 0; i < n; ++i) {
        int a,b;
        cin >> a >> b;
        v[i] = {a,b};
    }
    sort(v.begin(),v.end());
    int co = 0;
    if (v[0].fi != 0 and co + s - 1 < v[0].fi) {
        cout << "YES\n"; 
        return;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (v[i].se + s - 1 < v[i+1].fi) {
            cout << "YES\n"; 
            return;
        }
    }
    if (v[n-1].se + s -1 < m) {
            cout << "YES\n"; 
            return;
    }
    cout << "NO\n";

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        so();
    }
    return 0;
}

