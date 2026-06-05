#include<bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int N = 1e5 + 5;

int ans[N];

int mul(int a, int b){
	return a * 1ll * b % MOD;
}
int add(int a, int b){
	return (a + 0ll + b) % MOD;
}

int expo(int b, int e){
	int ret = 1;
	while(e > 0){
		if(e&1){
			ret = mul(ret, b);
		}
		b = mul(b, b);
		e >>= 1;
	}
	return ret;
}

void so(){
	int n,k;
	cin >> n >> k;
	for(int i = 1;  i <= n ; i++){
		ans[i] = expo(k,(i+1)/2);
		if(i&1)
			ans[i] = mul(ans[i] , i);
		else 
			ans[i] = mul(ans[i] ,  mul (i/2, 1 + k) );
	}
	int uwu = 0;
	for(int i = 1; i <= n ; i++){
		for(int j = i + i ; j <= n ; j += i){
			ans[j] = add(ans[j] , add(MOD,-mul(ans[i] , j/i)) );
		}
		uwu = add(uwu, mul(ans[i], n / i));
	}
	cout << uwu << '\n';
}

int main(){
	so();
	return 0;
}
