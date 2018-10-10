/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* pre = NULL;
    struct ListNode* cur = head;

    if (head == NULL) {
    	return NULL;
    }

    struct ListNode* temp = (struct ListNode*) malloc (sizeof(struct ListNode));
    while (cur->next) {
    	temp = cur->next;
    	cur->next = pre;
    	pre = cur;
    	cur = temp;

    }

    cur->next = pre;
    return cur;
}