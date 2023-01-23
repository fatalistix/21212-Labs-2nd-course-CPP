#pragma once

#include <iostream>
#include <map>
#include <SingletonHolder.h>

template
        <
                class AbstractProduct,
                class IdentifierType,
                class ProductCreator = AbstractProduct * (*)()
        >
class Factory
{
public:
    bool Register(const IdentifierType & id, ProductCreator creator);
    bool Unregister(const IdentifierType & id);
    bool IsRegistered(const IdentifierType & id);

    AbstractProduct * CreateObject(const IdentifierType & id);

    Factory(const Factory &)=delete;
    Factory & operator=(const Factory &)=delete;

private:
    friend SingletonHolder<Factory>;

    Factory()=default;
    ~Factory()=default;

    typedef std::map<IdentifierType, ProductCreator> FactoryAssocMap;
    FactoryAssocMap associations_;
};

////////////////////////////////////////////////////////////////////////////////
// Factory::Register
////////////////////////////////////////////////////////////////////////////////

template<class A, class I, class P>
bool Factory<A, I, P>::Register(const I & id, P creator)
{
    return associations_.insert(std::make_pair(id, creator)).second;
}

////////////////////////////////////////////////////////////////////////////////
// Factory::Unregister
////////////////////////////////////////////////////////////////////////////////

template<class A, class I, class P>
bool Factory<A, I, P>::Unregister(const I & id)
{
    return associations_.erase(id) == 1;
}

////////////////////////////////////////////////////////////////////////////////
// Factory::IsRegistered
////////////////////////////////////////////////////////////////////////////////

template<class A, class I, class P>
bool Factory<A, I, P>::IsRegistered(const I & id)
{
    return associations_.find(id) != associations_.end();
}

////////////////////////////////////////////////////////////////////////////////
// Factory::CreateObject
////////////////////////////////////////////////////////////////////////////////

template<class A, class I, class P>
A * Factory<A, I, P>::CreateObject(const I & id)
{
    auto it = associations_.find(id);
    if (it != associations_.end())
    {
        return (it->second)();
    }
    throw std::invalid_argument("Invalid identifier value");
}
