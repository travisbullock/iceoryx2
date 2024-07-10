// Copyright (c) 2024 Contributors to the Eclipse Foundation
//
// See the NOTICE file(s) distributed with this work for additional
// information regarding copyright ownership.
//
// This program and the accompanying materials are made available under the
// terms of the Apache Software License 2.0 which is available at
// https://www.apache.org/licenses/LICENSE-2.0, or the MIT license
// which is available at https://opensource.org/licenses/MIT.
//
// SPDX-License-Identifier: Apache-2.0 OR MIT

#ifndef IOX2_PORTFACTORY_EVENT_HPP_
#define IOX2_PORTFACTORY_EVENT_HPP_

#include "attribute_set.hpp"
#include "callback_progression.hpp"
#include "dynamic_config_event.hpp"
#include "iox/expected.hpp"
#include "iox/function.hpp"
#include "node_failure_enums.hpp"
#include "node_state.hpp"
#include "port_factory_listener.hpp"
#include "port_factory_notifier.hpp"
#include "service_name.hpp"
#include "service_type.hpp"
#include "static_config_event.hpp"

namespace iox2 {
template <ServiceType S>
class PortFactoryEvent {
   public:
    const ServiceName& service_name() const {}
    const std::string& uuid() const {}
    const AttributeSet& attributes() const {}
    const StaticConfigEvent& static_config() const {}
    const DynamicConfigEvent& dynamic_config() const {}

    iox::expected<void, NodeListFailure> nodes(
        const iox::function<CallbackProgression(NodeState<S>)>) const {}

    PortFactoryListener<S> listener_builder() const {}
    PortFactoryNotifier<S> notifier_builder() const {}
};
}  // namespace iox2

#endif
