if(DEFINED C_CPP_PLAYGROUND_BUILD_TOOL AND C_CPP_PLAYGROUND_BUILD_TOOL)
    if(DEFINED C_CPP_PLAYGROUND_TOOL_LINK_TO_DYLIB AND C_CPP_PLAYGROUND_TOOL_LINK_TO_DYLIB)
        # Dynamic linkage.
        add_executable(CCppPlaygroundToolDynamicLinked c_cpp_playground.c)
        set_target_properties(CCppPlaygroundToolDynamicLinked PROPERTIES
            RUNTIME_OUTPUT_NAME "c-cpp-playground"
            RUNTIME_OUTPUT_DIRECTORY "dynamic"
        )
        target_link_libraries(CCppPlaygroundToolDynamicLinked CCppPlaygroundLibDynamic)
        install(TARGETS CCppPlaygroundToolDynamicLinked
            RUNTIME DESTINATION "bin"
        )
    else()
        # Static linkage.
        add_executable(CCppPlaygroundToolStaticLinked c_cpp_playground.c)
        set_target_properties(CCppPlaygroundToolStaticLinked PROPERTIES
            RUNTIME_OUTPUT_NAME "c-cpp-playground"
            RUNTIME_OUTPUT_DIRECTORY "static"
        )
        target_link_libraries(CCppPlaygroundToolStaticLinked CCppPlaygroundLibStatic)
        install(TARGETS CCppPlaygroundToolStaticLinked
            RUNTIME DESTINATION "bin"
        )
    endif()
endif()
