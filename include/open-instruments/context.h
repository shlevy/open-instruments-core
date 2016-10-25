#pragma once

#include <map>
#include <functional>
#include <memory>
#include <string>

#include <network/uri.hpp>

#include "port.h"

namespace open_instruments { inline namespace v1 {
  /* Types of devices */
  enum class device_type {
    passthrough,
    oe_dio,
    oe_aio,
    oe_adio,
    oe_basic_intan,
    oe_neuropixel
  };

  /* Device context interface */
  class context {
  public:
    virtual ~context() = default;
    virtual std::unique_ptr<port> open_port(port_number, port_flags) = 0;
    virtual port_number get_num_ports() const = 0;
    virtual device_type get_device_type() const = 0;
  };

  /* Specific context implementations should register themselves with something like:
   *
   * static context_registration reg("xillybus", [](const network::uri & uri) {
   *   return std::make_unique<context>(construct xillybus context here);
   * });
   *
   * This lambda will then handle all URIs of the form xillybus://<whatever>
   */
  class context_registration {
  public:
    /* TODO: Should context_constructor take URI params already in a <string_view,string_view> map? */
    using context_constructor = std::function<std::unique_ptr<context>(const network::uri &)>;
    context_registration(std::string protocol, context_constructor);
    friend std::unique_ptr<context> open_context(const network::uri & uri);
  private:
    static std::map<std::string, context_constructor> registrations;
  };

  std::unique_ptr<context> open_context(const network::uri & uri);
} }
