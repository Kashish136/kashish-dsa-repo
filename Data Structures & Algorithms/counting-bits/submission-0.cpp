class Solution {
public:
   
   int helper(int n ){

    int count = 0;
    while( n > 0){
        n = n&(n-1);
        count++;
    }

    return count;
   }
    vector<int> countBits(int n) {
        
    vector<int>ans;
    for(int i = 0 ; i <= n ; i++){
        int key = helper(i);
        ans.push_back(key);
    }

    return ans ;
    }
};
