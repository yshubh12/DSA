// Better

void setMatrixZeroes(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    int col[m]={0};
    int row[n]={0};

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]==0){
                col[j]=1;
                row[i]=1;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(row[i] || col[j]){
                mat[i][j]==0;
            }
        }
    }
}

// TC: O(2*N*M)
// SC: O(M) + O(N)


// Optimal

void setMatrixZeroes(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    int col0=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]==0){
                mat[i][0]=0;
                if(j!=0){
                    mat[0][j]=0;
                }
                else col0=0;
            }
        }
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(mat[i][j]!=0){
                if(mat[i][0]==0 || mat[0][j]==0){
                    mat[i][j]==0;
                }
            }
        }
    }
    if(mat[0][0]==0){
        for(int j=0; j<m; j++) mat[0][j]=0;
    }
    if(col0=0){
        for(int i=0; i<n; i++) mat[i][0]=0;
    }
}
// No extra space used.