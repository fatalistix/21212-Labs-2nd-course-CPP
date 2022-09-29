typedef std::string Key;

struct Value
{
    unsigned age;
    unsigned weight;
};

struct Element
{
    Value TValue;
    Key TKey;
};

class FlatMap
{
private:
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

FlatMap::FlatMap()
{
    _array = new Element[_capacity];
}

FlatMap::~FlatMap()
{
    delete[] _array;
}

FlatMap::FlatMap(const FlatMap& m)
{
    _length   = m._length;
    _capacity = m._capacity;
    _array    = new Element[_capacity];
    // std::copy
    for (size_t i = 0; i < _length; i++)
    {
        _array[i] = m._array[i];
    }
}

FlatMap::FlatMap(FlatMap&& m) noexcept
{
    _capacity = m._capacity;
    _length   = m._length;
    _array    = m._array;
    m._array  = nullptr;
}

FlatMap& FlatMap::operator=(const FlatMap& m)
{
    if (this == &m)
    {
        return *this;
    }
    _capacity = m._capacity;
    _length   = m._length;
    delete[] _array;
    _array = new Element[_capacity];
    for (size_t i = 0; i < _length; i++)
    {
        _array[i] = m._array[i];
    }
    return *this;
}

FlatMap& FlatMap::operator=(FlatMap&& m) noexcept
{
    _capacity = m._capacity;
    _length   = m._length;
    _array    = m._array;
    m._array  = nullptr;
    return *this;
}

void FlatMap::swap(FlatMap& m)
{
    FlatMap buf(*this);
    *this = m;
    m = buf;
}

void FlatMap::clear()
{
    _length   = 0;
    _capacity = _default_capacity;
    delete[] _array;
    _array = new Element[_capacity];
}

bool FlatMap::erase(const Key& k)
{
    size_t l = 0;
    size_t r = _length;
    size_t m;
    while (l < r)
    {
        m = (r + l) >> 1;
        if (_array[m].TKey < k)
        {
            l = m + 1;
        }
        else if (_array[m].TKey > k)
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

bool FlatMap::insert(const Key& k, const Value& v)
{
    size_t l = 0;
    size_t r = _length;
    size_t m;
    while (l < r)
    {
        m = (r + l) >> 1;
        if (_array[m].TKey < k)
        {
            l = m + 1;
        }
        else if (_array[m].TKey > k)
        {
            r = m;
        }
        else
        {
            _array[m].TValue = v;
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
        buf[l].TValue = v;
        buf[m].TKey    = k;
        for (size_t i = l + 1; i < _length; i++)
        {
            buf[i] = _array[i - 1];
        }
        delete[] _array;
        _array = buf;
    }
    else
    {
        for (size_t i = _length - 1; i > m; i--)
        {
            _array[i] = _array[l - 1];
        }
        _array[l].TValue = v;
        _array[l].TKey   = k;
    }
    return true;
}

bool FlatMap::contains(const Key& k) const
{
    size_t l = 0;
    size_t r = _length;
    size_t m;
    while (l < r)
    {
        m = (r + l) >> 1;
        if (_array[m].TKey < k)
        {
            l = m + 1;
        }
        else if (_array[m].TKey > k)
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

Value& FlatMap::operator[](const Key& k)
{
    size_t l = 0;
    size_t r = _length;
    size_t m;
    while (l < r)
    {
        m = (r + l) >> 1;
        if (_array[m].TKey < k)
        {
            l = m + 1;
        }
        else if (_array[m].TKey > k)
        {
            r = m;
        }
        else
        {
            return _array[m].TValue;
        }
    }
    return FlatMap()._array[0].TValue;
}

Value& FlatMap::at(const Key& k)
{
    size_t l = 0;
    size_t r = _length;
    size_t m;
    while (l < r)
    {
        m = (r + l) >> 1;
        if (_array[m].TKey < k)
        {
            l = m + 1;
        }
        else if (_array[m].TKey > k)
        {
            r = m;
        }
        else
        {
            return _array[m].TValue;
        }
    }
    throw std::invalid_argument("This key doesn't contains in FlatMap");
}

const Value& FlatMap::at(const Key& k) const
{
    size_t l = 0;
    size_t r = _length;
    size_t m;
    while (l < r)
    {
        m = (r + l) >> 1;
        if (_array[m].TKey < k)
        {
            l = m + 1;
        }
        else if (_array[m].TKey > k)
        {
            r = m;
        }
        else
        {
            return _array[m].TValue;
        }
    }
    throw std::invalid_argument("This key doesn't contains in FlatMap");
}

size_t FlatMap::size() const
{
    return _capacity;
}

bool FlatMap::empty() const
{
    return !_length;
}

bool operator==(const FlatMap& a, const FlatMap& b)
{
    if (a._length == b._length)
    {
        for (size_t i = 0; i < a._length; i++)
        {
            if (a._array[i].TKey != b._array[i].TKey ||
                a._array[i].TValue.age != b._array[i].TValue.age ||
                a._array[i].TValue.weight != b._array[i].TValue.weight)
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool operator!=(const FlatMap& a, const FlatMap& b)
{
    return !(a == b);
}
