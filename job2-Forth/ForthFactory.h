#include <map>
#include <string>
//#include <functional>

template
<
    class AbstractProduct,
    class IdentifierType,
    class ProductCreator = AbstractProduct* (*)()//,
    //template<typename, class>
    //class FactoryErrorPolicy = DefaultFactoryError
>
class Factory //: FactoryErrorPolicy<IdentifierType, AbstractProduct>
{
public:
    bool Register(const IdentifierType& id, ProductCreator creator)
    {
        return associations_.insert(
                FactoryAssocMap::value_type(id, creator)).second;
    }

    bool Unregister(const IdentifierType& id)
    {
        return associations_.erase(id) == 1;
    }

    AbstractProduct* CreateObject(const IdentifierType& id)
    {
        typename FactoryAssocMap::const_iterator it = associations_.find(id);
        if (it != associations_.end())
        {
            return (it->second)();
        }
        //return OnUnknownType(id);
    }


private:
    typedef std::map<IdentifierType, AbstractProduct> FactoryAssocMap;
    FactoryAssocMap associations_;
};