/**
 * leetcode: remove linked list element
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

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        return method2(head, val);
    }

    void printList(ListNode* head) {
        ListNode* p = head;
        while (p!=NULL) {
            printf("%d,", p->val);
            p = p->next;
        }
        printf("\n");
    }
private:
    // this method has bugs, it can not deal with head, tail nodes.   
    ListNode* method1(ListNode* head, int val) {
        ListNode* p = head;
        while (p != NULL) {
            if (p->val == val) {
                ListNode* nextNode = p->next;
                p->val = nextNode->val;
                p->next = nextNode->next;
                delete nextNode;
            } else {
                p = p->next;
            }
            printList(head);
        }
        printList(head);
        return head;
    }

    // this is accepted by leetcode.
    // add the dummy node before the head, 
    // and using two pointers (previous, and current)
    ListNode* method2(ListNode* head, int val) {
        ListNode* myHead = new ListNode(0);
        myHead->next = head;
        ListNode* prev = myHead;
        ListNode* curr = myHead->next;
        
        while (curr != NULL) {
            if (curr->val == val) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                prev = prev->next;
                curr = prev->next;
            }
        }
        
        ListNode* newHead = myHead->next;
        delete myHead;
        return newHead;
    }
};

int main() {
    Solution sln;

    const int N = 10;
    int array[N] = {1, 1, 0, 0, 2, 2, 1, 1, 3, 5};
    ListNode* head = NULL;
    ListNode* p = head;
    for (int i=0; i<1; ++i) {
        ListNode* node = new ListNode(array[i]);
        if (p == NULL) {
            p = node;
            head = p;  
        } else {
            while (p->next != NULL) {
                printf("p=%d,%d\n", p->val, p->next);
                p = p->next;
            }
            p->next = node;
        }
    }
    printf("init: ");
    sln.printList(head);
    
    sln.removeElements(head, array[0]);
    
    return 0;
}

