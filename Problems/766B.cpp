#include <bits/stdc++.h>

#define ln '\n'
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++) cin >> v[i] ;

    sort(v.begin(), v.end());
    int ma = 0;

    for(int i = 0 ; i < n-2;i++){
            int di = v[i+2] - v[i+1];
            ma = max(ma,v[i]);
            if(ma > di){
                    cout << "YES";
                    return 0;
            }
    }
    cout << "NO";

    return 0;
}
