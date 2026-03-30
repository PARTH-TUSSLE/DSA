// brute
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> s;
        ListNode* temp = head;

        if ( temp == NULL || temp->next == nullptr ) {
            return NULL;
        }
        while ( temp ) {
            if ( s.find(temp) == s.end() ) {
                s.emplace(temp);
                temp = temp->next; 
            } else {
                return temp;
            }
        }
        return NULL;
    }
};

// optimal -> TORTOISE and HARE

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while ( fast != NULL && fast->next != nullptr ) {
            slow = slow->next;
            fast = fast->next->next;
            if ( slow == fast ) {
                slow = head;
                while ( slow != fast ) {
                slow = slow->next;
                fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
