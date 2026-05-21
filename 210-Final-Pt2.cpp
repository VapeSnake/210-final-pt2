// COMSC210 | Final Part 2 | Noel Mier-Luna
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <array>
using namespace std;

// This class was used in midterm 2, and I think it would be a great idea to use again for this coffee booth program.
class CoffeeBooth
{
private:
    struct Node
    {
        string name;
        string drinkOrder;
        Node *prev;
        Node *next;
        Node(string na, string dr, Node *p = nullptr, Node *n = nullptr)
        {
            name = na;
            drinkOrder = dr;
            prev = p;
            next = n;
        }
    };

    Node *head;
    Node *tail;

public:
    CoffeeBooth()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insert_after(string name, string drinkOrder, int position)
    {
        if (position < 0)
        {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node *newNode = new Node(name, drinkOrder);
        if (!head)
        {
            head = tail = newNode;
            return;
        }

        Node *temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp)
        {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode;
        temp->next = newNode;
    }

    void delete_val(string name)
    {
        if (!head)
            return;

        Node *temp = head;

        while (temp && temp->name != name)
            temp = temp->next;

        if (!temp)
            return;

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev;

        delete temp;
    }

    void delete_pos(int pos)
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }

        if (pos == 1)
        {
            pop_front();
            return;
        }

        Node *temp = head;

        for (int i = 1; i < pos; i++)
        {
            if (!temp)
            {
                cout << "Position doesn't exist." << endl;
                return;
            }
            else
                temp = temp->next;
        }
        if (!temp)
        {
            cout << "Position doesn't exist." << endl;
            return;
        }

        if (!temp->next)
        {
            pop_back();
            return;
        }

        Node *tempPrev = temp->prev;
        tempPrev->next = temp->next;
        temp->next->prev = tempPrev;
        delete temp;
    }

    void push_back(string name, string drinkOrder)
    {
        Node *newNode = new Node(name, drinkOrder);
        if (!tail)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(string name, string drinkOrder)
    {
        Node *newNode = new Node(name, drinkOrder);
        if (!head)
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void pop_front()
    {

        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *temp = head;

        if (head->next)
        {
            head = head->next;
            head->prev = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    void pop_back()
    {
        if (!tail)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = tail;

        if (tail->prev)
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    ~CoffeeBooth()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    void print()
    {
        Node *current = head;
        if (!current)
        {
            cout << "List is empty." << endl;
            return;
        }
        cout << "resulting line: \n"; // Moved here to print before the loop to avoid printing it multiple times.
        while (current)
        {
            cout << current->name << " \n";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse()
    {
        Node *current = tail;
        if (!current)
        {
            cout << "List is empty." << endl;
            return;
        }
        while (current)
        {
            cout << current->name << " ";
            current = current->prev;
        }
        cout << endl;
    }

    bool is_empty()
    {
        return head == nullptr;
    }

    string get_head_name()
    {
        if (head)
            return head->name;
        return "";
    }

    string get_head_drink()
    {
        if (head)
            return head->drinkOrder;
        return "";
    }
};

int main()
{
    vector<string> names = {
        "Liam", "Olivia", "Noah", "Emma", "Oliver",
        "Ava", "Elijah", "Charlotte", "William", "Sophia",
        "James", "Amelia", "Benjamin", "Isabella", "Lucas",
        "Mia", "Henry", "Evelyn", "Alexander", "Harper",
        "Mason", "Camila", "Michael", "Gianna", "Ethan",
        "Abigail", "Daniel", "Luna", "Jacob", "Ella",
        "Logan", "Elizabeth", "Jackson", "Sofia", "Levi",
        "Avery", "Sebastian", "Scarlett", "Jack", "Emily",
        "Aiden", "Aria", "Owen", "Penelope", "Samuel",
        "Chloe", "Matthew", "Layla", "David", "Milani"};

    array<string, 10> drinks = {
        "Espresso", "Latte", "Cappuccino", "Americano", "Mocha",
        "Macchiato", "Flat White", "Cold Brew", "Iced Coffee", "Frappuccino"};

    srand(time(0));
    CoffeeBooth booth;
    //Milestone 1 Complete. Vector for names and array for drinks created. Doubly Linked list imported from midterm 2 and changed to include drinks.

    return 0;
}