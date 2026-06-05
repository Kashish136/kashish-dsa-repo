class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char>st;
        int left = 0;
        int maxlength = 0;

        for(int right = 0 ; right < s.size() ; right++){
            char ch = s[right];

            if(st.find(ch) != st.end()){
                while(left < right && (st.find(ch) != st.end())){
                    st.erase(s[left]);
                    left++;
                }
            }

            maxlength = max(maxlength , (right-left+1));
            st.insert(ch);

        }
        return maxlength ;
    }
};
