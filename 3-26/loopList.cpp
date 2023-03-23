#include <stdio.h>
#define ElemType int

struct ListNode
{
    ElemType data;
    ListNode* next;

    ListNode(int x):
    data(x),
    next(nullptr){}
};

ListNode* initSqList(ElemType data){
    ListNode* L = new ListNode(data);
    L->next = L;
    return L;
}
void insertNode(ListNode* head, ElemType data){
    ListNode* in = new ListNode(data);
    in->next = head->next;
    head->next = in;
}
void printList(ListNode* head){
    ListNode* p = head->next;
    while (p!=head)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}
void combine(ListNode* A,ListNode* B){
ListNode* pA = A->next;
    ListNode* pB = B->next;
    while(pA->next!=A){
        pA=pA->next;
    }
    while(pB->next!=B){
        pB=pB->next;
    }
    pA->next=B->next;
    pB->next=A;
    delete B;
}
int main(){
ListNode* A = initSqList(0);
ListNode* B = initSqList(0);

insertNode(A,1);
insertNode(A,3);
insertNode(A,5);
insertNode(A,2);
insertNode(B,3);
insertNode(B,6);
insertNode(B,8);
insertNode(B,7);

printList(A);
printList(B);

combine(A,B);
printList(A);
}