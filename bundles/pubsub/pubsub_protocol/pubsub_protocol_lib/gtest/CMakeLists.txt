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

add_executable(celix_pswp_common_tests src/PS_WP_common_tests.cc)
target_include_directories(celix_pswp_common_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src)
target_link_libraries(celix_pswp_common_tests PRIVATE celix_pubsub_protocol_lib GTest::gtest Celix::pubsub_spi GTest::gtest_main)

add_test(NAME celix_pswp_common_tests COMMAND celix_pswp_common_tests)
setup_target_for_coverage(celix_pswp_common_tests SCAN_DIR ..)

if (LINKER_WRAP_SUPPORTED)
    add_executable(celix_pswp_common_ei_tests src/PS_WP_common_ei_tests.cc)
    target_include_directories(celix_pswp_common_ei_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src)
    target_link_libraries(celix_pswp_common_ei_tests PRIVATE celix_pubsub_protocol_lib GTest::gtest Celix::pubsub_spi GTest::gtest_main Celix::malloc_ei Celix::properties_ei)

    add_test(NAME celix_pswp_common_ei_tests COMMAND celix_pswp_common_ei_tests)
    setup_target_for_coverage(celix_pswp_common_ei_tests SCAN_DIR ..)
endif ()