# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.

celix_subproject(PUBSUB_PSA_WS "Build WebSocket PubSub Admin" ON DEPS HTTP_ADMIN)
if (PUBSUB_PSA_WS)
    find_package(jansson REQUIRED)
    find_package(libuuid REQUIRED)

    add_celix_bundle(celix_pubsub_admin_websocket
            BUNDLE_SYMBOLICNAME "apache_celix_pubsub_admin_websocket"
            VERSION "2.0.0"
            GROUP "Celix/PubSub"
            SOURCES
            src/psa_activator.c
            src/pubsub_websocket_admin.c
            src/pubsub_websocket_topic_sender.c
            src/pubsub_websocket_topic_receiver.c
            src/pubsub_websocket_common.c
            )

    target_link_libraries(celix_pubsub_admin_websocket PRIVATE
            Celix::framework Celix::log_helper Celix::utils
            Celix::http_admin_api
            )
    target_link_libraries(celix_pubsub_admin_websocket PRIVATE Celix::pubsub_spi Celix::pubsub_utils)
    target_link_libraries(celix_pubsub_admin_websocket PRIVATE Celix::shell_api)
    target_include_directories(celix_pubsub_admin_websocket PRIVATE src)
    celix_deprecated_utils_headers(celix_pubsub_admin_websocket)
    celix_deprecated_framework_headers(celix_pubsub_admin_websocket)

    install_celix_bundle(celix_pubsub_admin_websocket EXPORT celix COMPONENT pubsub)
    add_library(Celix::celix_pubsub_admin_websocket ALIAS celix_pubsub_admin_websocket)
endif (PUBSUB_PSA_WS)
