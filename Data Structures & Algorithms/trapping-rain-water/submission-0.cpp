class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> leftmax(n,0);
        for(int i=0;i<n;i++){
            leftmax[i]=max(height[i],leftmax[i-1]);
        }
        int water=0;
        int right=0;
        for(int i=n-1;i>=0;i--){
            right=max(right,height[i]);
            int h=min(right,leftmax[i]);
            water+=(h-height[i]);
        }
        return water;
    }
};
