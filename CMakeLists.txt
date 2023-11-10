cmake_minimum_required(VERSION 3.10.2)

project(o80_webcam)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

################
# Dependencies #
################

find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(ament_cmake_nose REQUIRED)
find_package(o80 REQUIRED)
find_package(OpenCV REQUIRED)
find_package(pybind11 REQUIRED)
ament_export_dependencies(o80 pybind11)

# prepare to export all needed targets
set(all_targets)
set(all_target_exports)


###########
# Library #
###########

add_library( ${PROJECT_NAME} SHARED
  src/driver.cpp
  src/frame.cpp
  src/standalone.cpp
  src/webcam.cpp )
target_include_directories(
  ${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  ${OpenCV_INCLUDE_DIRS}
  $<INSTALL_INTERFACE:include>)
ament_target_dependencies(${PROJECT_NAME} o80)
target_link_libraries(${PROJECT_NAME} o80::o80)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBRARIES})
ament_export_interfaces(export_${PROJECT_NAME} HAS_LIBRARY_TARGET)
list(APPEND all_targets ${PROJECT_NAME})
list(APPEND all_target_exports export_${PROJECT_NAME})


###################
# Python wrappers #
###################

add_library(${PROJECT_NAME}_py MODULE srcpy/wrappers.cpp)
target_link_libraries(${PROJECT_NAME}_py PRIVATE pybind11::module)
target_link_libraries(${PROJECT_NAME}_py PRIVATE ${PYTHON_LIBRARIES})
target_link_libraries(${PROJECT_NAME}_py PRIVATE ${PROJECT_NAME})
set_target_properties(${PROJECT_NAME}_py
  PROPERTIES PREFIX "" SUFFIX "${PYTHON_MODULE_EXTENSION}"
  OUTPUT_NAME ${PROJECT_NAME})
target_include_directories(
  ${PROJECT_NAME}_py
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:include> SYSTEM
  PUBLIC ${PYTHON_INCLUDE_DIRS})
_ament_cmake_python_get_python_install_dir()
install(TARGETS ${PROJECT_NAME}_py DESTINATION ${PYTHON_INSTALL_DIR})


######################
# Install and export #
######################

install(DIRECTORY include/ DESTINATION include)
install(
  TARGETS ${all_targets}
  EXPORT ${all_target_exports}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES
  DESTINATION include)
ament_package()


