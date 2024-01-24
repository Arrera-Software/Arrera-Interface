cmake_minimum_required(VERSION 3.5)

project(Arrera-Interface VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(TS_FILES Arrera-Interface_fr_FR.ts)

set(PROJECT_SOURCES
        main.cpp
        CArreraUI.cpp
        CArreraUI.h
        CArreraUI.ui
        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Arrera-Interface
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ArreraTheme.qrc
        cdaparametre.h cdaparametre.cpp cdaparametre.ui
        carrerasetting.h carrerasetting.cpp
        cconfiguration.h cconfiguration.cpp
        config.ini
        configMode1.ini
        configMode2.ini
        configMode3.ini
        configMode4.ini
        configMode5.ini
        cos.h cos.cpp
        carreraopensoft.h carreraopensoft.cpp
        arreraapplib.h arreraapplib.cpp arreraapplib.ui
        configAPP.ini
        cdaparaarreralib.h cdaparaarreralib.cpp cdaparaarreralib.ui
        carreraapropos.cpp carreraapropos.h carreraapropos.ui
        carreratakbar.h carreratakbar.cpp carreratakbar.ui

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Arrera-Interface APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(Arrera-Interface SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Arrera-Interface
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(Arrera-Interface PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Arrera-Interface)
endif()
set_target_properties(Arrera-Interface PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Arrera-Interface
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Arrera-Interface)
endif()
