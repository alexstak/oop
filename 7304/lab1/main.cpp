#include <assert.h>
#include <iostream>
#include <algorithm> // std::copy
#include <cstddef> // size_t
using namespace std;
template<typename T>
class Array
{
public:
// (default) constructor
Array(const size_t size = 0)
    : m_size(size)
    , m_array(m_size ? new T[m_size]() : nullptr)
{
    //cout<<"defalt\n";
}

const size_t size() const
{
    return m_size;
}

T& operator [](const size_t index)
{
    assert(index < m_size);

    return m_array[index];
}
Array A(Array&& a){};
//kon kop
Array (const Array& a)
    : m_size(a.m_size)
{
    //cout<<"kop"<< endl;
try {

    if (m_size){
        m_array = new T[m_size];
        std::copy(a.m_array,a.m_array+m_size,m_array);
    }
        else
            m_array = nullptr;
}
catch (...) {
    delete[] m_array;
    throw;
}
}
//op pr
Array& operator=(Array& a)
{
    //cout<<"===";
    if (this != &a)
    {
        T* tmp_array = nullptr;
    try {
        if (a.m_size){
            tmp_array = new T[a.m_size];
            std::copy(a.m_array,a.m_array+a.m_size,tmp_array);
        }
    else
        tmp_array = nullptr;
    }
    catch (...) {
        delete[] tmp_array;
        throw;
    }
    delete[] m_array;
    m_size = a.m_size;
    m_array = tmp_array;
    }
    return *this;
}
// mv con
Array (Array&& a)
{
    //cout<<"move\n";
    m_size = a.m_size;
    m_array = a.m_array;
    a.m_array = nullptr;
}
// dest
~Array() {
    //cout<<"destr\n";
    delete[] m_array;
}
private:
size_t m_size;
T* m_array;
};
