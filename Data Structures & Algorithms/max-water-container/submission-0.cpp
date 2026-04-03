class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans=0;
        int i=0;
        int j=heights.size()-1;
        while(i<j){
            int height=min(heights[i],heights[j]);
            int width=j-i;
            int area=height*width;
            ans=max(ans,area);
            if(heights[i]>heights[j]){
                j--;
            }else i++;
        }
        return ans;
    }
};
