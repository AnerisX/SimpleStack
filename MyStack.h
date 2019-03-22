#ifndef MYSTACK_H
#define MYSTACK_H

template <class T>
class MyStack
{
	struct Node
	{
		T data;
		Node *prev;
	};
	Node *top{ nullptr };
	size_t size = 0;
public:

	MyStack(){}
	MyStack(const MyStack& s)
	{
		MyStack tempS;
		Node* temp = s.top;
		while(temp != nullptr)
		{
			tempS.Push(temp->data);
			temp = temp->prev;
		}

		temp = tempS.top;
		while (temp != nullptr)
		{
			Push(temp->data);
			temp = temp->prev;
		}
	}
	~MyStack()
	{
		while (top != nullptr)
			Pop();
	}

	void operator= (const MyStack& s)
	{
		MyStack temp(s);
		std::swap(top, temp.top);
	}
	void Push(T input)
	{
		Node *temp = new Node;
		temp->data = input;
		temp->prev = top;
		top = temp;

		size++;
	}
	void Pop()
	{
		if (top == nullptr) { return; }

		Node *temp = new Node;
		temp = top;
		top = top->prev;
		
		delete temp;
		size--;
	}
	T Top()
	{
		if (top != nullptr)
			return top->data;
		else
			std::cout << "Error: No elements in stack." << std::endl;
	}
	size_t Size()
	{
		return size;
	}
	bool Empty()
	{
		if (top == nullptr)
			return true;
		else
			return false;
	}
};

#endif
