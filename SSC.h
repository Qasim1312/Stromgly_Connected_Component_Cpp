#include<iostream>
#include <string>
#include <fstream>
using namespace std;

#ifndef GRAPH_V3_0_H
#define GRAPH_V3_0_H

class List2d
{
public:
	struct node
	{
		node *next, *down;
		int data;
		node(int data = -1)
		{
			next = down = nullptr;
			this->data = data;
		}
	} *head;
	int index;
	int largestindex;
	List2d()
	{
		index = 0;
		largestindex = 0;
		head = nullptr;
	}
	void setlargestindex(string& output)
	{
		int maxindex = -1, maxnodes = -1;
		node *temp = head;
		int a = 0;
		while (temp != nullptr)
		{
			int nodes = 0;
			node *x = temp;
			while (x != nullptr)
			{
				nodes++;
				x = x->next;
			}
			if (nodes > maxnodes)
			{
				maxindex = a;
				maxnodes = nodes;
			}
			temp = temp->down;
			a++;
		}
		largestindex = maxindex;
		cout << "the Largest component has " << maxnodes << " nodes in it" << endl;
		cout << "and its list of nodes is now stored in a .outpout.txt file in root folder" << endl;
		temp = head;
		for (int b = 0; b < largestindex; b++)
		{
			temp = temp->down;
		}
		while (temp->next != nullptr)
		{
			output += to_string(temp->data) + '\n';
			temp = temp->next;
		}
		output += to_string(temp->data);
	}
	void increment()
	{
		index++;
	}
	void insert(int data)
	{
		if (head == nullptr)
		{
			head = new node(data);
			return;
		}
		node *temp = head;
		for (int a = 0; a < index; a++)
		{
			if (temp->down == nullptr)
			{
				temp->down = new node(-1);
			}
			temp = temp->down;
		}
		if (temp->data == -1)
		{
			temp->data = data;
			return;
		}
		while (temp->next != nullptr)
			temp = temp->next;
		temp->next = new node(data);
	}
	void print()
	{
		node *temp = head;

		temp = head;
		while (temp != nullptr)
		{
//			if(temp->data==-1)
//				continue;
			node *x = temp;
			while (x != nullptr)
			{
				cout << x->data << ", ";
				x = x->next;
			}
			cout << endl;
			temp = temp->down;
		}
	}
	void clear()
	{
		while (head != nullptr)
		{
			node *temp = head;
			head = head->down;
			while (temp != nullptr)
			{
				node *x = temp;
				temp = temp->next;
				delete x;
			}
		}
	}
	~
	List2d()
	{
		clear();
	}
};

class Stack
{
private:
	struct node
	{
		node *next;
		int data;
		node(int data = -1)
		{
			next = nullptr;
			this->data = data;
		}
	} *top;
public:
	Stack()
	{
		top = nullptr;
	}
	bool isEmpty()
	{
		return (top == nullptr) ? (true) : (false);
	}
	bool isIn(int data)
	{
		node *temp = top;
		while (temp != nullptr)
		{
			if (data == temp->data)
				return true;
			temp = temp->next;
		}
		return false;
	}
	void print()
	{
		node *temp = top;
		while (temp != nullptr)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
	void insert(int data)
	{
		if (!isIn(data))
		{
			node *temp = new node(data);
			temp->next = top;
			top = temp;
		}
	}
	void pop()
	{
		node *temp = top->next;
		delete top;
		top = temp;
	}
	int peek()
	{
		if (top == nullptr)
			return -1;
		return top->data;
	}
	void clear()
	{
		while (top != nullptr)
			pop();
	}
	~
	Stack()
	{
		clear();
	}
};
struct listNode
{
	listNode *next;
	int data;
	listNode(int data = -1)
	{
		next = nullptr;
		this->data = data;
	}
};
class List
{
public:
	listNode *list;

	List()
	{ list = nullptr; }
	void insert(int data)
	{
		if (list == nullptr)
		{
			list = new listNode(data);
			return;
		}
		listNode *temp = list;
		while (temp->next != nullptr)
		{
			if (temp->data == data)
				return;
			temp = temp->next;
		}
		if (temp->data == data)
			return;
		temp->next = new listNode(data);
	}
	void clear()
	{
		while (list != nullptr)
		{
			listNode *temp = list;
			list = list->next;
			delete temp;
		}
	}
	void print()
	{
		listNode *temp = list;
		while (temp != nullptr)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}
	}
	~List()
	{ clear(); }
};

class Tree
{
private:
	struct node
	{
		node *left, *right;
		int data;
		bool visited;
		List connections;
		node(int data = -1)
		{
			this->data = data;
			left = right = nullptr;
			visited = false;
		}
	} *root;
public:
	Tree()
	{
		root = nullptr;
	}
	void insert(int data, int connection = -1)
	{
		if (root == nullptr)
		{
			root = new node(data);
			if (connection != -1)
				root->connections.insert(connection);
		}
		else
		{
			node *temp = root;
			while (true)
			{
				if (data > temp->data && temp->right != nullptr)
					temp = temp->right;
				else if (data < temp->data && temp->left != nullptr)
					temp = temp->left;
				else if (data == temp->data)
				{
					if (connection != -1)
						temp->connections.insert(connection);
					return;
				}
				else if (data > temp->data && temp->right == nullptr)
				{
					temp->right = new node(data);
					if (connection != -1)
						temp->right->connections.insert(connection);
				}
				else if (data < temp->data && temp->left == nullptr)
				{
					temp->left = new node(data);
					if (connection != -1)
						temp->left->connections.insert(connection);
				}
			}

		}
	}
	void clear(node *temp = nullptr)
	{
		if (temp == nullptr)
			temp = root;
		if (temp != nullptr)
		{
			if (temp->left != nullptr)
				clear(temp->left);
			if (temp->right != nullptr)
				clear(temp->right);
			temp->connections.clear();
			delete temp;
			if (temp == root)
				root = nullptr;
			return;
		}
	}
	void printVisited(node *temp = nullptr)
	{
		if (temp == nullptr)
			temp = root;

		if (temp != nullptr)
		{
			if (temp->left != nullptr)
				printVisited(temp->left);

			if (temp->visited == true)
				cout << temp->data << endl;

			if (temp->right != nullptr)
				printVisited(temp->right);
			return;
		}
	}
	void printInorder(node *temp = nullptr)
	{
		if (temp == nullptr)
			temp = root;

		if (temp != nullptr)
		{
			if (temp->left != nullptr)
				printInorder(temp->left);
			cout << temp->data << "->";
			temp->connections.print();
			cout << endl;
			if (temp->right != nullptr)
				printInorder(temp->right);
			return;
		}
	}
	void SCC(List2d& components, Stack& stack, node *x, bool start = true)
	{
		if (start)
		{
			listNode *temp = x->connections.list;
			while (temp != nullptr)
			{
				SCCstart(components, stack, temp->data);
				temp = temp->next;
			}
			stack.insert(x->data);
		}
		else
		{
			listNode *temp = x->connections.list;
			while (temp != nullptr)
			{
				SCCend(components, stack, temp->data);
				temp = temp->next;
			}
			components.insert(x->data);
		}
	}
	void SCCstart(List2d components, Stack& stack, int data = -1, node *temp = nullptr)
	{
		if (temp == nullptr)
			temp = root;

		if (temp->data == data)
		{
			if (temp->visited)
			{
//				stack.insert(temp->data);
				return;
			}
			temp->visited = true;
			SCC(components, stack, temp);
			stack.insert(temp->data);
		}


		if (temp != nullptr)
		{
			if (temp->left != nullptr)
				SCCstart(components, stack, data, temp->left);

			if (data == -1 && !temp->visited)
			{
				temp->visited = true;
				SCC(components, stack, temp);
			}

			if (temp->right != nullptr)
				SCCstart(components, stack, data, temp->right);

			return;
		}
	}

	void SCCend(List2d& components, Stack& stack, int data, node *temp = nullptr)
	{
		if (temp == nullptr)
			temp = root;
		if (data < temp->data && temp->left != nullptr)
			SCCend(components, stack, data, temp->left);

		if (data > temp->data && temp->right != nullptr)
			SCCend(components, stack, data, temp->right);
		if (temp->data == data && temp->visited == false)
		{
			temp->visited = true;
			SCC(components, stack, temp, false);
			return;
		}
	}

	~Tree()
	{
		clear();
	}
};

class Graph
{
private:
	Tree straight;
	Tree reversed;
	Stack stack;
public:
	Graph()
	{
		string filename;
		cout << "Enter the name of file :";
		getline(cin, filename);

		ifstream File01(filename, fstream::in);
		if (File01.fail())
		{
			cout << "File could not be Found" << endl;
			return;
		}
		int x, y;
		int hashcount = 0;

		string z;
		for (int a = 0; a < 100; a++)
		{
			if (File01.eof())
				break;
			getline(File01, z);
			if (z[0] == '#')
				hashcount++;
		}
		File01.close();
		ifstream Filein(filename, fstream::in);
		for (; 0 < hashcount; hashcount--)
			getline(Filein, z);
		while (Filein >> x)
		{
			Filein >> y;
			straight.insert(x, y);
			straight.insert(y);
			reversed.insert(y, x);
			reversed.insert(x);
		}
		List2d components;
//		straight.printInorder();
//		cout << endl;
//		cout << endl;
//		cout << endl;
//		reversed.printInorder();
		straight.SCCstart(components, stack);
//		cout << endl;
//		stack.print();
//		cout << endl;
//		straight.printVisited();
		while (!stack.isEmpty())
		{
			reversed.SCCend(components, stack, stack.peek());
			stack.pop();
			components.increment();
		}
//		components.print();
		string output = "";
		components.setlargestindex(output);
		cout << endl;
		ofstream Fileout(filename + ".Output.txt", fstream::out);
		for (int a = 0; output[a]; a++)
		{
			Fileout << output[a];
		}
		Fileout.close();
//		reversed.printVisited();
		straight.clear();
		reversed.clear();
		Filein.close();
		return;
	}
	~Graph()
	{
		straight.clear();
		reversed.clear();
	}
};

#endif //GRAPH_V3_0_H
