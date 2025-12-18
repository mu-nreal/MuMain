#pragma once

#include <atomic>
#include <thread>

// Lightweight spin lock for short critical sections.
class SpinLock
{
public:
    SpinLock() = default;
    SpinLock(const SpinLock&) = delete;
    SpinLock& operator=(const SpinLock&) = delete;
    SpinLock(SpinLock&&) = delete;
    SpinLock& operator=(SpinLock&&) = delete;

    void lock()
    {
        while (m_Locked.test_and_set(std::memory_order_acquire))
        {
            std::this_thread::yield();
        }
    }

    bool try_lock()
    {
        return !m_Locked.test_and_set(std::memory_order_acquire);
    }

    void unlock()
    {
        m_Locked.clear(std::memory_order_release);
    }

private:
    std::atomic_flag m_Locked = ATOMIC_FLAG_INIT;
};
