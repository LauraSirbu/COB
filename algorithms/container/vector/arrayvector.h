#pragma once

#include <memorytracking.h>
#include "defaultvectorimplementation.h"

namespace kaos {

//-----------------------------------------------------------------------------------------------------------
template <
	typename ObjectT,
	typename HeapT = memory::legacy_heap_singleton_t
>
class ArrayVector
{
public:
	static const uint_t DEFAULT_SIZE = 32;
	
public:
	//-------------------------------------------------------------------------------------------------------
	inline ArrayVector(
		const uint_t size = DEFAULT_SIZE,
		HeapT heap = HeapT()
	)
	:	impl_(size, heap)
	{
	}
	//-------------------------------------------------------------------------------------------------------
	inline ArrayVector(
		const ArrayVector<ObjectT>& rhs
	)
	:	impl_(rhs.impl_)
	{
	}
	//-------------------------------------------------------------------------------------------------------
	inline ~ArrayVector()
	{
	}
	
	//-------------------------------------------------------------------------------------------------------
	inline void Add(
		const ObjectT& object
	)
	{
		impl_.Add(impl_.GetSize(), object);
	}
	//-------------------------------------------------------------------------------------------------------
	inline void Add(
		const uint_t index,
		const ObjectT& object
	)
	{
		impl_.Add(index, object);
	}
	//-------------------------------------------------------------------------------------------------------
	inline void AddVector(
		const ArrayVector<ObjectT>& vector
	)
	{
		for (uint_t i = 0; i < vector.GetSize(); ++i)
		{
			impl_.Add(impl_.GetSize(), vector[i]);
		}
	}
	//-------------------------------------------------------------------------------------------------------
	inline void Replace(
		const uint_t index,
		const ObjectT& object
	)
	{
		impl_.Replace(index, object);
	}
	//-------------------------------------------------------------------------------------------------------
	inline void Remove(
		const uint_t index
	)
	{
		impl_.Remove(index);
	}
	//-------------------------------------------------------------------------------------------------------
	inline void RemoveObject(
		const ObjectT& object
	)
	{
		uint_t index = impl_.Find(object);
		if (index < impl_.GetSize())
		{
			impl_.Remove(index);
		}
	}
	//-------------------------------------------------------------------------------------------------------
	inline void FastRemove(
		const uint_t index
	)
	{
		impl_.FastRemove(index);
	}
	//-------------------------------------------------------------------------------------------------------
	inline void FastRemoveObject(
		const ObjectT& object
	)
	{
		uint_t index = impl_.Find(object);
		if (index < impl_.GetSize())
		{
			impl_.FastRemove(index);
		}
	}
	//-------------------------------------------------------------------------------------------------------
	inline void RemoveBack()
	{
		impl_.Remove(GetSize()-1);
	}
	//-------------------------------------------------------------------------------------------------------
	inline void Clear()
	{
		impl_.Clear();
	}
	//-------------------------------------------------------------------------------------------------------
	inline ObjectT& GetFront()
	{
		return impl_.GetAt(0);
	}
	//-------------------------------------------------------------------------------------------------------
	inline const ObjectT& GetFront() const
	{
		return impl_.GetAt(0);
	}
	//-------------------------------------------------------------------------------------------------------
	inline ObjectT& GetBack()
	{
		return impl_.GetAt(GetSize()-1);
	}
	//-------------------------------------------------------------------------------------------------------
	inline const ObjectT& GetBack() const
	{
		return impl_.GetAt(GetSize()-1);
	}
	//-------------------------------------------------------------------------------------------------------
	inline ObjectT& GetAt(
		const uint_t index
	)
	{
		return impl_.GetAt(index);
	}
	//-------------------------------------------------------------------------------------------------------
	inline const ObjectT& GetAt(
		const uint_t index
	) const
	{
		return impl_.GetAt(index);
	}
	//-------------------------------------------------------------------------------------------------------
	inline const uint_t Find(
		const ObjectT& object
	) const
	{
		return impl_.Find(object);
	}
	//-------------------------------------------------------------------------------------------------------
	inline const uint_t GetSize() const
	{
		return impl_.GetSize();
	}
	//-------------------------------------------------------------------------------------------------------
	inline const bool_t IsEmpty() const
	{
		return impl_.IsEmpty();
	}
	//-------------------------------------------------------------------------------------------------------
	const ArrayVector<ObjectT>& operator = (
		const ArrayVector<ObjectT>& vector
	)
	{
		impl_.Clear();
		for (uint_t i = 0; i < vector.GetSize(); ++i)
		{
			// note this add goes to 'this'. so there is the possibility to grow
			// (at least theoretically inside a growable vector-implementation)
			Add(vector[i]);
		}
		return (*this);
	}
	//-------------------------------------------------------------------------------------------------------
	inline ObjectT& operator [] (
		const uint_t index
	)
	{
		return impl_.GetAt(index);
	}
	//-------------------------------------------------------------------------------------------------------
	inline const ObjectT& operator [] (
		const uint_t index
	) const
	{
		return impl_.GetAt(index);
	}
	//-------------------------------------------------------------------------------------------------------
	const bool_t operator == (
		const ArrayVector<ObjectT>& vector
	) const
	{
		return impl_.Equals(vector);
	}
	//-------------------------------------------------------------------------------------------------------
	const bool_t operator != (
		const ArrayVector<ObjectT>& vector
	) const
	{
		return !impl_.Equals(vector);
	}

private:
	DefaultVectorImplementation<ObjectT, HeapT> impl_;
};

} // namespace kaos
