//brute

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
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        int midIdx = 0;
        ListNode* temp = head;
        while ( temp ) {
            len++;
            temp = temp->next;
        }
        midIdx = (len/2)+1;
        int cnt = 1;
        ListNode* temp2 = head;
        while ( cnt <= midIdx ) {
            if ( cnt == midIdx ) {
                return temp2;
            }
            cnt++;
            temp2 = temp2->next;
        }
        return temp2;
    }
};

// optimal -> TORTOISE and HARE algo
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while ( fast != NULL && fast->next != nullptr ) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
