class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i:nums){
            m[i]++;
        }
        priority_queue<pair<int,int>>pq;
        for(pair<int,int> p:m){
            pq.push({p.second,p.first});
        }
        int i=0;
        while(i!=k && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
            i++;
        }
        return ans;
    }
};
