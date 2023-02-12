#pragma once

#include "JobSystem.h"
#include "ThreadPool.h"

#define AUDIO_JOB_THREAD_NUM 2
#define HIGH_JOB_THREAD_NUM 8
#define PHYSICS_JOB_THREAD_NUM 8
#define LOW_JOB_THREAD_NUM 8

namespace Glai::JobSystem
{

	class ThreadSystem
	{
	public:
		ThreadSystem() {
			renderThread		= CreateRef<ThreadPool>(1);
			audioPool			= CreateRef<ThreadPool>(AUDIO_JOB_THREAD_NUM);
			highPool			= CreateRef<ThreadPool>(HIGH_JOB_THREAD_NUM);
			physicsPool			= CreateRef<ThreadPool>(PHYSICS_JOB_THREAD_NUM);
			lowPool				= CreateRef<ThreadPool>(LOW_JOB_THREAD_NUM);
		}

		ThreadSystem(ThreadSystem& other) = delete;

		void operator=(const ThreadSystem&) = delete;

	public:

		void AddJob() {
			
		}

	private:
		Ref<ThreadPool>					renderThread;
		Ref<ThreadPool>					audioPool;
		Ref<ThreadPool>					highPool;
		Ref<ThreadPool>					physicsPool;
		Ref<ThreadPool>					lowPool;
	};
}

