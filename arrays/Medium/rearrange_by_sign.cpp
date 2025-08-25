// Method-1 : If no. of +ve and -ve elements are equal

vector<int> rearrange(vector<int> &a){
    int n=a.size();
    vector<int> ans(n,0);
    int pos=0;
    int neg=1;
    for(int i=0; i<n; i++){
        if(a[i]<0){
            ans[neg]=a[i];
            neg+=2;
        }
        else{
            ans[pos]=a[i];
            pos+=2;
        }
        return ans;
    }

}

// Method-2 :  If no. of +ve and -ve elements are not equal

vector<int> rearrange(vector<int> &a){
    vector<int> pos, neg;
    int n=a.size();
    for(int i=0; i<n; i++){
        if(a[i]>0){
            pos.push_back(a[i]);
        }
        else{
            neg.push_back(a[i]);
        }
    }

    if(pos.size()> neg.size()){
        for(int i=0; i<neg.size(); i++){
            a[2*i] = pos[i];
            a[2*i +1]= neg[i];
        }

        int index = neg.size() * 2;
        for(int i= neg.size(); i<pos.size(); i++){
            a[index]= pos[i];
            index++;
        }
    }
    else{
        for(int i=0; i<pos.size(); i++){
            a[2*i] = pos[i];
            a[2*i +1]= neg[i];
        }

        int index = pos.size() * 2;
        for(int i= pos.size(); i<neg.size(); i++){
            a[index]= neg[i];
            index++;
        }
    }
}