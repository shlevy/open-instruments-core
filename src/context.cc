#include <open-instruments/context.h>

namespace open_instruments { inline namespace v1 {
  context_registration::context_registration(std::string protocol, context_constructor ctor) {
    registrations.emplace(std::move(protocol), std::move(ctor));
  }

  std::unique_ptr<context> open_context(const network::uri & uri) {
    if (uri.has_scheme()) {
      auto reg = context_registration::registrations.find(uri.scheme().to_string());
      if (reg != context_registration::registrations.end()) {
        return reg->second(uri);
      }
    }
    return nullptr;
  }
} }
