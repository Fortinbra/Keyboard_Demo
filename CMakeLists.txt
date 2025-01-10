# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pimoroni_pico_plus2_rp2350 CACHE STRING "Board type")
set(PICO_CYW43_SUPPORTED 1)
set(PICO_DEOPTIMIZED_DEBUG 1)
# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(Keyboard_Demo C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(Keyboard_Demo Keyboard_Demo.cpp )

pico_set_program_name(Keyboard_Demo "Keyboard_Demo")
pico_set_program_version(Keyboard_Demo "0.1")


# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(Keyboard_Demo 1)
pico_enable_stdio_usb(Keyboard_Demo 0)

target_compile_definitions(Keyboard_Demo PRIVATE
  PICO_STACK_SIZE=4096
  CYW43_DEFAULT_PIN_WL_REG_ON=32
  CYW43_DEFAULT_PIN_WL_DATA_OUT=35
  CYW43_DEFAULT_PIN_WL_DATA_IN=35
  CYW43_DEFAULT_PIN_WL_HOST_WAKE=35
  CYW43_DEFAULT_PIN_WL_CLOCK=34
  CYW43_DEFAULT_PIN_WL_CS=33
  )

# Add the standard library to the build
target_link_libraries(Keyboard_Demo
        pico_stdlib
        pico_btstack_ble
        pico_btstack_cyw43
        pico_cyw43_arch_none
        )

# Add the standard include files to the build
target_include_directories(Keyboard_Demo PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
)
pico_btstack_make_gatt_header(Keyboard_Demo PRIVATE "${CMAKE_CURRENT_LIST_DIR}/hog_keyboard_demo.gatt")

pico_add_extra_outputs(Keyboard_Demo)

