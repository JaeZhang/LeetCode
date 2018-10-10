/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL) {
    	return head;
    }

    struct ListNode* cur = head;
    struct ListNode* pre = NULL;
    while (cur) {
    	if (head->val == val) {
    		head = head->next;
    		cur = head;
            continue;
    	}
    
    	if (cur->val == val) {
    		pre->next = cur->next;
            cur = cur->next;
    	} else {
            pre = cur;
            cur = cur->next;
        }

        
    	

    }
    return head;
}