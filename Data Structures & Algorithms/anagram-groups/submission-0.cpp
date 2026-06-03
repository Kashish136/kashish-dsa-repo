class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        

        unordered_map<string , vector<string>>result;

        for( const auto&s : strs){
            vector<int>count(26,0);
            for( int i = 0 ; i < s.size() ; i++){
                char ch = s[i];
                count[ch-'a']++;
            }

            string helper = to_string(count[0]);
            for(int i = 1 ; i < 26 ; i++){
                helper += ',' + to_string(count[i]);
            }
            result[helper].push_back(s);
        }

        vector<vector<string>>output;
        for( auto it : result){
            output.push_back(it.second);
        }


        return output ;

    }
};
