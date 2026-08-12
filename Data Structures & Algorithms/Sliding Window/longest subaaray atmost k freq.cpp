// You are given an integer array nums and an integer k.

// The frequency of an element x is the number of times it occurs in an array.

// An array is called good if the frequency of each element in this array is less than or equal to k.

// Return the length of the longest good subarray of nums.

// A subarray is a contiguous non-empty sequence of elements within an array.
//leetcode 2958
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int mx=1;
        unordered_map<int,int> m;
        while(j<nums.size()){
            m[nums[j]]++;
            while(i<nums.size() && m[nums[j]]>k){
                m[nums[i]]--;
                i++;
            }
            mx=max(mx,j-i+1);
            j++;
        }
        return mx;
    }
};