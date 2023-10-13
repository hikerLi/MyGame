#pragma once
#include <string>
#include <map>
#include <unordered_map>
#include <array>
#include <memory>
#include <queue>
#include <concurrent_queue.h>
#include <atomic>
#include <thread>
#define UInt16 unsigned short
#define UInt32 unsigned int
#define UInt64 unsigned long long
#define UByte unsigned char
#define BGString std::string
#define BGUnorderedMap std::unordered_map
#define ENUM enum class
#define BGArray std::array
#define Bool bool
#define BGVector std::vector
#define BGSharedPtr std::shared_ptr
#define BGMakeShared std::make_shared
#define BGQueue std::queue
#define BGConcurrentQueue Concurrency::concurrent_queue
#define BGAtomic std::atomic
#define BGThread std::thread