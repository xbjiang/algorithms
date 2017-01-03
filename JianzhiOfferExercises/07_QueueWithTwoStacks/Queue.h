#pragma once 
#include <stack>

template <typename T> class CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	void appendTail(const T& node);

	T deleteHead(void);
private:
	std::stack<T> stack1;
	std::stack<T> stack2;
};

template <typename T> CQueue<T>::CQueue()
{
}

template <typename T> CQueue<T>::~CQueue()
{
}

template <typename T> void CQueue<T>::appendTail(const T& node)
{
	stack1.push(node);
}

template <typename T> T CQueue<T>::deleteHead(void)
{
	if (stack2.empty())
	{
		while (!stack1.empty())
		{
			T& node = stack1.top();
			stack1.pop();
			stack2.push(node);
		}
	}

	if (stack2.empty())
	{
		printf("Queue is empty!");
		exit(1);
	}

	T head = stack2.top();
	stack2.pop();
	return head;
}