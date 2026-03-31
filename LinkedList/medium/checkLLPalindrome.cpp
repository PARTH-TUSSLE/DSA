// brute -> using stacks
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
    bool isPalindrome(ListNode* head) {
        stack<int>st;
        ListNode* temp = head;
        while ( temp ) {
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while ( temp ) {
            if ( st.top() != temp->val ) return false;
            temp = temp->next;
            st.pop();
        }
        return true;
    }
};

// optimal -> find middle -> reverse -> compare

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

    ListNode* reverseLL ( ListNode* head ) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while ( temp ) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while ( fast->next != NULL && fast->next->next != NULL ) {
            slow = slow -> next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverseLL( slow->next );
        ListNode* first = head;
        ListNode* second = newHead;
        while ( second != NULL ) {
            if ( first->val != second->val ) {
                reverseLL(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLL(newHead);
        return true;
    }
};
