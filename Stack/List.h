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
	};


	template<typename T>
	class List
	{
	private:
		std::shared_ptr<ListNode<T>> head = nullptr;
		size_t len = 0;

		ListNode<T>* GetLastNode()
		{
			std::shared_ptr<ListNode<T>> curnode = head;
			if (head == nullptr) return nullptr;
			while (curnode->nextnode != nullptr) curnode = curnode->nextnode;
			return curnode.get();
		}
	public:
		List() = default;
		List(const T val) { head = std::shared_ptr<ListNode<T>>(new ListNode<T>); head->value = val; len = 1; }

		size_t size()const { return len; }

		bool empty()const { return len == 0; }

		void push_back(const T val)
		{
			if (len == 0) { head = std::shared_ptr<ListNode<T>>(new ListNode<T>); head->value = val; len = 1; }
			else { auto lastnode = GetLastNode(); lastnode->nextnode = std::shared_ptr<ListNode<T>>(new ListNode<T>); lastnode->nextnode->value = val; len++; }
		}

		void pop_front()
		{
			if (head == nullptr) throw std::exception("can't pop");
			head = head->nextnode;// shared_ptr ��� ������� �� �����
			len--;
		}

		T& operator[](const size_t n)const//������ ����� ���� ������� ������ � ��������, � �������� ������ ���� ����� ������, �� � ����� �� ��������
		{
			auto curnode = head;
			if (curnode == nullptr) throw std::exception("can't get head");
			for (size_t i = 0; i < n; i++)//���� ��������� �� 1 ������ ���������� �������
			{
				curnode = curnode->nextnode;
				if (curnode == nullptr) throw std::exception("can't get node");
			}
			return curnode->value;
		}
	};
}