#include "o80/pybind11_helper.hpp"
#include "o80_webcam/standalone.hpp"
#include "o80_webcam/frame.hpp"

PYBIND11_MODULE(o80_webcam, m)
{

    typedef o80::Observation<0,o80::VoidState, o80_webcam::Frame> observation;
    pybind11::class_<observation>(m,"Observation")
        .def(pybind11::init<>())
        .def("get_iteration", &observation::get_iteration)
        .def("get_frequency", &observation::get_frequency)
        .def("get_time_stamp", &observation::get_time_stamp)
        .def("get_frame",
             [](observation& obs)
             {
                 o80_webcam::Frame frame = obs.get_extended_state();
                 return frame.get();
             }
             )
        .def("get_dimensions",
             [](observation& obs)
             {
                 o80_webcam::Frame frame = obs.get_extended_state();
                 return frame.dimensions();
             }
             );
        
    pybind11::class_<o80_webcam::Frame>(m, "Frame")
        .def(pybind11::init<>())
        .def("dimensions", &o80_webcam::Frame::dimensions)
        .def("get", &o80_webcam::Frame::get);
    

    o80::create_python_bindings<o80_webcam::Standalone,
                                o80::NO_OBSERVATION,
                                o80::NO_EXTENDED_STATE
                                >(m);
    o80::create_standalone_python_bindings<o80_webcam::Driver,
                                           o80_webcam::Standalone,
                                           int> // argument for driver (index to webcam)
        (m);
}
