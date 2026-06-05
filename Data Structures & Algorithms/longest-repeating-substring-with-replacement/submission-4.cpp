class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char , int>mpp;
        int left = 0;
        int maxfreq = 0;
        int output = 0;

        for(int right = 0 ; right < s.size() ; right++){
             char ch = s[right];
             mpp[ch]++;
             maxfreq = max(maxfreq , mpp[ch]);

        // jo bhi total length hai usmai jo bhi character
        // sabse baar baar repeat horha hai hum sirf usko consider 
        // krenge for solving this problem if agr uska count k 
        // se bda hojayega toh hum eliminate krdenge 
        while((right-left+1)-maxfreq > k){
           mpp[s[left]]--;
           left++;
        }

        output = max(output , right-left+1);


         
        }

        return output ;
    }
};
