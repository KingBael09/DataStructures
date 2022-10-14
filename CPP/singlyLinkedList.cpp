#include <iostream>

using namespace std;

class sllNode
{
public:
    int data;
    sllNode *next;
    // Default Constructor
    sllNode()
    {
        data = 0;
        this->next = NULL;
    }
    // Parameterized Constructor
    sllNode(int value)
    {
        this->data = value;
        this->next = NULL;
    }
};

class singlyLinkedList
{
    sllNode *head;

public:
    singlyLinkedList()
    {
        head = NULL;
    }

    void insertNode(int);
    void deleteNode(int);
    void display();
};

void singlyLinkedList::insertNode(int data)
{
    sllNode *newNode = new sllNode(data);

    if (head == NULL)
    {
        head = newNode;
        cout << "\nNode Created!\n\n";
        return;
    }

    sllNode *ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    cout << "\nNode Inserted!\n\n";
}

void singlyLinkedList::deleteNode(int position)
{
    sllNode *ptr = head, *temp = NULL;
    int listLen = 0;

    if (head == NULL)
    {
        cout << "\nList is Empty!" << endl;
        return;
    }

    while (ptr != NULL)
    {
        ptr = ptr->next;
        listLen++;
    }

    if (listLen < position)
    {
        cout << "\nIndex out of Range" << endl;
        return;
    }

    ptr = head;

    if (position == 1)
    {
        head = head->next;
        delete ptr;
        return;
    }

    while (position > 1)
    {
        temp = ptr;

        ptr = ptr->next;
        position--;
    }
    temp->next = ptr->next;
    // TF Happened

    delete ptr;
    cout << "\nNode Deleted!\n\n";
}

void singlyLinkedList::display()
{
    sllNode *ptr = head;

    if (head == NULL)
    {
        cout << "\nList is Empty" << endl;
        return;
    }
    cout << "Displaying List: ";
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{    int choice, data, position;

    singlyLinkedList list;

    while (choice != 0)
    {
        cout << "\n1. Enter New Node At the End\n2. Delete Node at Position\n3. Display List\n0. Exit" << endl;
        cout << "\n\nYour Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Data: ";
            cin >> data;
            list.insertNode(data);
            break;

        case 2:
            cout << "Enter Position of Node: ";
            cin >> position;
            list.deleteNode(position);
            break;
        case 3:
            list.display();
            break;
        case 0:
            cout << "Thank You!" << endl;
            break;
        default:
            cout << "Invalid Input\t\tPlease Retry";
            break;
        }
    }
}
