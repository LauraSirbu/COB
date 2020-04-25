#pragma once

#include <memorytracking.h>
#include "defaultvectorimplementation.h"

namespace kaos {

//-----------------------------------------------------------------------------------------------------------
/*!
	\brief Constant growing vector implementation
	\version 0.1
	\date 23.08.2008, Christian Oberholzer, implemented

	This class implements a constant growing instance of the VectorADT.
*/
template <
	typename ObjectT,
	typename HeapT = memory::legacy_heap_singleton_t
>
class VectorGrowingConstant
{
public:
	static const uint_t DEFAULT_SIZE = 32;
	static const uint_t DEFAULT_GROWTH = 16;
	
public:
	//-------------------------------------------------------------------------------------------------------
	inline VectorGrowingConstant(
		const uint_t size = DEFAULT_SIZE,
		const uint_t growth = DEFAULT_GROWTH,
		HeapT heap = HeapT()
	)
	:	impl_(size, heap),
		growth_(growth)
	{
	}
	//-------------------------------------------------------------------------------------------------------
	inline VectorGrowingConstant(
		const VectorGrowingConstant<ObjectT>& rhs
	)
	:	impl_(rhs.impl_),
		growth_(rhs.growth_)
	{
	}
	//-------------------------------------------------------------------------------------------------------
	inline ~VectorGrowingConstant()
	{
	}
	
	//-------------------------------------------------------------------------------------------------------
	inline void ReserveSpace(
		const uint_t num_elements
		)
	{
		while (GetSize() + num_elements >= impl_.AllocatedSize())
		{
			impl_.Grow(impl_.AllocatedSize() + growth_);
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
		if (GetSize() + 1 >= impl_.AllocatedSize())
		{
			impl_.Grow(impl_.AllocatedSize() + growth_);
		}
		impl_.Add(index, object);
	}
	//-------------------------------------------------------------------------------------------------------
	inline void AddVector(
		const VectorGrowingConstant<ObjectT>& vector
	)
	{
		uint_t max_index = impl_.Size() + vector.Size();
		if (max_index >= impl_.AllocatedSize())
		{
			uint_t new_size = impl_.AllocatedSize() + growth_;
			while (max_index >= new_size)
			{
				new_size += growth_;
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
		if (index < impl_.Size())
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
		if (index < impl_.Size())
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
		return impl_.At(0);
	}
	//-------------------------------------------------------------------------------------------------------
	inline const ObjectT& GetFront() const
	{
		return impl_.At(0);
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
	const VectorGrowingConstant<ObjectT>& operator = (
		const VectorGrowingConstant<ObjectT>& vector
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
		const VectorGrowingConstant<ObjectT>& vector
	) const
	{
		return impl_.Equals(vector);
	}
	//-------------------------------------------------------------------------------------------------------
	const bool_t operator != (
		const VectorGrowingConstant<ObjectT>& vector
	) const
	{
		return !impl_.Equals(vector);
	}

private:
	DefaultVectorImplementation<ObjectT, HeapT> impl_;
	uint_t growth_;
};

} // namespace kaos
