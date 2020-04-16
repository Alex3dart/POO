#include "Vector.h"
#include "Vector.h"

#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;


template<typename Type>
Vector<Type>::Vector(size_t capacity)
	: m_capacity(capacity)
	, m_lastIndex(0)
{
	if (m_capacity <= 0)
		throw logic_error("Vector must have possitive size");

	cout << "Constructor\n";
	values = new Type[m_capacity];
	for (size_t i = 0; i < m_capacity; i++)
	{
		values[i] = 0;
	}
}


template<typename Type>
Vector<Type>::~Vector()
{
	cout << "Destructor\n";
	delete[] values;
}


template<typename Type>
Type& Vector<Type>::operator[](size_t index)
{
#ifdef CHECK_BOUNDS
	if (index < m_capacity&&index >= 0);
#endif // CHECK_BOUNDS
		return values[index];
}


template<typename Type>
void Vector<Type>::push_back(Type value)
{
	const int reservation = 2;

	if (m_lastIndex >= m_capacity) {
		cout << "reallocate values\n";

		Type* values_tmp = new Type[m_capacity + reservation];
		std::copy(values, values + m_capacity, values_tmp);

		values_tmp[m_capacity] = value;
		//for (size_t i = 0; i < reservation-1; i++) {
		//	values_tmp[m_capacity+i+1] = 0;
		//}
		memset(values_tmp + m_capacity + 1, 0, (reservation - 1) * sizeof(Type));

		m_lastIndex = m_capacity;
		m_lastIndex++;

		m_capacity += reservation;

		delete[] values;
		values = values_tmp;
	}
	else // SI TENGO EL ESPACIO DE MEMORIA
	{
		values[m_lastIndex++] = value;
		cout << "push_back\n";
	}


}


template<typename Type>
void Vector<Type>::remove_reference(Type* reference) // Referencia es el valor que quieres quitar del array
{
		if (reference == nullptr) return;
	
		Type* tmp_values = new Type[m_capacity - 1];

		// Type* ptr = std::find(values, values + m_capacity, *reference);

		for (size_t i = 0, j = 0; i < m_capacity; i++)
		{
			if (reference != &values[i])
				{
					tmp_values[j] = values[i];
					j++;
				}
		}
		
		m_capacity--;
		m_lastIndex--;
		delete[] values;
		values = tmp_values;

}

template<typename Type>
void Vector<Type>::remove_at(size_t index)
{
	remove_reference(&values[index]);

}


