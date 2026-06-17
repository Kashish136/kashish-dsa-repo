class Solution {
public:
    int trap(vector<int>& height) {
        

        // int n = height.size();
        // if( n == 0){
        //     return 0;
        // }

        // vector<int>prefixmax(n,0);
        // vector<int>suffixmax(n,0);

        // prefixmax[0] = height[0];

        // for(int i = 1 ; i < n ; i++){
        //     prefixmax[i] = max(prefixmax[i-1] , height[i]);
        // }

        // suffixmax[n-1] = height[n-1];

        // for(int i = n-2 ; i >=0 ; i--){
        //     suffixmax[i] = max(suffixmax[i+1] , height[i]);
        // }

        // int output = 0;
        // for(int i = 0 ; i < n ; i++){
        //     output += min(prefixmax[i] , suffixmax[i])-height[i];
        // }

        // return output ;

        if(height.empty()){
            return 0 ;
        }

        int left = 0;
        int right = height.size()-1;
        int leftmax = height[left];
        int rightmax = height[right];

        int output = 0;

        while(left < right){
            
            if(leftmax < rightmax){
                left++;
                leftmax = max(leftmax , height[left]);
                output += leftmax-height[left];
            }

            else{
                right--;
                rightmax = max(rightmax , height[right]);
                output += rightmax-height[right];
            }
        }

        return output ;
    }
};
