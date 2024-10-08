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
    int n,k;
    string yes = "YES";
    string no = "NO";
    cin >> n >> k;
    if (n&1) {
        if (((k+1)/2)%2 == 0) {
            cout << yes; 
        } else cout << no;
    }else{
        if (k&1) {
            cout << ( (k/2)&1 ? no : yes);
        }else {
            cout << ( k%4 == 0 ? yes : no ) ;
        }
    }
    cout << ln;
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
