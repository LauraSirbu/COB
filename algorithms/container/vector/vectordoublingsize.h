#pragma once

#include <memorytracking.h>
#include "defaultvectorimplementation.h"

namespace kaos {

//-----------------------------------------------------------------------------------------------------------
template <
	typename ObjectT,
	typename HeapT = memory::legacy_heap_singleton_t
>
class VectorDoublingSize
{
public:
	static const uint_t DEFAULT_SIZE = 32;
	
public:
	//-------------------------------------------------------------------------------------------------------
	inline VectorDoublingSize(
		HeapT heap
	)
	:	impl_(DEFAULT_SIZE, heap)
	{
	}
	//-------------------------------------------------------------------------------------------------------
	inline VectorDoublingSize(
		const uint_t size = DEFAULT_SIZE,
		HeapT heap = HeapT()
	)
	:	impl_(size, heap)
	{
	}
	//-------------------------------------------------------------------------------------------------------
	inline VectorDoublingSize(
		const VectorDoublingSize<ObjectT, HeapT>& rhs
	)
	:	impl_(rhs.impl_)
	{
	}
	//-------------------------------------------------------------------------------------------------------
	template <typename OtherHeapT>
	inline VectorDoublingSize(
		const VectorDoublingSize<ObjectT, OtherHeapT>& rhs,
		HeapT heap
	)
	:	impl_(rhs.GetImpl(), heap)
	{
	}
	//-------------------------------------------------------------------------------------------------------
	inline ~VectorDoublingSize()
	{
	}
	//-------------------------------------------------------------------------------------------------------
	inline void ReserveSpace(
		const uint_t num_elements
		)
	{
		while (GetSize() + num_elements >= impl_.AllocatedSize())
		{
			impl_.Grow(2 * impl_.AllocatedSize());
		}
		impl_.ReserveSpace(num_elements);
	}
	//-------------------------------------------------------------------------------------------------------
	inline void Add(
		const ObjectT& object
	)
	{
		// calls 'this' to allow growth
		Add(impl_.GetSize(), object);
	}
	//-------------------------------------------------------------------------------------------------------
	inline void Add(
		const uint_t index,
		const ObjectT& object
	)
	{
		if (GetSize() + 1 > impl_.AllocatedSize())
		{
			impl_.Grow(2 * impl_.AllocatedSize());
		}
		impl_.Add(index, object);
	}
	//-------------------------------------------------------------------------------------------------------
	inline void AddVector(
		const VectorDoublingSize<ObjectT>& vector
	)
	{
		uint_t max_index = impl_.Size() + vector.Size();
		if (max_index >= impl_.AllocatedSize())
		{
			uint_t new_size = 2 * impl_.AllocatedSize();
			while (max_index >= new_size)
			{
				new_size *= 2;
			}
			impl_.Grow(new_size);
		}
		for (uint_t i = 0; i < vector.Size(); ++i)
		{
			impl_.Add(impl_.Size(), vector[i]);
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
	inline const uint_t GetAllocatedSize() const
	{
		return impl_.GetAllocatedSize();
	}
	//-------------------------------------------------------------------------------------------------------
	inline const bool_t IsEmpty() const
	{
		return impl_.IsEmpty();
	}
	//-------------------------------------------------------------------------------------------------------
	const VectorDoublingSize<ObjectT>& operator = (
		const VectorDoublingSize<ObjectT>& vector
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
	inline ObjectT& operator [] (
		const ulong_t index
	)
	{
		return impl_.GetAt(index);
	}
	//-------------------------------------------------------------------------------------------------------
	inline const ObjectT& operator [] (
		const ulong_t index
	) const
	{
		return impl_.GetAt(index);
	}
	//-------------------------------------------------------------------------------------------------------
	inline ObjectT& operator [] (
		const int_t index
	)
	{
		return impl_.GetAt(index);
	}
	//-------------------------------------------------------------------------------------------------------
	inline const ObjectT& operator [] (
		const int_t index
	) const
	{
		return impl_.GetAt(index);
	}
	//-------------------------------------------------------------------------------------------------------
	inline ObjectT& operator [] (
		const long_t index
	)
	{
		return impl_.GetAt(index);
	}
	//-------------------------------------------------------------------------------------------------------
	inline const ObjectT& operator [] (
		const long_t index
	) const
	{
		return impl_.GetAt(index);
	}
	//-------------------------------------------------------------------------------------------------------
	const bool_t operator == (
		const VectorDoublingSize<ObjectT>& vector
	) const
	{
		return impl_.Equals(vector);
	}
	//-------------------------------------------------------------------------------------------------------
	const bool_t operator != (
		const VectorDoublingSize<ObjectT>& vector
	) const
	{
		return !impl_.Equals(vector);
	}
	//-------------------------------------------------------------------------------------------------------
	const DefaultVectorImplementation<ObjectT, HeapT>& GetImpl() const
	{
		return impl_;
	}

private:
	DefaultVectorImplementation<ObjectT, HeapT> impl_;
};

} // namespace kaos
