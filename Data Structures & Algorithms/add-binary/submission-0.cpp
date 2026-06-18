class Solution {
public:
    string addBinary(string a, string b) {
        

        int n = a.size();
        int m = b.size();

        int l1 = n-1;
        int l2 = m-1;
        int carry = 0;
        string str = "";

        while(l1 >= 0|| l2 >= 0|| carry){
            
            int sum = carry;
            if(l1 >= 0){
               sum += a[l1]-'0';
               l1--;
            }

            if(l2 >= 0){
                sum += b[l2]-'0';
                l2--;
            }

            int ans = sum % 2;
            carry = sum / 2;

            str += (ans + '0');
        }

        reverse(str.begin(), str.end());
        return str;
    }
};