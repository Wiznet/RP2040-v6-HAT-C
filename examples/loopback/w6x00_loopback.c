/**
 * Copyright (c) 2021 WIZnet Co.,Ltd
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * ----------------------------------------------------------------------------------------------------
 * Includes
 * ----------------------------------------------------------------------------------------------------
 */
#include <stdio.h>

#include "port_common.h"

#include "wizchip_conf.h"
#include "w6x00_spi.h"

#include "loopback.h"

/**
 * ----------------------------------------------------------------------------------------------------
 * Macros
 * ----------------------------------------------------------------------------------------------------
 */
/* Clock */
#define PLL_SYS_KHZ (133 * 1000)

/* Buffer */
#define ETHERNET_BUF_MAX_SIZE (1024 * 2)

/* Socket */
#define SOCKET_TCP_SERVER 0
#define SOCKET_TCP_CLIENT 1
#define SOCKET_UDP 2
#define SOCKET_TCP_SERVER6 3
#define SOCKET_TCP_CLIENT6 4
#define SOCKET_UDP6 5

/* Port */
#define PORT_TCP_SERVER 5000
#define PORT_TCP_CLIENT 5001
#define PORT_UDP 5002
#define PORT_TCP_SERVER6 5004
#define PORT_TCP_CLIENT6 5005
#define PORT_UDP6 5006

#define IPV4
#define IPV6
#define TCP_SERVER
#define TCP_CLIENT
#define UDP
#define TCP_SERVER6
#define TCP_CLIENT6
#define UDP6

/**
 * ----------------------------------------------------------------------------------------------------
 * Variables
 * ----------------------------------------------------------------------------------------------------
 */
/* Network */
static wiz_NetInfo g_net_info =
    {
        .mac = {0x00, 0x08, 0xDC, 0x12, 0x34, 0x56}, // MAC address
        .ip = {192, 168, 11, 2},                     // IP address
        .sn = {255, 255, 255, 0},                    // Subnet Mask
        .gw = {192, 168, 11, 1},                     // Gateway
        .dns = {8, 8, 8, 8},                         // DNS server
#ifdef IPV6
        .lla = {0xfe, 0x80, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x02, 0x08, 0xdc, 0xff,
                0xfe, 0x57, 0x57, 0x25},             // Link Local Address
        .gua = {0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00},             // Global Unicast Address
        .sn6 = {0xff, 0xff, 0xff, 0xff,
                0xff, 0xff, 0xff, 0xff,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00},             // IPv6 Prefix
        .gw6 = {0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00},             // Gateway IPv6 Address
#endif
#if defined IPV4 && defined IPV6
        .ipmode = NETINFO_STATIC_ALL                 // Static IPv4 / IPv6
#elif defined IPV4
        .ipmode = NETINFO_STATIC_V4                  // Static IPv4
#elif defined IPV6
        .ipmode = NETINFO_STATIC_V6                  // Static IPv6
#endif
};

uint8_t tcp_client_destip[] = {
    192, 168, 11, 3
};

uint8_t tcp_client_destip6[] = {
    0xfe, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x02, 0x08, 0xdc, 0xff,
    0xfe, 0x57, 0x57, 0x24
};

uint16_t tcp_client_destport = 5003;

uint16_t tcp_client_destport6 = 5007;

/* Loopback */
static uint8_t g_tcp_server_buf[ETHERNET_BUF_MAX_SIZE] = {
    0,
};
static uint8_t g_tcp_client_buf[ETHERNET_BUF_MAX_SIZE] = {
    0,
};
static uint8_t g_udp_buf[ETHERNET_BUF_MAX_SIZE] = {
    0,
};
static uint8_t g_tcp_server6_buf[ETHERNET_BUF_MAX_SIZE] = {
    0,
};
static uint8_t g_tcp_client6_buf[ETHERNET_BUF_MAX_SIZE] = {
    0,
};
static uint8_t g_udp6_buf[ETHERNET_BUF_MAX_SIZE] = {
    0,
};

/**
 * ----------------------------------------------------------------------------------------------------
 * Functions
 * ----------------------------------------------------------------------------------------------------
 */
/* Clock */
static void set_clock_khz(void);

/**
 * ----------------------------------------------------------------------------------------------------
 * Main
 * ----------------------------------------------------------------------------------------------------
 */
int main()
{
    /* Initialize */
    int retval = 0;

    set_clock_khz();

    stdio_init_all();

    sleep_ms(1000 * 3);

    printf("==========================================================\n");
    printf("Compiled @ %s, %s\n", __DATE__, __TIME__);
    printf("==========================================================\n");

    wizchip_spi_initialize();
    wizchip_cris_initialize();

    wizchip_reset();
    wizchip_initialize();
    wizchip_check();

    network_initialize(g_net_info);

    /* Get network information */
    print_network_information(g_net_info);

    /* Infinite loop */
    while (1)
    {
#ifdef TCP_SERVER
        /* TCP server loopback test */
        if ((retval = loopback_tcps(SOCKET_TCP_SERVER, g_tcp_server_buf, PORT_TCP_SERVER, AS_IPV4)) < 0)
        {
            printf(" loopback_tcps error : %d\n", retval);

            while (1)
                ;
        }
#endif
#ifdef TCP_CLIENT
        /* TCP client loopback test */
        if ((retval = loopback_tcpc(SOCKET_TCP_CLIENT, g_tcp_client_buf, tcp_client_destip, tcp_client_destport, AS_IPV4)) < 0)
        {
            printf(" loopback_tcpc error : %d\n", retval);

            while (1)
                ;
        }
#endif
#ifdef UDP
        /* UDP loopback test */
        if ((retval = loopback_udps(SOCKET_UDP, g_udp_buf, PORT_UDP, AS_IPV4)) < 0)
        {
            printf(" loopback_udps error : %d\n", retval);

            while (1)
                ;
        }
#endif
#ifdef TCP_SERVER6
        /* TCP server loopback test */
        if ((retval = loopback_tcps(SOCKET_TCP_SERVER6, g_tcp_server6_buf, PORT_TCP_SERVER6, AS_IPV6)) < 0)
        {
            printf(" loopback_tcps IPv6 error : %d\n", retval);

            while (1)
                ;
        }
#endif
#ifdef TCP_CLIENT6
        /* TCP client loopback test */
        if ((retval = loopback_tcpc(SOCKET_TCP_CLIENT6, g_tcp_client6_buf, tcp_client_destip6, tcp_client_destport6, AS_IPV6)) < 0)
        {
            printf(" loopback_tcpc IPv6 error : %d\n", retval);

            while (1)
                ;
        }
#endif
#ifdef UDP6
        /* UDP loopback test */
        if ((retval = loopback_udps(SOCKET_UDP6, g_udp6_buf, PORT_UDP6, AS_IPV6)) < 0)
        {
            printf(" loopback_udps IPv6 error : %d\n", retval);

            while (1)
                ;
        }
#endif
    }
}

/**
 * ----------------------------------------------------------------------------------------------------
 * Functions
 * ----------------------------------------------------------------------------------------------------
 */
/* Clock */
static void set_clock_khz(void)
{
    // set a system clock frequency in khz
    set_sys_clock_khz(PLL_SYS_KHZ, true);

    // configure the specified clock
    clock_configure(
        clk_peri,
        0,                                                // No glitchless mux
        CLOCKS_CLK_PERI_CTRL_AUXSRC_VALUE_CLKSRC_PLL_SYS, // System PLL on AUX mux
        PLL_SYS_KHZ * 1000,                               // Input frequency
        PLL_SYS_KHZ * 1000                                // Output (must be same as no divider)
    );
}
