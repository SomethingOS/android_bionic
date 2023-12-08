/*
 * Copyright (C) 2023 Paranoid Android
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdlib.h>
#include <string.h>

#include "system_properties/some_imitation_hooks.h"

#define GMS_UNSTABLE "com.google.android.gms.unstable"

#define PROP_SECURITY_PATCH "ro.build.version.security_patch"
#define PROP_SIH_SECURITY_PATCH "persist.sys.somethingos.gms.SECURITY_PATCH"

#define PROP_FIRST_API_LEVEL "ro.product.first_api_level"
#define PROP_SIH_FIRST_API_LEVEL "persist.sys.somethingos.gms.FIRST_API_LEVEL"

void SomeImitationHooks::OnFind(const char** name) {
  if (getprogname() == nullptr || strcmp(getprogname(), GMS_UNSTABLE) != 0) {
    return;
  }
  SIH_LOG("name is %s", *name);
  if (strcmp(*name, PROP_SECURITY_PATCH) == 0) {
    *name = PROP_SIH_SECURITY_PATCH;
  } else if (strcmp(*name, PROP_FIRST_API_LEVEL) == 0) {
    *name = PROP_SIH_FIRST_API_LEVEL;
  } else {
    return;
  }
  SIH_LOG("name changed to %s", *name);
}
