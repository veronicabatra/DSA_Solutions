class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int maxfreq=0;
        int maxlen=0;
        unordered_map<char,int> m;
        while(r<s.size()){
            m[s[r]]++;
            maxfreq=max(maxfreq,m[s[r]]);
            int len=r-l+1;
            if(len-maxfreq<=k){
                maxlen=max(maxlen,len);
            }
            if(len-maxfreq>k){
                m[s[l]]--;
                l++;
            }
            r++;
        }
        return maxlen;
    }
};
