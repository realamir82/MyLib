cmake_minimum_required(VERSION 3.14)

project(AmirhoseinFarahmandLib VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick Widgets Core5Compat LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick Widgets Core5Compat LinguistTools)

set(TS_FILES AmirhoseinFarahmandLib_fa_IR.ts)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Assets/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Assets/)

# the header files
file(GLOB_RECURSE header_files FOLLOW_SYMLINKS "include/*.h")

# the source files
file(GLOB_RECURSE source_files FOLLOW_SYMLINKS "src/*.cpp")

# the ui files
file(GLOB_RECURSE resource_files FOLLOW_SYMLINKS "ui/*.qrc")

set(PROJECT_SOURCES
         ${TS_FILES}
         ${header_files}
         ${source_files}
         ${resource_files}
)


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(AmirhoseinFarahmandLib
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(AmirhoseinFarahmandLib SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(AmirhoseinFarahmandLib
          ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(AmirhoseinFarahmandLib
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Quick)

set_target_properties(AmirhoseinFarahmandLib PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS AmirhoseinFarahmandLib
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
   qt_import_qml_plugins(AmirhoseinFarahmandLib)
   qt_finalize_executable(AmirhoseinFarahmandLib)
endif()
