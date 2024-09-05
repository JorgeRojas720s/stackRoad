
#include "Node.h"

Node::Node()
{
	this->x = 0;
	this->y = 0;
	this->visited = false;
	this->next = nullptr;
}

Node::Node(int x, int y, bool visited)
{
	this->x = x;
	this->y = y;
	this->visited = visited;
	this->next = nullptr;
}

Node::~Node()
{
	this->x = 0;
	this->y = 0;
	this->visited = false;
	this->next = nullptr;
}

Node* Node::getNext()
{
	return this->next;
}

int Node::getX()
{
	return this->x;
}

int Node::getY()
{
	return this->y;
}

bool Node::getVisited()
{
	return this->visited;
}

void Node::setNext(Node* next)
{
	this->next = next;
}

void Node::setX(int x)
{
	this->x = x;
}

void Node::setY(int y)
{
	this->y = y;
}

void Node::setVisited(bool visited)
{
	this->visited = visited;
}

