//////////////////////////////////////////////////////////////////////////
//  - 싱글톤 -
//
//
//////////////////////////////////////////////////////////////////////////
#pragma once

#include <cassert>

// Lightweight CRTP singleton helper.
// Usage: class CFoo : public Singleton<CFoo> { ... };
template <typename T>
class Singleton
{
public:
    Singleton()
    {
        assert(s_Instance == nullptr && "Singleton already created");
        s_Instance = static_cast<T*>(this);
    }

    virtual ~Singleton()
    {
        if (s_Instance == this)
        {
            s_Instance = nullptr;
        }
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

    static T& GetSingleton()
    {
        assert(s_Instance != nullptr && "Singleton not created");
        return *s_Instance;
    }

    static T* GetSingletonPtr()
    {
        return s_Instance;
    }

    static bool IsInitialized()
    {
        return s_Instance != nullptr;
    }

protected:
    static inline T* s_Instance = nullptr;
};