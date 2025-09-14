int countStudents(vector<int>& arr, int pages){
    int students=1;
    long long pagesStudent=0;
    for(int i=0; i<arr.size(); i++){
        if(pagesStudent+arr[i] <= pages){
            pagesStudent+=arr[i];
        }
        else{
            students+=1;
            pagesStudent=arr[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr, int n, int students){
    if(n<students) return -1;
    int low= *max_element(arr.begin(), arr.end());
    int high= accumulate(arr.begin(), arr.end(), 0);
    while(low<=high){
        int mid=(low+high)/2;
        int cntStudents=countStudents(arr, mid);
        if(cntStudents > students) low=mid+1;
        else high=mid-1;
    }
    return low;
}