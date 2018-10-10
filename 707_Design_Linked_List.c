typedef struct LNode{
    int val;
    struct LNode* next;
} MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* head = (MyLinkedList*) malloc (sizeof(MyLinkedList));
    head->next = NULL;
    return head;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0)
    	return -1;
    int i = 0;
    MyLinkedList* p = obj->next;
    while (i < index && p) {
    	i  ++;
    	p =p->next;
    }
    if (p)
    	return p->val;
    else
    	return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
	if (!obj)
		return;
    MyLinkedList* temp = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    temp->val = val;
    temp->next = obj->next;
    obj->next = temp;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    struct LNode* p = obj;
    while (p->next)
    	p = p->next;
    MyLinkedList* temp = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    if (!temp)
    	return;
    temp->val = val;
    temp->next = NULL;
    p->next = temp;

}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0)
    	return;
    if (index == 0) {
    	MyLinkedList* temp = (MyLinkedList*) malloc (sizeof(MyLinkedList));
    	temp->val = val;
    	temp->next = obj->next;
    	obj->next = temp;
    } else {
    	MyLinkedList* p = obj->next;
	    int i = 0;
	    while (i < index - 1 && p) {
	    	p = p->next;
	    	i ++;
	    }
	    if (i == index - 1 && p) {
	    	
			MyLinkedList* temp = (MyLinkedList*) malloc (sizeof(MyLinkedList));
			temp->next = p->next;
			temp->val = val;
			p->next = temp;
	    	
	    }
    }

}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0)
    	return;
    struct LNode* p = obj;
    int i = 0;
    while (i < index) {
    	if (p->next)
    		p = p->next;
    	else
    		break;
        i ++;
    }

    if (i == index) {
    	MyLinkedList* temp = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    	temp = p->next;
    	if (temp) {
    		p->next = temp->next;
    		free(temp);
    	}
    }

}

void myLinkedListFree(MyLinkedList* obj) {
    while (obj) {
    	MyLinkedList* temp = obj;
    	free(obj);
    	obj = temp->next;
    }
}



/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * struct MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
 */