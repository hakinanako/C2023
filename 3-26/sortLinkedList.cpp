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

void insertNode(ListNode* L,ListNode* P){
    ListNode* N = L->next;
    P->next = N;
    L->next = P;
}

bool sortNode(ListNode* head){
if(head == nullptr || head->next == nullptr){
return false; 
}
ListNode* p = head->next; 
while(p != nullptr){
ListNode* q = p->next; 
while(q != nullptr){
if(p->data > q->data){ 
int tmp = p->data;
p->data = q->data;
q->data = tmp;
}
q = q->next;
}
p = p->next; 
}
return true;
}

bool increase(ListNode* head){
    if(head == nullptr || head->next == nullptr){
        return false; 
    }
    ListNode* p = head->next; 
    while(p != nullptr){
        ListNode* q = p->next; 
        while(q != nullptr){
            if(p->data > q->data){ 
                return false;
            }
            q = q->next;
        }
        p = p->next; 
    }
    return true;
}

int main(){
    ListNode* head = new ListNode(0); 
    ElemType arr[] = {2,4,1,8,5}; 
    ElemType n = sizeof(arr)/sizeof(arr[0]); 
    for(int i=0;i<n;i++){
        ListNode* node = new ListNode(arr[i]);
        insertNode(head,node);
    }

     bool isincA = increase(head);
     printf("is increase:%d\n",isincA);

    sortNode(head); 
    ListNode* p = head->next;
    while(p != nullptr){
        printf("%d ",p->data); 
        p = p->next;
    }
    printf("\n");

     bool isinc = increase(head);
     printf("is increase:%d",isinc);
    return 0;
}