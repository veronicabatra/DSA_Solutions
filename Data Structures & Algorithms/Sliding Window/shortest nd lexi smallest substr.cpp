//2904. Shortest and Lexicographically Smallest Beautiful String
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i=0;
        int j=0;
        int count=0;
        int mn=INT_MAX;
        string ans="";
        int st;
        while(j<s.size()){
            if(s[j]=='1') count++;
            while(i<=j && count==k) {
                int len=j-i+1;
                if(mn>j-i+1 || (mn==j-i+1 && ans>=s.substr(i,len))){
                    ans=s.substr(i,len);
                    mn=j-i+1;
                }
                if(s[i]=='1') count--;
                i++;
            }
            j++;
        }
        return ans;
    }
};