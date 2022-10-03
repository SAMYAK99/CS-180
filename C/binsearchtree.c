#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct gbst
{
    int dsize;
    int (*compareFn)(void *, void *);
    void (*printNode)(void *);
    struct bstnode *root;
};

typedef struct gbst *genericBST;

struct bstnode
{
    void *data;
    struct bstnode *lchild;
    struct bstnode *rchild;
};

void Print(void *a)
{
    printf("%d ", *(int *)a);
}

int Compint(void *a, void *b)
{
    if (*(int *)a == *(int *)b)
        return 0;
    else if (*(int *)a > *(int *)b)
        return 1;
    else
        return -1;
}

int Compchar(void *a, void *b)
{
    if (*(char *)a == *(char *)b)
        return 0;
    else if (*(char *)a > *(char *)b)
        return 1;
    else
        return -1;
}

int Compfloat(void *a, void *b)
{
    if (*(float *)a == *(float *)b)
        return 0;
    else if (*(float *)a > *(float *)b)
        return 1;
    else
        return -1;
}

genericBST createGBST(int dsize, int (*cfunction)(void *, void *), void (*printNode)(void *))
{
    genericBST Gbst = (genericBST)malloc(sizeof(struct gbst));
    Gbst->printNode = printNode;
    Gbst->compareFn = cfunction;
    Gbst->dsize = dsize;
    Gbst->root = (struct bstnode *)malloc(sizeof(struct bstnode));
    Gbst->root = NULL;
    return Gbst;
}

struct bstnode *searchGBST(genericBST gt, void *d)
{
    if (gt == NULL)
        return NULL;
    struct bstnode *ptr, *par;
    ptr = gt->root;
    while (ptr != NULL)
    {
        if (gt->compareFn(d, ptr->data) == 0)
        {
            return ptr;
        }
        else if (gt->compareFn(d, ptr->data) == 1)
        {
            par = ptr;
            ptr = ptr->rchild;
        }
        else
        {
            par = ptr;
            ptr = ptr->lchild;
        }
    }
    return par;
}

void insertNodeGBST(genericBST gt, void *d)
{

    struct bstnode *newNode = (struct bstnode *)malloc(sizeof(struct bstnode));
    newNode->data = malloc(gt->dsize);
    memcpy((void *)(newNode->data), (void *)d, gt->dsize);
    newNode->lchild = NULL;
    newNode->rchild = NULL;

    if (gt->root == NULL)
    {
        gt->root = newNode;
        return;
    }

    struct bstnode *par = searchGBST(gt, d);

    if (gt->compareFn(par->data, d) == -1)
    {
        par->rchild = newNode;
    }
    else
    {
        par->lchild = newNode;
    }

    return;
}

void Inorder(genericBST gt, struct bstnode *p)
{
    if (p == NULL)
        return;
    Inorder(gt, p->lchild);
    gt->printNode(p->data);
    Inorder(gt, p->rchild);
}

void Preorder(genericBST gt, struct bstnode *p)
{
    if (p == NULL)
        return;
    gt->printNode(p->data);
    Preorder(gt, p->lchild);
    Preorder(gt, p->rchild);
}

void Postorder(genericBST gt, struct bstnode *p)
{
    if (p == NULL)
        return;
    Postorder(gt, p->lchild);
    Postorder(gt, p->rchild);
    gt->printNode(p->data);
}

int travarseGBST(genericBST gt, int order)
{
    if (gt->root == NULL)
        return 0;
    if (order == 0)
        Inorder(gt, gt->root);
    else if (order == 1)
        Preorder(gt, gt->root);
    else if (order == 2)
        Postorder(gt, gt->root);
    else
    {
        printf("Invalid Option !");
    }
    return 1;
}

void preTraversalExp(genericBST gt, struct bstnode *node, FILE *fp)
{
    if (node == NULL)
        return;
    fwrite((node->data), gt->dsize, 1, fp);
    preTraversalExp(gt, node->lchild, fp);
    preTraversalExp(gt, node->rchild, fp);
}

int exportGBST(genericBST gt, const char *fname)
{
    FILE *file;
    file = fopen(fname, "wb");

    if (file == NULL)
        return 0;
    preTraversalExp(gt, gt->root, file);
    fclose(file);
    return 1;
}

genericBST importGBST(const char *fname, int (*cf)(void *, void *), void (*pn)(void *), int dsize)
{
    genericBST newBST = createGBST(dsize, cf, pn);
    FILE *file;
    file = fopen(fname, "rb");
    if (file == NULL)
        return 0;
    void *input;
    while (fread(&input, dsize, 1, file))
    {
        insertNodeGBST(newBST, &input);
    }
    fclose(file);
    return newBST;
}


int main()
{
    printf("Enter The required Datatype : \n1. Int\n2. Char\n3. Float\n");
    int ch;
    scanf("%d", &ch);

    genericBST tree;
    if (ch == 1)
    {
        int (*cfunction)(void *, void *) = &Compint;
        void (*printNode)(void *) = &Print;
        tree = createGBST((sizeof(int)), cfunction, printNode);
    }
    else if (ch == 2)
    {
        int (*cfunction)(void *, void *) = &Compchar;
        void (*printNode)(void *) = &Print;
        tree = createGBST((sizeof(char)), cfunction, printNode);
    }
    else if (ch == 3)
    {
        int (*cfunction)(void *, void *) = &Compfloat;
        void (*printNode)(void *) = &Print;
        tree = createGBST((sizeof(float)), cfunction, printNode);
    }
    else
    {
        printf("Invalid Choice !");
        return 0;
    }

    while (1)
    {
        printf("Enter The Data You want To Insert : ");
        int data;
        scanf("%d", &data);
        void *ptr = &data;
        insertNodeGBST(tree, ptr);
        char choice;
        fflush(stdin);
        printf("Do You Want To Insert More Data ?(Y/N) ");
        scanf("%c", &choice);
        if (choice == 'N' || choice == 'n')
            break;
    }

    int flag;
    printf("\nTo search press the item:");
    scanf("%d",&flag);
    struct bstnode* s1;
    s1=searchGBST(tree,&flag);
    if(tree->compareFn(s1->data,&flag)==0)
    {
        printf("Item is present\n");
    }
    else
    {
        printf("Item not present\n");
    }
    

    printf("\nInorder  : ");
    int res = travarseGBST(tree, 0);
    printf("\nPreorder  : ");
    res = travarseGBST(tree, 1);
    printf("\nPostorder  : ");
    res = travarseGBST(tree, 2);

    printf("\nfor file purpose press 1\n");
    scanf("%d",&flag);
    if(flag==1)
    {

    exportGBST(tree, "a.txt");

    int (*cf)(void *, void *) = &Compint;
    void (*pn)(void *) = &Print;
    genericBST newBST = importGBST("a.txt", cf, pn, sizeof(int));

    printf("\nInorder  : ");
    res = travarseGBST(newBST, 0);
    printf("\nPreorder  : ");
    res = travarseGBST(newBST, 1);
    printf("\nPostorder  : ");
    res = travarseGBST(newBST, 2);
    }
    return 0;
}
