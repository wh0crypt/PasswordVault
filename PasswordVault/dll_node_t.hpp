#pragma once

#include <iostream>

template <class T>
class dll_node_t
{
public:
	dll_node_t(void) : prev_(NULL), next_(NULL), data_() {}
	dll_node_t(const T& data) : prev_(NULL), next_(NULL), data_(data) {}

	dll_node_t<T>* GetPrev(void) const { return prev_; }
	dll_node_t<T>* GetNext(void) const { return next_; }
	T& GetData(void) const { return data_; }
	void SetPrev(const dll_node_t<T>* prev) { prev_ = prev; }
	void SetNext(const dll_node_t<T>* next) { next_ = next; }
	void SetData(const T* data) { data_ = data; }

	std::ostream& Write(std::ostream& = std::cout) const;

private:
	T data_;
	dll_node_t<T>* prev_, next_;
};

template <class T>
std::ostream& dll_node_t<T>::Write(std::ostream& os) const
{
	os << data_;
	return os;
}