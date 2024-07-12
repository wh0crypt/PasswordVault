#pragma once

#include <cassert>

#include "dll_node_t.hpp"

template <class T>
class dll_t
{
public:
	dll_t(void) : head_(NULL), tail_(NULL), size_(0) {}
	~dll_t(void);
	
	dll_node_t<T>* GetHead(void) const { return head_; }
	dll_node_t<T>* GetTail(void) const { return tail_; }
	int GetSize(void) const { return size_; }

	bool Empty(void) const;

	void PushBack(dll_node_t<T>*);
	void PushFront(dll_node_t<T>*);
	dll_node_t<T>* PopBack(void);
	dll_node_t<T>* PopFront(void);

	dll_node_t<T>* Erase(dll_node_t<T>*);

	std::ostream& Write(std::ostream& = std::cout) const;

private:
	int size_;
	dll_node_t<T>* head_;
	dll_node_t<T>* tail_;
};

template <class T>
dll_t<T>::~dll_t(void)
{
	while(head_ != NULL)
	{
		dll_node_t<T>* aux = head_;
		head_ = head_->GetNext();
		delete aux;
	}
	size_ = 0;
	tail_ = NULL;
}

template <class T>
bool dll_t<T>::Empty(void) const
{
	if(head_ == NULL)
	{
		assert(tail_ == NULL);
		assert(!size_);
		return true;
	}

	return false;
}

template <class T>
void dll_t<T>::PushBack(dll_node_t<T>* node)
{
	assert(node != NULL);
	if(Empty())
	{
		head_ = node;
		tail_ = node;
	}
	else
	{
		tail_->SetNext(node);
		node->SetPrev(tail_);
		tail_ = node;
	}
	size_++;
}

template <class T>
void dll_t<T>::PushFront(dll_node_t<T>* node)
{
	assert(node != NULL);
	if(Empty())
	{
		head_ = node;
		tail_ = node;
	}
	else
	{
		head_->SetPrev(node);
		node->SetNext(head_);
		head_ = node;
	}
	size_++;
}

template <class T>
dll_node_t<T>* dll_t<T>::PopBack(void)
{
	assert(!Empty());
	dll_node_t<T>* aux = tail_;
	tail_ = tail_->GetPrev();

  if(tail_ != NULL) tail_->SetNext(NULL);
  else head_ = NULL;

	size_--;
  aux->SetNext(NULL);
  aux->SetPrev(NULL);
  return aux;
}

template <class T>
dll_node_t<T>* dll_t<T>::PopFront(void)
{
	assert(!Empty());
	dll_node_t<T>* aux = head_;
	head_ = head_->GetNext();

  if(head_ != NULL) head_->SetPrev(NULL);
  else tail_ = NULL;

	size_--;
  aux->SetNext(NULL);
  aux->SetPrev(NULL);
  return aux;
}

template <class T>
dll_node_t<T>* dll_t<T>::Erase(dll_node_t<T>* node)
{
	assert(node != NULL);

	if(node->GetPrev() != NULL) node->GetPrev()->SetNext(node->GetNext());
	else head_ = node->GetNext();
	if(node->GetNext() != NULL) node->GetNext()->SetPrev(node->GetPrev());
	else tail_ = node->GetPrev();

	size_--;
	node->SetNext(NULL);
	node->SetPrev(NULL);
	return node;
}

template <class T>
std::ostream& dll_t<T>::Write(std::ostream& os) const
{
	dll_node_t<T>* aux = head_;
	while(aux != NULL)
	{
		aux->Write(os);
		aux = aux->GetNext();
	}
	return os;
}