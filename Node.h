#pragma once
#include<iostream>
#include <string>


template<typename T, typename S>
class Node
{

public:
    Node();
    Node(T data1, S data2);
    T getData1() const;
    S getData2() const;
    void setNextNode(Node<T, S>* const nextNode);
    Node<T, S>* getNextNode() const;
    void setData(const T data1, const S data2);

private:
    T data1;
    S data2;
    Node<T, S>* next;
};


template<typename T, typename S>
Node<T, S>::Node()
{}

template<typename T, typename S>
Node<T, S>::Node(T data1, S data2)
{
    this->data1 = data1;
    this->data2 = data2;
    this->next = nullptr;
}

template<typename T, typename S>
T Node<T, S>::getData1() const
{
    return this->data1;
}

template<typename T, typename S>
S Node<T, S>::getData2() const
{
    return this->data2;
}

template<typename T, typename S>
void Node<T, S>::setNextNode(Node<T, S>* const nextNode)
{
    this->next = nextNode;
}

template<typename T, typename S>
Node<T, S>* Node<T, S>::getNextNode() const
{
    return this->next;
}

template<typename T, typename S>
void Node<T, S>::setData(const T data1, S data2)
{
    this->data1 = data1;
    this->data2 = data2;
}




