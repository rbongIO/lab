typedef struct LNode *PtrToLNode;
struct Lnode{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

/*查找*/
#define ERROR NULL
 Position Find(List L, ElementType X)
 {
     Position P = L;

     while(P && P->Data!= X)
        P = P->Next;
    if(P)
        return P;
    else
        return ERROR;
 }

 /*带头节点的插入*/
 /*注意：再插入位置P上与课程视频有所不同，课程视频中i是序列位序
 （从1开始），这里P是链表节点指针，在P之前插入新节点*/
bool Insert(List L, ElementType X, Position P)
{
    Position tmp, pre;
    for(pre = L; pre && pre->Next!=P; pre = pre->Next);
    if(pre == NULL){
        printf("插入位置参数错误\n");
        return false;
    }
    else{
        tmp = (Position)malloc(sizeof(struct lNode));

        tmp-> Data = X;
        tmp->Next = P;
        pre->Next = tmp;

        return true;

    }
}

/*带头节点的删除*/

bool Delete(List L, Position P)
{
    Position tmp, pre;
    for(pre = L; pre && pre->Next!=P; pre = pre->next);
    if(pre == NULL || P == NULL){
        printf("删除位置参数错误\n");
        return false;
    }
    else(
        pre->Next = P->Next;
        free(P);
        return true;
    )
}