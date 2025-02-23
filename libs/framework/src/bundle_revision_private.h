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
 * bundle_revision_private.h
 *
 *  \date       Feb 12, 2013
 *  \author     <a href="mailto:dev@celix.apache.org">Apache Celix Project Team</a>
 *  \copyright  Apache License, Version 2.0
 */

#ifndef BUNDLE_REVISION_PRIVATE_H_
#define BUNDLE_REVISION_PRIVATE_H_

#include "bundle_revision.h"
#include "celix_threads.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * The bundle revision structure represents a revision of a bundle.
 * A bundle can have multiple revisions. A bundle revision is immutable.
 */
struct bundleRevision {
    celix_framework_t *fw;
    long revisionNr;
    char *root;
    char *location;
    manifest_pt manifest;
};

/**
 * Creates a new revision for the given inputFile or location.
 * The location parameter is used to identify the bundle.
 *
 * @note Symbol exported for testing purposes.
 *
 * @param fw The Celix framework where to create the bundle revision.
 * @param root The root for this revision in which the bundle is extracted and state is stored.
 * @param location The location associated with the revision.
 * @param manifest The manifest for the revision.
 * @param[out] bundle_revision The output parameter for the created revision.
 *
 * @return Status code indication failure or success:
 * 		- CELIX_SUCCESS when no errors are encountered.
 * 		- CELIX_ENOMEM If allocating memory for <code>bundle_revision</code> failed.
 */
CELIX_FRAMEWORK_EXPORT celix_status_t celix_bundleRevision_create(celix_framework_t* fw, const char *root, const char *location, manifest_pt manifest, bundle_revision_pt *bundle_revision);

bundle_revision_t* bundleRevision_revise(const bundle_revision_t* revision, const char* updatedBundleUrl);

celix_status_t bundleRevision_destroy(bundle_revision_pt revision);

#ifdef __cplusplus
}
#endif

#endif /* BUNDLE_REVISION_PRIVATE_H_ */
