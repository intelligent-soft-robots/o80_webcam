#include "o80_webcam/standalone.hpp"

namespace o80_webcam
{
    Standalone::Standalone(std::shared_ptr<Driver> driver_ptr,
                           double frequency,
                           std::string segment_id)
        : o80::Standalone<STANDALONE_QUEUE_SIZE,
                          0,
                          Driver,
                          o80::VoidState,
                          Frame>(driver_ptr, frequency, segment_id)
    {
    }

    None Standalone::convert(const o80::States<STANDALONE_N_ACTUATORS, o80::VoidState>& vs)
    {
        return None();
    }

    o80::States<STANDALONE_N_ACTUATORS, o80::VoidState> Standalone::convert(const cv::Mat& driver_out)
    {

        o80::States<STANDALONE_N_ACTUATORS, o80::VoidState> states;
        return states;
    }

    void Standalone::enrich_extended_state(Frame& frame,
                               const cv::Mat &mat)
    {
        frame.set(mat);
    }
    
}
