#include <iostream>
#include "Stack.h"


Stack::Stack()
{
	this->root = nullptr;
}

void Stack::road(int matrix[7][7], int x, int y, int a, int b)
{
	if (this->root == nullptr) {
		insertToStack(new Node(x, y, false));
	}


	bool end = false;

	do {
		std::cout << "[" << x << "," << y << "]" << "\n";

		if (insertTop(matrix, x, y, a, b, end)) {
			continue;
		}
		if (insertRight(matrix, x, y, a, b, end)) {
			continue;
		}
		if (insertBottom(matrix, x, y, a, b, end)) {
			continue;
		}
		if (insertLeft(matrix, x, y, a, b, end)) {
			continue;
		}

		/* Logica para devolverse de un camino*/

		if (popTop(matrix, x, y)) {
			continue;
		}
		if (popRight(matrix, x, y)) {
			continue;
		}
		if (popBottom(matrix, x, y)) {
			continue;
		}
		if (popLeft(matrix, x, y)) {
			continue;
		}

	} while (end == false);
	std::cout << "[" << x << "," << y << "]";
}

void Stack::recursiveRoad(int matrix[7][7], int x, int y, int a, int b)
{
	std::cout << "[" << x << "," << y << "]" << "\n";

	if (this->root == nullptr) {
		insertToStack(new Node(x, y, false));
	}

	if (x == a && y == b) {
		return;
	}

	bool end = false;


	if (insertTop(matrix, x, y, a, b, end)) {
		return recursiveRoad(matrix, x, y, a, b);
	}
	if (insertRight(matrix, x, y, a, b, end)) {
		return recursiveRoad(matrix, x, y, a, b);
	}
	if (insertBottom(matrix, x, y, a, b, end)) {
		return recursiveRoad(matrix, x, y, a, b);
	}
	if (insertLeft(matrix, x, y, a, b, end)) {
		return recursiveRoad(matrix, x, y, a, b);
	}

	/* Logica para devolverse de un camino*/

	if (popTop(matrix, x, y)) {
		return recursiveRoad(matrix, x, y, a, b);
	}
	if (popRight(matrix, x, y)) {
		return recursiveRoad(matrix, x, y, a, b);
	}
	if (popBottom(matrix, x, y)) {
		return recursiveRoad(matrix, x, y, a, b);
	}
	if (popLeft(matrix, x, y)) {
		return recursiveRoad(matrix, x, y, a, b);
	}

}


bool Stack::insertTop(int matrix[7][7], int& x, int& y, int a, int b, bool& end)
{
	if (matrix[x - 1][y] == 1 && !visited(x - 1, y)) {
		insertToStack(new Node(x - 1, y, false));
		if (x - 1 == a && y == b) {
			end = true;
		}
		x = x - 1;
		return true;
	}
	return false;
}

bool Stack::insertRight(int matrix[7][7], int& x, int& y, int a, int b, bool& end)
{
	if (matrix[x][y + 1] == 1 && !visited(x, y + 1)) {
		insertToStack(new Node(x, y + 1, false));
		if (x == a && y + 1 == b) {
			end = true;
		}
		y = y + 1;
		return true;
	}
	return false;
}

bool Stack::insertBottom(int matrix[7][7], int& x, int& y, int a, int b, bool& end)
{
	if (matrix[x + 1][y] == 1 && !visited(x + 1, y)) {
		insertToStack(new Node(x + 1, y, false));
		if (x + 1 == a && y == b) {
			end = true;
		}
		x = x + 1;
		return true;
	}
	return false;
}

bool Stack::insertLeft(int matrix[7][7], int& x, int& y, int a, int b, bool& end)
{
	if (matrix[x][y - 1] == 1 && !visited(x, y - 1)) {
		insertToStack(new Node(x, y - 1, false));
		if (x == a && y - 1 == b) {
			end = true;
		}
		y = y - 1;
		return true;
	}
	return false;
}

bool Stack::popTop(int matrix[7][7], int& x, int& y)
{
	if (matrix[x - 1][y] == 0 || visited(x - 1, y)) {
		std::cout << "<-";
		Node* previous = pop();
		x = previous->getX();
		y = previous->getY();
		return true;
	}
	return false;
}

bool Stack::popRight(int matrix[7][7], int& x, int& y)
{
	if (matrix[x][y + 1] == 0 || visited(x, y + 1)) {
		std::cout << "<-";
		Node* previous = pop();
		x = previous->getX();
		y = previous->getY();
		return true;
	}
	return false;
}

bool Stack::popBottom(int matrix[7][7], int& x, int& y)
{
	if (matrix[x + 1][y] == 0 || visited(x + 1, y)) {
		std::cout << "<-";
		Node* previous = pop();
		x = previous->getX();
		y = previous->getY();
		return true;
	}
	return false;
}

bool Stack::popLeft(int matrix[7][7], int& x, int& y)
{
	if (matrix[x][y - 1] == 0 || visited(x, y - 1)) {
		std::cout << "<-";
		Node* previous = pop();
		x = previous->getX();
		y = previous->getY();
		return true;
	}
	return false;
}

bool Stack::visited(int x, int y) {

	if (this->root == nullptr) {
		std::cout << "La lista esta vacía";
	}
	else {
		Node* current = this->root;
		while (current != nullptr) {
			if (current->getX() == x && current->getY() == y) {
				return true;
			}
			current = current->getNext();
		}
		return false;
	}
}

void Stack::insertToStack(Node* data)
{
	if (this->root == nullptr) {
		this->root = data;
	}
	else {
		Node* current = this->root;
		while (current->getNext() != nullptr) {
			current = current->getNext();
		}
		current->setNext(data);

	}

}

Node* Stack::pop()
{
	if (this->root != nullptr) {
		Node* currentNode = this->root;
		Node* previous = nullptr;

		if (currentNode->getNext() == nullptr) {
			this->root = nullptr;
			return currentNode;
		}

		while (currentNode != nullptr && currentNode->getVisited() == false) {

			/*

			std::cout << "\n" << "[" << endNode->getX() << "," << endNode->getY() << "]" << endNode->getVisited();;
			std::cout << "[------------------]";

			*/
			previous = currentNode;

			currentNode = currentNode->getNext();

		}

		previous->setVisited(true); // a los visitados que no eran les coloco true de que ya se reviso
		//previous->setNext(nullptr);
		return previous;
	}
	return nullptr;
}

/*

void Stack::print()
{
	Node* current = this->root;
	while (current != nullptr) {
		std::cout << "\n" <<  "[" << current->getX() << "," << current->getY() << "]";
		current = current->getNext();
	}

}

*/

