class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char , int>mpp;

        for(int i = 0 ; i < t.size() ; i++){
            mpp[t[i]]++;
        }
   

        int left = 0;
        int right = 0;
        int n = s.size();
        int count = 0;
        int index = -1;

        while(right < n){

            if(mpp[s[right]] > 0){
                count++;
            }

            mpp[s[right]]--;


            while(count == t.size() ){

                int length = right-left+1;
                if(length < output){
                    output = length ;
                    index = left;
                }

                mpp[s[left]]++;

                if(mpp[s[left]] > 0){
                    count--;
                }
                left++;
            }

            right++;
        }

        if(index == -1){
            return "";
        }

        return s.substr(index , output);
    }
};
