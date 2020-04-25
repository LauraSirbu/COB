#pragma once

#include <memorytracking.h>

namespace kaos {

//-----------------------------------------------------------------------------------------------------------
/*!
	\brief Vector-ADT

	Vector Abstract Data Type. This template represents an abstract data type without
	a concrete implementation. Implementations are done within the specialized template
	classes which are implementing some special grow-algorithms.
*/
template <
	typename ObjectT
>
class VectorADT
{
public:
	/// default constructor.
	VectorADT();
	/// copy constructor.
	VectorADT(const VectorADT<ObjectT>& rhs);
	/// destructor
	~VectorADT();

	/// Add the given object at the back of the vector.
	void Add(const ObjectT& object);
	/// Insert the given object at the specified index into the vector. This method has O(n) runtime.
	void Add(const uint_t index, const ObjectT& object);
	/// Add the contents of the parameter vector to the back of this vector.
	void AddVector(const VectorADT<ObjectT>& vector);
	/// Replace the object at the specified index with the new object.
	void Replace(const uint_t index, const ObjectT& object);
	/// Remove the object at the specified index. This methode has O(n) runtime.
	void Remove(const uint_t index);
	/// Remove the object from the vector. This method searches the object and removes it afterwards. It has O(n) runtime.
	void RemoveObject(const ObjectT& object);
	/// Remove the object at the specified index. It is replace by the element at the back of the
	/// vector. Thus this methode implements O(1) runtime.
	void FastRemove(const uint_t index);
	/// Remove the object from the vector. This may be little faster than the normal Remove(ObjectT&) but still it
	/// needs to search the object.
	void FastRemoveObject(const ObjectT& object);
	/// Remove the object at the back of the vector.
	void RemoveBack();
	/// Clear the vector.
	void Clear();

	/// Returns a reference to the object at the front of the vector.
	ObjectT& GetFront();
	/// Returns a reference to the object at the front of the vector.
	const ObjectT& GetFront() const;
	/// Returns a reference to the back of the vector.
	ObjectT& GetBack();
	/// Returns a reference to the back of the vector.
	const ObjectT& GetBack() const;
	/// Returns a reference to the object at the specified index.
	ObjectT& GetAt(const uint_t index);
	/// Returns a reference to the object at the specified index.
	const ObjectT& GetAt(const uint_t index) const;
	/// Searches the object and returns the index to the object. If the object can't be found
	/// this methode returns the value of Size() and with this an invalid index.
	const uint_t Find(const ObjectT& object) const;
	/// Returns the current size of the vector. Count of elements stored inside it.
	const uint_t GetSize() const;
	/// Returns a flag indicating if this vector is empty.
	const bool_t IsEmpty() const;

	/// copies the given vector into this one.
	const VectorADT<ObjectT>& operator = (const VectorADT<ObjectT>& rhs);
	/// returns a reference to the object at the specified index.
	ObjectT& operator [] (const uint_t index);
	/// returns a reference to the object at the specified index.
	const ObjectT& operator [] (const uint_t index) const;
	/// compares the contents of this vector with the contents of the other one. Returns true
	/// if they are equal and false otherwise.
	const bool_t operator == (const VectorADT<ObjectT>& rhs) const;
	/// compares the contents of this vector with the contents of the other one. Returns true
	/// if they are equal and false otherwise.
	const bool_t operator != (const VectorADT<ObjectT>& rhs) const;
};

} // namespace kaos
