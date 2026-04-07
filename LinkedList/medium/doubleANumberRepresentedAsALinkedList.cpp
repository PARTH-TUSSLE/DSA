// brute
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

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr) {
        ListNode* next = curr->next; 
        curr->next = prev;           
        prev = curr;                
        curr = next;                 
    }

    return prev; 
}
    ListNode* doubleIt(ListNode* head) {
        stack<int>st;
        ListNode* temp = head;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;
        int carry = 0;
        while ( temp ) {
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while ( !st.empty() ) {
            int num = st.top();
            num*=2;
            ListNode* newNode = new ListNode((num%10)+carry);
            carry = num/10;
            curr->next = newNode;
            curr = newNode;
            st.pop();
        }
        if ( carry ) {
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
            curr = newNode;
        }
        return reverseList(dummyNode->next);
    }
};
