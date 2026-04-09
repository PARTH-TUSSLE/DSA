// brute -> lenght and diff approach
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
    ListNode* rotateRight(ListNode* head, int k) {
        if ( head == NULL || head->next == NULL ) {
            return head;
        }
        ListNode* temp = head;
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode* curr = dummyNode;

        int len = 0;
        while ( temp ) {
            len++;
            temp = temp->next;
        }
        k = k%len;
        int diff = len-k;
        int cnt = 0; 
        temp = head;
        while ( temp ) {
            cnt++;
            if ( cnt > diff ) {
                ListNode* newNode = new ListNode(temp->val);
                curr->next = newNode;
                curr = curr->next;
            }
            temp = temp->next;
        }
        cnt = 0;
        temp = head;
        while ( temp ) {
            cnt++;
            if ( cnt <= diff ) {
                ListNode* newNode = new ListNode(temp->val);
                curr->next = newNode;
                curr = curr->next;
            }
            temp = temp->next;
        }
        return dummyNode->next;
    }
}; 

//optimal -> make the LL circuar first

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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* tail = head;
        if (head == NULL || head->next == NULL) return head;
        int len = 1;
        while ( tail && tail->next ) {
            len++;
            tail = tail->next;
        }
        k = k % len;
        if (k == 0) return head;
        int diff = len-k;
        ListNode* temp = head;
        for ( int i = 1; i < diff; i++ ) {
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next = NULL;
        tail->next = head;
        return newHead;
    }
};
