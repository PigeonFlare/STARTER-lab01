// Made by Henry Li

#include "intlist.h"

#include <iostream>

using std::cout;

// copy constructor
IntList::IntList(const IntList &source)
{
    head = nullptr;
    tail = nullptr;
    for (Node *n = source.head; n; n = n->next)
    {
        push_back(n->info);
    }
}

// destructor deletes all nodes
IntList::~IntList()
{
    Node *current = head;
    while (current)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}

// return sum of values in list
int IntList::sum() const
{
    int total = 0;
    for (Node *n = head; n; n = n->next)
    {
        total += n->info;
    }
    return total;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const
{
    for (Node *n = head; n; n = n->next)
    {
        if (n->info == value)
        {
            return true;
        }
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const
{
    if (!head)
    {
        return 0;
    }
    int m = head->info;
    for (Node *n = head->next; n; n = n->next)
    {
        if (n->info > m)
        {
            m = n->info;
        }
    }
    return m;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const
{
    int cnt = count();
    if (cnt == 0)
    {
        return 0.0;
    }
    return static_cast<double>(sum()) / cnt;
}

// inserts value as new node at beginning of list
void IntList::push_front(int value)
{
    Node *n = new Node{value, head};
    head = n;
    if (!tail)
    {
        tail = n;
    }
}

// append value at end of list
void IntList::push_back(int value)
{
    Node *n = new Node{value, nullptr};
    if (!head)
    {
        head = n;
        tail = n;
    }
    else
    {
        tail->next = n;
        tail = n;
    }
}

// return count of values
int IntList::count() const
{
    int cnt = 0;
    for (Node *n = head; n; n = n->next)
    {
        ++cnt;
    }
    return cnt;
}

// Assignment operator should copy the list from the source
// to this list, deleting/replacing any existing nodes
IntList &IntList::operator=(const IntList &source)
{
    if (this == &source)
    {
        return *this;
    }

    Node *current = head;
    while (current)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;

    for (Node *n = source.head; n; n = n->next)
    {
        push_back(n->info);
    }

    return *this;
}

// constructor sets up empty list
IntList::IntList()
{
    head = nullptr;
    tail = nullptr;
}

// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const
{
    Node *n = head;
    cout << '[';
    while (n)
    {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}
