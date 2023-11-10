#include "o80/pybind11_helper.hpp"
#include "o80_webcam/standalone.hpp"
#include "o80_webcam/frame.hpp"

PYBIND11_MODULE(o80_webcam, m)
{

    pybind11::class_<o80_webcam::Frame>(m, "Frame")
        .def(pybind11::init<>())
        .def("dimensions", &o80_webcam::Frame::dimensions)
        .def("get", &o80_webcam::Frame::get);
    

    o80::create_python_bindings<o80_webcam::Standalone,
                                o80::NO_EXTENDED_STATE
                                >(m);
    o80::create_standalone_python_bindings<o80_webcam::Driver,
                                           o80_webcam::Standalone,
                                           int> // argument for driver (index to webcam)
        (m);
}
