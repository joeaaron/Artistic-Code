#pragma once
#include <condition_variable>
#include <mutex>
#include <queue>

template <typename T> class BlockingQueue 
{
public:
	BlockingQueue<T>(const size_t &m_size)
		: max_queue_length_(m_size), not_empty_(false), not_full_(true) {}
	void Push(const T &ele);
	T Pop();

private:
	std::queue<T> elements_;
	std::mutex elements_mutex_;
	std::condition_variable not_full_cond_;
	std::condition_variable not_empty_cond_;
	bool not_full_;
	bool not_empty_;
	size_t max_queue_length_;
};

template <typename T> void BlockingQueue<T>::Push(const T &ele) 
{
	std::unique_lock<std::mutex> lck(elements_mutex_);
	if (elements_.size() < max_queue_length_) 
	{
		elements_.push(ele);
	}
	else 
	{
		///需要等待队列内容被取出
		not_full_ = false;
		///为了避免假唤醒的情况出现
		not_full_cond_.wait(lck, [this] { return not_full_; });
		elements_.push(ele);
	}
	not_empty_ = true;
	not_empty_cond_.notify_all();
}

template <typename T> T BlockingQueue<T>::Pop() 
{
	std::unique_lock<std::mutex> lck(elements_mutex_);
	T ele;
	if (!elements_.empty()) 
	{
		ele = elements_.front();
		elements_.pop();
	}
	else 
	{
		not_empty_ = false;
		not_empty_cond_.wait(lck, [this] { return not_empty_; });
		ele = elements_.front();
		elements_.pop();
	}
	not_full_ = true;
	not_full_cond_.notify_all();
	return ele;
}