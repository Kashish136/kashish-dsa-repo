class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        
        queue<int>q;
        q.push(0);
        int n = s.size();

        while(!q.empty()){
            int i = q.front();
            q.pop();

            int start = min(n , i+minJump);
            int end = min( n , i+maxJump);

            for(int k = start ; k <= end ; k++){
                if(s[k] == '0'){

                    if( k == n-1){
                        return true ;
                    }

                    q.push(i);
                }
            }
        }

        return false ;
    }
};