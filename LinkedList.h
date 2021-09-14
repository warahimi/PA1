#pragma once
#include "Node.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
template<typename T, typename S>
class LinkedList
{

public:
    LinkedList();
    void insertAtBeginning(const T& data1, const S& data2);
    void deleteNode(const std::string& command);
    Node<T, S>* getHeadNode() const;
    Node<T, S>* getTailNode() const;

private:
    Node<T, S>* head;
};


template<typename T, typename S>
LinkedList<T, S>::LinkedList()
{
    this->head = nullptr;
}

template<typename T, typename S>
void LinkedList<T, S>::deleteNode(const std::string& command)
{

    //if list is empty
    {
        if (head==nullptr)
        {
            cout << "The list is empty.\n";
            return;
        }
        else
        {
            Node<T, S>* curNode = head, *prevNode = nullptr;
            //travers the list to find the item to delete 
            while (curNode != nullptr)
            {
                if (curNode->getData1() == command)
                {
                    //found the node to delete
                    break;
                }
                else
                {
                    //continue traversing 
                    prevNode = curNode;
                    curNode = curNode->getNextNode();
                }
            }
            //node not found
            if (curNode == nullptr)
            {
                cout << "Command " << command << " not found in the list.\n";
            }
            else
            {
                //Item found and curNode is point to it

                //case 1: if the it is the head node
                if (head == curNode)
                {
                    head = head->getNextNode();
                }
                else
                {
                    //deleting from beyond the head
                    prevNode->setNextNode(curNode->getNextNode());
                }
                delete curNode;
            }
        }
    }
}

template<typename T, typename S>
void LinkedList<T, S>::insertAtBeginning(const T& data1, const S& data2)
{
    //creating node on the heap
    Node<T, S>* newNode = new Node<T, S>(data1, data2);

    if (newNode != nullptr)
    {
        if (this->head == nullptr)
        {
            this->head = newNode;
        }
        else
        {
            newNode->setNextNode(this->head);
            this->head = newNode;
        }
    }
}



template<typename T, typename S>
Node<T, S>* LinkedList<T, S>::getHeadNode() const
{
    return this->head;
}

template<typename T, typename S>
Node<T, S>* LinkedList<T, S>::getTailNode() const
{
    return this->tail;
}






