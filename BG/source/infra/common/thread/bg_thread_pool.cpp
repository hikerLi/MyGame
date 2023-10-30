#include "bg_thread_pool.h"
namespace BG
{
	Task::Task(std::function<void()>&& func)
	{
		m_func = std::move(func);
	}

	void Task::invoke()
	{
		m_func();
	}

	Thread::Thread(ThreadPool* thread_pool_ref): m_thread_pool_ref(thread_pool_ref), m_stop(false)
	{
		m_thread = BGNew<BGThread>(&Thread::threadLogic, this);
	}

	Thread::~Thread()
	{
	}

	void Thread::threadLogic()
	{
		while (true)
		{
			Task* task;
			if (m_thread_pool_ref->try_pop(task))
			{
				task->invoke();
			}
			else if(m_stop)
			{
				break;
			}
		}
	}

	void Thread::stop()
	{
		m_stop =true;
	}

	void Thread::join()
	{
		m_thread->join();
		delete m_thread;
	}

	ThreadPool::ThreadPool(UInt32 pool_size)
	{
		for (UInt32 i = 0; i < pool_size; i++)
		{
			m_threads.emplace_back(this);
		}
	}

	ThreadPool::~ThreadPool()
	{
		for (auto iter = m_threads.begin(); iter != m_threads.end(); iter++)
		{
			(*iter).stop();
		}

		for (auto iter = m_threads.begin(); iter != m_threads.end(); iter++)
		{
			(*iter).join();
		}
	}

	Bool ThreadPool::try_pop(Task* task)
	{
		return m_tasks.try_pop(task);
	}

	

	

}