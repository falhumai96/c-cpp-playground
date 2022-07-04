file(GLOB CCppPlaygroundLibSrc
    "private/*.c"
    "private/*.cpp"
    "public/*.c"
    "public/*.cpp"
)

file(GLOB CCppPlaygroundLibPublicHeaders
    "${PROJECT_SOURCE_DIR}/include/public/*.h"
    "${PROJECT_SOURCE_DIR}/include/public/*.hpp"
)

if(DEFINED C_CPP_PLAYGROUND_BUILD_DYLIB AND C_CPP_PLAYGROUND_BUILD_DYLIB)
    # Dynamic library.
    add_library(CCppPlaygroundLibDynamic SHARED "${CCppPlaygroundLibSrc}")
    set_target_properties(CCppPlaygroundLibDynamic PROPERTIES
        ARCHIVE_OUTPUT_NAME "c_cpp_playground"
        RUNTIME_OUTPUT_NAME "c_cpp_playground"
        LIBRARY_OUTPUT_NAME "c_cpp_playground"
        ARCHIVE_OUTPUT_DIRECTORY "dynamic"
        RUNTIME_OUTPUT_DIRECTORY "dynamic"
        LIBRARY_OUTPUT_DIRECTORY "dynamic"
        CMAKE_EXCLUDE_FROM_ALL ON
        PUBLIC_HEADER "${CCppPlaygroundLibPublicHeaders}"
    )
    target_include_directories(CCppPlaygroundLibDynamic INTERFACE "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/public>" "$<INSTALL_INTERFACE:${PROJECT_SOURCE_DIR}/include>")
    target_include_directories(CCppPlaygroundLibDynamic PRIVATE "${PROJECT_SOURCE_DIR}/include")
    install(TARGETS CCppPlaygroundLibDynamic
        RUNTIME DESTINATION "bin"
        LIBRARY DESTINATION "lib"
        ARCHIVE DESTINATION "lib"
        PUBLIC_HEADER DESTINATION "include"
    )
else()
    # Static library.
    add_library(CCppPlaygroundLibStatic STATIC "${CCppPlaygroundLibSrc}")
    set_target_properties(CCppPlaygroundLibStatic PROPERTIES
        ARCHIVE_OUTPUT_NAME "c_cpp_playground"
        RUNTIME_OUTPUT_NAME "c_cpp_playground"
        LIBRARY_OUTPUT_NAME "c_cpp_playground"
        ARCHIVE_OUTPUT_DIRECTORY "static"
        RUNTIME_OUTPUT_DIRECTORY "static"
        LIBRARY_OUTPUT_DIRECTORY "static"
        CMAKE_EXCLUDE_FROM_ALL ON
        PUBLIC_HEADER "${CCppPlaygroundLibPublicHeaders}"
    )
    target_include_directories(CCppPlaygroundLibStatic INTERFACE "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/public>" "$<INSTALL_INTERFACE:${PROJECT_SOURCE_DIR}/include>")
    target_include_directories(CCppPlaygroundLibStatic PRIVATE "${PROJECT_SOURCE_DIR}/include")
    install(TARGETS CCppPlaygroundLibStatic
        RUNTIME DESTINATION "bin"
        LIBRARY DESTINATION "lib"
        ARCHIVE DESTINATION "lib"
        PUBLIC_HEADER DESTINATION "include"
    )
endif()
