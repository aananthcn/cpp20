#include <iostream>
#include <coroutine>


struct CoroType {
	struct promise_type {
		CoroType get_return_object() { return CoroType(this); }
		std::suspend_always initial_suspend() { return {}; }
		std::suspend_always final_suspend() noexcept { return {}; }
		void unhandled_exception() noexcept {
			std::rethrow_exception(std::current_exception());
		}
		void return_void(){};
	};

	CoroType(promise_type* p) : m_handle(std::coroutine_handle<promise_type>::from_promise(*p)) {}

	~CoroType() {
		std::cout << "Handle destroyed..." << std::endl;
		m_handle.destroy();
	}

	std::coroutine_handle<promise_type> m_handle;
};


CoroType do_work() {
	std::cout << "Doing first thing..." << std::endl;
	co_await std::suspend_always{};
	std::cout << "Doing second thing..." << std::endl;
	co_await std::suspend_always{};
	std::cout << "Doing third thing..." << std::endl;
}


int main() {
	auto task = do_work(); // co-routine suspended on call

	task.m_handle(); // this resumes the coroutine. When next suspension point is hit it pauses.
	task.m_handle.resume();
	task.m_handle.resume();
	// task.m_handle.resume(); // DISASTER (segmentation fault) if you uncomment this.

	std::cout << "Done!" << std::endl;

	return 0;
}