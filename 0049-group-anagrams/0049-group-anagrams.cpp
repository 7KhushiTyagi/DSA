class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string,vector<string>> map;

        for(string ele:strs){
            string str=ele;
            sort(str.begin(),str.end());
            map[str].push_back(ele);
        }

        vector<vector<string>> res;

        for(auto it:map){
            res.push_back(it.second);
        }
        return res;
        
    }
};