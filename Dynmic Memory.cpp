#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class DynamicMemoryAllocation
{
public:
    Node *HEAD;

    DynamicMemoryAllocation()
    {
        HEAD = NULL;
    }

    void append(int value)
    {
        Node *newNode = new Node(value);

        if (HEAD == NULL)
        {
            HEAD = newNode;
            return;
        }

        Node *ptr = HEAD;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = newNode;
    }

    void display()
    {
        if (HEAD == NULL)
        {
            cout << "List is empty..." << endl;
            return;
        }

        Node *ptr = HEAD;

        cout << "Linked List: ";
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    void insert_at_beginning(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = HEAD;
        HEAD = newNode;
    }

    void Search(int key)
    {
        Node *ptr = HEAD;
        int position = 1;

        while (ptr != NULL)
        {
            if (ptr->data == key)
            {
                cout << "Key found at position: " << position << endl;
                return;
            }
            ptr = ptr->next;
            position++;
        }

        cout << "Key not found..." << endl;
    }

    void Delete_node(int key)
    {
        if (HEAD == NULL)
        {
            cout << "List is empty..." << endl;
            return;
        }

        if (HEAD->data == key)
        {
            Node *temp = HEAD;
            HEAD = HEAD->next;
            delete temp;
            cout << "Node deleted successfully!" << endl;
            return;
        }

        Node *ptr = HEAD;
        Node *prev = NULL;

        while (ptr != NULL && ptr->data != key)
        {
            prev = ptr;
            ptr = ptr->next;
        }

        if (ptr == NULL)
        {
            cout << "Key not found..." << endl;
            return;
        }

        prev->next = ptr->next;
        delete ptr;

        cout << "Node deleted successfully!" << endl;
    }

    void reverse()
    {
        Node *prev = NULL;
        Node *current = HEAD;
        Node *nextNode = NULL;

        while (current != NULL)
        {
            nextNode = current->next;
            current->next = prev;

            prev = current;
            current = nextNode;
        }

        HEAD = prev;
        cout << "Linked List reversed successfully!" << endl;
    }
};

int main()
{
    DynamicMemoryAllocation obj;

    obj.append(10);
    obj.append(20);
    obj.append(30);
    obj.append(40);

    obj.display();

    obj.insert_at_beginning(5);
    obj.display();

    obj.Search(30);
    obj.Search(99);

    obj.Delete_node(20);
    obj.display();

    obj.reverse();
    obj.display();

    return 0;
}
