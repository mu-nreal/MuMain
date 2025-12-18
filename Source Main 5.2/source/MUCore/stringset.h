#pragma once

#include <map>
#include <string>

namespace leaf
{
    template <class T>
    class TStringSet
    {
    public:
        using string_type = std::basic_string<T, std::char_traits<T>, std::allocator<T>>;
        using string_map_type = std::map<int, string_type>;

        TStringSet() = default;
        TStringSet(const TStringSet& other)
        {
            for (const auto& entry : other.m_mapString)
            {
                Add(entry.first, entry.second);
            }
        }

        ~TStringSet() = default;

        TStringSet& operator=(const TStringSet& other)
        {
            if (this != &other)
            {
                m_mapString.clear();
                for (const auto& entry : other.m_mapString)
                {
                    Add(entry.first, entry.second);
                }
            }
            return *this;
        }

        bool Add(int key, const T* szString)
        {
            if (szString == nullptr)
            {
                return false;
            }

            auto inserted = m_mapString.emplace(key, szString);
            return inserted.second;
        }

        bool Add(int key, const string_type& strString)
        {
            auto inserted = m_mapString.emplace(key, strString);
            return inserted.second;
        }

        bool Remove(int key)
        {
            auto erased = m_mapString.erase(key);
            return erased > 0;
        }

        void RemoveAll()
        {
            m_mapString.clear();
        }

        std::size_t GetCount() const
        {
            return m_mapString.size();
        }

        int GetKey(int index) const
        {
            if (index < 0 || static_cast<std::size_t>(index) >= m_mapString.size())
            {
                return -1;
            }

            auto it = m_mapString.begin();
            std::advance(it, index);
            return it->first;
        }

        const string_type& GetObj(int index) const
        {
            if (index < 0 || static_cast<std::size_t>(index) >= m_mapString.size())
            {
                return m_strNone;
            }

            auto it = m_mapString.begin();
            std::advance(it, index);
            return it->second;
        }

        const T* Find(int key) const
        {
            auto mi = m_mapString.find(key);
            if (mi != m_mapString.end())
            {
                return mi->second.c_str();
            }
            return nullptr;
        }

        const string_type& FindObj(int key) const
        {
            auto mi = m_mapString.find(key);
            if (mi != m_mapString.end())
            {
                return mi->second;
            }
            return m_strNone;
        }

        const T* operator[](int index) const
        {
            return GetObj(index).c_str();
        }

    private:
        string_map_type m_mapString;
        string_type m_strNone{};
    };

    using CStringSet = TStringSet<char>;
    using CStringSetW = TStringSet<wchar_t>;
}
