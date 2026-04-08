/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

  ListNode*getKthNode(ListNode*curr , int k){

        // k -= 1;

        while( curr != nullptr && k > 0){
            k--;
            curr = curr->next;
        }

    return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
           ListNode*dummy = new ListNode(0);
        dummy->next = head ;

        ListNode*groupprev = dummy ;

        // here dummy node is acting as a main previous link for tracking the elements on the backend side 

        while(true){

            ListNode*kth = getKthNode(groupprev , k);

            if(!kth){
                break;
            }

            ListNode*groupnext = kth->next;

            // store the next group head 

            ListNode*prev = groupnext;
            ListNode*current = groupprev->next;


            for( int i = 0 ; i < k ; i++){
                ListNode*temp = current->next;
                current->next = prev;
                prev = current;
                current = temp ;
            }

            ListNode*temp = groupprev->next;
            groupprev->next = kth;

            groupprev = temp;

        }

        return dummy->next;
    }
};
