class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char,int>mpp;
        for(int i = 0 ; i < s1.size() ; i++){
            char ch = s1[i];
            mpp[ch]++;
        }

    unordered_map<char , int>mpp2;

    int left = 0;
    for(int right = 0 ; right < s2.size() ; right++){
        char ch = s2[right];
        mpp2[ch]++;

        if(right-left+1 > s1.size()){
            mpp2[s2[left]]--;
            left++;

        if(mpp2[s2[left]] == 0)
        mpp2.erase(s2[left]);


        }

        if(mpp == mpp2){
            return true ;
        }


    }

    return false ;
    }
};
