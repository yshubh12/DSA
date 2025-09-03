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



// If array have multiple target elements return the smallest index

class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        int ans=-1;
        while(low<=high){
            int mid= (low+high)/2;
            if(arr[mid]<k) low=mid+1;
            else if(arr[mid]>k){
                high=mid-1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};