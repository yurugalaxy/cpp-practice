#ifndef BASE_H
#define BASE_H

#include <cstdint>
#include <memory>

typedef uint16_t U16;
typedef int16_t I16;
typedef uint32_t U32;
typedef int32_t I32;
typedef uint64_t U64;
typedef int64_t I64;

namespace Yuru {
template <typename T> using Shared = std::shared_ptr<T>;
template <typename T> using Unique = std::unique_ptr<T>;
template <typename T> using Weak = std::weak_ptr<T>;
} // namespace Yuru

#endif
