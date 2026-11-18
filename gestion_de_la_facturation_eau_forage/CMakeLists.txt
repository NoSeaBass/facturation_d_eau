 cmake_minimum_required(VERSION 3.16)

project(gestion_de_la_facturation_eau_forage VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

set(PROJECT_SOURCES
        main.cpp
        application.cpp
        application.h
        application.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(gestion_de_la_facturation_eau_forage
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        gestionfactures.cpp gestionfactures.h gestionfactures.ui
        nouvellefacture.cpp nouvellefacture.h nouvellefacture.ui
        mainwindow.cpp mainwindow.h mainwindow.ui
        #gestion_compteurs.cpp gestion_compteurs.h gestion_compteurs.ui
        association.cpp association.h association.ui
        windowGestion.cpp windowGestion.h windowGestion.ui
        basedonnee.cpp basedonnee.h
        trans_archive.cpp trans_archive.h trans_archive.ui
        selectclient.cpp selectclient.h selectclient.ui
        listeprelevement.h listeprelevement.cpp listeprelevement.ui
        listeclient.h listeclient.cpp listeclient.ui
        client.h client.cpp client.ui
        clientmodel.h clientmodel.cpp
        databasemanager.h databasemanager.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET gestion_de_la_facturation_eau_forage APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(gestion_de_la_facturation_eau_forage SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(gestion_de_la_facturation_eau_forage
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(gestion_de_la_facturation_eau_forage PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.gestion_de_la_facturation_eau_forage)
endif()
set_target_properties(gestion_de_la_facturation_eau_forage PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS gestion_de_la_facturation_eau_forage
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(gestion_de_la_facturation_eau_forage)
endif()
