class Solution {
public:

//   int helper(string&s , string&t , int i , int j){

//        if( j < 0){
//          return 1;
//        }

//        if( i < 0){
//         return 0 ;
//        }


//        if(s[i] == t[j]){
//          return helper(s , t , i-1 , j-1) + helper( s , t , i-1 , j);
//        }

//        else{
//          return helper(s , t , i-1 , j);
//        }
//   }




    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();

        // vector<vector<int>>dp(n+1 , vector<int>(m+1,-1));
        
        // for( int i = 0  ; i <= n ; i++){
        //     dp[i][0] = 1;
        // }

        // for( int j = 1 ; j <= m ; j++){
        //     dp[0][j] = 0;
        // }




        vector<int>prev(m+1 ,0);
        vector<int>current(m+1,0);

        prev[0] = 1;
        current[0] = 1;



        for( int i = 1 ; i <= n ; i++){
            for( int j = 1 ; j <= m ; j++){
                if(s[i-1] == t[j-1]){
                    current[j] = prev[j-1] + prev[j];
                }

                else{

                    current[j] = prev[j];
                }
            }

            prev = current ;
        }


        

        return prev[m];
    }
};
