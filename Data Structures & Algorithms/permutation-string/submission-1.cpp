class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<int,int>mpp;
        for(int i = 0 ; i < s1.size() ; i++){
            char ch = s1[i];
            mpp[ch]++;
        }

       
       int count = 0;
        for(int right = 0 ; right < s2.size() ; right++){
            char ch = s2[right];
            mpp[ch]--;

            if(mpp[ch] == 0){
                count++;
            }

            if(count == s1.size()){
                return true ;
            }


            
        }

        return false ;
    }
};
