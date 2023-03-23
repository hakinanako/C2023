#include <stdio.h>
#define ElemType char
#define MaxSize 100

struct SqList
{
    ElemType *elem;
    int length;
};

bool initSqList(SqList &L)
{
    L.elem = new ElemType[MaxSize];
    if (!L.elem)
    {
        return false;
    }
    L.length = 0;
    return true;
}

bool initSqList(SqList &L, int length)
{
    L.elem = new ElemType[length];
    if (!L.elem)
    {
        return false;
    }
    L.length = 0;
    return true;
}

bool insertSqList(SqList &L, ElemType &data, int index)
{
    if (L.length == MaxSize)
    {
        return false;
    }
    if (index < 0 || index > L.length)
    {
        return false;
    }
    if (L.length > 0)
    {
        for (int j = L.length - 1; j >= index; --j)
        {
            L.elem[j + 1] = L.elem[j];
        }
    }
    L.elem[index] = data;
    L.length += 1;
    return true;
}

bool getData(SqList &L, ElemType &data, int i)
{
    if (i < 1 || i > MaxSize)
    {
        return false;
    }
    data = L.elem[i - 1];
    return true;
}

int dataLocation(SqList &L, ElemType &elem)
{
    for (int i = 0; i < L.length; i++)
    {
        if (elem == L.elem[i])
        {
            return i;
        }
    }
    return -1;
}

bool delData(SqList &L, int i)
{
    if (i < 1 || i >= L.length || L.length == 0)
    {
        return false;
    }
    for (int p = i; p <= L.length; p++)
    {
        L.elem[p - 1] = L.elem[p];
    }
    L.length--;
    return true;
}

bool isEmpty(SqList &L)
{
    return L.length == 0 ? true : false;
}

void toStringList(SqList &L)
{
    for (size_t i = 0; i < L.length; i++)
    {
        printf("%c\t", L.elem[i]);
    }
    printf("\n");
}

// void sortList(SqList &L){
//       for (size_t i = L.length-1 ;i>0;i--)
//       {
//         for (size_t j = 0; j<i; j++)
//         {
//             if (L.elem[j]>L.elem[j+1])
//             {
//                 /* code */
//                 ElemType temp = L.elem[j];
//                 L.elem[j] = L.elem[j+1];
//                 L.elem[j+1] = temp;
//             }
            
//         }
        
//       } 
//}

// int main()
// {
//     SqList *sq = new SqList();
//     initSqList(*sq);

//     char a[5] = {'a', 'b', 'c', 'd', 'e'};
//     // printf("\n");
//     int i = 0;
//     for (char insert : a)
//     {
//         insertSqList(*sq, insert, i);
//         i++;
//     }
//     // for (int i = 0; i < sq->length; i++)
//     //     {
//     //         printf("\t%c",sq->elem[i]);
//     //     }
//     toStringList(*sq);
//     printf("\n");
//     printf("length = %d\n", sq->length);

//     bool emp = isEmpty(*sq);
//     printf("isEmpty:%d\n", (int)emp);

//     char data;
//     getData(*sq, data, 3);
//     printf("the[3]:%c\n", data);

//     char l = 'a';
//     int location = dataLocation(*sq, l);
//     printf("the a: %d\n", location);

//     char in = 'f';
//     insertSqList(*sq, in, 4 - 1);
//     //  int k = 0;
//     //     for(char insert:a){
//     //         insertSqList(*sq,insert,i);
//     //         k++;
//     //         }
//     // for (int i = 0; i < sq->length; i++)
//     //     {
//     //         printf("\t%c",sq->elem[i]);
//     //     }
//     toStringList(*sq);
//     printf("\n");
//     delData(*sq, 3);
//     // for (int i = 0; i < sq->length; i++)
//     //     {
//     //         printf("\t%c",sq->elem[i]);
//     //     }
//     toStringList(*sq);

    
//     sortList(*sq);
//     toStringList(*sq);
// }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             