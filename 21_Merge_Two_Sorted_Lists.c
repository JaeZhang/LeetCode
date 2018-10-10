/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* result;
    struct ListNode* temp;
    struct ListNode* p;
    struct ListNode* q;
    
    
    
    p = l1;
    q = l2;
    if (p==NULL && q==NULL)
        return NULL;
    
    
    result = (struct ListNode*) malloc (sizeof(struct ListNode));
    result->val = 0;
    temp = NULL;

    while (p && q) {
    	if (temp == NULL) {
    		temp = result;
    	} else {
    		temp->next = (struct ListNode*) malloc (sizeof(struct ListNode));
    		temp = temp->next;
    	}

    	if (p->val >= q->val) {
    		temp->val = q->val;
            q = q->next;
    	} else {
            temp->val = p->val;
            p = p->next;
        }
    		
        
    	temp->next = NULL;
    }

    while (p) {
    	if (temp == NULL) {
    		temp = result;
    	} else {
    		temp->next = (struct ListNode*) malloc (sizeof(struct ListNode));
    		temp = temp->next;
    	}
 
   		temp->val = p->val;
    	p = p->next;
    	temp->next = NULL;
    }

    while (q) {
    	if (temp == NULL) {
    		temp = result;
    	} else {
    		temp->next = (struct ListNode*) malloc (sizeof(struct ListNode));
    		temp = temp->next;
    	}
 
   		temp->val = q->val;
    	q = q->next;
    	temp->next = NULL;
    }
    
    return result;
}