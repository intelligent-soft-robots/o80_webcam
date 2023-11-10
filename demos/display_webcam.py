import cv2
import numpy as np
import time
import o80_webcam as cam

frequency = 50
camera_index = 0
duration = 20
segment_id = "o80_webcam_demo"

cam.start_standalone(segment_id, frequency, False, camera_index)

frontend = cam.FrontEnd(segment_id)
frontend.reset_next_index()
time_start = time.time()

while time.time() - time_start < duration:
    obs = frontend.wait_for_next()
    es = obs.get_extended_state()
    frame = es.get()
    dims = es.dimensions()
    data = np.array(frame, dtype=np.uint8)
    img = data.reshape(dims)
    cv2.imshow("o80_webcam_demo", img)
    cv2.waitKey(1)

cv2.destroyAllWindows()

cam.stop_standalone(segment_id)
