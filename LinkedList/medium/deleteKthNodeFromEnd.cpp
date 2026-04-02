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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 1;
        int idxFromStart = 0;
        ListNode* temp = head;
        if ( head == NULL ) {
            return head;
        }
        if ( head->next == NULL ) {
            return NULL;
        }
        while( temp->next != nullptr ) {
            len++;
            temp = temp->next;
        }
        if ( n > len ) {
            return head;
        }
        idxFromStart = len-n+1;
        temp = head;
        int cnt = 1;
        ListNode* prev = NULL;
        if (idxFromStart == 1) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }
        while ( temp ) {
            if ( cnt == idxFromStart ) {
                prev->next = temp->next;
                temp->next = NULL;
                delete temp;
                break;
            }
            cnt++;
            prev = temp; 
            temp = temp->next;
        }
        return head;
    }
};

// optimal

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        if ( head == NULL ) {
            return head;
        }
        for ( int i = 0; i < n; i++ ) {
            fast = fast->next;
        }
        if ( fast == NULL ) {
            return head->next;
            delete head;
        }
        ListNode* slow = head;
        while ( fast->next != nullptr ) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* nodeTBD = slow->next;
        slow->next = slow->next->next;
        delete nodeTBD;
        return head;
    }
};
