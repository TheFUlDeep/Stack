#pragma once
#include <memory>

namespace TheFulDeep
{
	template<typename T>
	class List;

	template<typename T>
	class ListNode
	{
		friend class List<T>;
	private:
		T value;
		std::shared_ptr<ListNode<T>> nextnode = nullptr;
	public:
		ListNode() = default;
		ListNode<T>* GetNextNode()const { return nextnode.get(); }
		T GetValue()const { return value; }
	};


	template<typename T>
	class List
	{
	private:
		std::shared_ptr<ListNode<T>> head = nullptr;
		ListNode<T>* end = nullptr;
		size_t len = 0;

	public:
		List() = default;
		List(const T val) { head = std::shared_ptr<ListNode<T>>(new ListNode<T>); head->value = val; end = head.get(); len = 1; }

		size_t size()const { return len; }

		bool empty()const { return len == 0; }

		void push_back(const T val)
		{
			if (len == 0) { *this = List<T>(val); }
			else { end->nextnode = std::shared_ptr<ListNode<T>>(new ListNode<T>); end->nextnode->value = val; end = end->nextnode.get(); len++; }
		}

		T pop_front()
		{
			if (head == nullptr) throw std::exception("can't pop");
			T val = head->value;
			head = head->nextnode;// shared_ptr сам очистит за собой
			len--;
			return val;
		}

		T& operator[](const size_t n)const//вообще можно было создать массив с адресами, и получать нужный ноуд через массив, но я решил не париться
		{
			auto curnode = head;
			if (curnode == nullptr) throw std::exception("can't get head");
			for (size_t i = 0; i < n; i++)//буду проходить на 1 меньше указанного индекса
			{
				curnode = curnode->nextnode;
				if (curnode == nullptr) throw std::exception("can't get node");
			}
			return curnode->value;
		}


		ListNode<T>* GetHead()const { return head.get(); }
	};
}