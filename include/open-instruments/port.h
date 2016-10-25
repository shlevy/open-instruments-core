#pragma once

#include <memory>
#include <limits>

#include "stream.h"

namespace open_instruments { inline namespace v1 {
  using port_number = int;
  enum class port_flags : int {
  };
  /* Device port interface */
  class port {
  public:
    virtual ~port() = default;
    virtual std::unique_ptr<stream> open_stream(stream_number num = 0) = 0;
  };
} }
