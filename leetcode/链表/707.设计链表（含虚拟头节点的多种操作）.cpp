class MyLinkedList
{
public:
    // 定义链表节点结构体
    struct LinkedNode
    {
        int val;
        LinkedNode *next;
        LinkedNode(int val) : val(val), next(nullptr) {}
    };

    // 初始化链表
    MyLinkedList()
    {
        _dummyHead = new LinkedNode(0); // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点 //虚拟表头要用new创建
        _size = 0;                      // 记录节点个数
    }

    // 获取到第index个节点数值，如果index是非法数值直接返回-1， 注意index是从0开始的，第0个节点就是头结点
    int get(int index)
    {
        if (index > (_size - 1) || index < 0) // _size - 1为最大的索引值
        {
            return -1;
        }
        LinkedNode *cur = _dummyHead->next;
        // 此时cur指向第一个元素
        while (index--)
        { // 如果--index 就会陷入死循环
            cur = cur->next;
        }
        // 此时的cur指向第index个节点
        return cur->val;
    }

    // 在链表最前面插入一个节点，插入完成后，新插入的节点为链表的新的头结点
    void addAtHead(int val)
    {
        LinkedNode *newNode = new LinkedNode(val); // 新节点，注意new
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    // 在链表最后面添加一个节点
    void addAtTail(int val)
    {
        LinkedNode *newNode = new LinkedNode(val); // 新节点，注意new
        LinkedNode *cur = _dummyHead;
        // 此时cur指向虚拟头节点
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        // 此时cur指向最后一个元素
        cur->next = newNode;
        _size++;
    }

    // 在第index个节点之前插入一个新节点。例如index为0，那么新插入的节点为链表的新头节点。
    // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
    // 如果index大于链表的长度，则返回空
    void addAtIndex(int index, int val)
    {
        if (index > _size)
        {
            return;
        }
        LinkedNode *newNode = new LinkedNode(val);
        LinkedNode *cur = _dummyHead;
        // 此时cur指向虚拟头节点
        while (index--)
        {
            cur = cur->next;
        }
        // 此时cur指向第index-1个元素
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }

    // 删除第index个节点，如果index 大于等于链表的长度，直接return，注意index是从0开始的
    void deleteAtIndex(int index)
    {
        if (index >= _size || index < 0)
        {
            return;
        }
        LinkedNode *cur = _dummyHead;
        // 此时cur指向虚拟头节点
        while (index--)
        {
            cur = cur->next;
        }
        // 此时cur指向第index-1个元素
        LinkedNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }

    // 打印链表
    void printLinkedList()
    {
        LinkedNode *cur = _dummyHead;
        while (cur->next != nullptr)
        {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

private:
    int _size;
    LinkedNode *_dummyHead;
};