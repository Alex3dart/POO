#pragma once

template<typename Type>
class Vector {

public:
	Vector(size_t capacity);
	~Vector();

	Type& operator[](size_t index);

	void push_back(Type value);

	void remove_reference(Type* reference);
	void remove_at(size_t index);

private:
	Type* values;

	size_t m_capacity;
	size_t m_lastIndex;

};
#include "Vector.inl"