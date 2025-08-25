// Better

int majorityElement(vector<int> v){
    map<int, int> mpp;

    for(int i=0; i<v.size(); i++){
        mpp[v[i]]++;
    }

    for(auto it:mpp){
        if(mpp.second > (v.size()/2)){
            return it.first;
        }
    }
    return -1;
}

// TC: O(N Log N)
// SC: O(N)


// Optimal ---- Moore's Voting Algo

int majorityElement(vector<int> a){
    int cnt=0;
    int el;
    for(int i=0; i<a.size(); i++){
        if(cnt==0){
            el=a[i];
            cnt++;
        }
        else if(a[i]==el){
            cnt++;
        }
        else cnt--;
    }

    int cnt1=0;
    for(int i=0; i<a.size(); i++){
        if(a[i]==el) cnt1++;
    }
    if(cnt1==(a.size() / 2)){
        return el;
    }
    return -1;
}