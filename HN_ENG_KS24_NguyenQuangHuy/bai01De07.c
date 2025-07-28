#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char customer[50];
    int status;
    float total;
} Order;

typedef struct NodeD
{
    Order data;
    struct NodeD *prev, *next;
} NodeD;

typedef struct NodeS
{
    Order data;
    struct NodeS *next;
} NodeS;

NodeD *headD = NULL;
NodeS *headS = NULL;

// ======== TẠO NODE ========
NodeD *createNodeD(Order data)
{
    NodeD *node = (NodeD *)malloc(sizeof(NodeD));
    node->data = data;
    node->next = node->prev = NULL;
    return node;
}

NodeS *createNodeS(Order data)
{
    NodeS *node = (NodeS *)malloc(sizeof(NodeS));
    node->data = data;
    node->next = NULL;
    return node;
}

void addOrder()
{
    Order o;
    printf("Nhap ID don hang: ");
    scanf("%d", &o.id);
    printf("Nhap ten khach hang: ");
    getchar();
    gets(o.customer);
    printf("Nhap tong tien: ");
    scanf("%f", &o.total);
    o.status = 0;

    NodeD *node = createNodeD(o);
    if (headD == NULL)
    {
        headD = node;
    }
    else
    {
        NodeD *temp = headD;
        while (temp->next)
            temp = temp->next;
        temp->next = node;
        node->prev = temp;
    }
    printf("Da them don hang moi.\n");
}

void showOrders()
{
    printf("\n—— Don hang CHUA GIAO ——\n");
    NodeD *d = headD;
    if (!d)
        printf("Khong co don chua giao.\n");
    while (d)
    {
        printf("ID: %d | Ten: %s | Tien: %.2f | Trang thai: Chua giao\n", d->data.id, d->data.customer, d->data.total);
        d = d->next;
    }

    printf("\n—— Don hang DA GIAO ——\n");
    NodeS *s = headS;
    if (!s)
        printf("Khong co don da giao.\n");
    while (s)
    {
        printf("ID: %d | Ten: %s | Tien: %.2f | Trang thai: Da giao\n", s->data.id, s->data.customer, s->data.total);
        s = s->next;
    }
}

void deleteOrder()
{
    int id;
    printf("Nhap ID can xoa: ");
    scanf("%d", &id);
    NodeD *temp = headD;

    while (temp && temp->data.id != id)
        temp = temp->next;

    if (!temp)
    {
        printf("Khong tim thay don hang.\n");
        return;
    }

    if (temp->prev)
        temp->prev->next = temp->next;
    else
        headD = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Da xoa don hang co ID %d.\n", id);
}

void updateOrder()
{
    int id;
    printf("Nhap ID can cap nhat: ");
    scanf("%d", &id);
    NodeD *temp = headD;

    while (temp && temp->data.id != id)
        temp = temp->next;

    if (!temp)
    {
        printf("Khong tim thay don hang.\n");
        return;
    }

    printf("Nhap ten moi: ");
    getchar();
    gets(temp->data.customer);
    printf("Nhap tong tien moi: ");
    scanf("%f", &temp->data.total);
    printf("Cap nhat thanh cong.\n");
}

void markAsDelivered()
{
    int id;
    printf("Nhap ID don hang da giao: ");
    scanf("%d", &id);
    NodeD *temp = headD;

    while (temp && temp->data.id != id)
        temp = temp->next;

    if (!temp)
    {
        printf("Khong tim thay don hang.\n");
        return;
    }

    Order o = temp->data;
    o.status = 1;

    NodeS *node = createNodeS(o);
    if (headS == NULL)
        headS = node;
    else
    {
        NodeS *t = headS;
        while (t->next)
            t = t->next;
        t->next = node;
    }

    if (temp->prev)
        temp->prev->next = temp->next;
    else
        headD = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Da chuyen don hang vao danh sach da giao.\n");
}

void sortOrders()
{
    if (!headD || !headD->next)
        return;

    for (NodeD *i = headD; i != NULL; i = i->next)
    {
        for (NodeD *j = i->next; j != NULL; j = j->next)
        {
            if (i->data.total > j->data.total)
            {
                Order temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("Da sap xep don hang theo tong tien.\n");
}

void searchOrder()
{
    char name[50];
    printf("Nhap ten khach hang can tim: ");
    getchar();
    gets(name);
    int found = 0;

    NodeD *d = headD;
    while (d)
    {
        if (strcmp(d->data.customer, name) == 0)
        {
            printf("CHUA GIAO | ID: %d | Tien: %.2f\n", d->data.id, d->data.total);
            found = 1;
        }
        d = d->next;
    }

    NodeS *s = headS;
    while (s)
    {
        if (strcmp(s->data.customer, name) == 0)
        {
            printf("DA GIAO   | ID: %d | Tien: %.2f\n", s->data.id, s->data.total);
            found = 1;
        }
        s = s->next;
    }

    if (!found)
        printf("Khong tim thay ten khach hang trong danh sach.\n");
}

int main()
{
    int choice;
    do
    {
        printf("\n—————— ORDER MANAGER ——————\n");
        printf("1. Them don hang moi\n");
        printf("2. Hien thi danh sach don hang\n");
        printf("3. Xoa don hang (theo ID)\n");
        printf("4. Cap nhat thong tin don hang\n");
        printf("5. Danh dau don hang da giao\n");
        printf("6. Sap xep don hang theo tong tien\n");
        printf("7. Tim kiem don hang theo ten khach\n");
        printf("8. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addOrder();
            break;
        case 2:
            showOrders();
            break;
        case 3:
            deleteOrder();
            break;
        case 4:
            updateOrder();
            break;
        case 5:
            markAsDelivered();
            break;
        case 6:
            sortOrders();
            break;
        case 7:
            searchOrder();
            break;
        case 8:
            printf("Tam biet!\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (choice != 8);

    return 0;
}
