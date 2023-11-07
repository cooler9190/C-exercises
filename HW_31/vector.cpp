#pragma once
 
#include <cstddef>
#include <initializer_list>
#include <stdexcept>
 
template <typename T>
class Vector
{
public:
    using size_type = size_t;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using reference = T&;
    using const_reference = const T&;
 
    class iterator
    {
    public:
        using value_type = Vector::value_type;
        using difference_type = Vector::difference_type;
        using reference = Vector::reference;
 
        iterator();
        iterator(T* ptr);
        iterator& operator++()
        {
            ++ptr_;
            return *this;
        }
        iterator operator++(int)
        {
            iterator result = *this;
            ++*this;
            return result;
        }
        iterator& operator--()
        {
            --ptr_;
            return *this;
        }
        iterator operator--(int)
        {
            iterator result = *this;
            --*this;
            return result;
        }
        reference operator*() const
        {
            return *ptr_;
        }
        iterator& operator+=(difference_type diff)
        {
            ptr_ += diff;
            return *this;
        }
        iterator& operator-=(difference_type diff)
        {
            ptr_ -= diff;
            return *this;
        }
    private:
        T* ptr_;
    };
 
    class const_iterator
    {
        const T* ptr_;
    public:
        using value_type = Vector::value_type;
        using difference_type = Vector::difference_type;
        using reference = Vector::const_reference;
        using iterator_category = std::random_access_iterator_tag;
 
        const_iterator() : ptr_(nullptr) {}
        const_iterator(const iterator& it) : ptr_(&*it) {}
        const_iterator(const T* ptr) : ptr_(ptr) {}
 
        const_iterator& operator++()
        {
            ++ptr_;
            return *this;
        }
        const_iterator operator++(int)
        {
            const_iterator result = *this;
            ++*this;
            return result;
        }
        const_iterator& operator--()
        {
            --ptr_;
            return *this;
        }
        const_iterator operator--(int)
        {
            const_iterator result = *this;
            --*this;
            return result;
        }
        const_iterator operator*() const
        {
            return *ptr_;
        }
        const_iterator& operator+=(difference_type diff)
        {
            ptr_ += diff;
            return *this;
        }
        const_iterator& operator-=(difference_type diff)
        {
            ptr_ -= diff;
            return *this;
        }
    };
 
    //Ex 5
    class reverse_iterator
    {
    public:
        using value_type = Vector::value_type;
        using difference_type = Vector::difference_type;
        using pointer = Vector::value_type *;
        using reference = Vector::reference;
 
        reverse_iterator() : ptr_(nullptr) {}
        reverse_iterator(T *ptr) : ptr_(ptr) {}
 
        reverse_iterator &operator++()
        {
            --ptr_;
            return *this;
        }
 
        reverse_iterator operator++(int)
        {
            reverse_iterator result = *this;
            ++*this;
            return result;
        }
 
        reverse_iterator &operator--()
        {
            ++ptr_;
            return *this;
        }
 
        reverse_iterator operator--(int)
        {
            reverse_iterator result = *this;
            --*this;
            return result;
        }
 
        reference operator*() const
        {
            return *ptr_;
        }
 
        reverse_iterator &operator+=(difference_type diff)
        {
            ptr_ -= diff;
            return *this;
        }
 
        reverse_iterator &operator-=(difference_type diff)
        {
            ptr_ += diff;
            return *this;
        }
 
    private:
        T *ptr_;
    };
 
    class const_reverse_iterator
    {
    public:
        using value_type = Vector::value_type;
        using difference_type = Vector::difference_type;
        using pointer = const Vector::value_type *;
        using reference = Vector::const_reference;
 
        const_reverse_iterator() : ptr_(nullptr) {}
        const_reverse_iterator(const iterator &it) : ptr_(&*it) {}
        const_reverse_iterator(const T *ptr) : ptr_(ptr) {}
 
 
    private:
        const T *ptr_;
    };
 
reverse_iterator rbegin()
{
    return reverse_iterator(data_ + size_ - 1);
}
 
const_reverse_iterator rbegin() const
{
    return const_reverse_iterator(data_ + size_ - 1);
}
 
reverse_iterator rend()
{
    return reverse_iterator(data_ - 1);
}
 
const_reverse_iterator rend() const
{
    return const_reverse_iterator(data_ - 1);
}
 
const_reverse_iterator crbegin() const
{
    return const_reverse_iterator(data_ + size_ - 1);
}
 
const_reverse_iterator crend() const
{
    return const_reverse_iterator(data_ - 1);
}
 
    Vector() = default;
    explicit Vector(size_type size);
    Vector(size_type size, const_reference element);
    Vector(std::initializer_list<value_type> l);
    template <typename It>
    Vector(It b, It e);
    Vector(const Vector& other);
    Vector(Vector&& other);
    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other);
 
    //Ex_01
    bool operator<(const Vector& other) const;
    bool operator<=(const Vector& other) const;
    bool operator>(const Vector& other) const;
    bool operator>=(const Vector& other) const;
 
    //Ex_02
    void assign(size_type count, const T& value);
 
    //Ex_03
    iterator erase(iterator pos);
    iterator erase(iterator first, iterator last);
 
    //Ex_04
    iterator insert(iterator pos, const T& value);
    iterator insert(iterator pos, size_type count, const T& value);
 
    //Ex6
    void shrink();
 
    bool empty() const;
    size_type size() const;
    size_type capacity() const;
    T* data();
    const T* data() const;
    T& at(size_type idx);
    const T& at(size_type idx) const;
    T& operator[](size_type idx);
    const T& operator[](size_type idx) const;
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    void clear();
    void reserve(size_type capacity);
    void resize(size_type count);
    void push_back(const T& val);
    void push_back(T&& val);
    void pop_back();
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    const_iterator cbegin();
    const_iterator cend();
    ~Vector();
 
private:
    size_type size_ = 0;
    size_type capacity_ = 0;
    const_reference data_ = nullptr;
    void reallocate(size_type capacity);
    static constexpr int growthRateMultiplyer_ = 2;
    static constexpr int initialCapacity_ = 1;
};
 
template <typename T>
inline Vector<T>::Vector(size_type size)
    : size_(size)
    , capacity_(size)
    , data_(size ? new value_type[size]{} : nullptr) //Cheks if size > 0
    {}
 
template <typename T>
inline Vector<T>::~Vector()
{
    delete[] data_;
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}
 
template <typename T>
inline Vector<T>::Vector(size_type size, const_reference element)
    : size_(size)
    , capacity_(size)
    , data_(size ? new value_type[size]{} : nullptr)
    {
        std::fill_n(data_, size_, element);
    }
 
template <typename T>
inline Vector<T>::Vector(std::initializer_list<value_type> l)
    : size_(l.size())
    , capacity_(size_)
    , data_(size ? new value_type[size_]{} : nullptr)
    {
        std::copy(l.begin(), l.end(), data_);
    }
 
template <typename T>
template <typename It>
inline Vector<T>::Vector(It b, It e)
    : size_(std::distance(b, e))
    , capacity_(size_)
    , data_(size_ ? new T[size_] {} : nullptr)
    {
        std::copy(b, e, data_);
    }
 
template <typename T>
inline Vector<T>::Vector(const Vector& other)
    : size_(other.size_)
    , capacity_(other.capacity_)
    , data_(other.capacity_ ? new T[other.capacity_] {} : nullptr)
    {
        std::copy(other.data_, other.data_ + other.size_, data_);
    }
 
template <typename T>
inline Vector<T>::Vector(Vector&& other)
    : size_(other.size_)
    , capacity_(other.capacity_)
    , data_(other.data_)
    {
        other.size_ = 0;
        other.capacity_ = 0;
        other.data_ = nullptr;
    }
 
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other)
{
    if (&other = this)
    {
        return *this;
    }
    delete[] data_;
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = new T[capacity_];
    std::copy(other.data_, other.data_ + other.size_, data_);
    return *this;
}
 
template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& other)
{
    if (&other = this)
    {
        return *this;
    }
    delete[] data_;
    data_ = other.data_;
    size_ = other.size_;
    capacity_ = other.capacity_;
    other.data_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
 
    return *this;
}
 
template<typename T>
bool Vector<T>::empty() const
{
    return size_ == 0;
}
 
template <typename T>
typename Vector<T>::size_type Vector<T>::size() const
{
    return size_;
}
 
template <typename T>
typename Vector<T>::size_type Vector<T>::capacity() const
{
    return capacity_;
}
 
template <typename T>
const T* Vector<T>::data() const
{
    return data_;
}
 
template <typename T>
T* Vector<T>::data()
{
    return data_;
}
 
template <typename T>
T& Vector<T>::at(size_type idx)
{
    if (idx >= size_)
    {
        throw std::out_of_range("Vector::at: Index out of range!");
    }
    return data_[idx];
}
 
typename Vector<T>::const_reference Vector<T>::at(size_type idx) const
{
    return const_cast<Vector*>(this)->at(idx);
}
 
T& Vector<T>::operator[](size_type idx)
{
    return data_[idx];
}
 
const T& Vector<T>::operator[](size_type idx) const
{
    return data_[idx];
}
 
typename Vector::T& Vector<T>::front()
{
    return data_[0];
}
 
const typename Vector<T>::T& Vector<T>::front() const
{
    return data_[0];
}
 
typename Vector<T>::T& Vector<T>::back()
{
    size_type idx = size_ - 1;
    return data_[idx];
}
 
const T& Vector<T>::back() const
{
    size_type idx = size_ - 1;
    return data_[idx];
}
 
template <typename T>
inline void Vector<T>::reallocate(size_type capacity)
{
    T* new_data = new T[capacity] {};
    if (data_)
    {
        std::copy(data_, data_ + std::min(capacity, size_), new_data);
        delete[] data_;
    }
    data_ = new_data;
    capacity_ = capacity;
}
 
template <typename T>
void Vector<T>::clear()
{
    delete[] data_;
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}
 
template <typename T>
void Vector<T>::reserve(size_type capacity)
{
    if (capacity > capacity_)
    {
        reallocate(capacity);
    }
}
 
template <typename T>
void Vector<T>::resize(size_type count)
{
    if (count != capacity_)
    {
        reallocate(count);
    }
    size_ = count;
}
 
template <typename T>
void Vector<T>::push_back(const T& val)
{
    if (size_ == capacity_)
    {
        reserve(capacity_ > 0 ? capacity_ * growthRateMultiplyer_ : 1);
    }
    data_[size_++] = val;
}
 
template <typename T>
void Vector<T>::push_back(T&& val)
{
    if (size_ == capacity_)
    {
        reserve (capacity_ > 0 ? capacity_ * growthRateMultiplyer_ : 1);
    }
    data_[size_++] = std::move(val);
}
 
template <typename T>
void Vector<T>::pop_back()
{
    if (size_ == 0)
    {
        throw std::out_of_range("Cannot use pop_back on an empty vector!");
    }
    resize(--size_);
}
 
template <typename T>
Vector<T>::iterator::iterator()
    : ptr_(nullptr)
{
}
 
template <typename T>
Vector<T>::iterator::iterator(T* ptr)
    : ptr_(ptr)
{
}
 
 
template <typename T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return iterator(data_ ? &data_[0] : nullptr);
}
 
template <typename T>
typename Vector<T>::const_iterator Vector<T>::begin()
{
    return const_iterator(data_ ? &data_[0] : nullptr)
}
 
template <typename T>
typename Vector<T>::iterator Vector<T>::end()
{
    return iterator(data_ ? &data_[size_] : nullptr);
}
 
template <typename T>
typename Vector<T>::const_iterator Vector<T>::end()
{
    return const_iterator(data_ ? &data_[size_] : nullptr);
}
 
template <typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin()
{
    return const_iterator(data_ ? &data_[size_] : nullptr);
}
 
template <typename T>
typename Vector<T>::const_iterator Vector<T>::cend()
{
    return const_iterator(data_ ? &data_[size_] : nullptr);
}
 
//The Homework starts from here
 
template <typename T>
bool Vector<T>::operator<(const Vector<T>& other) const
{
    if (size_ != other.size_)
    {
        return size_ < other.size_;
    }
    for (size_type i = 0; i < size_; ++i)
    {
        if (data_[i] != other.data_[i])
        {
            return data_[i] < other.data_[i];
        }
    }
    return false;
}
 
template <typename T>
bool Vector<T>::operator<=(const Vector<T>& other) const
{
    return (*this < other) || (*this == other);
}
 
template <typename T>
bool Vector<T>::operator>(const Vector<T>& other) const
{
    return !(*this <= other);
}
 
template <typename T>
bool Vector<T>::operator>=(const Vector<T>& other) const
{
    return !(*this < other);
}
 
//Ex_02
template <typename T>
void Vector<T>::assign(size_type count, const T& value)
{
    if (count >capacity_)
    {
        reallocate(count);
    }
    std::fill_n(data_, count, value);
    size_ = count;
}
 
//Ex_03
template <typename T>
typename Vector<T>::iterator Vector<T>::erase(iterator pos)
{
    if (pos < begin() || pos >= end())
    {
        throw std::out_of_range("Vector::erase: Iterator out of range!");
    }
 
    size_type index = std::distance(begin(), pos);
 
    if (index < size_)
    {
        std::copy(pos + 1, end(), pos);
    }
 
    --size_;
 
    return pos;
}
 
template <typename T>
typename Vector<T>::iterator Vector<T>::erase(iterator first, iterator last)
{
    if (first < begin() || last > end() || first > last)
    {
        throw std::out_of_range("Vector::erase: Invalid range!");
    }
 
    size_type count = std::distance(first, last);
    size_type index = std::distance(begin(), first);
 
    if (count > 0)
    {
        std::copy(last, end(), first);
    }
 
    size_ -= count;
 
    return begin() + index;
}
 
//Ex 4
template <typename T>
typename Vector<T>::iterator Vector<T>::insert(iterator pos, const T& value)
{
    size_type index = pos - begin();
    if (index > size_)
    {
        throw std::out_of_range("Vector::insert: Index out of range!");
    }
 
    if (size_ == capacity_)
    {
        size_type new_capacity = capacity_ > 0 ? capacity_ * growthRateMultiplyer_ : initialCapacity_;
        reallocate(new_capacity);
    }
 
    for (size_type i = size_; i > index; --i)
    {
        data_[i] = data_[i - 1];
    }
 
    data_[index] = value;
    ++size_;
 
    return iterator(data_ + index);
}
 
template <typename T>
typename Vector<T>::iterator Vector<T>::insert(iterator pos, size_type count, const T& value)
{
    size_type index = pos - begin();
    if (index > size_)
    {
        throw std::out_of_range("Vector::insert: Index out of range!");
    }
 
    if (size_ + count > capacity_)
    {
        size_type new_capacity = std::max(capacity_, size_ + count);
        reallocate(new_capacity);
    }
 
    for (size_type i = size_ + count - 1; i >= index + count; --i)
    {
        data_[i] = data_[i - count];
    }
 
    for (size_type i = index; i < index + count; ++i)
    {
        data_[i] = value;
    }
 
    size_ += count;
 
    return iterator(data_ + index);
}
 
template <typename T>
void Vector<T>::shrink()
{
    if (size_ < capacity_ / 4)
    {
        size_type new_capacity = capacity_ / 2;
        reallocate(new_capacity);
    }
}