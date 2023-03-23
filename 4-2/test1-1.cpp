#include "SqList.cpp"

int main()
{
    SqList *sq = new SqList();
    initSqList(*sq);

    char a[5] = {'a', 'b', 'c', 'd', 'e'};
    // printf("\n");
    int i = 0;
    for (char insert : a)
    {
        insertSqList(   *sq, insert, i);
        i++;
    }
    // for (int i = 0; i < sq->length; i++)
    //     {
    //         printf("\t%c",sq->elem[i]);
    //     }
    toStringList(*sq);
    printf("\n");
    printf("length = %d\n", sq->length);

    bool emp = isEmpty(*sq);
    printf("isEmpty:%d\n", (int)emp);

    char data;
    getData(*sq, data, 3);
    printf("the[3]:%c\n", data);

    char l = 'a';
    int location = dataLocation(*sq, l);
    printf("the a: %d\n", location);

    char in = 'f';
    insertSqList(*sq, in, 4 - 1);
    //  int k = 0;
    //     for(char insert:a){
    //         insertSqList(*sq,insert,i);
    //         k++;
    //         }
    // for (int i = 0; i < sq->length; i++)
    //     {
    //         printf("\t%c",sq->elem[i]);
    //     }
    toStringList(*sq);
    printf("\n");
    delData(*sq, 3);
    // for (int i = 0; i < sq->length; i++)
    //     {
    //         printf("\t%c",sq->elem[i]);
    //     }
    toStringList(*sq);

    
    // sortList(*sq);
    // toStringList(*sq);
}     