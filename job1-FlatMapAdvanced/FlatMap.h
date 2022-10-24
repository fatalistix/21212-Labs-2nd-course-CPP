#define DEBUG

// This associative container avoids to keep pairs key-value
// but only when key have comparison operations
// It uses array for containing elements
// and uses binary search for finding key or insert
template<class Key, class Value>
class FlatMap
{
public:
    // Constructors
    FlatMap();
    FlatMap(const FlatMap&);
    FlatMap(FlatMap&&) noexcept;

    // Destructor
    ~FlatMap();

    // Swaps values of 2 FlatMaps
    void swap(FlatMap&);

    // Assignment operators
    FlatMap& operator=(const FlatMap&);
    FlatMap& operator=(FlatMap&&) noexcept;

    // Erases all data of FlatMap, sets length = 0 and capacity = default_capacity = 8
    void clear();

    // Erases data by key and if success returns true
    // If key is not in map, returns false
    bool erase(const Key&);

    // Inserts data
    // Finds place by binary search
    // If key already exists, returns false
    // else inserts this element and returns true
    bool insert(const Key&, const Value&);

    // Checks if element is in FlatMap by key
    // returns true if key is
    // else returns false
    bool contains(const Key&) const;

    // Insecure
    // If FlatMap contains this key, returns value
    // else returns random element
    Value& operator[](const Key&);

    // Secure
    // If FlatMap contains this key, returns value
    // else throws std::invalid_argument()
    Value& at(const Key&);

    // Secure
    // For const elements
    const Value& at(const Key&) const;

    // Returns number of elements in this container
    [[nodiscard]] size_t size() const;

    // Returns true if no elements else false
    [[nodiscard]] bool empty() const;

    // EQ operator, checks all elements in container
    // If there are any different returns false
    template<class TKey, class TValue>
    friend bool operator==(const FlatMap<TKey, TValue>& a, const FlatMap<TKey, TValue>& b);

    // Not EQ operator, calls !(.. == ..)
    template<class TKey, class TValue>
    friend bool operator!=(const FlatMap<TKey, TValue>& a, const FlatMap<TKey, TValue>& b);

    // Methods for tests
    // Converts array of keys and values to std::vector<key>
#ifdef DEBUG
    explicit operator std::vector<Key>() const
    {
        std::vector<Key> forRet;
        for (size_t i = 0; i < _length; i++)
        {
            forRet.push_back(_array[i]._key);
        }
        return forRet;
    }

    // Converts array of keys and values to std::vector<value>
    explicit operator std::vector<Value>() const
    {
        std::vector<Value> forRet;
        for (size_t i = 0; i < _length; i++)
        {
            forRet.push_back(_array[i]._value);
        }
        return forRet;
    }
#endif

private:
    struct Element      // All pairs of keys and values are stored in structs
    {
        Key   _key;
        Value _value;
    };
    Element* _array;    // Massive of pairs
    size_t static const _default_capacity = 8;
    size_t _length   = 0;
    size_t _capacity = _default_capacity;

    // Addons
    // Used quite in every function
    // Binary search returns index of element when search ends
    size_t binarySearch(const Key &k) const
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
                return m;
            }
        }
        return l;
    }
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
FlatMap<Key, Value>::FlatMap(const FlatMap& m) :
    _length  (m._length),
    _capacity(m._capacity)
{
    _array = new Element[_capacity];
    std::copy(m._array, m._array + m._length, _array);
}

template <class Key, class Value>
FlatMap<Key, Value>::FlatMap(FlatMap&& m) noexcept :
    _length  (m._length),
    _capacity(m._capacity)
{
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
    delete[]  _array;
    _array    = new Element[_capacity];
    std::copy(m._array, m._array + m._length, _array);
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
    *this = std::move(m);
        m = std::move(buf);
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
    const size_t index = binarySearch(k);
    if (index < _length && _array[index]._key == k)
    {
        std::copy(_array + index + 1, _array + _length, _array + index);
        --_length;
        return true;
    }
    return false;
}

template <class Key, class Value>
bool FlatMap<Key, Value>::insert(const Key& k, const Value& v)
{
    size_t index = binarySearch(k);
    if (index < _length && _array[index]._key == k)
    {
        return false;
    }

    if (_length + 1 >= _capacity) {
        _capacity <<= 1;
    }
    auto* buf = new Element[_capacity];
    std::copy(_array, _array + index, buf);
    std::copy(_array + index, _array + _length, buf + index + 1);

    buf[index]._value = v;
    buf[index]._key   = k;
    delete[] _array;
    _array = buf;

    ++_length;
    return true;
}

template <class Key, class Value>
bool FlatMap<Key, Value>::contains(const Key& k) const
{
    const size_t index = binarySearch(k);
    if (index < _length && _array[index]._key == k)
    {
        return true;
    }
    return false;
}

template <class Key, class Value>
Value& FlatMap<Key, Value>::operator[](const Key& k)
{
    const size_t index = binarySearch(k);
    if (index < _length && _array[index]._key == k)
    {
        return _array[index]._value;
    }
    return FlatMap()._array[0]._value;
}

template <class Key, class Value>
Value& FlatMap<Key, Value>::at(const Key& k)
{
    const size_t index = binarySearch(k);
    if (index < _length && _array[index]._key == k)
    {
        return _array[index]._value;
    }
    throw std::invalid_argument("This key doesn't contains in FlatMap");
}

template <class Key, class Value>
const Value& FlatMap<Key, Value>::at(const Key& k) const
{

    const size_t index = binarySearch(k);
    if (index < _length && _array[index]._key == k)
    {
        return _array[index]._value;
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
            if ((a._array[i]._key   != b._array[i]._key) ||
                (a._array[i]._value != b._array[i]._value))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

template<class Key, class Value>
bool operator!=(const FlatMap<Key, Value>& a, const FlatMap<Key, Value>& b)
{
    return !(a == b);
}
