class Solution{
public:
    vector<int> sortedArray(vector<int> a, vector<int> b){
        int n= a.size();
        int m= b.size();
        int i=0;
        int j=0;
        vector<int> ans;

        while(i<n && j<m){
            if(a[i]<b[j]) i++;
            else if(b[j]<a[i]) j++;
            else{
                ans.push_back(a[i]);
                i++;
                j++;
            }
        }
    }

}

// TC: O(n+m) we iterate through the smallest array of two
// SC: O(n+m) in worst case