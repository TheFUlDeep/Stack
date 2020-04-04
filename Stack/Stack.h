#pragma once
#include <iostream>
#include <deque>

//типа использую паттерн адаптер (нет)

namespace TheFulDeep {

	template<typename T>
	class Stack
	{
	private:
		std::deque<T> deque;
	public:
		Stack() = default;
		Stack(T val) { deque = std::deque<T>(val); }

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
		size_t iter = 0;
		for (auto i = stack.deque.begin(); i < stack.deque.end(); ++i) { out << stack.deque[iter] << "\n"; iter++; }
		return out;
	}
}