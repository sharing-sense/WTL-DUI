// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_VIEWS_BUTTON_DRAG_UTILS_H_
#define UI_VIEWS_BUTTON_DRAG_UTILS_H_
#pragma once

#include "base/string16.h"
#include "ui/views/views_export.h"

class GURL;
class SkBitmap;

namespace ui {
class OSExchangeData;
}

namespace button_drag_utils {

// Sets url and title on data as well as setting a suitable image for dragging.
// The image looks like that of the bookmark buttons.
VIEWS_EXPORT void SetURLAndDragImage(const GURL& url,
                                     const string16& title,
                                     const SkBitmap& icon,
                                     ui::OSExchangeData* data);

}  // namespace drag_utils

#endif  // UI_VIEWS_BUTTON_DRAG_UTILS_H_