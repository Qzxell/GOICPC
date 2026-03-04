#include<bits/stdc++.h>
#define all(c) (c).begin(), (c).end()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

void so(){
    int A, B, C;
    cin >> A >> B >> C;

    if (B > C) {
        if (A >= C && A < B) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    else {
        if (A >= C || A < B) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
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

