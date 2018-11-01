#ifndef _List_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Position;
typedef Position List;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Delete(ElementType X, List L);
void Insert(ElementType X, Position P, List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

#endif	/* _List_H */

/* Place in the Implementation file */
struct Node
{
	ElementType Element;
	Position Next;
};

/*return true if L is empty */
int IsEmpty(List L)
{
	return L->Next == NULL;
}

/*return true if p is the last position in list L */
/*Parameter L is unused in this implementation */
int IsLast(List L,Position P)
{
	return P->Next == NULL;
}

/*return Position of X in L; NULL if not found*/
Position Find(ElementType X, List L)
{
	Position P;

	P = L->Next;

	while(P != NULL && P->Element != X)
	{
		P = L->Next;
	}
	return P; 
}

/*Delete first occurrence of X from a list*/
/*Assume use of a header node*/
void Delete(ElementType X, List L)
{
	Position P, TmpCell;
	P = FindPrevious(X,L);
	if(!IsLast(P,L)){		/*Aussmption of header use*/
		TmpCell = P->Next;	/*X is found;delete if*/
		P->Next = TmpCell->Next;/*Bypass deleted cell*/
		free(TmpCell);
	}
}

/*If X is not found,then Next field of returned */
/*Position is NULL*/
/*Assume aheader*/
Position FindPrevious(ElementType X, List L)
{
	Position P;
	P = L;
	while (P->Next != NULL && P->Next->Element != X)
		P = P->Next;
	return P;
}

/*Insert (after legal Position P)*/
/*Header implementation aussemed*/
/*Paramater L is unused in this implementation*/
void Insert(ElementType X, List L, Position P)
{
	Position m;
	m=malloc(sizeof(struct Node));
	if(m == NULL) printf("OUT OF SPACE!");
	m->Element = X;
	m->Next = P->Next;
	P->Next = m;
}
