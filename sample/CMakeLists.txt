file(GLOB_RECURSE sampleSRC *.cpp)
SET(CMAKE_EXE_LINKER_FLAGS "/SUBSYSTEM:WINDOWS")
#set_target_properties(wxFreeCharDemo PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS")
add_executable(wxFreeCharDemo demo.cpp ${sampleSRC})
target_link_libraries(wxFreeCharDemo ${wxWidgets_LIBRARIES} wxFreeChart)

