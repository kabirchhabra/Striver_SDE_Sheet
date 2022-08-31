class Solution {
private:
    void dfs(vector<vector<int>>& mat, vector<vector<bool>>& visited, int i, int j){
        if(visited[i][j]) return;
        visited[i][j]=true;
        
        if(atlantic[i][j] && pacific[i][j]) ans.push_back(vector<int>{i,j});
        
        if(i+1 < m && mat[i+1][j] >= mat[i][j]) dfs(mat, visited, i+1, j);
        if(i - 1 >= 0 && mat[i - 1][j] >= mat[i][j]) dfs(mat, visited, i - 1, j);
        if(j + 1 <  n && mat[i][j + 1] >= mat[i][j]) dfs(mat, visited, i, j + 1); 
        if(j - 1 >= 0 && mat[i][j - 1] >= mat[i][j]) dfs(mat, visited, i, j - 1);
    }
    public:
    
    int m,n;
    vector<vector<bool>> atlantic, pacific;
    vector<vector<int>> ans;
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        if(mat.size()==0) return ans;
        
        m = mat.size();
        n = mat[0].size();
        
        atlantic = pacific = vector<vector<bool>> (m, vector<bool>(n,false));
        
        for(int i=0;i<m;i++) dfs(mat,pacific, i, 0), dfs(mat,atlantic,i, n-1);
        for(int i=0; i<n;i++) dfs(mat,pacific, 0, i), dfs(mat,atlantic, m-1,i);
        
        return ans;
    }
};