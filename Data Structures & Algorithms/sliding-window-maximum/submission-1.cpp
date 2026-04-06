class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q; //index 
        int i=0;
        while(i<k){
            while(!q.empty() && nums[q.back()]<nums[i]) q.pop_back();
            q.push_back(i);
            i++;
        }
        ans.push_back(nums[q.front()]);
        for(int j=k;j<nums.size();j++){
            if(q.front()==j-k) q.pop_front();
            while(!q.empty() && nums[q.back()]<=nums[j]) q.pop_back();
            q.push_back(j);
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
