#pragma once
#include "common/type/bg_base_type.h"
#include <memory>
namespace BG
{
	template<class PoolType>
	class ObjectPool
	{
	public:
		ObjectPool(UInt64 chunck_size = 4096);
		PoolType* allocate();
		void deallocate(const PoolType* item);
		void resize(UInt64 new_chunck_size);
	private:
		const UInt32 m_incr_item_count = 1024;
		BGQueue<PoolType*> m_item_pool;
		UInt64 m_chunck_size;
	};

	template<class PoolType>
	inline ObjectPool<PoolType>::ObjectPool(UInt64 chunck_size) : m_chunck_size(chunck_size)
	{
		resize(chunck_size);
	}

	template<class PoolType>
	inline PoolType* ObjectPool<PoolType>::allocate()
	{
		if (m_item_pool.size() == 0)
		{
			resize(m_incr_item_count);
		}

		PoolType* pool_object = m_item_pool.front();
		m_item_pool.pop();

		new (pool_object) PoolType();
		return pool_object;
	}

	template<class PoolType>
	inline void ObjectPool<PoolType>::deallocate(const PoolType* item)
	{
		item->~PoolType();
		m_item_pool.push(item);
	}

	template<class PoolType>
	inline void ObjectPool<PoolType>::resize(UInt64 new_chunck_size)
	{
		if (m_item_pool.size() > 0)
		{
			return;
		}

		std::aligned_storage<sizeof(PoolType), alignof(PoolType)>::type pool_object_vector[new_chunck_size];
		for (UInt64 i = 0; i < new_chunck_size; i++)
		{
			PoolType* pool_object = reinterpret_cast<PoolType>(pool_object_vector + sizeof(PoolType) * i);
			m_item_pool.push(pool_object);
		}
	}
}