#pragma once

#include <memory>
#include "o80/driver.hpp"
#include "o80_webcam/webcam.hpp"

namespace o80_webcam
{

    class None{};

    class Driver : public o80::Driver<None, cv::Mat>
    {
    public:
        Driver(int index);
        void start();
        void stop();
        void set(const None& in);
        cv::Mat get();
    private:
        int index_;
        std::shared_ptr<Webcam> webcam_;
    };
}
