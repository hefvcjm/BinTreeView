cmake_minimum_required(VERSION 3.0)

project(BINTREE_VIEW_SRC)

find_package( OpenCV REQUIRED )

set(MY_INCLUDE_DIRS ../include/view)
set(graphviz_INCLUDE_DIRS /usr/include/graphviz)
set(graphviz_LIBS gvc cdt cgraph)

include_directories(
    ${OpenCV_INCLUDE_DIRS}
    ${graphviz_INCLUDE_DIRS}
    ${MY_INCLUDE_DIRS})

add_library(view bintree_view)
target_link_libraries(view ${graphviz_LIBS} ${OpenCV_LIBS})