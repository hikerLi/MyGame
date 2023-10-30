#pragma once
#include "common/type/bg_base_type.h"
#include <functional>
namespace BG
{
	class Task
	{
	public:
		Task(std::function<void()>&& func);

		void invoke();
	private:
		std::function<void()> m_func;
	};

	class ThreadPool;
	class Thread
	{
	public:
		Thread() = delete;
		Thread(ThreadPool* pool_ref);
		//Thread(const Thread&) = delete;
		~Thread();

		//Thread& operator=(const Thread&) = delete;

		void threadLogic();

		void stop();

		void join();
	private:
		BGThread* m_thread;
		ThreadPool* m_thread_pool_ref;
		Bool m_stop;
	};

	class ThreadPool
	{
	public:
		friend class Thread;
		ThreadPool(UInt32 pool_size = 16);
		~ThreadPool();

		template<class F, class... Args>
		void enqueue(F&& f, Args &&... args);
	private:
		Bool try_pop(Task* task);
	private:
		BGVector<Thread> m_threads;
		BGConcurrentQueue<Task*> m_tasks;
	};

	template<class F, class ...Args>
	inline void ThreadPool::enqueue(F&& f, Args && ...args)
	{
		Task* task = BGNew<Task>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
		m_tasks.push(task);
	}
}