#include <vector>
#include <cstddef>
#include <iostream>
#include <algorithm>

#ifndef PQ_H
#define PQ_H


template<typename T, typename Compare>
class pq{
    public:
        //Skall detta inte vara pq?
        pq(Compare comp): comp(comp){}

        void push(T element);
        T top() const;
        T pop();
        bool empty() const;
        size_t size() const;
        void print() const;
    private:
        Compare comp;
        std::vector<T> data;
};

template<typename T, typename Compare>
void pq<T,Compare>::push(T element){
    data.push_back(element);
    std::sort(data.begin(), data.end(), comp);
}

template <typename T, typename Compare>
T pq<T, Compare>::pop(){
    auto front = data.front();
    data.erase(data.begin());
    return front;
}

template <typename T, typename Compare>
T pq<T,Compare>::top() const{
    return data.front();
}



template <typename T, typename Compare>
bool pq<T,Compare>::empty() const{
    if(data.empty()){
        return true;
    }
    return false;
}

template <typename T, typename Compare>
size_t pq<T, Compare>::size() const{
    return data.size();
}

template <typename T, typename Compare>
void pq<T, Compare>::print() const{
    for(auto& order: data){
        std::cout << order.namn << " : " << order.pris << "\n";
    }
}
#endif