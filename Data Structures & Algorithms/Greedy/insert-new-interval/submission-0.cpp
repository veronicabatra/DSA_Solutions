class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       vector<vector<int>> ans;
       int n=intervals.size();
       int i=0;
       while(i<n && intervals[i][1]<newInterval[0]){
        ans.push_back({intervals[i][0],intervals[i][1]});
        i++;
       }
       int st=newInterval[0];
       int end=newInterval[1];
       while(i<n && intervals[i][0]<=newInterval[1]){
        st=min(st,intervals[i][0]);
        end=max(end,intervals[i][1]);
        i++;
       }
       ans.push_back({st,end});
       while(i<n){
        ans.push_back({intervals[i][0],intervals[i][1]});
        i++;
       }
        return ans;
    }
};
