class Solution {
public:
    int maxEle(vector<int>& nums){
        int maxi=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            maxi=max(maxi,nums[i]);
        }
        return maxi;
    }

    long long sumByD(vector<int>& nums, int divisor){
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=ceil((double)nums[i]/(double)divisor);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1, high=maxEle(nums);
        while(low<=high){
            int mid=(low+high)/2;
            if(sumByD(nums, mid)<=threshold) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};

// TC: O(n log m)