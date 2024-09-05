#pragma once

class Node {
private:

	Node* next;
	int x;
	int y;
	bool visited;

public:
	Node();
	Node(int, int, bool);
	~Node();

	Node* getNext();
	int getX();
	int getY();
	bool getVisited();
	void setNext(Node*);
	void setX(int x);
	void setY(int y);
	void setVisited(bool);


};