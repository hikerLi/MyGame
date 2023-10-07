#pragma once

#include "common/type/bg_base_type.h"
namespace BG
{
	template<class IDType>
	class IDAllocator
	{
	public:
		IDType allocateID();
		void deallocateID(const IDType& id);

	private:
		IDType m_id_index;
	};

	template<class IDType>
	inline IDType IDAllocator<IDType>::allocateID()
	{
		return ++m_id_index;
	}

	template<class IDType>
	inline void IDAllocator<IDType>::deallocateID(const IDType& id)
	{
	}
}