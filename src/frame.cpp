#include "o80_webcam/frame.hpp"

namespace o80_webcam
{

    Frame::Frame(){
        frame_.resize(O80_WEBCAM_WIDTH * O80_WEBCAM_HEIGHT * O80_WEBCAM_CHANNELS);
    }

    void Frame::set(const cv::Mat& mat)
    {
        mat.reshape(1, 1).copyTo(frame_);
    }

    const std::vector<unsigned char>& Frame::get() const
    {
        return frame_;
    }

    std::tuple<int,int,int> Frame::dimensions() const
    {
        return std::make_tuple(O80_WEBCAM_HEIGHT,O80_WEBCAM_WIDTH,O80_WEBCAM_CHANNELS);
    }
    
}
