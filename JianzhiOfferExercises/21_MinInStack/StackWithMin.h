#pragma once

#include <stack>
#include <assert.h>

template <typename T>
class StackWithMin
{
public:
	StackWithMin();
	~StackWithMin();

	void push(const T& element);
	void pop();

	T& top();
	const T& top() const;

	const T& min() const;

	bool empty() const;
	size_t size() const;

private:
	std::stack<T> container;
	std::stack<T> Min;
};

template <typename T> StackWithMin<T>::StackWithMin()
{
}

template <typename T> StackWithMin<T>::~StackWithMin()
{
}

template <typename T> void StackWithMin<T>::push(const T& element)
{
	container.push(element);
	if (Min.empty())
		Min.push(element);
	else
	{
		T currMin = element < Min.top() ? element : Min.top();
		Min.push(currMin);
	}
}

template <typename T> void StackWithMin<T>::pop()
{
	assert(container.size() > 0 && Min.size() > 0);

	container.pop();
	Min.pop();
}

template <typename T> T& StackWithMin<T>::top()
{
	assert(container.size() > 0 && Min.size() > 0);

	return container.top();
}

template <typename T> const T& StackWithMin<T>::top() const
{
	assert(container.size() > 0 && Min.size() > 0);

	return container.top();
}

template <typename T> const T& StackWithMin<T>::min() const
{
	assert(container.size() > 0 && Min.size() > 0);

	return Min.top();
}

template <typename T> bool StackWithMin<T>::empty() const
{
	return container.empty();
}

template <typename T> size_t StackWithMin<T>::size() const
{
	return container.size();
}