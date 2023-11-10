#pragma once
#include "opencv2/opencv.hpp"
#include "sstream"

#define O80_WEBCAM_WIDTH 1280
#define O80_WEBCAM_HEIGHT 720
#define O80_WEBCAM_CHANNELS 3


namespace o80_webcam
{
    
class Webcam
{
public:
    Webcam(int index);
    ~Webcam();
    cv::Mat capture();
private:
    int index_;
    cv::VideoCapture camera_;
};

}
