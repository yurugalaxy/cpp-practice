// Created by Kae 14/05/2026

#ifndef BASE_H
#define BASE_H

#include <cstdint>
#include <memory>

typedef uint8_t U8;
typedef int8_t I8;
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
