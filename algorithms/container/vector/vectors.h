//-----------------------------------------------------------------------------------------------------------
#pragma once

#include <memorytracking.h>
#include "vectoradt.h"
#include "arrayvector.h"
#include "vectordoublingsize.h"
#include "vectorgrowingconstant.h"

namespace kaos {

// default vector implementation
template <
	typename TypeT,
	typename HeapT = memory::legacy_heap_singleton_t
>
class Vector : public VectorDoublingSize<TypeT, HeapT>
{
private:
	typedef VectorDoublingSize<TypeT, HeapT> base_t;

public:
	//-------------------------------------------------------------------------------------------------------
	Vector(HeapT heap)
	:	VectorDoublingSize<TypeT, HeapT>(heap)
	{
	}
	//-------------------------------------------------------------------------------------------------------
	inline Vector(
		const uint_t size = base_t::DEFAULT_SIZE,
		HeapT heap = HeapT()
	)
	:	VectorDoublingSize<TypeT, HeapT>(size, heap)
	{
	}
	//-------------------------------------------------------------------------------------------------------
	inline Vector(
		const VectorDoublingSize<TypeT, HeapT>& rhs
	)
	:	VectorDoublingSize<TypeT, HeapT>(rhs)
	{
	}
	//-------------------------------------------------------------------------------------------------------
	template <typename OtherHeapT>
	inline Vector(
		const VectorDoublingSize<TypeT, OtherHeapT>& rhs,
		HeapT heap = HeapT()
	)
	:	VectorDoublingSize<TypeT, HeapT>(rhs, heap)
	{
	}
	//-------------------------------------------------------------------------------------------------------
	inline ~Vector()
	{
	}
};

} // namespace kaos
