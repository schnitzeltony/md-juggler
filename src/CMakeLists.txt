add_library(MdJuggler
    SHARED
        # for moc & qtcreator to have it in-tree
        ${CMAKE_SOURCE_DIR}/include/mdjuggler.h
        ${CMAKE_SOURCE_DIR}/include/abstractstreamitemrenderer.h
        ${CMAKE_SOURCE_DIR}/include/abstractstreamitemdelegate.h
        abstractstreamitemdelegate_p.h
        abstractstreamitemdelegate.cpp
        abstractstreamitemrenderer_p.h
        abstractstreamitemrenderer.cpp
        resources.qrc
)
add_library(MdJuggler::MdJuggler ALIAS MdJuggler)
set_target_properties(MdJuggler PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(MdJuggler PROPERTIES SOVERSION ${MDJUGGLER_VERSION_MAJOR})

# export header
include(GenerateExportHeader)
generate_export_header(MdJuggler)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/mdjuggler_export.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/mdjuggler
)

# announce global headers - build perspective
include_directories(
    # public header
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    # generated export header
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    # plugin-interface header
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# announce headers - target perspective
target_include_directories(MdJuggler
    PUBLIC
        $<INSTALL_INTERFACE:include/mdjuggler>
)

# additional compiler options
target_compile_options(MdJuggler PRIVATE -Wall)

# some target magic added by qtcreator
target_compile_definitions(MdJuggler PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

target_link_libraries(MdJuggler
    PRIVATE
        Qt5::Core
        # ask linker to help us finding unresolved symbols
        "-Wl,--no-undefined"
)

# install library
install(TARGETS MdJuggler
    EXPORT MdJugglerExport
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# configure MdJugglerConfigVersion.cmake
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    MdJugglerConfigVersion.cmake
    VERSION ${PACKAGE_VERSION}
    COMPATIBILITY SameMinorVersion
)

# configure MdJugglerConfig.cmake
configure_file(MdJugglerConfig.cmake.in MdJugglerConfig.cmake @ONLY)

# install MdJugglerConfig(Version).cmake
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/MdJugglerConfig.cmake"
              "${CMAKE_CURRENT_BINARY_DIR}/MdJugglerConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MdJuggler
)

# install targets cmake-files
install(EXPORT MdJugglerExport
    FILE MdJugglerTargets.cmake
    NAMESPACE MdJuggler::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MdJuggler
)
