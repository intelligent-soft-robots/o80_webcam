#include "o80_webcam/webcam.hpp"

namespace o80_webcam
{

    Webcam::Webcam(int index)
        : index_{index},
          camera_{index}
    {
        if (!camera_.isOpened()) {
            std::stringstream ss;
            ss << "webcam error: could not open camera with index " << index;
            throw std::runtime_error(ss.str());
        }
        camera_.set(cv::CAP_PROP_FRAME_WIDTH, O80_WEBCAM_WIDTH);
        camera_.set(cv::CAP_PROP_FRAME_HEIGHT, O80_WEBCAM_HEIGHT);
    }

    Webcam::~Webcam()
    {
        camera_.release();
    }
    
    cv::Mat Webcam::capture() {
        cv::Mat frame;
        camera_.read(frame);
        if (frame.empty()) {
            std::stringstream ss;
            ss << "webcam error: frame captured from camera with index "
               << index_ << " is empty";
            throw std::runtime_error(ss.str());
        }
        return frame;
    }

    
}
