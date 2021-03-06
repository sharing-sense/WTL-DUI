// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_VIEWS_EXAMPLES_CONTENT_CLIENT_EXAMPLES_BROWSER_MAIN_PARTS_H_
#define UI_VIEWS_EXAMPLES_CONTENT_CLIENT_EXAMPLES_BROWSER_MAIN_PARTS_H_
#pragma once

#include "base/basictypes.h"
#include "base/memory/scoped_ptr.h"
//#include "content/public/browser/browser_main_parts.h"

namespace aura {
namespace client {
class StackingClient;
}
}

namespace base {
class Thread;
}

namespace ui {
class Clipboard;
}

namespace content {

class ShellBrowserContext;
class ShellDevToolsDelegate;
struct MainFunctionParams;
}

namespace views {
class ViewsDelegate;
namespace examples {

class ExamplesBrowserMainParts : public content::BrowserMainParts {
 public:
  explicit ExamplesBrowserMainParts(
      const content::MainFunctionParams& parameters);
  virtual ~ExamplesBrowserMainParts();

  // Overridden from content::BrowserMainParts:
  virtual void PreEarlyInitialization() OVERRIDE {}
  virtual void PostEarlyInitialization() OVERRIDE {}
  virtual void PreMainMessageLoopStart() OVERRIDE;
  virtual void PostMainMessageLoopStart() OVERRIDE {}
  virtual void ToolkitInitialized() OVERRIDE {}
  virtual int PreCreateThreads() OVERRIDE;
  virtual void PreMainMessageLoopRun() OVERRIDE;
  virtual bool MainMessageLoopRun(int* result_code) OVERRIDE;
  virtual void PostMainMessageLoopRun() OVERRIDE;
  virtual void PostDestroyThreads() OVERRIDE {}

  ui::Clipboard* GetClipboard();
  content::ShellDevToolsDelegate* devtools_delegate() {
    return devtools_delegate_;
  }

  content::ShellBrowserContext* browser_context() {
    return browser_context_.get();
  }

 private:
  scoped_ptr<content::ShellBrowserContext> browser_context_;

  scoped_ptr<ui::Clipboard> clipboard_;
  content::ShellDevToolsDelegate* devtools_delegate_;
  scoped_ptr<views::ViewsDelegate> views_delegate_;
#if defined(USE_AURA)
  scoped_ptr<aura::client::StackingClient> stacking_client_;
#endif

  DISALLOW_COPY_AND_ASSIGN(ExamplesBrowserMainParts);
};

}  // namespace examples
}  // namespace views

#endif  // UI_VIEWS_EXAMPLES_CONTENT_CLIENT_EXAMPLES_BROWSER_MAIN_PARTS_H_
