class Solution {
public:
    bool fn(vector<int> &nums,int diff,int pairs){
        int count=0;
        int i=1;
        while(i<nums.size()){
            if(nums[i]-nums[i-1]<=diff){
                count++;
                i+=2;
            }else i++;
            if(count>=pairs) return true;
        }
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mn=INT_MAX;
        int mx=nums[n-1]-nums[0];
        int st=0;
        int end=mx;
        int ans=0;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(fn(nums,mid,p)){
                ans=mid;
                end=mid-1;
            }
            else st=mid+1;
        }
        return ans;
    }
};