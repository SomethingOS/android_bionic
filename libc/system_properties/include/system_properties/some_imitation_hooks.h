/*
 * Copyright (C) 2023 Paranoid Android
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <async_safe/log.h>

#define DEBUG false
#define LOG_TAG "SomeImitationHooks/Native"
#define SIH_LOG(fmt, ...) if (DEBUG) \
  async_safe_format_log(ANDROID_LOG_INFO, LOG_TAG, "%s: " fmt, __func__, ##__VA_ARGS__)

class SomeImitationHooks {
 public:
  SomeImitationHooks() = default;
  void OnFind(const char** name);
};
