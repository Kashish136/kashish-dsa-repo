class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        

        vector<int>ans;
        int n = asteroids.size();
        stack<int>st;


        for(int i = 0 ; i < n ; i++){

            int asteroid = asteroids[i];
            bool destroyed = false;

            while(!st.empty() && (st.top() > 0 && asteroid < 0)){

                if(abs(asteroid) > st.top()){
                    st.pop();
                    continue;
                }

                else if( abs(asteroid) == st.top()){
                    destroyed = true;
                    st.pop();
                    break;
                }

                else{
                    destroyed = true;
                    break;
                }
            }

            if(!destroyed){
                st.push(asteroid);
            }
        }

        int s = st.size();
        vector<int> result(s);
        for (int i = s - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};