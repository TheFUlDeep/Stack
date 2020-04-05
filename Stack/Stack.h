#pragma once
#include <iostream>
#include "List.h"

//типа использую паттерн адаптер (нет)

namespace TheFulDeep {

	template<typename T>
	class Stack
	{
	private:
		List<T> deque;
	public:
		Stack() = default;
		Stack(T val) { deque = List<T>(val); }

		void push(const T val) { deque.push_back(val); }
		void pop(const size_t n = 1) { size_t ncopy = n; if (ncopy > deque.size()) ncopy = deque.size(); for (size_t i = 0; i < ncopy; i++) deque.pop_front(); }
		bool isEmpty()const { return deque.empty(); }
		size_t getSize()const { return deque.size(); }
		void clean() { deque.clear(); }

		template<typename U>
		friend std::ostream& operator<<(std::ostream&, const Stack<U>&);
	};


	template<typename U>
	std::ostream & operator<<(std::ostream &out, const Stack<U> &stack)
	{
		for (size_t i = 0; i < stack.deque.size(); i++) out << stack.deque[i] << "\n";
		return out;
	}
}