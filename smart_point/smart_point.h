#pragma once
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
        smart_ptr(smart_ptr& other)
        {
            ptr_ = other.release();
        }
        T* release()
        {
            T* ptr = ptr_;
            ptr_ = nullptr;
            return ptr;
        }
    private:
        T* ptr_;
    };
}
