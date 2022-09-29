template<class Key, class Value>
class FlatMap
{
private:
    struct Element
    {
        Key   _key;
        Value _value;
    };
    Element* _array;
    size_t static const _default_capacity = 8;
    size_t _length   = 0;
    size_t _capacity = _default_capacity;
public:
    FlatMap();
    ~FlatMap();

    FlatMap(const FlatMap&);
    FlatMap(FlatMap&&) noexcept;

    void swap(FlatMap&);
    FlatMap& operator=(const FlatMap&);
    FlatMap& operator=(FlatMap&&) noexcept;

    void clear();

    bool erase(const Key&);

    bool insert(const Key&, const Value&);

    bool contains(const Key&) const;

    Value& operator[](const Key&);

    Value& at(const Key&);

    const Value& at(const Key&) const;

    size_t size() const;
    bool empty() const;

    friend bool operator==(const FlatMap&, const FlatMap&);
    friend bool operator!=(const FlatMap&, const FlatMap&);
};

template<class Key, class Value>
FlatMap<Key, Value>::FlatMap()
{
    _array = new Element[_capacity];
}

template <class Key, class Value>
FlatMap<Key, Value>::~FlatMap()
{
    delete[] _array;
}

template <class Key, class Value>
FlatMap<Key, Value>::FlatMap(const FlatMap& m)
{
    _length   = m._length;
    _capacity = m._capacity;
    _array = std::copy(m._array);
}

template <class Key, class Value>
FlatMap<Key, Value>::FlatMap(FlatMap&& m) noexcept
{
    _capacity = m._capacity;
    _length   = m._length;
    _array    = m._array;
    m._array  = nullptr;
}

template <class Key, class Value>
FlatMap<Key, Value>& FlatMap<Key, Value>::operator=(const FlatMap& m)
{
    if (this == &m)
    {
        return *this;
    }
    _capacity = m._capacity;
    _length   = m._length;
    delete[] _array;

    _array = std::copy(m._array);
    return *this;
}

template <class Key, class Value>
FlatMap<Key, Value>& FlatMap<Key, Value>::operator=(FlatMap&& m) noexcept
{
    _capacity = m._capacity;
    _length   = m._length;
    _array    = m._array;
    m._array  = nullptr;
    return *this;
}

template <class Key, class Value>
void FlatMap<Key, Value>::swap(FlatMap& m)
{
    FlatMap buf(*this);
    *this = m;
    m = buf;
}

template <class Key, class Value>
void FlatMap<Key, Value>::clear()
{
    _length   = 0;
    _capacity = _default_capacity;
    delete[] _array;
    _array = new Element[_capacity];
}

template <class Key, class Value>
bool FlatMap<Key, Value>::erase(const Key& k)
{
    size_t l = 0;
    size_t r = _length;
    size_t m;
    while (l < r)
    {
        m = (r + l) >> 1;
        if (_array[m]._key < k)
        {
            l = m + 1;
        }
        else if (_array[m]._key > k)
        {
            r = m;
        }
        else
        {
            for (size_t i = m + 1; i < _length; i++)
            {
                _array[i - 1] = _array[i];
            }
            --_length;
            return true;
        }
    }
    return false;
}

template <class Key, class Value>
bool FlatMap<Key, Value>::insert(const Key& k, const Value& v)
{
    size_t l = 0;
    size_t r = _length;
    size_t m;
    while (l < r)
    {
        m = (r + l) >> 1;
        if (_array[m]._key < k)
        {
            l = m + 1;
        }
        else if (_array[m]._key > k)
        {
            r = m;
        }
        else
        {
            _array[m]._value = v;
            return false;
        }
    }
    ++_length;
    if (_length >= _capacity)
    {
        _capacity <<= 1;
        auto* buf = new Element[_capacity];

        for (size_t i = 0; i < l; i++)
        {
            buf[i] = _array[i];
        }
        for (size_t i = l + 1; i < _length; i++)
        {
            buf[i] = _array[i - 1];
        }

        buf[l]._value = v;
        buf[l]._key   = k;
        delete[] _array;
        _array = buf;
    }
    else
    {
        for (size_t i = _length - 1; i > m; i--)
        {
            _array[i] = _array[l - 1];
        }
        _array[l]._value = v;
        _array[l]._key   = k;
    }
    return true;
}

template <class Key, class Value>
bool FlatMap<Key, Value>::contains(const Key& k) const
{
    size_t l = 0;
    size_t r = _length;
    size_t m;
    while (l < r)
    {
        m = (r + l) >> 1;
        if (_array[m]._key < k)
        {
            l = m + 1;
        }
        else if (_array[m]._key > k)
        {
            r = m;
        }
        else
        {
            return true;
        }
    }
    return false;
}

template <class Key, class Value>
Value& FlatMap<Key, Value>::operator[](const Key& k)
{
    size_t l = 0;
    size_t r = _length;
    size_t m;
    while (l < r)
    {
        m = (r + l) >> 1;
        if (_array[m]._key < k)
        {
            l = m + 1;
        }
        else if (_array[m]._key > k)
        {
            r = m;
        }
        else
        {
            return _array[m]._value;
        }
    }
    return FlatMap()._array[0]._value;
}

template <class Key, class Value>
Value& FlatMap<Key, Value>::at(const Key& k)
{
    size_t l = 0;
    size_t r = _length;
    size_t m;
    while (l < r)
    {
        m = (r + l) >> 1;
        if (_array[m]._key < k)
        {
            l = m + 1;
        }
        else if (_array[m]._key > k)
        {
            r = m;
        }
        else
        {
            return _array[m]._value;
        }
    }
    throw std::invalid_argument("This key doesn't contains in FlatMap");
}

template <class Key, class Value>
const Value& FlatMap<Key, Value>::at(const Key& k) const
{
    size_t l = 0;
    size_t r = _length;
    size_t m;
    while (l < r)
    {
        m = (r + l) >> 1;
        if (_array[m]._key < k)
        {
            l = m + 1;
        }
        else if (_array[m]._key > k)
        {
            r = m;
        }
        else
        {
            return _array[m]._value;
        }
    }
    throw std::invalid_argument("This key doesn't contains in FlatMap");
}

template <class Key, class Value>
size_t FlatMap<Key, Value>::size() const
{
    return _length;
}

template <class Key, class Value>
bool FlatMap<Key, Value>::empty() const
{
    return !_length;
}

template <class Key, class Value>
bool operator==(const FlatMap<Key, Value>& a, const FlatMap<Key, Value>& b)
{
    if (a._length == b._length)
    {
        for (size_t i = 0; i < a._length; i++)
        {
            if (a._array[i]._key   == b._array[i]._key ||
                a._array[i]._value == b._array[i]._value)
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

template <class Key, class Value>
bool operator!=(const FlatMap<Key, Value>& a, const FlatMap<Key, Value>& b)
{
    return !(a == b);
}

