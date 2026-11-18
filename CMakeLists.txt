cmake_minimum_required(VERSION 3.16)
project(arrera VERSION 1.0 LANGUAGES C CXX)

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include(FetchContent)

FetchContent_Declare(
        arrera_qt
        GIT_REPOSITORY https://github.com/Arrera-Librairy/Arrera_qt.git
        GIT_TAG v1.0.0
)
FetchContent_MakeAvailable(arrera_qt)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets WebSockets)

qt_standard_project_setup()

qt_add_executable(arrera WIN32 MACOSX_BUNDLE
        main.cpp
        resource.qrc
        gui/arrera/arreraui.cpp gui/arrera/arreraui.h gui/arrera/arreraui.ui
        gui/setting/arrerasettingui.cpp gui/setting/arrerasettingui.h gui/setting/arrerasettingui.ui
        gui/update/windowsmaj.cpp gui/update/windowsmaj.h gui/update/windowsmaj.ui
        librairy/cdetectionos.cpp librairy/cdetectionos.h
        librairy/cjsonword.cpp librairy/cjsonword.h
        librairy/csetting.cpp librairy/csetting.h
        manager/application/capplication.cpp manager/application/capplication.h
        manager/application/capppc.cpp manager/application/capppc.h
        manager/application/cappspeciaux.cpp manager/application/cappspeciaux.h
        manager/application/carreraapp.cpp manager/application/carreraapp.h
        manager/communication/assistant.cpp manager/communication/assistant.h
        manager/search/carrerarecheche.cpp manager/search/carrerarecheche.h
        manager/setting/cainterfacesetting.cpp manager/setting/cainterfacesetting.h
        manager/socket/carreraserveur.cpp manager/socket/carreraserveur.h
        manager/update/ctigerdemon.cpp manager/update/ctigerdemon.h
)

if(APPLE)
    set(APP_ICON_MACOS "${CMAKE_CURRENT_SOURCE_DIR}/img/arrera-interface.icns")
    set_source_files_properties(${APP_ICON_MACOS} PROPERTIES
        MACOSX_PACKAGE_LOCATION "Resources"
    )
    target_sources(arrera PRIVATE ${APP_ICON_MACOS})
    set_target_properties(arrera PROPERTIES
        MACOSX_BUNDLE_ICON_FILE "arrera-interface.icns"
    )
elseif(WIN32)
    set(APP_ICON_RC "${CMAKE_CURRENT_BINARY_DIR}/app_icon.rc")
    file(WRITE "${APP_ICON_RC}" "IDI_ICON1 ICON \"${CMAKE_CURRENT_SOURCE_DIR}/img/icon-linux-win.ico\"\n")
    target_sources(arrera PRIVATE "${APP_ICON_RC}")
endif()

target_link_libraries(arrera PRIVATE
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::WebSockets
        Arrera::Qt
)

install(TARGETS arrera
        BUNDLE DESTINATION .
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_generate_deploy_app_script(
        TARGET arrera
        OUTPUT_SCRIPT deploy_script
        NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
