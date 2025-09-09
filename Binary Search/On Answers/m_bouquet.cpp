class Solution {
public:
    bool countPossible(vector<int>& bloomDay,int day,int m,int k){
        int n=bloomDay.size();
        int cnt=0;
        int nBloom=0;
        for(int i=0; i<n; i++){
            if(bloomDay[i]<=day){
                cnt++;
            }
            else{
                nBloom+=cnt/k;
                cnt=0;
            }
        }
        nBloom+=(cnt/k);
        return nBloom >= m;
    }
    int maxElement(vector<int> &bloomDay){
        int maxi=INT_MIN;
        for(int i=0; i<bloomDay.size(); i++){
            maxi=max(maxi, bloomDay[i]);
        }
        return maxi;
    }
    int minElement(vector<int> &bloomDay){
        int mini=INT_MAX;
        for(int i=0; i<bloomDay.size(); i++){
            mini=min(mini, bloomDay[i]);
        }
        return mini;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long val= m * 1LL * k * 1LL;
        if(val>bloomDay.size()) return -1;
        int low=minElement(bloomDay), high=maxElement(bloomDay);
        while(low<=high){
            long long mid=(low+high)/2;
            if(countPossible(bloomDay,mid,m,k)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};