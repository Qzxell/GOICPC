#include<bits/stdc++.h>
#define ln '\n'
#define ll long long
#define pb push_back
#define vii vector<pair<int,int>>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

void so(){
    int c,m,x;
    cin >> c >> m >> x;
    if (c > m) {
        swap(c,m); 
    }
    x += (m - c);
    if (x > c) {
        cout <<  c << ln;
        return;
    }
    int ap = (c - x + 2)/3;
    int app = (c- x )/3;
    int ans =  max(min(x + 2*ap,c -ap),min(x + 2*app,c -app));
    cout << ans << ln;
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

