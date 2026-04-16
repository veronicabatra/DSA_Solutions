class Solution {
public:
    void fn(vector<vector<int>> &ans,vector<int> &inner,int k,int n,int num){
        if(num>n+1) return;
        if(inner.size()==k){
            ans.push_back(inner);
            return;
        }
        inner.push_back(num);
        fn(ans,inner,k,n,num+1);
        inner.pop_back();
        fn(ans,inner,k,n,num+1);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> inner;
        fn(ans,inner,k,n,1);
        return ans;
    }
};