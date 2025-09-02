int search(vector<int>& nums, int target) {
    int n=nums.size();
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid= (low+high)/2;
        if(nums[mid]<target) low=mid+1;
        else if(nums[mid]>target){
            high=mid-1;
        }
        else return mid;
    }
    return -1;
}

// TC: O(log n) -- binary search
// SC: O(1)