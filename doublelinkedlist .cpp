
struct Node
{
    Node* next;
    Node* prv;
    int data;

};
class linkedlist
{

public:
    Node* head, * t; Node* p;
    linkedlist()
    {
        head = NULL; p = NULL; t == NULL;
    }
    void insert(int val)
    {
        Node* ne = new Node(); ne->data = val; ne->next = NULL;
        // cout << "ddk\n";
        if (head == NULL)
        {
            t = ne; head = ne;  return;
        }
        ne->prv = t;
        t->next = ne;
        t = ne;
    }
    void pos(int v)
    {
        int i = 0;
        Node* tmp = head;
        while (i < v)
        {
            i++; tmp = tmp->next;
        }
        p = tmp;
    }
    void moveLeft()
    {
        if (p != head && p != NULL)
        {
            p = p->prv;
        }
    }
    void moveRigth()
    {
        if (p->next != NULL && p != NULL)
        {
            p = p->next;
        }
    }
    void insert_Left(int val)
    {
        Node* ne = new Node();
        ne->data = val;
        if (p == head)
        {
            ne->next = p; p->prv = ne;
            head = ne;
            return;
        }
        ne->next = p; ne->prv = p->prv;
        p->prv->next = ne;
        p->prv = ne;
    }
    void insert_Rigth(int val)
    {
        Node* ne = new Node();
        ne->data = val;
        if (p == t)
        {
            ne->prv = p;
            p->next = ne;
            t = ne;
            ne->next = NULL; return;
        }
        ne->prv = p;
        ne->next = p->next;
        p->next->prv = ne;
        p->next = ne;
    }
    void dis()
    {
        Node* t = head;
        while (t != NULL)
        {
            cout << t->data << ' ';
            t = t->next;
        }
    }
};