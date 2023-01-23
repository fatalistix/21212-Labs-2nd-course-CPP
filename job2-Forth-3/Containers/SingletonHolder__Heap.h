#pragma once

#include <iostream>

////////////////////////////////////////////////////////////////////////////////
// class SingletonHolder
////////////////////////////////////////////////////////////////////////////////

template <class ObjectType>
class SingletonHolder
{
public:
    // Returns a reference to singleton object
    static ObjectType & Instance();

    // Deleted methods
    SingletonHolder & operator=(const SingletonHolder &)=delete;
    SingletonHolder(const SingletonHolder &)=delete;
private:
    // Helpers
    static void MakeInstance();
    static void DestroySingleton();

    // Protection
    SingletonHolder()=default;
    ~SingletonHolder()=default;

    // Data
    static ObjectType * pInstance_;
    static bool        destroyed_;
};

////////////////////////////////////////////////////////////////////////////////
// SingletonHolder's data
////////////////////////////////////////////////////////////////////////////////

template<class T>
T * SingletonHolder<T>::pInstance_ = 0;

template<class T>
bool SingletonHolder<T>::destroyed_ = false;

////////////////////////////////////////////////////////////////////////////////
// SingletonHolder::Instance
////////////////////////////////////////////////////////////////////////////////

template<class T>
inline T & SingletonHolder<T>::Instance()
{
    if (!pInstance_)
    {
        MakeInstance();
    }
    return *pInstance_;
}

////////////////////////////////////////////////////////////////////////////////
// SingletonHolder::MakeInstance
////////////////////////////////////////////////////////////////////////////////

template<class T>
void SingletonHolder<T>::MakeInstance()
{
    if (destroyed_)
    {
        throw std::logic_error("Dead Reference Detected");
    }
    pInstance_ = new T;
    std::atexit(&DestroySingleton);
}

////////////////////////////////////////////////////////////////////////////////
// SingletonHolder::MakeInstance
////////////////////////////////////////////////////////////////////////////////

template<class T>
void SingletonHolder<T>::DestroySingleton()
{
    delete pInstance_;
    pInstance_ = 0;
    destroyed_ = true;
}