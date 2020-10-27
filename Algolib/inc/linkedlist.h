#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "framework.h"
template <typename T>
struct LLNode
{
	T info;
	LLNode<T> *link = nullptr;
};

template <typename T>
class LLinkedList
{
public:
	void applyall(std::function<void(T)> func)
	{
		LLNode<T> *PTR = START;
		while (PTR != nullptr)
		{
			func(PTR->info);
			PTR = PTR->link;
		}
	}

	void PrintConsole(std::ostream& out)
	{
		LLNode<T>* PTR = START;
		while (PTR != nullptr)
		{
			out << PTR->info;
			PTR = PTR->link;
		}
	}

	void append(T item)
	{
		LLNode<T> *NEW_NODE = new LLNode<T>;
		NEW_NODE->info = item;
		NEW_NODE->link = nullptr; // Already
		if (START == nullptr)
		{
			START = NEW_NODE;
		}
		else
		{
			LLNode<T> *LAST = START;
			while (LAST->link != nullptr)
			{
				LAST = LAST->link;
			}
			LAST->link = NEW_NODE;
		}
	}

	void insloc(LLNode<T> *loc, T item) noexcept(false)
	{
		LLNode<T> *NEW_NODE = new LLNode<T>;
		INFO(NEW_NODE) = item;

		if (loc == nullptr)
		{
			NEW_NODE->link = START;
			START = NEW_NODE;
		}
		else
		{
			NEW_NODE->link = loc->link;
			loc->link = NEW_NODE;
		}
	}

private:
	LLNode<T> *START = nullptr;
};

#endif