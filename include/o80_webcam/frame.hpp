#pragma once

#include <vector>
#include <tuple>
#include <opencv2/opencv.hpp>
#include "o80_webcam/webcam.hpp"

namespace o80_webcam
{

    class Frame
    {
    public:
        Frame();

        void set(const cv::Mat& mat);
        
        template<class Archive>
        void serialize(Archive& archive)
        {
            archive(frame_);
        }

        const std::vector<unsigned char>& get() const;
        std::tuple<int,int,int> dimensions() const;
        
    private:
        std::vector<unsigned char> frame_;

    };
    
}
