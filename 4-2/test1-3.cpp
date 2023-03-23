#include "SqList.cpp"

void sortList(SqList &L);

SqList intersection(SqList &A, SqList &B){
    int length = A.length<B.length?A.length:B.length;
    SqList *anwser = new SqList();
    initSqList(*anwser,length);
    int indexA = 0;
    int indexB = 0;
    sortList(A);
    sortList(B);
    int insert = 0;
    while (indexA<A.length&&indexB<B.length)
    {
        if (A.elem[indexA] == B.elem[indexB])
        {
            insertSqList(*anwser, A.elem[indexA], insert);
            insert++;
            indexA++;
            indexB++;
        }
        else if (A.elem[indexA] < B.elem[indexB])
        {
            indexA++;
        }else{
            indexB++;
        }
        
        
    }
    return *anwser;
}

void sortList(SqList &L){
      for (size_t i = L.length-1 ;i>0;i--)
      {
        for (size_t j = 0; j<i; j++)
        {
            if (L.elem[j]>L.elem[j+1])
            {
                /* code */
                ElemType temp = L.elem[j];
                L.elem[j] = L.elem[j+1];
                L.elem[j+1] = temp;
            }
            
        }
        
      } 
}

int main(){
     SqList *A = new SqList();
     initSqList(*A);
    char aList[5] = {'a', 'b', 'c', 'd', 'e'};

    {int i = 0;
    for (char insert : aList)
    {
        insertSqList(*A, insert, i);
        i++;
    }
    }
     SqList *B = new SqList();
     initSqList(*B);
    char bList[2] = {'e', 'd'};

    {int j = 0;
    for (char insert : bList)
    {
        insertSqList(*B, insert, j);
        j++;
    }
    }

    SqList anw = intersection(*A,*B);

    toStringList(anw);
}