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
	LLinkedList(bool sorted = false, std::ostream *plog = nullptr)
	{
		this->is_sorted = sorted;
		this->log = plog;
	}
	const size_t Count() const
	{
		int cont{0};
		auto fnc = [&](T) { ++cont; };
		ApplyAll(fnc);
		return cont;
	}

	void ApplyAll(std::function<void(T)> func) const
	{
		LLNode<T> *PTR = START;
		while (PTR != nullptr)
		{
			func(PTR->info);
			PTR = PTR->link;
		}
	}

	void Append(T item)
	{
		if (this->is_sorted)
		{
			InsertAndSort(item);
		}
		else
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
	}

	void DeleteFirst(T item)
	{
		LLNode<T> *preNode, *theNode;
		FindFirstOccurence(item, preNode, theNode);
		if (theNode == nullptr)
		{
			if (this->log != nullptr)
				*(this->log) << "Item not in list" << '\n';
			return;
		}
		RemoveAfter(preNode, theNode);
	}

private:
	void FindFirstOccurence(T item, LLNode<T> *&preceedingNode, LLNode<T> *&theNode) const
	{
		if (START == nullptr)
		{
			preceedingNode = theNode = nullptr;
			return;
		}

		if (START->info == item)
		{
			preceedingNode = nullptr;
			theNode = START;
			return;
		}

		LLNode<T> *PrevNode = START;
		LLNode<T> *PTR = START->link;
		while (PTR != nullptr)
		{
			if (PTR->info == item)
			{
				theNode = PTR;
				preceedingNode = PrevNode;
				return;
			}
			PrevNode = PTR;
			PTR = PTR->link;
		}

		theNode = nullptr;
		return;
	}

	void RemoveAfter(LLNode<T> *preceedingNode, LLNode<T> *theNode) noexcept(false)
	{
		if (this->START == nullptr)
		{
			if (this->log != nullptr)
				*(this->log) << "UNDERFLOW" << '\n';
			return;
		}

		if (preceedingNode == nullptr)
			START = START->link;
		else
			preceedingNode->link = theNode->link;

		delete theNode;
	}

	void InsertBefore(LLNode<T> *loc, T item) noexcept(false)
	{
		LLNode<T> *NEW_NODE = new LLNode<T>;
		NEW_NODE->info = item;

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

	void InsertAndSort(T item)
	{
		LLNode<T> *location;
		FindLocation(item, location);
		InsertBefore(location, item);
	}

	void FindLocation(const int &item, LLNode<T> *&LOC) const
	{
		if (START == nullptr || item < START->info)
		{
			LOC = nullptr;
			return;
		}
		LLNode<T> *PREV = START;
		LLNode<T> *PTR = START->link;
		while (PTR != nullptr)
		{
			if (item < PTR->info)
				break;

			PREV = PTR;
			PTR = PTR->link;
		}
		LOC = PREV;
	}

private:
	LLNode<T> *START = nullptr;
	/* mutable */ std::ostream *log = nullptr;
	bool is_sorted{false};
};

#endif