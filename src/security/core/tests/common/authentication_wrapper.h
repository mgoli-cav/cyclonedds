/*
 * Copyright(c) 2006 to 2020 ADLINK Technology Limited and others
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v. 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0, or the Eclipse Distribution License
 * v. 1.0 which is available at
 * http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * SPDX-License-Identifier: EPL-2.0 OR BSD-3-Clause
 */
#ifndef SECURITY_CORE_TEST_AUTHENTICATION_WRAPPER_H_
#define SECURITY_CORE_TEST_AUTHENTICATION_WRAPPER_H_

#include "dds/security/dds_security_api.h"
#include "dds/security/authentication_wrapper_export.h"
#include "plugin_wrapper_msg_q.h"

/* Init in wrapper mode */
SECURITY_EXPORT int32_t init_test_authentication_wrapped(const char *argument, void **context);
SECURITY_EXPORT int32_t finalize_test_authentication_wrapped(void *context);

/* Init in all-ok mode: all functions return success without calling the actual plugin */
SECURITY_EXPORT int32_t init_test_authentication_all_ok(const char *argument, void **context);
SECURITY_EXPORT int32_t finalize_test_authentication_all_ok(void *context);

/* Init in missing function mode: one of the function pointers is null */
SECURITY_EXPORT int32_t init_test_authentication_missing_func(const char *argument, void **context);
SECURITY_EXPORT int32_t finalize_test_authentication_missing_func(void *context);

/* Init function fails */
SECURITY_EXPORT int32_t init_test_authentication_init_error(const char *argument, void **context);
SECURITY_EXPORT int32_t finalize_test_authentication_init_error(void *context);

SECURITY_EXPORT struct message * test_authentication_plugin_take_msg(dds_domainid_t domain_id, message_kind_t kind, DDS_Security_IdentityHandle lidHandle, DDS_Security_IdentityHandle ridHandle, DDS_Security_IdentityHandle hsHandle, dds_duration_t timeout);
SECURITY_EXPORT void test_authentication_plugin_release_msg(struct message *msg);

#endif /* SECURITY_CORE_TEST_AUTHENTICATION_WRAPPER_H_ */