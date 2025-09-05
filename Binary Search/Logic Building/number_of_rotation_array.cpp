class Solution {
public:
    int findKRotation(vector<int> &arr)  {
        int low = 0, high = arr.size()-1, index=-1;
        int ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;

            if(arr[low]<=arr[high]){ // Already sorted array
                if(arr[low]<ans){
                    index = low;
                    ans = arr[low];
                }
                break;
            }
            if(arr[low]<=arr[mid]){ // left half sorted
                if(arr[low]<ans){
                    index = low;
                    ans = arr[low];
                }
                low = mid+1;
            }
            else{
                // Right half sorted
                if(arr[mid]<ans){
                    index = mid;
                    ans = arr[mid];
                }
                high = mid-1;
            }
        }
        return index;
    }
};