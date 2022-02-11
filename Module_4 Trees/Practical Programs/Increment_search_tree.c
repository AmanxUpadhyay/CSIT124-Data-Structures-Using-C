#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

void create(struct node **root)
{
    int p;
    struct node *tem;
    printf("Enter root data: ");
    scanf("%d", &p);
    while (p != -1)
    {
        tem = *root;
        while (1)
        {
            if (tem == NULL)
            {
                struct node *q = (struct node *)malloc(sizeof(struct node));
                q->data = p;
                q->lchild = q->rchild = NULL;

                *root = q;
                break;
            }

            else if (tem->data > p)
            {
                struct node *q = (struct node *)malloc(sizeof(struct node));
                q->data = p;
                q->lchild = q->rchild = NULL;

                if (tem->lchild)
                    tem = tem->lchild;
                else
                {
                    tem->lchild = q;
                    break;
                }
            }

            else if (tem->data < p)
            {
                struct node *q = (struct node *)malloc(sizeof(struct node));
                q->data = p;
                q->lchild = q->rchild = NULL;

                if (tem->rchild)
                    tem = tem->rchild;
                else
                {
                    tem->rchild = q;
                    break;
                }
            }

            else
            {
                printf("Element already present.");
                break;
            }
        }

        printf("Enter the data to insert: ");
        scanf("%d", &p);
    }
}

void RecInOrder(struct node *p)
{
    if (p == NULL)
        return;

    RecInOrder(p->lchild);
    printf("%d ", p->data);
    RecInOrder(p->rchild);
}

void insert(struct node **root, int p)
{
    struct node *tem;

    tem = *root;
    while (1)
    {
        if (tem == NULL)
        {
            struct node *q = (struct node *)malloc(sizeof(struct node));
            q->data = p;
            q->lchild = q->rchild = NULL;

            *root = q;
            break;
        }

        else if (tem->data > p)
        {
            struct node *q = (struct node *)malloc(sizeof(struct node));
            q->data = p;
            q->lchild = q->rchild = NULL;

            if (tem->lchild)
                tem = tem->lchild;
            else
            {
                tem->lchild = q;
                break;
            }
        }

        else if (tem->data < p)
        {
            struct node *q = (struct node *)malloc(sizeof(struct node));
            q->data = p;
            q->lchild = q->rchild = NULL;

            if (tem->rchild)
                tem = tem->rchild;
            else
            {
                tem->rchild = q;
                break;
            }
        }

        else
        {
            printf("Element already present.");
            break;
        }
    }
}

int OnlyLeft(struct node *p)
{
    if (p == NULL)
        return 0;
    int x, y;
    x = OnlyLeft(p->lchild);
    y = OnlyLeft(p->rchild);
    if (p->lchild && !(p->rchild))
    {
        return x + y + 1;
    }
    else
        return x + y;
}

int Search(struct node *root, int key)
{
    struct node *tem = root;
    while (tem)
    {
        if (tem->data > key)
            tem = tem->lchild;
        else if (tem->data < key)
            tem = tem->rchild;
        else
        {
            insert(&root, key + 10);
            return 1;
        }
    }
    return 0;
}

int main()
{
    struct node *root = NULL;
    printf("Enter the Binary search tree data, Enter -1 to stop adding.\n");
    create(&root);

    printf("\nInOrder form of tree: ");
    RecInOrder(root);

    printf("\n\n\nNumber of Nodes having Left Child Only: ");
    printf("%d", OnlyLeft(root));

    printf("\n\nSearched for 4. \n");
    int x = Search(root, 4);
    printf("Returned value is %d", x);
    printf("\nInOrder form of tree: ");
    RecInOrder(root);

    printf("\n\nSearched for 15. \n");
    x = Search(root, 15);
    printf("Returned value is %d", x);
    printf("\nInOrder form of tree: ");
    RecInOrder(root);
}