#pragma once

#include "o80/memory_clearing.hpp"
#include "o80/standalone.hpp"
#include <o80/void_state.hpp>
#include "o80_webcam/driver.hpp"
#include "o80_webcam/frame.hpp"

namespace o80_webcam
{
    constexpr int STANDALONE_QUEUE_SIZE = 200;
    constexpr int STANDALONE_N_ACTUATORS = 0;
    
    class Standalone
        : public o80::Standalone<STANDALONE_QUEUE_SIZE,
                                 STANDALONE_N_ACTUATORS,
                                 Driver,
                                 o80::VoidState,  
                                 Frame>  
    {

    public:
        
        Standalone(std::shared_ptr<Driver> driver_ptr,
                   double frequency,
                   std::string segment_id);
        
        None convert(const o80::States<STANDALONE_N_ACTUATORS, o80::VoidState>& vstate);
        
        o80::States<STANDALONE_N_ACTUATORS, o80::VoidState> convert(const cv::Mat& driver_out);
        
        void enrich_extended_state(Frame& frame,
                                   const cv::Mat &mat);
        
};

}

