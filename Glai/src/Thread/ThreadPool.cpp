#include "EngineCore.h"
#include "ThreadPool.h"

Engine::JobSystem::ThreadPool::ThreadPool(uint8_t numThreads)
{
    this->numThreads = numThreads;
}

void Engine::JobSystem::ThreadPool::Start()
{
    threads.resize(numThreads);
    for (uint32_t i = 0; i < numThreads; i++) {
        threads.at(i) = std::thread([this]() {
                ThreadLoop();
            });
    }
}

void Engine::JobSystem::ThreadPool::QueueJob(Job* job)
{
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        jobs.push(job);
    }
    mutex_condition.notify_one();
}

void Engine::JobSystem::ThreadPool::Stop()
{
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        should_terminate = true;
    }
    mutex_condition.notify_all();
    for (std::thread& active_thread : threads) {
        active_thread.join();
    }
    threads.clear();
}

bool Engine::JobSystem::ThreadPool::Busy()
{
    bool poolbusy;
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        poolbusy = jobs.empty();
    }
    return poolbusy;
}

void Engine::JobSystem::ThreadPool::ThreadLoop()
{
    while (true) {
        Job* job;
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            mutex_condition.wait(lock, [this] {
                return !jobs.empty() || should_terminate;
                });
            if (should_terminate) {
                return;
            }
            job = jobs.front();
            jobs.pop();
        }
        job->Execute();
    }
}
