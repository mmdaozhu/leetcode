/*
解体思路：
    LRU

时间复杂度分析：O(n)
*/

#include <cassert>
#include <iostream>
#include <list>
#include <unordered_map>

class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {}

    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) {
            return -1;
        }
        list.erase(it->second.second);
        list.push_front(key);
        it->second.second = list.begin();
        return it->second.first;
    }

    void put(int key, int value) {
        auto it = map.find(key);
        if (it != map.end()) {
            list.erase(it->second.second);
            list.push_front(key);
            it->second.first = value;
            it->second.second = list.begin();
        } else {
            if (list.size() >= capacity_) {
                map.erase(list.back());
                list.pop_back();
            }
            list.push_front(key);
            map[key] = {value, list.begin()};
        }
    }

private:
    std::list<int> list;
    using lit = std::list<int>::iterator;
    using pair = std::pair<int, lit>;

    std::unordered_map<int, pair> map;
    int capacity_;
};

void test1() {
    LRUCache obj(2);
    obj.put(1, 1);
    obj.put(2, 2);
    assert(obj.get(1) == 1);
    obj.put(3, 3);
    assert(obj.get(2) == -1);
    obj.put(4, 4);
    assert(obj.get(1) == -1);
    assert(obj.get(3) == 3);
    assert(obj.get(4) == 4);
}

int main() {
    test1();
    return 0;
}