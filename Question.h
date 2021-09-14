#pragma once
#include<iostream>
#include "Node.h"
using std::string;
class Question
{
public:
	Question();
	Question(Node<string,string>* command, int qNumber);
	~Question();
	void setData(Node<string, string>* command);
	Node<string,string>* getCommand();
	void setQNumber(const int num);
	int getQNumber();

private:
	Node<string, string>* command;
	int qNumber;
};

