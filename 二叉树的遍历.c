
typedef struct TreeNode *BinTree
typedef BinTree Position

void PreOrderTraversal(BinTree BT)
{
    if(BT){
        printf("%d", BT->Data);
        PreOrderTraversal( BT->Left);
        PreOrderTraversal( BT->Right);
    }
}

void InOrderTraversal(BinTree BT)
{
    if(BT){
        InOrderTraversal( BT->Left );
        printf("%d", Bt->Data);
        InOrderTraversal( BT->Right);
    }
}

void PostOrderTraversal(BinTree BT)
{
    if(BT){
        PostOrderTraversal( BT->Left );
        PostOrderTraversal( BT->Right );
        printf("%d", BT->Data);
    }
}

/*二叉树的非递归遍历*/
void unInOrderTraversal( BinTree BT){
    BinTree T = BT;
    Stack S = CreatStack (MaxSize);
    while(T || !IsEmpty(S)){
        while(T){
            Push(S,T);
            T = T->Left;
        }
        if(!isEmpty(S)){
            T = Pop(S);
            printf("%d", T->Data);
            T = T->Right;
        }
    }
}

/*层序遍历*/
void LevelOrderTraversal(BinTree BT)
{
    Queue Q; BinTree T;
    if(!BT) return;
    Q = CreatQueue( MaxSize );
    AddQ(Q, BT);
    while(!IsEmptyQ(Q)){
        T = DeleteQ(Q);
        printf("%d\n". T->Data);
        if(T->Left) AddQ(Q,T->Left);
        if(T->Right) AddQ(Q,T->Right);
    }
}