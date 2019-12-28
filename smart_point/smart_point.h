#pragma once
#include <utility>
namespace rstd
{
    template <typename T>
    class smart_ptr {
    public:
        explicit smart_ptr(T* ptr = nullptr)
            : ptr_(ptr) {}
        ~smart_ptr()
        {
            delete ptr_;
        }
        T* get() const { return ptr_; }

        T& operator*() const { return *ptr_; }
        T* operator->() const { return ptr_; }
        operator bool() const { return ptr_; }

        smart_ptr(smart_ptr&& other)
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
    };
}
