/*二叉树的表示*/
/*结构数组表示二叉树*/

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode
{
    ElementType Element;
    Tree Left;
    Tree Right;
}T1[MaxTree],T2[MaxTree];

/*int main()
{
    建二叉树1
    建二叉树2
    判断是否同构并输出
    rtturn 0；
}
*/

int main()
{
    Tree R1,R2;
    R1 = BuildTree(T1);
    R2 = BuildTree(T2);
    if(isomorphic(R1,R2)) printf("yes\n");
    else printf("No\n");

    return 0;

} 