# io6Library
add_library(IOLIBRARY6_FILES STATIC)

target_sources(IOLIBRARY6_FILES PUBLIC
        ${PORT_DIR}/io6Library/src/w6x00_spi.c
        ${PORT_DIR}/io6Library/src/w6x00_gpio_irq.c
        )

target_include_directories(IOLIBRARY6_FILES PUBLIC
        ${WIZNET6_DIR}/Ethernet
        ${PORT_DIR}/io6Library/inc
        ${PORT_DIR}
        )

target_link_libraries(IOLIBRARY6_FILES PRIVATE
        pico_stdlib
        hardware_spi
        hardware_dma
        hardware_clocks
        )

# timer
add_library(TIMER_FILES STATIC)

target_sources(TIMER_FILES PUBLIC
        ${PORT_DIR}/timer/timer.c
        )

target_include_directories(TIMER_FILES PUBLIC
        ${PORT_DIR}/timer
        )

target_link_libraries(TIMER_FILES PRIVATE
        pico_stdlib      
        )
