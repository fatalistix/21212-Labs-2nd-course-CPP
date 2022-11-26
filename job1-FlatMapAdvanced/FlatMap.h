#pragma once

#include <iostream>
#include <vector>

#define DEBUG

/**
 * @brief A container made up of (key, value) pairs, which can be
 * retrieved based on a key, in logarithmic time.
 *
 * @tparam Key      Type of key objects.
 * @tparam Value    Type of mapped objects.
 *
 * FlatMap supports bidirectional iterators.
 */
template<class Key, class Value>
class FlatMap
{
public:
    /// All pairs of Keys (as _key) and Values (as _value) are stored in struct.
    struct Element
    {
        const Key   _key;
              Value _value;
    };

    /**
     * @brief @b Constructors: \n
     * @c FlatMap() - Creates a %FlatMap with no elements. \n\n
     *
     * @c FlatMap(const FlatMap &) - %FlatMap copy constructor.
     * @param m - A %FlatMap of identical elements types.
     *
     * All the element of @a m are copied, but any unused capacity in @a m will not be copied. \n
     *
     * Copy constructing requires lineal time. \n\n
     *
     * @c FlatMap(FlatMap &&) - %FlatMap move constructor. \n\n
     * The newly-created %FlatMap contains the exact content of the moved instance.
     * Afterwards @a m is a valid, but unspecified %FlatMap. \n
     *
     * Move constructing requires constant time.
     */
    FlatMap();
    FlatMap(const FlatMap &);
    FlatMap(FlatMap &&) noexcept;

    /**
       *  The dtor only erases the elements, and note that if the
       *  elements themselves are pointers, the pointed-to memory is
       *  not touched in any way.  Managing the pointer is the user's
       *  responsibility.
       */
    ~FlatMap();

    /**
     * @brief Swaps data with another %FlatMap.
     * @param m - A %FlatMap of the same element type.
     *
     * This exchanges the elements between two FlatMaps in constant time
     * (It is only swapping a pointer and size_t fields).
     */
    void swap(FlatMap &);

    /**
     * @brief @b %FlatMap @b assignment @b operators: \n
     *
     * @c operator=(const FlatMap &) - assignment operator.
     * @param m - A %FlatMap of identical elements types.
     *
     * All the elements of @a m are copied, but any unused capacity in
     * @a m will not be copied. \n
     *
     * Assignment requires lineal time. \n\n
     *
     * @c operator=(FlatMap &&) - move assignment operator. \n\n
     *
     * The content of @a m are moved into this %FlatMap (without copying).
     * Afterwards @a m is a valid, but unspecified %FlatMap.\n
     *
     * Moving assignment requires constant time.
     */
    FlatMap & operator=(const FlatMap &);
    FlatMap & operator=(FlatMap &&) noexcept;

    /**
     *  Erases all elements in a %FlatMap.  Note that this function only
     *  erases the elements, and that if the elements themselves are
     *  pointers, the pointed-to memory is not touched in any way.
     *  Managing the pointer is the user's responsibility.
     */
    void clear();

    /**
     *  @brief Erases elements according to the provided key.
     *  @param  k - Key of element to be erased.
     *  @return  True if element was erased and false if element wasn't found
     *
     *  This function erases the element located by the given key from
     *  a %FlatMap.
     *  Note that this function only erases the element, and that if
     *  the element is itself a pointer, the pointed-to memory is not touched
     *  in any way.  Managing the pointer is the user's responsibility. \n
     *
     *  Erase requires logarithmic time for search and erase and lineal time for alignment.
     */
    bool erase(const Key &);

    /**
    *  @brief Attempts to insert a Element{_key, _value} into the %FlatMap.
    *  @param k - Key to be inserted.
    *  @param v - Value to be mapped by Key.
    *
    *  @return  True if element was inserted and false if the Key is already in %FlatMap.
    *
    *  This function attempts to insert a (key, value) pair into the %FlatMap.
    *  A %FlatMap relies on unique keys and thus a pair is only inserted if its
    *  first element (the key) is not already present in the %FlatMap.
    *
    *  Insertion requires logarithmic time for finding a position to inserting and
    *  lineal time for alignment.
    */
    bool insert(const Key &, const Value &);

    /**
     * Finds whether an element with the given key exists.
     *
     * @param k - Key of (key, value) pair to be located.
     *
     * @return True if there is an element with the specified key.
     *
     * Locating requires logarithmic time.
     */
    bool contains(const Key &) const;

    /**
       *  @brief  Subscript ( @c [] ) access to %FlatMap data.
       *  @param  k - The key for which data should be retrieved.
       *  @return  A reference to the value of the (key,value) pair.
       *
       *  Allows for easy lookup with the subscript ( @c [] )
       *  operator.  Returns data associated with the key specified in
       *  subscript.  If the key does not exist, a pair with that key
       *  is created using default values, which is then returned. \n
       *
       *  Lookup requires logarithmic time.
       */
    Value & operator[](const Key &);

    /**
       *  @brief  Access to %FlatMap data.
       *  @param  k - The key for which data should be retrieved.
       *  @return  A reference to the data whose key is equivalent to @a k, if
       *           such a data is present in the %FlatMap.
       *  @throw  std::out_of_range  If no such data is present.
       *
       *  Lookup requires logarithmic time.
       */
    Value & at(const Key &);
    const Value & at(const Key &) const;

    /// Returns the size of the %FlatMap.
    [[nodiscard]] size_t size() const;

    /** Returns true if the %map is empty.  (Thus begin() would equal
       *  end().)
      */
    [[nodiscard]] bool empty() const;

    template<class TKey, class TValue>
    friend bool operator==(const FlatMap<TKey, TValue> & a, const FlatMap<TKey, TValue> & b);

    template<class TKey, class TValue>
    friend bool operator!=(const FlatMap<TKey, TValue> & a, const FlatMap<TKey, TValue> & b);

    template <Key, Value>
    class iterator
    {
    public:
        iterator()=default;
        iterator(const iterator &)=default;

        ~iterator()=default;

        Element & operator*() const noexcept { return *cur_; }
        iterator & operator++() noexcept { return ++cur_; }
        iterator operator++(int) noexcept { auto forRet = *this; ++cur_; return forRet; }
        iterator & operator--() noexcept { return --cur_; }
        iterator operator--(int) noexcept { auto forRet = *this; --cur_; return forRet; }
        Element * operator->() const noexcept { return cur_; }
        iterator & operator=(const iterator &) noexcept =default;
        iterator & operator=(iterator &&) noexcept =default;

    private:
        Element * cur_;
    };

private:
    Element* _array;
    size_t static const _default_capacity = 8;
    size_t _length   = 0;
    size_t _capacity = _default_capacity;

    size_t binarySearch(const Key & k) const
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

#ifdef DEBUG
    std::vector<Key> GetVectorOfKeys()
    {
        std::vector<Key> forRet;
        for (size_t i = 0; i < _length; i++)
        {
            forRet.push_back(_array[i]._key);
        }
        return forRet;
    }

    std::vector<Value> GetVectorOfValues()
    {
        std::vector<Value> forRet;
        for (size_t i = 0; i < _length; i++)
        {
            forRet.push_back(_array[i]._value);
        }
        return forRet;
    }
#endif
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
    FlatMap buf = std::move(*this);
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
    throw std::out_of_range("This key doesn't contains in FlatMap");
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
/**
   *  @brief  FlatMap equality comparison.
   *  @param  a - A %FlatMap.
   *  @param  b - A %FlatMap of the same type as @a a.
   *  @return  True if the size and elements of the maps are equal.
   *
   *  This is an equivalence relation.  It is linear in the size of the
   *  maps.  Maps are considered equivalent if their sizes are equal,
   *  and if corresponding elements compare equal.
  */
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

/// Based on operator==
template<class Key, class Value>
bool operator!=(const FlatMap<Key, Value>& a, const FlatMap<Key, Value>& b)
{
    return !(a == b);
}
