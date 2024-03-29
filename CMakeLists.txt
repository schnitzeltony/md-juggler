cmake_minimum_required(VERSION 3.1)

project(md-juggler LANGUAGES CXX)
set(MDJUGGLER_VERSION_MAJOR "0")
set(MDJUGGLER_VERSION_MINOR "0")
set(MDJUGGLER_VERSION_PATCH "1")

set(PROJECT_VERSION "${MDJUGGLER_VERSION_MAJOR}.${MDJUGGLER_VERSION_MINOR}.${MDJUGGLER_VERSION_PATCH}")

# global Qt/C++ settings
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# cmake macros
include(FeatureSummary)
include(GNUInstallDirs)

# qt5 libs
find_package(Qt5 COMPONENTS Core Gui CONFIG REQUIRED)

add_subdirectory(src)

# install public headers
install(
    DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/mdjuggler
)

# spawn out some info on configuration
feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)

