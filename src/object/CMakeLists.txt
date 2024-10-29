#Use this file to declare the newly created library

add_library(object 
  ${CMAKE_CURRENT_SOURCE_DIR}/Object.cpp
)

add_library(hittable 
  ${CMAKE_CURRENT_SOURCE_DIR}/Hittable.cpp
)