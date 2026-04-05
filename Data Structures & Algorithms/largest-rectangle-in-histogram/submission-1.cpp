class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> ns(n,n);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(!s.empty()) ns[i]=s.top();
            s.push(i);
        }
        int ans=0;
        while(!s.empty()) {
            s.pop();
        }
        int ps=-1;
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i]) {
                s.pop();
            }
            if(!s.empty()) {
                int curr=(ns[i]-s.top()-1)*heights[i];
                ans=max(ans,curr);
            }
            else{
                int curr=(ns[i]-(-1)-1)*heights[i];
                ans=max(curr,ans);
            }
            s.push(i);
        }
        return ans;
    }
};
