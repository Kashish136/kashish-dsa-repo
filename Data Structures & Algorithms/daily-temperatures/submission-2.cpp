class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
          int n = temperatures.size(); //size of array
        
        // To store the next greater elements
        vector<int> ans(n);
        
        // Stack to get elements in LIFO fashion
        stack<int> st;
        
        // Start traversing from the back
        for(int i=n-1; i >= 0; i--) {
            
            // Get the current element
            int currEle = temperatures[i];
            
            /* Pop the elements in the stack until 
            the stack is not empty and the top 
            element is not the greater element */
            while(!st.empty() && temperatures[st.top()] < currEle) {
                st.pop();
            }
            
            /* If the greater element is not 
            found, stack will be empty */
            if(st.empty()) 
                ans[i] = 0;
                
            // Else store the answer
            else 
                ans[i] = st.top();
            
            /* Push the current element in the stack 
            maintaining the decreasing order */
            st.push(i);
        }
        
        // Return the result
        return ans;
    }
};
