#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define frac pair<ll,ll>
#define node pair<double,int> 

int A[8],B[8];

vector<int> p(8);

double prob(int id1, int id2){// j1, j2
    double num = A[id1];
    double den = A[id1] + B[id2];
    return num/den;
}

double f(int j1, int l, int r){
    if(l == r)
        return 1;

    int mid = (l + r)>>1;
    bool ok = 0;
    for(int i = l ; i <= mid; i++)if( p[i] == j1)
        ok = 1;
    int l_c = ( ok ? mid + 1 : l);
    int r_c = ( ok ? r : mid);

    double cons = f(j1, (ok ? l : mid + 1) , (ok ? mid : r));

    double ret = 0;
    for(int i = l_c ; i <= r_c ; i++){
        ret += f(p[i] , l_c , r_c) * prob( (ok ? j1 : p[i] ) , (ok ? p[i] : j1));
    }
    return ret * cons;
}

int fac(int num){
    if(num == 0)return 1;
    return num*fac(num-1);
}
void so(){
    for(int i= 0; i < 8 ;i++)
        cin >> A[i] >> B[i];
    iota(p.begin(),p.end(),0);
    double ans = 0;
    do{
        ans = max(ans,f(0,0,7));
    }while(next_permutation(p.begin(),p.end()));
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(8) ;
    so();
    return 0;
}
