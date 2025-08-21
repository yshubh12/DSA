vector<int> sortedArray(vector<int> a, vector<int> b){
    int n=a.size();
    int m=b.size();
    int i=0;
    int j=0;
    vector<int> unionArray;

    while(i<n && j<m){
        if(a[i]<=b[j]){
            if(unionArray.size()==0 || unionArray.back()!=a[i]){
                unionArray.push_back(a[i]);
            }
            i++;
        }
        else{
            if(unionArray.size()==0 || unionArray.back()!=b[i]){
                unionArray.push_back(b[i]);
            }
            j++;
        }
    }

    while(i<n)
    {
        if(unionArray.size()==0 || unionArray.back()!=a[i]){
            unionArray.push_back(a[i]);
        }
        i++;
    }

    while(j<m){
        if(unionArray.size()==0 || unionArray.back()!=b[i]){
                unionArray.push_back(b[i]);
            }
            j++;
    }
    return unionArray;
}


// TC: O(n+m)
// SC: O(n+m)