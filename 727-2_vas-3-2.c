#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value; // значение, которое хранит узел
    struct node *next; // ссылка на следующий элемент списка
    struct node *prev; // ссылка на предыдущий элемент
};

struct list
{
struct node *head; // начало списка
struct node *tail; // конец списка
};

// инициализация пустого списка
void init(struct list* l)
{
    l->head = NULL;
    l->tail = NULL;
}
//удалить все элементы из списка
void clear(struct list* l)
{
    struct node *buf;

    while(l->head != NULL)
    {
        buf = l->head;
        l->head = l->head->next;
        free(buf);
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
// поиск элемента по значению. вернуть NULL если элемент не найден
struct node* find(struct list* l, int value)
{
    struct node *buf;
    buf = l->head;
    while(buf != NULL)
    {
        if(buf->value == value)
        {
            return buf;
        }
        else
        {
            buf = buf->next;
        }
    }
        return NULL;
}
// вставка значения в конец списка, вернуть 0 если успешно
int push_back(struct list* l, int value)
{
    //printf("1");
    struct node *buf;
    buf = l->tail;

    //printf("2");
    struct node *nd;
    // выделение памяти под корень списка
    nd = (struct node*)malloc(sizeof(struct node));
    nd->next = NULL;
    nd->prev = l->tail;
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
// вставка значения в начало списка, вернуть 0 если успешно
int push_front(struct list* l, int value)
{
    //printf("1");
    struct node *buf;
    buf = l->head;

    //printf("2");
    struct node *nd;
    // выделение памяти под корень списка
    nd = (struct node*)malloc(sizeof(struct node));
    nd->next = buf;
    nd->prev = NULL;
    nd->value = value;

    //printf("3");
    l->head = nd;
    if(l->tail == NULL)
    {
        l->tail = nd;
    }
    else
    {
        buf->prev = nd;
    }

    //printf("4");
    if(l->head->value == value)
    {
        //printf("end");
        return 0;
    }
    return 1;
}
// вставка значения после указанного узла, вернуть 0 если успешно
int insertAfter(struct list* l, int position, int value)
{
    //printf("1 ");
    struct node *buf, *sec;
    buf = l->head;

    //printf("1.5 ");
    if(buf == NULL)
        {
            return 1;
        }
    for (int i = 1; i < position; i++)
    {
        if(buf->next == NULL)
        {
            return 1;
        }
        buf = buf->next;
    }
    sec = buf->next;

    //printf("2 ");
    struct node *nd;
    // выделение памяти под корень списка
    nd = (struct node*)malloc(sizeof(struct node));
    nd->next = sec;
    nd->prev = buf;
    nd->value = value;

    //printf("3 ");
    buf->next = nd;
    if (sec != NULL)
    {
        sec->prev = nd;
    }
    if(l->tail == buf)
    {
        l->tail = nd;
    }

    //printf("4 ");
    if(buf->next->value == value)
    {
        //printf("end ");
        return 0;
    }
    return 1;
}
// вставка значения перед указанным узлом, вернуть 0 еслиуспешно
int insertBefore(struct list* l, int position, int value)
{
    //printf("1 ");
    struct node *buf, *pre;
    buf = l->head;

    //printf("1.5 ");
    if(buf == NULL)
        {
            return 1;
        }
    for (int i = 1; i < position; i++)
    {
        if(buf->next == NULL)
        {
            return 1;
        }
        buf = buf->next;
    }
    pre = buf->prev;

    //printf("2 ");
    struct node *nd;
    // выделение памяти под корень списка
    nd = (struct node*)malloc(sizeof(struct node));
    nd->next = buf;
    nd->prev = pre;
    nd->value = value;

    //printf("3 ");
    buf->prev = nd;
    if(pre != NULL)
    {
        pre->next = nd;
    }
    if(l->head == pre)
    {
        l->head = nd;
    }

    //printf("4 ");
    if(buf->prev->value == value)
    {
        //printf("end ");
        return 0;
    }
    return 1;
}
// удалить первый элемент из списка с указанным значением,вернуть 0 если успешно
int removeFirst(struct list* l, int value)
{
    //printf("1 ");
    struct node *buf, *sec, *pre;
    buf = l->head;
    pre = NULL;

    //printf("1.5 ");
    if(buf == NULL)
        {
            return 1;
        }
    while (buf->value != value)
    {
        if(buf->next == NULL)
        {
            return 1;
        }
        pre = buf;
        buf = buf->next;
    }
    sec = buf->next;

    //printf("2 ");
    free(buf);

    //printf("3 ");
    if(pre == NULL)
    {
        l->head = sec;
    }
    else
    {
        pre->next = sec;
    }
    if(sec == NULL)
    {
        l->tail = pre;
    }
    else
    {
        sec->prev = pre;
    }


    //printf("end ");
    return 0;

}
// удалить последний элемент из списка с указанным значением, вернуть 0 если успешно
int removeLast(struct list* l, int value)
{
    //printf("1 ");
    struct node *buf, *sec, *pre;
    buf = l->tail;
    sec = NULL;

    //printf("1.5 ");
    if(buf == NULL)
        {
            return 1;
        }
    while (buf->value != value)
    {
        if(buf->prev == NULL)
        {
            return 1;
        }
        sec = buf;
        buf = buf->prev;
    }
    pre = buf->prev;

    //printf("2 ");
    free(buf);

    //printf("3 ");
    if(pre == NULL)
    {
        l->head = sec;
    }
    else
    {
        pre->next = sec;
    }
    if(sec == NULL)
    {
        l->tail = pre;
    }
    else
    {
        sec->prev = pre;
    }


    //printf("end ");
    return 0;
}
// вывести все значения из списка в прямом порядке, через пробел, после окончания вывода перейти на новую строку
void print(struct list* l)
{
    struct node *buf;
    buf = l->head;
    while(buf->next != NULL)
    {
        printf("%d ", buf->value);
        buf = buf->next;
    }
    printf("%d", buf->value);
    printf("\n");
}
// вывести все значения из списка в обратном порядке, через пробел, после окончания вывода перейти на новую строку
void print_invers(struct list* l)
{
    struct node *buf;
    buf = l->tail;
    while(buf->prev != NULL)
    {
        printf("%d ", buf->value);
        buf = buf->prev;
    }
    printf("%d", buf->value);
    printf("\n");
}
void checkFn (struct list* l)
{
    print(l);
    print_invers(l);
    printf("%d %d \n", l->head->value, l->tail->value);
}

void checkAll ()
{
    struct list *mylst;
    mylst = (struct list*)malloc(sizeof(struct list));
    init(mylst);
    clear(mylst);
    isEmpty(mylst);
    push_back(mylst, 1);
    push_back(mylst, 2);
    push_back(mylst, 3);
    push_back(mylst, 4);
    push_back(mylst, 5);
    //print(mylst);
    checkFn(mylst);
    push_front(mylst, -1);
    push_front(mylst, -2);
    push_front(mylst, -3);
    //print(mylst);
    checkFn(mylst);
    insertAfter(mylst, 6, 123);
    insertAfter(mylst, 2, 153);
    insertAfter(mylst, 10, 153);
    //print(mylst);
    checkFn(mylst);
    removeFirst(mylst, -1);
    //print(mylst);
    checkFn(mylst);
    //////////////////
    insertBefore(mylst, 3, 999);
    //print(mylst);
    checkFn(mylst);
    removeLast(mylst, 4);
    //print(mylst);
    checkFn(mylst);
}

int main()
{
    //checkAll();
    struct list *mylst;
    mylst = (struct list*)malloc(sizeof(struct list));

    init(mylst);

    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        push_back(mylst, x);
    }
    print(mylst);
    //3
    int k1, k2, k3;
    scanf("%d %d %d", &k1, &k2, &k3);
    if (find(mylst, k1) != NULL)
    {
        printf("%d", 1);
    }
    else{printf("%d", 0);}
    if (find(mylst, k2) != NULL)
    {
        printf("%d", 1);
    }
    else{printf("%d", 0);}
    if (find(mylst, k3) != NULL)
    {
        printf("%d\n", 1);
    }
    else{printf("%d\n", 0);}
    //5
    int m;
    scanf("%d", &m);
    push_back(mylst, m);
    print_invers(mylst);
    //7
    int t;
    scanf("%d", &t);
    push_front(mylst, t);
    print(mylst);
    //9
    int j;
    scanf("%d %d", &j, &x);
    insertAfter(mylst, j, x);
    print_invers(mylst);
    //11
    int u, y;
    scanf("%d %d", &u, &y);
    insertBefore(mylst, u, y);
    print(mylst);
    //13
    int z;
    scanf("%d", &z);
    removeFirst(mylst, z);
    print_invers(mylst);
    //15
    int r;
    scanf("%d", &z);
    removeLast(mylst, z);
    print(mylst);
    //17
    clear(mylst);

    return 0;
}

