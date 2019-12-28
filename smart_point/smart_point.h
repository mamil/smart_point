#pragma once
#include <utility>
namespace rstd
{
    class shared_count
    {
    public:
        shared_count() :count_(1) {}
        void add_count()
        {
            ++count_;
        }
        long reduce_count()
        {
            return --count_;
        }
        long get_count()
        {
            return count_;
        }
    private:
        long count_;
    };

    template <typename T>
    class smart_ptr {
    public:
        explicit smart_ptr(T* ptr = nullptr)
            : ptr_(ptr)
        {
            if (ptr_)
            {
                shared_count_ = new shared_count();
            }
        }
        ~smart_ptr()
        {
            if (ptr_ and !shared_count_->reduce_count())
            {
                delete shared_count_;
                delete ptr_;
            }
        }
        T* get() const { return ptr_; }

        T& operator*() const { return *ptr_; }
        T* operator->() const { return ptr_; }
        operator bool() const { return ptr_; }

        template <typename U>
        smart_ptr(smart_ptr<U>&& other)
        {
            ptr_ = other.release();
        }
        T* release()
        {
            T* ptr = ptr_;
            ptr_ = nullptr;
            return ptr;
        }
        smart_ptr& operator=(smart_ptr rhs)
        {
            rhs.swap(*this);
            return *this;
        }
        void swap(smart_ptr& rhs)
        {
            using std::swap;
            swap(ptr_, rhs.ptr_);
        }
    private:
        T* ptr_;
        shared_count* shared_count_;
    };
}
