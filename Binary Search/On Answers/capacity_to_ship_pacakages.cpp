class Solution {
public:
    int daysReq(vector<int>& weights, int capacity){
        int days=1, load=0;
        for(int i=0; i<weights.size(); i++){
            if(load+weights[i]>capacity){
                days+=1;
                load=weights[i];
            }
            else load+=weights[i];
        }
        return days;
    }
    int maxCapacity(vector<int>& weights){
        int sum=0;
        for(int i=0; i<weights.size(); i++){
            sum+=weights[i];
        }
        return sum;
    }
    int maxEle(vector<int>& weights){
        int maxi=INT_MIN;
        for(int i=0; i<weights.size(); i++){
            maxi=max(maxi,weights[i]);
        }
        return maxi;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=maxEle(weights), high=maxCapacity(weights);
        while(low<=high){
            int mid=(low+high)/2;
            int usedDays=daysReq(weights, mid);
            if(usedDays<=days) high=mid-1;
            else low=mid+1;
        }
        return low;
        
    }
};