#include<bits/stdc++.h>
#define ln '\n'
#define pb push_back
#define vii vector<pair<int,int>>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

void so(){
    int a,aa,b,bb;
    cin >> a >> aa >> b >> bb;
    int ans = 0;
    int g = 0;
    if (a > b and aa >= bb) {
        ans++; 
    }else if (a >= b and aa > bb) {
        ans++; 
    }
    if (aa > b and a >= bb) {
        ans++; 
    }else if (aa >= b and a > bb) {
        ans++; 
    }
    cout << ans*2<<ln;

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

