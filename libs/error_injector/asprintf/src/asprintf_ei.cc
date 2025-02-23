/*
 Licensed to the Apache Software Foundation (ASF) under one
 or more contributor license agreements.  See the NOTICE file
 distributed with this work for additional information
 regarding copyright ownership.  The ASF licenses this file
 to you under the Apache License, Version 2.0 (the
 "License"); you may not use this file except in compliance
 with the License.  You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing,
  software distributed under the License is distributed on an
  "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
  KIND, either express or implied.  See the License for the
  specific language governing permissions and limitations
  under the License.
 */

#include "asprintf_ei.h"
#include <cstdarg>
#include <cstdio>
#include <errno.h>

extern "C" {

int __real_asprintf(char** buf, const char* format, ...);
CELIX_EI_DEFINE(asprintf, int)
int __wrap_asprintf(char** buf, const char* format, ...) {
    errno = ENOMEM;
    CELIX_EI_IMPL(asprintf);
    errno = 0;
    va_list args;
    va_start(args, format);
    int rc = vasprintf(buf, format, args);
    va_end(args);
    return rc;
}

}
