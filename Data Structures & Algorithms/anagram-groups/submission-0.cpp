class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>,vector<string>> m;
        vector<vector<string>> ans;
        for(string str:strs){
            map<char,int> inner;
            for(char c:str){
                inner[c]++;
            }
            m[inner].push_back(str);
        }
        for(pair<map<char,int>,vector<string>> p:m){
            ans.push_back(p.second);
        }
        return ans;
    }
};
