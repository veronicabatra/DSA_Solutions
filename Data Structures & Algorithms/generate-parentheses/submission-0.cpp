class Solution {
public:
    void fn(vector<string> &ans,string inner,int open,int close){
        if(open==0 && close==0) {
            ans.push_back(inner);
            return;
        }
        if(open>0){
            fn(ans,inner+"(",open-1,close);
        }
        if(close>open){
            fn(ans,inner+")",open,close-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string inner;
        fn(ans,inner,n,n);
        return ans;
    }
};
