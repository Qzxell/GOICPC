class Solution {
public:
        vector<vector<int>> rec(int n) {
                if(n == 0){
                        vector<vector<int>> ret = {{0}};
                        return ret;
                }
                int len = (1<<n);
                int tot = len*len;
                vector<vector<int>> ret(len,vector<int>(len,0));
                vector<vector<int>> aux = rec(n-1);
                auto fil = [&](int x,int y,int in){
                        int tam = len/2;
                        for(int i = 0;i < tam;i++){
                                for(int j = 0;j < tam;j++){
                                        ret[i+x][j+x] = aux[i][j] + in;
                                }
                        }
                };
                int au = (len/2)*(len/2);
                fil(0,len/2,0);
                fil(len/2,len/2,au);
                fil(len/2,0,au+au);
                fil(0,0,au+au+au);
                return ret;
        }
};
