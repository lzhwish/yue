// Copyright 2017 Cheng Zhao. All rights reserved.
// Use of this source code is governed by the license that can be found in the
// LICENSE file.

#ifndef NATIVEUI_MAC_MOUSE_CAPTURE_H_
#define NATIVEUI_MAC_MOUSE_CAPTURE_H_

#import <Cocoa/Cocoa.h>

namespace nu {

class View;

// Simulating the SetCapture of Windows.
class MouseCapture {
 public:
  explicit MouseCapture(View* view);
  ~MouseCapture();

  MouseCapture& operator=(const MouseCapture&) = delete;
  MouseCapture(const MouseCapture&) = delete;

 private:
  void ProcessCapturedMouseEvent(NSEvent* event);

  View* view_;
  id local_monitor_;
  id global_monitor_;
};

}  // namespace nu

#endif  // NATIVEUI_MAC_MOUSE_CAPTURE_H_
