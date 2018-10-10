typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last;
};

/*初始化*/
List MakeEmpty()
{
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;
    
    return L;
}
/*查找*/
#define ERROR -1

Position Find(List L; ElementType X)
{
    Position i = 0;

    while(i <= L->Last && L->Data[i] != X)
        i++;
    if(i > L->Last) return ERROR;/*如果没找到，返回错误信息*/

    else return i; /*找到后返回的是存储位置*/

}

/*插入*/
/*注意：再插入位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里是
存储下标位置（从0开始），两者差1*/
bool Insert(List L, ElementType X, Position P)
{
    Position i = 0;

    if(L->Last == MAXSIZE-1){
        printf("表满");
        return false;
    }
    if(P < 0 || P > L->Last+1;){
        printf("位置不合法");
        return false;
    }

    for(i = L->Last; i >= P; i--)
        L->Data[i+1] = L->Data[i];
    L->Data[P] = X;
    L->Last++;
    return true;
}

/*删除*/
/*注意：再删除位置参数P时与视频有所不同，该P是下标*/
bool Delete(List L, Position P)
{
    Position i;

    if(P < 0 || P > L->Last+1){
        pritnf("位置不合法")；
        return false;
    }

    for(i = P+1; i <= L->Last; i++)
        L->Data[i - 1] = L->Data[i];
    L->last--;
    return true;
}
