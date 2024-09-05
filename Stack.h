#pragma once
#include "Node.h"


class Stack {

private:
	Node* root;
public:

	Stack();
	/*~Stack();*/
	void road(int[7][7],int, int, int, int);
	void recursiveRoad(int[7][7], int, int, int, int);
	void insertToStack(Node*);

	bool insertTop(int[7][7], int&, int&, int, int, bool&);
	bool insertRight(int[7][7], int&, int&, int, int, bool&);
	bool insertBottom(int[7][7], int&, int&, int, int, bool&);
	bool insertLeft(int[7][7], int&, int&, int, int, bool&);

	bool popTop(int[7][7], int&, int&);
	bool popRight(int[7][7], int&, int&);
	bool popBottom(int[7][7], int&, int&);
	bool popLeft(int[7][7], int&, int&);



	bool visited(int, int);
	Node* pop();
	//void print();


	

};
