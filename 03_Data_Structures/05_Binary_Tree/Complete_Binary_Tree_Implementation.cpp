#include <iostream>
using namespace std;

class CompleteBT
{
    int *data;
    int size;
    int capacity;

public:
    CompleteBT(int cap)
    {
        capacity = cap;
        size = 0;
        data = new int[capacity];
    }

    ~CompleteBT()
    {
        delete[] data;
    }

    void insert(int val)
    {
        if (size == capacity)
            return;
        data[size++] = val;
    }

    int parent(int i)
    {
        if (i == 0)
            return -1;
        return (i - 1) / 2;
    }

    int leftNode(int i)
    {
        int idx = 2 * i + 1;
        return (idx < size) ? idx : -1;
    }

    int rightNode(int i)
    {
        int idx = 2 * i + 2;
        return (idx < size) ? idx : -1;
    }

    int leftSibling(int i)
    {
        if (i % 2 == 0 && i > 0)
            return i - 1;
        return -1;
    }

    int rightSibling(int i)
    {
        if (i % 2 == 1 && i + 1 < size)
            return i + 1;
        return -1;
    }

    int get(int idx)
    {
        if (idx < size)
            return data[idx];
        return -1;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    CompleteBT tree(10);

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(60);

    tree.print();

    int i = 2;

    int p = tree.parent(i);
    if (p != -1)
        cout << tree.get(p) << endl;
    else
        cout << "None" << endl;

    int l = tree.leftNode(i);
    if (l != -1)
        cout << tree.get(l) << endl;
    else
        cout << "None" << endl;

    int r = tree.rightNode(i);
    if (r != -1)
        cout << tree.get(r) << endl;
    else
        cout << "None" << endl;

    int ls = tree.leftSibling(i);
    if (ls != -1)
        cout << tree.get(ls) << endl;
    else
        cout << "None" << endl;

    int rs = tree.rightSibling(i);
    if (rs != -1)
        cout << tree.get(rs) << endl;
    else
        cout << "None" << endl;

    return 0;
}
