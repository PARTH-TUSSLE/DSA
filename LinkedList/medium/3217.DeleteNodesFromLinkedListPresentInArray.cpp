// brute-> TLE

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {         
        if ( head == NULL ) {
            return NULL;
        }
        ListNode* temp = head;
        ListNode* dNode = new ListNode(-1);
        dNode->next = head;
        ListNode* prev = dNode;
        while ( temp ) {
            if ( find(nums.begin(), nums.end(), temp->val) != nums.end() ) {
                ListNode* nextNode = temp->next;
                prev->next = nextNode;
                temp->next = NULL;
                temp = nextNode;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        return dNode->next;
    }
};

// optimal -> just use unordered set to search in O(1)

//TC -> O(n × m) -> worst case O(n + m) -> best case || SC-> O(n)

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {         
        unordered_set<int> st(nums.begin(), nums.end());
        if ( head == NULL ) {
            return NULL;
        }
        ListNode* temp = head;
        ListNode* dNode = new ListNode(-1);
        dNode->next = head;
        ListNode* prev = dNode;
        while ( temp ) {
            if ( st.find(temp->val) != st.end() ) {
                ListNode* nextNode = temp->next;
                prev->next = nextNode;
                temp->next = NULL;
                temp = nextNode;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        return dNode->next;
    }
};
