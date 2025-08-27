void rotateMatrix(vector<int> &mat){
    int n=mat.size();
    for(int i=0; i<n-1; i++){
        for(int j=i+1; i<n; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }
    for(int i=0; i<n; i++){
        reverse(mat[i].begin(), mat[i].end());
    }
}

// TC: O(N/2 * N/2) + O(N * N/2)