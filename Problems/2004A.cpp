#include<bits/stdc++.h>
#define ln '\n'
#define pb push_back
#define vii vector<pair<int,int>>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

void so(){
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i]; 
    }
    if (n!= 2) {
        cout << "NO\n"; 
        return;
    }
    if (n == 2 and abs(v[0] - v[1]) == 1) {
        cout << "NO\n"; 
        return;
    }
    cout << "YES\n";
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

