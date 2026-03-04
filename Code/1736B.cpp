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

int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}
void so(){
    int n;
    cin >> n;
    vi v(n);
    vi ls(n+1);
    for (int i = 0 ; i < n ; i++){
        cin >> v[i];
    }
    for (int i = 1 ; i < n ; i++){
        ls[i] = lcm(v[i-1],v[i]);
    }
    ls[0] = v[0];
    ls[n] = v[n-1];
    for (int i = 0 ; i < n ; i++){
        if (gcd(ls[i],ls[i+1]) > v[i]) {
            cout << "NO\n";
            return;
        }

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

