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
    int ax,ay , bx,by , cx,cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    if (ax == cx or ay == cy or (abs(cx-ax) == abs(cy-ay))) {
        cout << "NO\n" ;
        return;
    }

    if ((bx > ax and cx < ax) or (bx < ax and cx > ax) or (by > ay and cy < ay) or (by < ay and cy > ay) ) {
        cout << "NO\n" ;
        return;
    }
    cout << "YES\n";

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    tt = 1;
    while(tt--){
        so();
    }
    return 0;
}

