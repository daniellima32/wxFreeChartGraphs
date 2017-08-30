file(GLOB_RECURSE wxFreeChartSRC *.cpp)
add_library(wxFreeChart ${wxFreeChartSRC})
target_link_libraries(wxFreeChart ${wxWidgets_LIBRARIES})
source_group("wxFreeChart" FILES ${wxFreeChartSRC})
