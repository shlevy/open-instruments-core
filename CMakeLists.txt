cmake_minimum_required (VERSION 3.6)
file (STRINGS "VERSION" VERSION)
project (open-instruments-core VERSION "${VERSION}")

include(GNUInstallDirs)

include_directories (include)
add_library (open-instruments-core src/context.cc)
set_property (TARGET open-instruments-core PROPERTY CXX_STANDARD 11)
set_property (TARGET open-instruments-core PROPERTY SOVERSION 1)

install (TARGETS open-instruments-core
         LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
         ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}")
install (DIRECTORY include/ DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")
