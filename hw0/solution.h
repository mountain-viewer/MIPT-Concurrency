#pragma once

#include <vector>
#include <functional>
#include <thread>

template <class Task>
void hello_world(std::function<void(const Task&)> func, const std::vector<Task>& tasks) {
  std::vector<std::thread> threads;
  threads.reserve(tasks.size());

  for (const auto& task : tasks) {
    threads.push_back(std::thread(func, task));
  }

  for (auto& thread : threads) {
    thread.join();
  }
}

