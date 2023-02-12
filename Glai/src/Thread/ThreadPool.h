#pragma once
#include "Job.h"

namespace Glai::JobSystem
{
    class ThreadPool {
    public:
        ThreadPool() = delete;
        ThreadPool(uint8_t numThreads);
    public:
        void Start();
        void QueueJob(Job* job);
        void Stop();
        bool Busy();

    private:
        void ThreadLoop();

        bool                        should_terminate = false;

        std::mutex                  queue_mutex;
        std::condition_variable     mutex_condition;
        std::vector<std::thread>    threads;
        std::queue<Job*>            jobs;

        uint32_t                    numThreads;
    };
}