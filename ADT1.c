#ifdef _Tree_H
struct TreeNode;
typedef struct TreeNode *Position；
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X,SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);

#endif /* _Tree_H */

struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

SearchTree MakeEmpty(SearchTree T)
{
    if( T != NULL){
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        Free(T);
    }
    return NULL;
}
 
Position FindMin(SearchTree T)
{
    if( T == NULL)
        return NULL;
    
    else if(T->Left == NULL)
        return T;
    else
        return FindMin(T->Left);
}

Position FindMax(SearchTree T)
{
    if(T != NULL)
        
        while(T->Right != NULL){
            T = T-> Right;
        }
        return T;
}

SearchTree Insert(ElementType X, SearchTree T)
{
    if(T == NULL)
    {
        /*creat and return aone-node tree*/
        T = malloc(sizeof(struct TreeNode));
        if(T == NULL)
            FataError("Out of space!!!");
        else
        {
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    }
    else if(X < T->Element)
        T->Left = Insert(X, T->Left);
    else if(x > T->Element)
        T->Right = Insert(X, T->Right);
    return T;
}

SearchTree Delete(ElementType X, SearchTree T)
{
    Position TmpCell;

    if(T == NULL)
        Error( "Element not found");
    else if(X < T->ElementType)/*Go Left*/
        T->Left = Delete(X, T->Left);
    else if(X > T->ElementType)/*go Right*/
        T->Right = Delete(X, T->Right);
    else/*found element to be deleted */ 
    if（T->Left && T->Right)/*Two children*/
    {
        /*Replace with smallest in right subtree*/
        TmpCell = FindMin(T->Right);
        T->Element = TmpCell->Element;
        T->Right = Delete(T->Element, T->Right);
    }
    else
    {
        TmpCell = T;
        if(T->Left == NULL)
            T = T->Right;
        else if(T->Right == NULL)
            T = T->Left;
        free(TmpCell);
    }
    return T;
}