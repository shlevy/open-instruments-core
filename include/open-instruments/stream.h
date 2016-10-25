#pragma once

#include <cstddef>
#include <type_traits>

namespace open_instruments { inline namespace v1 {
  enum class stream_flags : int {
  };

  /* Attributes of a data stream */
  struct stream_attributes {
    size_t buffer_size;
    size_t timeout_msec;
    stream_flags flags;
  };

  /* TODO Should this be an enum? */
  using stream_number = int;

  /* Data stream interface */
  class stream {
    virtual ~stream() = default;
    virtual stream_attributes read_attributes() = 0;
    virtual void write_attributes(stream_attributes) = 0;
    virtual size_t read(void * buf, size_t count) = 0;
    virtual size_t write(void * buf, size_t count) = 0;
  };
} }
