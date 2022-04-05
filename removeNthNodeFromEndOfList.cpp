/**
 * leetcode: remove nth node from end of list
 * easy
 */
#include <cstdio>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

    
};
ListNode* createList(int* values, int size) {
		ListNode* head = NULL;
		ListNode* tail = NULL;
		for (int i=0; i<size; ++i) {
			ListNode* p = new ListNode(values[i]);
			if (head == NULL) {
				head = p;
				tail = p;
			} else {
				tail->next = p;
				tail = p;
			}
		}
    return head;
}

void destroyList(ListNode* head) {
		ListNode* p = head;
		while (p != NULL) {
			ListNode* temp = p;
			p = p->next;
			delete temp;
		}
}

void printList(ListNode* head) {
		ListNode* p = head;
        printf("[");
		while (p->next != NULL) {
            printf("%d,", p->val);
			p = p->next;
		}
        printf("%d]\n", p->val);
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) { 
            return NULL;
        }
        M - n = k;
       
        
        
        ListNode* tail = head;
        int count = 1;
        while (tail->next != NULL) {
            tail = tail->next;
            count++;
        }
        int actualK = k % count;
        //printf("count=%d, actualK=%d\n", count, actualK);
        
        
        ListNode* q = head;
        for (int i=0; i<count-actualK-1; ++i) {
             q = q->next;
        }
        
        ListNode* newHead = q->next;
        tail->next = head;
        q->next = NULL;
        
        return newHead;
    }
};

int main() {
    const int N = 5;
    int a[N] = {1,2,3,4,5};
    Solution sln;
    for (int i=0; i<10; ++i) {
        ListNode* head = createList(a, N);
        printf("%d-----\n", i);
        printList(head);
        ListNode* newHead = sln.rotateRight(head, i);
        printList(newHead);
        destroyList(newHead);
    }
    return 0;
}
