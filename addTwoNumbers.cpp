/**
 * leetcode: rotate list
 * medium
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        printList(l1);
        printList(l2);
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* dummyHead = new ListNode(-1);
        ListNode* tail = dummyHead;
        bool isCarry = false;
        while (p != NULL && q != NULL) {
            int sum = p->val + q->val;
            ListNode* temp = new ListNode(sum);
            tail->next = temp;
            tail = temp;
            printList(dummyHead->next);
            p = p->next;
            q = q->next;
        }
        printf("aaaaaaaaaaa\n");
        while (p != NULL) {
            ListNode* temp = new ListNode(p->val);
            tail->next = temp;
            tail = temp;
            printList(dummyHead->next);
            p = p->next;
        }
        printf("bbbbbbbbbbbbb\n");
        while (q != NULL) {
            ListNode* temp = new ListNode(q->val);
            tail->next = temp;
            tail = temp;
            printList(dummyHead->next);
            q = q->next;
        }
        printf("ccccccccccccccc\n");

        ListNode* r = dummyHead->next;
        for ( ;r->next != NULL; r=r->next) {
            int value = r->val;
            if (value >= 10) {
                r->val = value % 10;
                r->next->val += value/10;
            }
        }
        if (r->val >= 10) {
            int value = r->val;
            r->val = value % 10;
            r->next = new ListNode(value/10);
        }

        printList(dummyHead->next);

        ListNode* head = dummyHead->next;
        delete dummyHead;
        return head;
    }
private:
};

int main() {
    const int M = 4;
    const int N = 6;
    int a[M] = {1,2,3,5};
    int b[N] = {4,6,8,2,3,5};
    Solution sln;
    for (int i=0; i<1; ++i) {
        ListNode* l1= createList(a, M);
        ListNode* l2= createList(b, N);
        printf("%d-----\n", i);
        ListNode* newHead = sln.addTwoNumbers(l1, l2);
        printList(newHead);
        destroyList(l1);
        destroyList(l2);
        destroyList(newHead);
    }
    return 0;
}
