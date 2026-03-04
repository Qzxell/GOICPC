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
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i =0 ; i< n ; i++)cin >> v[i];
    int ans = 0;
    for(int i =0 ; i< n ; i++){
        int c = 1;
        v[i] += 'B';
        for(int j =0 ; j< n ; j++){
            if(v[i][j] == v[i][j+1] and v[i][j] == 'N'){
                c++;
            }else {
                ans += c/2;
                c = 1;
            }
        }
    }
    cout << ans ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    while (tt--){
        so();
    }
    return 0;
}
