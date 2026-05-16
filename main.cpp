#include <iostream>
#include "treap.hpp"

using namespace std;
using namespace ds;

void print_options()
{
    cout << "\n1. Insert element\n";
    cout << "2. Remove element\n";
    cout << "3. Find element\n";
    cout << "4. Find minimum\n";
    cout << "5. Find maximum\n";
    cout << "6. Remove minimum\n";
    cout << "7. Remove maximum\n";
    cout << "8. Print (inorder)\n";
    cout << "9. Test copy constructor\n";
    cout << "10. Test move constructor\n";
    cout << "11. Exit\n\n";
    cout << "CHOOSE: ";
}

int main()
{
    cout << "-- WELCOME TO A TREAP VISUALIZER! --\n";
    Treap<int> *t = new Treap<int>();

    while (1)
    {
        print_options();
        string option;
        cin >> option;

        if (option == "1")
        {
            int val;
            cout << "ENTER VALUE: ";
            cin >> val;
            t->insert(val);
        }

        else if (option == "2")
        {
            int val;
            cout << "ENTER VALUE: ";
            cin >> val;
            t->remove(val);
        }

        else if (option == "3")
        {
            int val;
            cout << "ENTER VALUE: ";
            cin >> val;
            cout << "ELEMENT " << val;
            if (t->find(val)) cout << " FOUND!\n";
            else cout << " NOT FOUND!\n";
        }

        else if (option == "4")
        {
            try
            {
                cout << t->find_minimum() << '\n';
            }
            catch (...)
            {
                cout << "EMPTY TREE!\n";
            }
        }

        else if (option == "5")
        {
            try
            {
                cout << t->find_maximum() << '\n';
            }
            catch (...)
            {
                cout << "EMPTY TREE!\n";
            }
        }

        else if (option == "6") t->remove_minimum();

        else if (option == "7") t->remove_maximum();

        else if (option == "8") cout << *t << '\n';

        else if (option == "9")
        {
            cout << "ORIGINAL: " << *t << '\n';
            Treap<int> copy_t(*t);
            cout << "COPY: " << copy_t << '\n';
        }

        else if (option == "10")
        {
            cout << "BEFORE MOVE: " << *t << '\n';
            Treap<int> *moved = new Treap<int>(move(*t));
            cout << "MOVE CONSTRUCTOR: " << *moved << '\n';
            cout << "ORIGINAL AFTER MOVE: " << *t << '\n';
            delete moved;
        }

        else break;
    }
    
    delete t;
    return 0;
}