#include "Question.h"


Question::Question()
{
	this->command = nullptr;
	this->qNumber = 0;
}
Question::Question(Node<string, string>* command, int qNumber)
{
	this->command = command;
	this->qNumber = qNumber;
}
Question::~Question()
{
}
void Question::setData(Node<string, string>* command)
{
	this->command = command;
}
Node<string, string>* Question::getCommand()
{
	return this->command;
}
int Question::getQNumber()
{
	return this->qNumber;
}

void Question::setQNumber(const int num)
{
	this->qNumber = num;
}