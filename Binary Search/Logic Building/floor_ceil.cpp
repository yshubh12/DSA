#include<bits/stdc++.h>
class Solution{
private:
    int findFloor(vector<int> &nums, int x){
        int n=nums.size();
        int low=0, high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]<=x){
                ans=nums[x];
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }

    int findCeil(vector<int> &nums, int x){
        int n=nums.size();
        int low=0, high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>=x){
                ans=nums[x];
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }

public:
    vector<int> getFloorAndCeil(vector<int> nums, int x){
        int floor=findFloor(nums, x);
        int ceil=findCeil(nums, x);
        return {floor, ceil};
    }
};