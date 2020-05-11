#pragma once
#include <iostream>
#include <stdint.h>
#include <stdbool.h>
using namespace std;

template<class T>
class Vector
{
public:
	/// Default C-tor
	Vector();

	/// Create a vector of capacity n.
	Vector<T>(const T&);

	/// C-tor with initializer list
	Vector(std::initializer_list<T> list);

	/// Copy C-tor. Change address.
	Vector(const Vector<T>& obj);

	/// Move constructor. Don't change address. Use rvalue.
	Vector(Vector<T>&& rhs);

	/// Destructor
	~Vector();

	/// Returns the current size of the vector. Count of elements stored inside it.
	T GetSize() const;

	/// Capacity of vector
	T Capacity() const;

	/// Returns true if vector is empty.
	T IsEmpty() const;

	/// Returns a reference to the object at the front of the vector.
	T& GetFront();

	/// Returns a reference to the object at the front of the vector.
	const T& GetFront() const;

	/// Returns a reference to the back of the vector.
	T& GetBack();

	/// Print vector elements.
	void Print();

	/// Add the given object at the back of the vector.
	void Add(T& data);

	/// Insert the given object at the specified index into the vector. This method has O(n) runtime.
	void AddAtIndex(T index, T& data);

	/// Add the contents of the parameter vector to the back of this vector.
	void Add(const Vector<T>& vector);

	/// Replace the object at the specified index with the new object.
	void Replace(const T index, const T& object);

	/// Remove the object at the specified index. This methode has O(n) runtime.
	void Remove(const T index);

	/// Remove the object at the specified index. It is replace by the element at the back of the
	/// vector. Thus this methode implements O(1) runtime.
	void FastRemove(const T index);

	/// Remove the object at the back of the vector.
	void RemoveBack();

	/// If the vector is not large, double current capacity.
	void AllocNewSize();

	/// Return size of the internally allocated array
	T GetAllocatedSize();

	/// Clear the vector.
	void Clear();

	/// Overload ----------------------------------------------------------------------------------------

	/// copies the given vector into this one.
	Vector<T>& operator=(const Vector<T>& rhs);

	/// Move assignment operator. moves the object referenced into this object(rvalue into left side)
	Vector<T>& operator=(Vector<T>&& rhs);

	/// returns a reference to the object at the specified index.
	T& operator[](T index);

	/// returns a reference to the object at the specified index.
	const T& operator[](const T index) const;

	/// compares the contents of this vector with the contents of the other one. Returns true
	/// if they are equal and false otherwise.
	const bool operator==(const Vector<T>& rhs) const;

	/// Compares the contents of this vector with the contents of the other one. Returns true
	/// if they are equal and false otherwise.
	const bool operator!=(const Vector<T>& rhs) const;

private:
	// Vector size
	T size;
	// Store address of vector
	T* arr;
};

/// Default Constructor
template<class T>
Vector<T>::Vector()
{
	//arr = new T;
	//size = 0;
}

/// Parameterized Constructor
template<class T>
Vector<T>::Vector(const T& rhs)
{
	//size = rhs;
	arr = new T;
}

/// C-tor with initializer list
template<class T>
Vector<T>::Vector(std::initializer_list<T> list)
	:arr{ new T[list.size()] }
{
	size = list.size();
	std::copy(list.begin(), list.end(), arr);
}

/// Copy Constructor - initialize an object base on another object from the same class.
template<class T>
Vector<T>::Vector(const Vector<T>& obj)
{
	size = obj.size;
	delete[] arr;
	arr = new T[size];
	for (int i = 0; i < obj.size; i++)
	{
		arr[i] = obj.arr[i];
	}
}

/// Move constructor - move rValue into lValue without copy
template<class T>
Vector<T>::Vector(Vector<T>&& rhs)
{
	// Copy
	size = rhs.size;
	arr = rhs.arr;

	// Release the data pointer from the source object
	rhs.arr = nullptr;
	rhs.size = 0;
}

/// Destructor
template<class T>
Vector<T>::~Vector()
{
	delete[] arr;
	arr = nullptr;
}

/// Check if vector is empty
template<class T>
T Vector<T>::IsEmpty() const
{
	return size == 0;
}

/// Return vector size.
template<class T>
T Vector<T>::GetSize() const
{
	return size;
}

/// Return current size present in vector.
template<class T>
T Vector<T>::Capacity() const
{
	return size;
}

/// Returns a reference to the object at the front of the vector.
template<class T>
T& Vector<T>::GetFront()
{
	return arr[0];
}

/// Returns a reference to the object at the front of the vector.
template<class T>
const T& Vector<T>::GetFront() const
{
	return arr[0];
}

/// Returns a reference to the back of the vector.
template<class T>
T& Vector<T>::GetBack()
{
	return arr[size - 1];
}

/// Add the given object at the back of the vector.
template<class T>
void Vector<T>::Add(T& data)
{
	// Allocate new memory space if the size of the vector is greater than the capacity of the vector
	if (size + 1 > data)
	{
		AllocNewSize();
	}
	arr[size] = data;
	size++;
}

/// Insert the given object at the specified index into the vector. This method has O(n) runtime.
template<class T>
void Vector<T>::AddAtIndex(T index, T& data)
{
	if (arr[index] != NULL)
	{
		arr[index] = data;
	}
	else
	{
		Add(data);
	}
}

/// Add the contents of the parameter vector to the back of this vector.
template<class T>
void Vector<T>::Add(const Vector<T>& vector)
{
	// Allocate new memory space if the size of the vector is greater than the capacity of the vector
	if (size + 1 > vector.size)
	{
		AllocNewSize();
	}

	int count{ 0 };
	T sz = vector.size;
	for (T i = 0; i < sz; i++)
	{
		arr[count] = vector.arr[i];
		count++;
	}
	size = count;
}

/// Replace the object at the specified index with the new object.
template<class T>
void Vector<T>::Replace(const T index, const T& object)
{
	if (index > size)
	{
		return;
	}

	arr[index] = object;
}

/// Remove the object at the specified index. This methode has O(n) runtime.
template<class T>
void Vector<T>::Remove(const T index)
{
	if (index > size)
		return;

	for (int i = 0; i < size; i++)
	{
		if (i == index)
		{
			arr[i] = arr[i + 1];
			size--;
		}
	}
}

/// Remove the object at the specified index. It is replace by the element at the back of the
/// vector. Thus this methode implements O(1) runtime.
template<class T>
void Vector<T>::FastRemove(const T index)
{
	if (index > size)
		return;

	arr[index] = arr[size];
	size--;
}

/// Remove the object at the back of the vector.
template<class T>
void Vector<T>::RemoveBack()
{
	if (size != NULL)
	{
		arr[size] = NULL;
		size--;
	}
}

/// If the vector is not large, double current capacity.
template<class T>
void Vector<T>::AllocNewSize()
{
	// Increase vector capacity by doubling the size of the vector by 2
	size = size * 2;

	// Declare new array
	T* temp = new T[size];

	// Copy data from old array into new array
	for (T i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	// delete old array and have new array take the place of old array
	delete[] arr;
	arr = temp;

}

/// Return size of the internally allocated array
template<class T>
T Vector<T>::GetAllocatedSize()
{
	return size;
}

/// Print vector elements.
template<class T>
void Vector<T>::Print()
{
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

/// Clear Function
template<class T>
void Vector<T>::Clear()
{
	delete[]arr;
}

/// Returns a reference to the object at the specified index.
template<class T>
T& Vector<T>::operator[](T index)
{
	if (index >= size) {
		cout << "Array index out of bound, exiting";
		exit(0);
	}
	return arr[index];
}

/// Returns a reference to the object at the specified index.
template<class T>
const T& Vector<T>::operator[](const T index) const
{
	if (index >= size) {
		cout << "Array index out of bound, exiting";
		exit(0);
	}
	return &arr[index];
}

/// copies the given vector into this one.
template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs)
{
	if (this != &rhs)
	{
		size = rhs.size;
		delete[] arr;
		arr = new T[size];
		for (int i = 0; i < rhs.size; i++)
		{
			arr[i] = rhs.arr[i];
		}
	}
	return *this;
}

/// Move assignment operator. moves the object referenced into this object(rvalue into left side)
template<class T>
Vector<T>& Vector<T>::operator=(Vector<T>&& rhs)
{
	if (this != &rhs)
	{
		delete[] arr;

		arr = rhs.arr;
		size = rhs.size;

		rhs.arr = nullptr;
		rhs.size = 0;
	}
	return *this;
}

/// compares the contents of this vector with the contents of the other one. Returns true
/// if they are equal and false otherwise.
template<class T>
const bool Vector<T>::operator==(const Vector<T>& rhs) const
{
	if (size == rhs.size && *arr == *rhs.arr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/// Compares the contents of this vector with the contents of the other one. Returns true
/// if they are equal and false otherwise.
template<class T>
const bool Vector<T>::operator!=(const Vector<T>& rhs) const
{
	if (size != rhs.size && *arr != *rhs.arr)
	{
		return false;
	}
	else
	{
		return true;
	}
}