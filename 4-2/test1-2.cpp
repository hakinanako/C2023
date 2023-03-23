#include "SqList.cpp"

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
    SqList *sq = new SqList();
    initSqList(*sq);

    char a[11] = {'a', 'b','c','d','m','e','n','z','u','v','w'};
    int i = 0;
    for (char insert : a)
    {
        insertSqList(*sq, insert, i);
        i++;
    }

    toStringList(*sq);
    sortList(*sq);
    toStringList(*sq);
}