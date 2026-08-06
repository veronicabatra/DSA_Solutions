class Solution {
public:
    int time(vector<int> nums,int hr){
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=(nums[i]+hr-1)/hr; //we can also do ceil,but this is more optimized 
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& nums, int h) {
        int mx=nums[0];
        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i]);
        }
        int st=1;
        int end=mx;
        int ans=mx;
        while(st<=end){
            int mid=st+(end-st)/2;
            int hours=time(nums,mid);
            if(hours<=h) {
                ans=mid;
                end=mid-1;
            }else {
                st=mid+1;
            }
        }
        return ans;
    }
};
