// brute -> unordered set
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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        ListNode* temp = head;

        if ( temp == NULL || temp->next == nullptr ) {
            return false;
        }
        while ( temp ) {
            if ( s.find(temp) == s.end() ) {
                s.emplace(temp);
                temp = temp->next; 
            } else {
                return true;
            }
        }
        return false;
    }
};

// optimal -> TORTOISE HARE

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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while ( fast != NULL && fast->next != nullptr ) {
            slow = slow->next;
            fast = fast->next->next;
            if ( slow == fast ) {
                return true;
            }
        }
        return false;
    }
};
