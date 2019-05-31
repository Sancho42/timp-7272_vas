#include <stdio.h>
#include <stdlib.h>
/* структура для хранения узла дерева. Необходимо хранить
ссылки на потомков, предка и некоторое значение (целое чис
ло) */

struct node_l
{
    struct node *value; // значение, которое хранит узел
    struct node_l *next; // ссылка на следующий элемент списка
};

struct list
{
struct node_l *head; // начало списка
struct node_l *tail; // конец списка
};

// инициализация пустого списка
void init_l(struct list* l)
{
    l->head = NULL;
    l->tail = NULL;
}
//удалить все элементы из списка
void clear_l(struct list* l)
{
    struct node_l *buf;

    while(l->head != NULL)
    {
        buf = l->head;
        l->head = l->head->next;
        free(buf);
        //printf("element_deleted");

    }
}
// проверка на пустоту списка
int isEmpty(struct list* l)
{
    if(l->head == NULL)
    {
        return 1;
    }
    return 0;
}
// вставка значения в конец списка, вернуть 0 если успешно
int push_back_l(struct list* l, struct node *value)
{
    //printf("1");
    struct node_l *buf;
    buf = l->tail;

    //printf("2");
    struct node_l *nd;
    // выделение памяти под корень списка
    nd = (struct node_l*)malloc(sizeof(struct node_l));
    nd->next = NULL;
    nd->value = value;

    //printf("3");
    l->tail = nd;
    if(l->head == NULL)
    {
        l->head = nd;
    }
    else
    {
        buf->next = nd;
    }

    //printf("4");
    if(l->tail->value == value)
    {
        //printf("end");
        return 0;
    }
    return 1;
}
// вывести 'ktvtyns из списка в прямом порядке
struct node* give(struct list* l)
{
    struct node_l *buf;
    buf = l->head;
    l->head = l->head->next;
    struct node *viv;
    viv = buf->value;
    free(buf);
    return viv;

}

/////////////////////////////////////////////////////////////////////

struct node
{
    int value;
    struct node *mom;
    struct node *right;
    struct node *left;
};
/* структура для хранения дерева. хранит ссылку на корень
дерева и количество элементов в дереве */
struct tree
{
    struct node *root;
    int all;
};
// инициализация пустого дерева
void init(struct tree* t)
{
    t->root = NULL;
    t->all = 0;
}
//удалить все элементы из дерева
void clear_node_T(struct node* t)
{
    if (t->left != NULL)
    {
        clear_node_T(t->left);
    }
    if (t->right != NULL)
    {
        clear_node_T(t->right);
    }
    free(t);
}
void clear(struct tree* t)
{
    clear_node_T(t->root);
    t->root = NULL;
    t->all = 0;
}

/* поиск элемента по значению. вернуть 0 если элемент найд
ен и ссылку на найденнйы элемент в переменную n если n !=
NULL. в случае если элемент не найден вернуть 1
*/
int find(struct tree* t, int value, struct node** viv)
{
    struct node *buf;
    buf = t->root;
    if (buf != NULL)
    {
        while(buf != NULL && buf->value != value)
        {
            if(value > buf->value)
            {
                buf = buf->right;
            }
            else if(value < buf->value)
            {
                buf = buf->left;
            }
        }
    }

    if (buf != NULL)
    {
        *viv = buf;
        return 0;
    }
    return 1;
}
/* вставка значения в дерево. вернуть 0 если вставка выпол
нена успешна,
1 если элемент уже существует
2 если не удалось выделить память для нового элемента
*/
int insert(struct tree* t, int value)
{
    struct node *branch;
    branch = (struct node*)malloc(sizeof(struct node));
    if(branch == NULL)
    {
        return 2;
    }
    branch->value = value;
    branch->right = NULL;
    branch->left = NULL;

    if (t->root == NULL)
    {
        branch->mom = NULL;
        t->root = branch;
        t->all++;
        return 0;
    }
    else
    {
        struct node *buf, *ma;
        buf = t->root;
        while(buf != NULL)
        {
            if(value > buf->value)
            {
                ma = buf;
                buf = buf->right;
            }
            else if (value < buf->value)
            {
                ma = buf;
                buf = buf->left;
            }
            else{return 1;}
        }
        branch->mom = ma;
        if (ma->value > value)
        {
            ma->left = branch;
        }
        if (ma->value < value)
        {
            ma->right = branch;
        }
        t->all++;
        return 0;
    }
}
/* удалить элемент из дерева. вернуть 0 если элемент был у
дален и 1 если нет элемента с указанным значением */
void findMax (struct node *t, struct node** n)
{
    struct node *buf;
    buf = t;
    if (buf != NULL)
    {
        while(buf->right != NULL)
        {
            buf = buf->right;
        }
    }
    *n = buf;
}
void findMin (struct node *t, struct node** n)
{
    struct node *buf;
    buf = t;
    if (buf != NULL)
    {
        while(buf->left != NULL)
        {
            buf = buf->left;
        }
    }
    *n = buf;
}
 int remove_tree(struct tree* t, int value)
{
    int i;
    struct node *fi, *buf, *c_mom, *c_right, *c_left;
    fi = NULL;
    buf = NULL;
    i = find(t, value, &fi);

    if (i == 0)
    {
        t->all--;
        if(fi->right != NULL)
        {

            //printf("%d", fi->right->value);
            findMin(fi->right, &buf);
            c_mom = buf->mom;
            c_right = buf->right;
            c_left = buf->left;
            //связь с роддителем
            buf->mom = fi->mom;
            if (fi->mom != NULL)
            {
                if(fi->mom->value > fi->value)
                {
                    fi->mom->left = buf;
                }
                else
                {
                    fi->mom->right = buf;
                }
            }
            else
            {
                t->root = buf;
            }
            //связь с левым
            buf->left = fi->left;
            if (fi->left != NULL)
            {
                fi->left->mom = buf;
            }
            //связь с правым
            if(fi->right != buf)
            {
                buf->right = fi->right;
            }
            else if (buf->right != NULL)
            {
                buf->right = buf->right;
            }
            else
            {
                buf->right = NULL;
            }
            if(buf->right != NULL)
            {
                buf->right->mom = buf;
            }
//buf->right = NULL;
            //востановление пробела
            if(fi != c_mom)
            {
                 if(c_right != NULL)
                {
                    c_right->mom = c_mom;
                }
                if (c_mom != NULL)
                {
                    c_mom->left = c_right;
                }
            }
//buf->right = NULL;
            //
            free(fi);
            return 0;
        }
        else if (fi->left != NULL)
        {

            //printf("%d", fi->right->value);
            findMax(fi->left, &buf);
            c_mom = buf->mom;
            c_right = buf->right;
            c_left = buf->left;
            //связь с роддителем
            buf->mom = fi->mom;
            if (fi->mom != NULL)
            {
                 if(fi->mom->value > fi->value)
                {
                    fi->mom->left = buf;
                }
                else
                {
                    fi->mom->right = buf;
                }
            }
            else
            {
                t->root = buf;
            }
            //связь с правым
            buf->right = fi->right;
            if (fi->right != NULL)
            {
                fi->right->mom = buf;
            }
            //связь с левым
            if(fi->left != buf)
            {
                buf->left = fi->left;
            }
            else if (buf->left != NULL)
            {
                buf->left = buf->left;
            }
            else
            {
                buf->left = NULL;
            }
            if(buf->left != NULL)
            {
                buf->left->mom = buf;
            }
            //востановление пробела
            if(fi != c_mom)
            {
                if(c_left != NULL)
                {
                    c_left->mom = c_mom;
                }
                if (c_mom != NULL)
                {
                    c_mom->right = c_left;
                }
            }
            //
            free(fi);
            return 0;
        }
        else
        {
            if(fi->mom->value > fi->value)
            {
                fi->mom->left = NULL;
            }
            else
            {
                fi->mom->right = NULL;
            }
            free(fi);
            return 0;
        }
    }
    return 1;
}

/* удалить минимальный элемент из поддерева, корнем которо
го является n. вернуть значение удаленного элемента */
int removeMin(struct node* n, struct tree *t)
{
    if (n == NULL)
    {
        return -1;
    }
    struct node *buf;
    int viv;
    findMin(n, &buf);
    viv = buf->value;
    remove_tree(t, viv);
    return viv;
}
/* выполнить правое вращение поддерева, корнем которого яв
ляется n. вернуть 0 при успещшно выполнение операции и 1 в
случае если вращение невозможно */
int rotateRight(struct tree *t, struct node *n)
{
    struct node *fi, *buf, *c_mom, *c_left;
    fi = n;
    buf = NULL;

    if (fi->left != NULL)
    {
        //printf("%d", fi->right->value);
        findMax(fi->left, &buf);
        c_mom = buf->mom;
        c_left = buf->left;
        //связь с роддителем
        buf->mom = fi->mom;
        if (fi->mom != NULL)
        {
             if(fi->mom->value > fi->value)
            {
                fi->mom->left = buf;
            }
            else
            {
                fi->mom->right = buf;
            }
        }
        else
        {
            t->root = buf;
        }
        //связь с правым
        buf->right = fi;
        fi->mom = buf;
        //связь с левым
        if(fi->left != buf)
        {
            buf->left = fi->left;
        }
        else if (buf->left != NULL) //////????
        {
            buf->left = buf->left;
        }
        else
        {
            buf->left = NULL;
        }
        ////////////////////////////////??????^^
        if(buf->left != NULL)
        {
            buf->left->mom = buf;
        }
        //востановление пробела
        if(fi != c_mom)
        {
             if(c_left != NULL)
            {
                c_left->mom = c_mom;
            }
            if (c_mom != NULL)
            {
                c_mom->right = c_left;
            }
        }
        //зачистка левого указателя
        fi->left = NULL;
        //
        return 0;
    }
    else
    {
        return 1;
    }
}
/* выполнить левое вращение поддерева, корнем которого явл
яется n. вернуть 0 при успещшно выполнение операции и 1 в
случае если вращение невозможно */
int rotateLeft(struct tree *t, struct node *n)
{
    struct node *fi, *buf, *c_mom, *c_right;
    fi = n;
    buf = NULL;

    if (fi->right != NULL)
    {
        //printf("%d", fi->right->value);
        findMin(fi->right, &buf);
        c_mom = buf->mom;
        c_right = buf->right;
        //связь с роддителем
        buf->mom = fi->mom;
        if (fi->mom != NULL)
        {
             if(fi->mom->value > fi->value)
            {
                fi->mom->left = buf;
            }
            else
            {
                fi->mom->right = buf;
            }
        }
        else
        {
            t->root = buf;
        }
        //связь с левым
        buf->left = fi;
        fi->mom = buf;
        //связь с правым
        if(fi->right != buf)
        {
            buf->right = fi->right;
        }
        else if (buf->right != NULL) //////????
        {
            buf->right = buf->right;
        }
        else
        {
            buf->right = NULL;
        }
        ////////////////////////////////??????^^
        if(buf->right != NULL)
        {
            buf->right->mom = buf;
        }
        //востановление пробела
        if(fi != c_mom)
        {
             if(c_right != NULL)
            {
                c_right->mom = c_mom;
            }
            if (c_mom != NULL)
            {
                c_mom->left = c_right;
            }
        }
        //зачистка правого указателя
        fi->right = NULL;
        //
        return 0;
    }
    else
    {
        return 1;
    }
}
/* вывести все значения из поддерева корнем которого являе
тся n по уровнем, начиная с корня. каждый уровень выводитс
я на своей строке. элементы в строке разделяются пробелом.
если на указанном месте нет элемента, заменить его значен
ием '_'. Если дерево пусто вывести '-' */
void print(struct node* n)
{
    struct list *li1;
    li1 = (struct list*)malloc(sizeof(struct list));
    init_l(li1);
    struct list *li2;
    li2 = (struct list*)malloc(sizeof(struct list));
    init_l(li2);
    //
    push_back_l(li1,n);
    //
    int fp, sp;
    fp = 1;
    sp= 1;
    while(sp == 1)
    {
        sp = 0;
        fp = 1;
        while(fp == 1)
        {
            fp = 0;
//printf("()");
            if(!isEmpty(li1))
            {
//printf("io");
                fp = 1;
                //
                if (li1->head->value != NULL)
                {
                    if (li1->head->value->left != NULL)
                    {
                        sp = 1;

                    }
                    push_back_l(li2,li1->head->value->left);
//printf("2");
                    if (li1->head->value->right != NULL)
                    {
                        sp = 1;
                    }
                    push_back_l(li2,li1->head->value->right);
                }
                else
                {
                    push_back_l(li2, NULL);
                    push_back_l(li2, NULL);
                }

//printf("3");
                struct node *viv;
                viv = give(li1);
//printf("4");
                if (viv != NULL)
                {
                    printf("%d", viv->value);
                    /*//^
                    if(viv->left != NULL)
                    {
                        printf("%d", viv->left->value);
                    }
                    else
                    {
                        printf("N");
                    }
                     if(viv->right != NULL)
                    {
                        printf("%d", viv->right->value);
                    }
                    else
                    {
                        printf("N");
                    }
                     if(viv->mom != NULL)
                    {
                        printf("%d", viv->mom->value);
                    }
                    else
                    {
                        printf("N");
                    }
                    *///^
                }
                else
                {
                    printf("_");
                }
//printf("5");
            }

            if(!isEmpty(li1))
            {
                printf(" ");
            }
            else
            {
                fp = 0;
                printf("\n");
                struct list *buf;
                buf = li1;
                li1 = li2;
                li2 = buf;
                clear_l(li2);
            }
        }
    }
}
// вывести все значения дерева t, аналогично функции print (Если дерево пусто вывести '-')
void printTree(struct tree* t)
{
    if(t->root == NULL)
    {
        printf("-\n");
    }
    else
    {
        print(t->root);
    }
}
//////////// 5практика
void traversal_wide(struct tree* t)
{
    struct list *li1;
    li1 = (struct list*)malloc(sizeof(struct list));
    init_l(li1);
    struct list *li2;
    li2 = (struct list*)malloc(sizeof(struct list));
    init_l(li2);
    //
    push_back_l(li1,t->root);
    //
    int fp;
    fp = 1;

    while(fp == 1)
    {
        fp = 0;
//printf("()");
        if(!isEmpty(li1))
        {
//printf("io");
            fp = 1;
            //
            if (li1->head->value != NULL)
            {
                push_back_l(li1,li1->head->value->left);
//printf("2");
                push_back_l(li1,li1->head->value->right);
            }

//printf("3");
            struct node *viv;
            viv = give(li1);
//printf("4");
            if (viv != NULL)
            {
                printf("%d", viv->value);
            }
//printf("5");
        }

        if(!isEmpty(li1) && li1->head->value != NULL)
        {
            printf(" ");
        }
        else
        {
            fp = 0;
            printf("\n");
        }
    }
}
//обзод в глубину (я не пойму как это можно сделать без рекурсии)
void traversal_deep (struct tree *t)
{
    struct node *act, *buf;
    int pro, rea;
    rea = t->all;
    act = t->root;
    buf = act;
    pro = 0;
//1
    if(t->root != NULL)
    {
        while (pro < rea)
        {
            if(act == buf || buf == act->mom)
            {
                pro++;
                printf("%d", act->value);
                if(act->left != NULL)
                {
                    buf = act;
                    act = act->left;
                }
                else if(act->right != NULL)
                {
                    buf = act;
                    act = act->right;
                }
                else if(act->mom != NULL)
                {
                    buf = act;
                    act = act->mom;
                }
                else
                {
                   printf("\n");
                }
                //А здесь живёт мистер Костыль ))))
                if(pro < rea)
                {
                    printf(" ");
                }
            }

            else if(act->right != NULL && buf == act->left)
            {
                buf = act;
                act = act->right;
            }
            else if(act->mom != NULL && (buf == act->right || buf == act->left))
            {
                buf = act;
                act = act->mom;
            }
        }
        printf("\n");
    }
}

//обход в глубину , но наоборот
void tr_deep_rev (struct node *n)
{
    if(n->left != NULL)
    {
        tr_deep_rev(n->left);
    }
    if(n->right != NULL)
    {
        tr_deep_rev(n->right);
    }
    printf("%d ", n->value);
}
void traversal_deep_rev (struct tree *t)
{
    if(t->root != NULL)
    {

        if(t->root->left != NULL)
        {
            tr_deep_rev(t->root->left);
        }
        if(t->root->right != NULL)
        {
            tr_deep_rev(t->root->right);
        }
        printf("%d", t->root->value);
        printf("\n");
    }
    /* это я случайно сделал обратный проход без рекурсий
    struct node *act, *buf;
    int pro, rea;
    rea = t->all;
    act = t->root;
    buf = act;
    pro = 0;
//1
    if(t->root != NULL)
    {
        while (pro < rea)
        {
            if(act->left != NULL && buf != act->right && buf != act->left)
            {
                buf = act;
                act = act->left;
            }
            else if(act->left == NULL && act->right == NULL)
            {
                pro++;
                printf("%d", act->value);
                buf = act;
                act = act->mom;
            }
            else if(act->right != NULL && buf == act->left)
            {
                buf = act;
                act = act->right;
            }
            else if(buf == act->right || (buf == act->left && act->right == NULL))
            {
                pro++;
                printf("%d", act->value);
                buf = act;
                act = act->mom;
            }
        }
        printf("\n");
    }
    */
}
///////////////////////////////////////////^^^^^^^^^^^^^^^
///////////////////////////
void check_all()
{
    struct tree *myt;
    myt = (struct tree*) malloc(sizeof(struct tree));

    //printf("Hello!\n");

    init(myt);

    int q;
    for (int i = 0; i < 7;i++)
    {
        scanf("%d", &q);
        q = insert(myt, q);
        //printf ("polojili? - %d \n", !q);
    }
    printTree(myt);
    remove_tree(myt, 1);
    printTree(myt);
    remove_tree(myt, 5);
    printTree(myt);
}

int main()
{
    //check_all();

    ////
    //1
    int sc;
    struct tree *myt;
    myt = (struct tree*) malloc(sizeof(struct tree));
    init(myt);

    for(int i = 0; i < 7; i++)
    {
        scanf ("%d", &sc);
        insert(myt, sc);
    }
    //printTree(myt);
    //traversal_wide(myt);
    //printf("1\n");
    //traversal_deep(myt);
    //printf("2\n");
    traversal_deep_rev(myt);

    ////
    return 0;
}

