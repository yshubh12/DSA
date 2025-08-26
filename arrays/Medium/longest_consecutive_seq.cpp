// Better 

int longestConsecutiveSeq(vector<int> &a){
    int n= a.size();
    if(n==0) return 0;
    sort(a.begin(), a.end());
    int longest =1;
    int lastSmaller = INT_MIN;
    int cnt=0;
    for(int i=0; i<n; i++){
        if(a[i] - 1 == lastSmaller){
            cnt +=1;
            lastSmaller = a[i];
        }
        else if(lastSmaller != a[i]){
            cnt =1;
            lastSmaller = a[i];
        }

        longest = max(longest, cnt);
    }
    return longest;
}

// Optimal -- Set

int longestConsecutiveSeq(vector<int> &a){
    n=a.size();
    if(n==0) return 0;
    int longest=1;
    unordered_set<int> st;

    for(int i=0; i<n; i++){
        st.insert(a[i]);
    }

    for(auto it:st){
        if(st.find(it-1) == st.end()){
            x=it;
            cnt=1;
            while(st.find(x+1) != st.end()){
                x=x+1;
                cnt++;
            }
            longest=max(longest, cnt);
        }
    }
    return longest;
}