#pragma once
#include <iostream>
using namespace std;
template <class T>
class Stack
{

private:
	T* fElements;
	int fStackPointer;
	int fStackSize;
public:
	Stack(int aSize)
	{
		
		fElements = new T[aSize]; //new Template array
		fStackPointer = 0;
		fStackSize = aSize;
	};
	~Stack()
	{
		delete[] fElements;
	};

	bool isEmpty()
	{
		return fStackPointer == 0;
	};
	int size() const
	{
		return fStackPointer;
	};
	void push(const T& aItem)
	{
		if (fStackPointer < fStackSize)
		{
			fElements[fStackPointer++] = aItem;
		}			
		else
		{
			throw overflow_error("Stack is full.");
		}
	};
	void pop()
	{
		if (!isEmpty())
		{
			fStackPointer--;
		}
		else
		{
			underflow_error("Stack is empty.");
		}
	};
	const T& top()
	{
		if (!isEmpty())
		{
			return fElements[fStackPointer - 1];
		}
		else
		{
			throw underflow_error("Stack is empty");
		}
	};

};

