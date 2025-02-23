/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 *  KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
/**
 * ip_utils.h
 *
 *  \date       Jun 24, 2019
 *  \author     <a href="mailto:dev@celix.apache.org">Apache Celix Project Team</a>
 *  \copyright  Apache License, Version 2.0
 */

#ifndef IP_UTILS_H_
#define IP_UTILS_H_

#include <ctype.h>

#include "celix_errno.h"
#include "celix_utils_export.h"

#ifdef __cplusplus
extern "C" {
#endif

CELIX_UTILS_DEPRECATED_EXPORT unsigned int ipUtils_ipToUnsignedInt(char *ip);

CELIX_UTILS_DEPRECATED_EXPORT char *ipUtils_unsignedIntToIp(unsigned int ip);

CELIX_UTILS_DEPRECATED_EXPORT unsigned int ipUtils_prefixToBitmask(unsigned int prefix);

CELIX_UTILS_DEPRECATED_EXPORT int ipUtils_netmaskToPrefix(const char *netmask);

CELIX_UTILS_DEPRECATED_EXPORT char *ipUtils_findIpBySubnet(const char *ipWithPrefix);

#ifdef __cplusplus
}
#endif
#endif /* IP_UTILS_H_ */
