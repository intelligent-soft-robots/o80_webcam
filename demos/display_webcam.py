"""
Connects to the usb camera at index 0, creates corresponding o80 standalone, 
and connects to it via an o80 backend. The backend is used to read the 
image array from the shared memory and display it in an opencv window.
Runs for 20 seconds then exits.
"""

import cv2
import numpy as np
import time
import o80_webcam as cam

frequency = 100
camera_index = 0
duration = 20
segment_id = "o80_webcam_demo"

cam.start_standalone(segment_id, frequency, False, camera_index)

frontend = cam.FrontEnd(segment_id)
frontend.reset_next_index()
time_start = time.time()

while time.time() - time_start < duration:
    obs = frontend.wait_for_next()
    frame = obs.get_frame()
    dimensions = obs.get_dimensions()
    img = np.array(frame, dtype=np.uint8).reshape(dimensions)
    cv2.imshow("o80_webcam_demo", img)
    cv2.waitKey(1)

cv2.destroyAllWindows()

cam.stop_standalone(segment_id)
