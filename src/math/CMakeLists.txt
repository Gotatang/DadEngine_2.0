add_subdirectory(matrix/)
add_subdirectory(quaternion/)
add_subdirectory(vector/)

add_library(math ${DADENGINE_MATH_SRC})

target_include_directories(math PRIVATE
        ${CMAKE_SOURCE_DIR}/include/math
)
