#pragma once

#include <queue>
#include <iostream>

template<typename T, class _Compare = std::less<T>>
class Heap : public std::priority_queue<T, std::vector<T>, _Compare>
{
public:
    
    bool remove(const T& value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
        }
        else {
            return false;
        }
    }
};
using MinHeap = Heap<int64_t>;
using MaxHeap = Heap<int64_t, std::greater<uint64_t>>;

class RunningMedian
{
private:
    // Running window for median calculation. -1 means global
    const int64_t m_window = -1;
    // heaps for storing values above and below median
    MinHeap m_minHeap;  // max is top
    MaxHeap m_maxHeap;  // min is top
    
    // helper functions
    void rebalanceHeaps() {
        while(static_cast<int64_t>(m_minHeap.size() - m_maxHeap.size()) >= 2) {
            int64_t tmp = m_minHeap.top();
            m_maxHeap.push(tmp);
            m_minHeap.pop();
        }
        while(static_cast<int64_t>(m_maxHeap.size() - m_minHeap.size()) >= 2) {
            int64_t tmp = m_maxHeap.top();
            m_minHeap.push(tmp);
            m_maxHeap.pop();
        }
    }
    double median() {
        if(m_minHeap.size() == m_maxHeap.size()) {
            if(m_minHeap.empty())
                return 0.0;
            return (static_cast<double>(m_minHeap.top() + m_maxHeap.top())) / 2.0;
        }
        if(m_minHeap.size() > m_maxHeap.size())
            return m_minHeap.top();
        return m_maxHeap.top();
    }
    void addValue(int64_t val) {
        const double med = median();
        if(val > med)
            m_maxHeap.push(val);
        else
            m_minHeap.push(val);
        rebalanceHeaps();
    }
    void removeValue(int64_t val) {
        const double med = median();
        if(val > med)
            m_maxHeap.remove(val);
        else
            m_minHeap.remove(val);
        rebalanceHeaps();
    }
    
public:
    RunningMedian(uint64_t window) : m_window(window) {}
    
    // given me an array, I print out all running medians
    void print(const std::vector<int64_t>& arr) {
        for(int i=0 ; i<arr.size() ; ++i) {
            const int64_t val = arr[i];
            addValue(val);
            if(m_window != -1 && i >= m_window)
                removeValue(arr[i-m_window]);
            std::cout << median() << ",";
        }
    }
};
