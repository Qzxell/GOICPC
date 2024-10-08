#include<bits/stdc++.h>
#define ln '\n'
#define pb push_back
#define vii vector<pair<int,int>>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

void so(){
    int x,y,k;
    cin >> x >> y >> k;
    int xx = x*k;
    int yy = y*k;
    k--;
    int cur = -k/2;
    for (int i = 1; i <= k/2; ++i) {
        cout << cur << ' ' << cur << ln;;
        cur++;
    }
    int ma = 1e9;
    if (k&1 and xx == 0 and yy == 0) {
        cout << -ma << ' ' << ma << ln; 
    }else if (k&1) {
        cout << 0 << ' ' << 0 << ln; 
    }
    cur = 1;
    for (int i = 1; i <= k/2; ++i) {
        cout << cur << ' ' << cur << ln;;
        cur++;
    }
    if (k&1 and xx == 0 and yy == 0) {
        cout << ma << ' ' << -ma << ln; 
    }else cout << xx << ' ' << yy << ln;
    cout << ln;


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

