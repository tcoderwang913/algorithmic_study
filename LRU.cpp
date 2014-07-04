/**
Design and implement a data structure for Least Recently Used (LRU) cache. It should 
support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in 
the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. 
When the cache reached its capacity, it should invalidate the least recently 
used item before inserting a new item.
*/

struct CacheEntry{
    int key;
    int value;
    CacheEntry(int k, int v): key(k), value(v) {}
};

class LRUCache{
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }
    int get(int key) {
        if (m_map.find(key) == m_map.end()) return -1;
        MoveToHead(key);
        return m_map[key]->value;
    }
    
    void set(int key, int value) {
        if (m_map.find(key) == m_map.end()){
            //frame does not appear in the hash map, then 
            //create a new entry and move to head
            //if the cache is full, erase from end of cache
            CacheEntry entry(key, value);
            if (m_LRU_cache.size() >= m_capacity) {
                m_map.erase(m_LRU_cache.back().key);
                m_LRU_cache.pop_back();
            }
            m_LRU_cache.push_front(entry);
            m_map[key] = m_LRU_cache.begin();
            return ;
        }
        
        m_map[key]->value = value;
        MoveToHead(key);
    }

private:
    int m_capacity;
    map<int, list<CacheEntry>::iterator> m_map;
    list<CacheEntry> m_LRU_cache;
    
    //Need to understand more about how this method works
    void MoveToHead(int key) {
    	//the current entry pointed by key
        auto updateEntry = *m_map[key];
        //erase the iterator from map
        m_LRU_cache.erase(m_map[key]);
        //get the entry to front of list
        m_LRU_cache.push_front(updateEntry);
        //update iterator position for current frame with key
        m_map[key] = m_LRU_cache.begin();
        
    }
};