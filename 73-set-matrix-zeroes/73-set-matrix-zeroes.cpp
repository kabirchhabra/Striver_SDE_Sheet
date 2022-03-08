class Solution {
private:
    void setR_C_0(vector<vector<int>>& matrix, int x, int y){
        for(int i=0; i<x; i++) matrix[i][y]=0;
        for(int i=x+1; i<matrix.size();i++) matrix[i][y]=0;
        for(int j=0; j<y; j++) matrix[x][j]=0;
        for(int j=y+1; j<matrix[0].size();j++) matrix[x][j]=0;
    }
public:
    vector<int> f0x, f0y;
    void setZeroes(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    f0x.push_back(i);
                    f0y.push_back(j);
                }
            }
        }
        
        for(int i=0;i<f0x.size();i++){
            setR_C_0(matrix, f0x[i], f0y[i]);
        }
    }
};