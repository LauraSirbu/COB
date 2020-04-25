#pragma once

#include <memorytracking.h>

namespace kaos {

//-----------------------------------------------------------------------------------------------------------
template <
	typename ObjectT,
	typename HeapT
>
class DefaultVectorImplementation
{
public:
	//-------------------------------------------------------------------------------------------------------
	inline DefaultVectorImplementation(
		const uint_t size,
		HeapT heap
	)
	:	size_(size),
		element_count_(0),
		array_(NULL),
		heap_(heap)
	{
		kaos_assert(size_ > 0, "size must be > 0");
		array_ = CreateArray(size_);
	}
	//-------------------------------------------------------------------------------------------------------
	inline DefaultVectorImplementation(
		const DefaultVectorImplementation<ObjectT, HeapT>& rhs
	)
	:	size_(rhs.size_),
		element_count_(rhs.element_count_),
		array_(NULL),
		heap_(rhs.heap_)
	{
		kaos_assert(rhs.size_ > 0, "size must be > 0");
		array_ = CreateArray(size_);
		for (uint_t i = 0; i < element_count_; ++i)
			{ KAOS_INPLACE_NEW(ObjectT, &array_[i])(rhs.array_[i]); }
	}
	//-------------------------------------------------------------------------------------------------------
	template <typename OtherHeapT>
	inline DefaultVectorImplementation(
		const DefaultVectorImplementation<ObjectT, OtherHeapT>& rhs,
		HeapT heap
	)
	:	size_(rhs.GetAllocatedSize()),
		element_count_(rhs.GetSize()),
		array_(NULL),
		heap_(heap)
	{
		kaos_assert(size_ > 0, "size must be > 0");
		array_ = CreateArray(size_);
		for (uint_t i = 0; i < element_count_; ++i)
			{ KAOS_INPLACE_NEW(ObjectT, &array_[i])(rhs.GetAt(i)); }
	}
	//-------------------------------------------------------------------------------------------------------
	inline ~DefaultVectorImplementation()
	{
		Clear();
		DeleteArray(array_);
	}
	//-------------------------------------------------------------------------------------------------------
	inline void ReserveSpace(
		const uint_t num_elements
	)
	{
		kaos_assert(size_ > 0, "size must be > 0");
		kaos_assert(GetSize() + num_elements < size_, "there must be enough room inside the vector for the number of elements");

		for (kaos::uint_t i = element_count_; i < element_count_ + num_elements; ++i)
			{ KAOS_INPLACE_NEW(ObjectT, &array_[i])(); }
	}
	//-------------------------------------------------------------------------------------------------------
	inline void Add(
		const uint_t index,
		const ObjectT& object
	)
	{
		kaos_assert(size_ > 0, "size must be > 0");
		kaos_assert(index <= element_count_, "index must be valid");
		kaos_assert(index < size_, "there must be room inside the vector for the new entry!");

		// move elements up
		if (element_count_ > 0)
		{
			uint_t target_index = element_count_;
			while (target_index > index)
			{
				if (target_index < element_count_)
					{ ResetIndex(target_index); }
				KAOS_INPLACE_NEW(ObjectT, &array_[target_index])(array_[target_index-1]);
				--target_index;
			}
		}

		// insert at correct index
		if (index < element_count_)
		{
			ResetIndex(index);
		}
		KAOS_INPLACE_NEW(ObjectT, &array_[index])(object);

		// insert last element ...
		++element_count_;
	}
	//-------------------------------------------------------------------------------------------------------
	inline void Replace(
		const uint_t index,
		const ObjectT& object
	)
	{
		kaos_assert(size_ > 0, "size must be > 0");
		kaos_assert(index < element_count_, "index must be valid");
		array_[index] = object;
	}
	//-------------------------------------------------------------------------------------------------------
	inline void Remove(
		const uint_t index
	)
	{
		kaos_assert(size_ > 0, "size must be > 0");
		kaos_assert(index < element_count_, "index must be valid");
		for (uint_t i = index; i < (element_count_-1); ++i)
		{
			array_[i] = array_[i+1];
		}
		ResetIndex(element_count_-1);
		--element_count_;
	}
	//-------------------------------------------------------------------------------------------------------
	inline void FastRemove(
		const uint_t index
	)
	{
		kaos_assert(size_ > 0, "size must be > 0");
		kaos_assert(index < element_count_, "index must be valid");
		if (index < (element_count_-1))
		{
			array_[index] = array_[element_count_-1];
		}
		ResetIndex(element_count_-1);
		--element_count_;
	}
	//-------------------------------------------------------------------------------------------------------
	inline void Clear()
	{
		kaos_assert(size_ > 0, "size must be > 0");
		for (uint_t i = 0; i < element_count_; ++i)
		{
			ResetIndex(i);
		}
		element_count_ = 0;
	}
	//-------------------------------------------------------------------------------------------------------
	inline ObjectT& GetAt(
		const uint_t index
	)
	{
		return GetAt(static_cast<ulong_t>(index));
	}
	//-------------------------------------------------------------------------------------------------------
	inline const ObjectT& GetAt(
		const uint_t index
	) const
	{
		return GetAt(static_cast<ulong_t>(index));
	}
	//-------------------------------------------------------------------------------------------------------
	inline ObjectT& GetAt(
		const ulong_t index
	)
	{
		kaos_assert(size_ > 0, "size must be > 0");
		kaos_assert(index < element_count_, "index must be valid");
		return array_[index];
	}
	//-------------------------------------------------------------------------------------------------------
	inline const ObjectT& GetAt(
		const ulong_t index
	) const
	{
		kaos_assert(size_ > 0, "size must be > 0");
		kaos_assert(index < element_count_, "index must be valid");
		return array_[index];
	}
	//-------------------------------------------------------------------------------------------------------
	inline ObjectT& GetAt(
		const int_t index
	)
	{
		return GetAt(static_cast<long_t>(index));
	}
	//-------------------------------------------------------------------------------------------------------
	inline const ObjectT& GetAt(
		const int_t index
	) const
	{
		return GetAt(static_cast<long_t>(index));
	}
	//-------------------------------------------------------------------------------------------------------
	inline ObjectT& GetAt(
		const long_t index
	)
	{
		kaos_assert(size_ > 0, "size must be > 0");
		kaos_assert(index >= 0, "index must be valid");
		kaos_assert(index < element_count_, "index must be valid");
		return array_[index];
	}
	//-------------------------------------------------------------------------------------------------------
	inline const ObjectT& GetAt(
		const long_t index
	) const
	{
		kaos_assert(size_ > 0, "size must be > 0");
		kaos_assert(index >= 0, "index must be valid");
		kaos_assert(index < element_count_, "index must be valid");
		return array_[index];
	}
	//-------------------------------------------------------------------------------------------------------
	inline const uint_t Find(
		const ObjectT& object
	) const
	{
		kaos_assert(size_ > 0, "size must be > 0");
		for (uint_t i = 0; i < element_count_; ++i)
		{
			if (array_[i] == object)
			{
				return i;
			}
		}
		return element_count_;
	}
	//-------------------------------------------------------------------------------------------------------
	inline const uint_t GetAllocatedSize() const
	{
		return size_;
	}
	//-------------------------------------------------------------------------------------------------------
	inline const uint_t GetSize() const
	{
		return element_count_;
	}
	//-------------------------------------------------------------------------------------------------------
	inline const bool_t IsEmpty() const
	{
		return element_count_ == 0;
	}
	//-------------------------------------------------------------------------------------------------------
	inline const uint_t AllocatedSize() const
	{
		return size_;
	}
	//-------------------------------------------------------------------------------------------------------
	template <
		typename OtherVectorT
	>
	inline const bool_t Equals(
		const OtherVectorT& vector
	) const
	{
		if (vector.GetSize() != GetSize())
		{
			return false;
		}
		for (uint_t i = 0; i < GetSize(); ++i)
		{
			if (GetAt(i) != vector.GetAt(i))
			{
				return false;
			}
		}
		return true;
	}
	//-------------------------------------------------------------------------------------------------------
	void Grow(
		const uint_t new_size
	)
	{
		ObjectT* new_array = CreateArray(new_size);
		for (uint_t i = 0; i < element_count_; ++i)
		{
			KAOS_INPLACE_NEW(ObjectT, &new_array[i])(array_[i]);
			ResetIndex(i);
		}
		size_ = new_size;
		DeleteArray(array_);
		array_ = new_array;
	}
	
private:
	//-------------------------------------------------------------------------------------------------------
	inline void ResetIndex(
		const uint_t index
	)
	{
		// ObjectT has no destructor this will generate an unreferenced formal parameter warning
		// with 'index' therefore:
		KAOS_UNREFERENCED_PARAMETER(index); // potentialy unreferenced parameter...
		array_[index].~ObjectT();
#if defined(KAOS_DEBUG)
		memset(&array_[index], 0, sizeof(ObjectT));
#endif
	}
	//-------------------------------------------------------------------------------------------------------
	inline ObjectT* CreateArray(
		const uint_t size
	)
	{
		return (ObjectT*)(KAOS_NEW_DYNAMIC_ARRAY(unsigned char, sizeof(ObjectT) * size, heap_));
	}
	//-------------------------------------------------------------------------------------------------------
	inline void DeleteArray(
		ObjectT*& array
	)
	{
		if (array)
		{
			unsigned char* ptr = (unsigned char*)array;
			KAOS_DELETE_ARRAY(ptr, heap_);
			array = NULL;
		}
	}
	
private:
	uint_t size_;
	uint_t element_count_;
	ObjectT* array_;
	HeapT heap_;
};

} // namespace kaos
