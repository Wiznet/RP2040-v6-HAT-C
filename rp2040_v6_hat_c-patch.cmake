# CMake minimum required version
cmake_minimum_required(VERSION 3.12)

# Find git
find_package(Git)

if(NOT Git_FOUND)
	message(FATAL_ERROR "Could not find 'git' tool for RP2040-v6-HAT-C patching")
endif()

message("RP2040-v6-HAT-C patch utils found")

set(RP2040_V6_HAT_C_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(IO6LIBRARY_SRC_DIR "${RP2040_V6_HAT_C_SRC_DIR}/libraries/io6Library")
set(MBEDTLS_SRC_DIR "${RP2040_V6_HAT_C_SRC_DIR}/libraries/mbedtls")
set(PICO_EXTRAS_SRC_DIR "${RP2040_V6_HAT_C_SRC_DIR}/libraries/pico-extras")
set(PICO_SDK_SRC_DIR "${RP2040_V6_HAT_C_SRC_DIR}/libraries/pico-sdk")
set(PICO_SDK_TINYUSB_SRC_DIR "${RP2040_V6_HAT_C_SRC_DIR}/libraries/lib/tinyusb")
set(RP2040_HAT_C_PATCH_DIR "${RP2040_V6_HAT_C_SRC_DIR}/patches")

# Delete untracked files in io6Library
if(EXISTS "${IO6LIBRARY_SRC_DIR}/.git")
	message("cleaning io6Library...")
	execute_process(COMMAND ${GIT_EXECUTABLE} -C ${IO6LIBRARY_SRC_DIR} clean -fdx)
	execute_process(COMMAND ${GIT_EXECUTABLE} -C ${IO6LIBRARY_SRC_DIR} reset --hard)
	message("io6Library cleaned")
endif()

# Delete untracked files in mbedtls
if(EXISTS "${MBEDTLS_SRC_DIR}/.git")
	message("cleaning mbedtls...")
	execute_process(COMMAND ${GIT_EXECUTABLE} -C ${MBEDTLS_SRC_DIR} clean -fdx)
	execute_process(COMMAND ${GIT_EXECUTABLE} -C ${MBEDTLS_SRC_DIR} reset --hard)
	message("mbedtls cleaned")
endif()

# Delete untracked files in pico-extras
if(EXISTS "${PICO_EXTRAS_SRC_DIR}/.git")
	message("cleaning pico-extras...")
	execute_process(COMMAND ${GIT_EXECUTABLE} -C ${PICO_EXTRAS_SRC_DIR} clean -fdx)
	execute_process(COMMAND ${GIT_EXECUTABLE} -C ${PICO_EXTRAS_SRC_DIR} reset --hard)
	message("pico-extras cleaned")
endif()

# Delete untracked files in pico-sdk
if(EXISTS "${PICO_SDK_SRC_DIR}/.git")
	message("cleaning pico-sdk...")
	execute_process(COMMAND ${GIT_EXECUTABLE} -C ${PICO_SDK_SRC_DIR} clean -fdx)
	execute_process(COMMAND ${GIT_EXECUTABLE} -C ${PICO_SDK_SRC_DIR} reset --hard)
	message("pico-sdk cleaned")
endif()

execute_process(COMMAND ${GIT_EXECUTABLE} -C ${RP2040_V6_HAT_C_SRC_DIR} submodule update --init)

# Delete untracked files in tinyusb
if(EXISTS "${PICO_SDK_TINYUSB_SRC_DIR}/.git")
	message("cleaning pico-sdk tinyusb...")
	execute_process(COMMAND ${GIT_EXECUTABLE} -C ${PICO_SDK_TINYUSB_SRC_DIR} clean -fdx)
	execute_process(COMMAND ${GIT_EXECUTABLE} -C ${PICO_SDK_TINYUSB_SRC_DIR} reset --hard)
	message("pico-sdk tinyusb cleaned")
endif()

execute_process(COMMAND ${GIT_EXECUTABLE} -C ${PICO_SDK_SRC_DIR} submodule update --init)
