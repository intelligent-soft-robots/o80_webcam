#include "o80_webcam/driver.hpp"

namespace o80_webcam
{

    Driver::Driver(int index)
        : index_{index}
    {}

    void Driver::start(){
        webcam_ = std::make_shared<Webcam>(index_);
    }

    void Driver::stop(){
        webcam_.reset();
    }

    void Driver::set(const None& in){}

    cv::Mat Driver::get()
    {
        return webcam_->capture();
    }
    
}
