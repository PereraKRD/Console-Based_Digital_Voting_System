#pragma once
#include <iostream>
using namespace std;


template <typename T>


class List {
public:
    class Node {
    public:
        T data;
        Node* next;

        //destructor
        ~Node() {

        }
    };

    Node* head;

    List() {
        head = NULL;
    }
    //destructor
    ~List() {

    }

    void add(T item) {
        Node* node = new Node;
        node->data = item;
        if (head == NULL)
        {
            head = node;
        }
        else
        {
            Node* current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = node;
        }
    }

    T* findByID(int id) {
        Node* current;
        current = head;
        while (current != NULL) {
            if (current->data.getID() == id) {
                return &current->data;
            }
            current = current->next;
        }
        return NULL;
    }

    void contesterDisplay() {
        Node* current;
        current = head;
        cout << "\t\t\t\t\t________________________________\t" << endl;
        cout << "\t\t\t\t\t|   ID \t|\t" << "  NAME" << "\t\t|" << endl;
        cout << "\t\t\t\t\t________________________________\t" << endl;
        while (current != NULL)
        {
            cout << "\t\t\t\t\t|   " << current->data.getID() << "\t|\t" << current->data.getName() << "\t|" << endl;
            current = current->next;
        }
        cout << "\t\t\t\t\t________________________________\t" << endl;
    }

    void voterDisplay() {
        Node* current = head;
        cout << " _______________________________________________________________________________________________________________" << endl;
        cout << " | ID |" << "\tFIRSTNAME\t|" << "\tLASTNAME\t|" << "\tDOB\t\t|" << "\tADDRESS\t\t|" << "  Voted(0/1)  |" << endl;
        cout << " _______________________________________________________________________________________________________________" << endl;
        while (current != NULL)
        {
            cout << " | " << current->data.getID() << "  |\t" << current->data.getFirstName() <<
                "\t\t|\t" << current->data.getLastName() << "\t\t|\t" << current->data.getDateOfBirth() << "\t|\t" <<
                current->data.getAddress() << "\t|\t" << current->data.getIsVoted() << "      |" << endl;
            current = current->next;
        }
        cout << " _______________________________________________________________________________________________________________" << endl;
        delete current;
    }

    void contesterCountDisplay() {
        Node* current;
        current = head;
        cout << "\t\t\t________________________________________________________________" << endl;
        cout << "\t\t\t|\tID\t|" << "\tNAME\t\t" << "|\tVote Count\t|" << endl;
        cout << "\t\t\t________________________________________________________________" << endl;
        while (current != NULL)
        {
            if (current == head)
                cout << "\033[32m";
            else
                cout << "\033[37m";
            cout << "\t\t\t|\t" << current->data.getID() << "\t|\t" << current->data.getName() << "\t|\t  " << current->data.getVoteCount() << "    \t\t|" << endl;
            current = current->next;
        }
        cout << "\t\t\t________________________________________________________________" << endl;
        delete current;
    }


    void finalResults() {
        Node* current;
        current = head;
        while (current != NULL) {
            Node* temp;
            temp = current->next;
            while (temp != NULL) {
                if (current->data.getVoteCount() < temp->data.getVoteCount()) {
                    Node* N = new Node;
                    N->data = current->data;
                    current->data = temp->data;
                    temp->data = N->data;
                    delete N;
                }
                temp = temp->next;
            }
            current = current->next;
            delete temp;
        }
        delete current;
        contesterCountDisplay();
    }
};