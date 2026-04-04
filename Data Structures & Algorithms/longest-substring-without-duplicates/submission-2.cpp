class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int len=0;
        int left=0;
        for(int i=0;i<s.size();i++){
            if(m.count(s[i])){
                if(m[s[i]]>=left){
                left=m[s[i]]+1;
                }
            }
            m[s[i]]=i;
            len=max(len,i-left+1);
        }
        return len;
    }
};
