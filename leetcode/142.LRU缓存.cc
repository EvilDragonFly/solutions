#include <bits/stdc++.h>
using namespace std;
class LRUCache
{
public:
    LRUCache(int capacity) : _capacity(capacity)
    {
    }

    int get(int key)
    {
        auto it = _table.find(key);
        if (it != _table.end())
        {
            _lru.splice(_lru.begin(), _lru, it->second);//内部更新热度
            return it->second->second;
        }
        return -1;
    }

    void put(int key, int value)
    {
        auto it = _table.find(key);
        if (it != _table.end())
        {
            _lru.splice(_lru.begin(), _lru, it->second);
            it->second->second = value;//更新value
            return;
        }

        _lru.emplace_front(key, value);
        _table[key] = _lru.begin();

        if (_table.size() > _capacity)
        {
            _table.erase(_lru.back().first);
            _lru.pop_back();
        }
    }

private:
    unordered_map<int, std::list<std::pair<int, int>>::iterator> _table;//满足0(n)的get，put复杂度
    std::list<std::pair<int, int>> _lru;//从begin()到end()热度递减,链表对于内部元素频繁移位操作是最佳数据结构
    int _capacity;
};