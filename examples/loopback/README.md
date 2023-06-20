# How to Test Loopback Example



## Step 1: Prepare software

The following serial terminal programs are required for Loopback example test, download and install from below links.

- [**Tera Term**][link-tera_term]
- [**Hercules**][link-hercules]
- [**Script Communicator**][link-ScriptCommunicator]


## Step 2: Prepare hardware

If you are using W6100-EVB-Pico, you can skip '1. Combine...'

1. Connect the WIZnet Ethernet module to your Raspberry Pi Pico.

2. Connect an ethernet cable to WIZnet Ethernet module, using the W6100-EVB-Pico ethernet port.

3. Connect the Raspberry Pi Pico and W6100-EVB-Pico to a desktop or laptop using a 5 pin micro USB cable.



## Step 3: Setup Loopback Example

To test the Loopback example, some minor adjustments will be required in the code.

1. Configure the SPI port and pin in the 'w6x00_spi.h' file located in the 'RP2040-v6-HAT-C/port/io6Library/inc/' directory.

Set up the SPI interface that you'll be using.

```cpp
/* SPI */
#define SPI_PORT spi0

#define PIN_SCK     18
#define PIN_MOSI    19
#define PIN_MISO    16
#define PIN_CS      17
#define PIN_RST     20
```

If you intend to experiment with the Loopback example using SPI DMA, ensure that you uncomment the 'USE_SPI_DMA' line.

```cpp
/* Use SPI DMA */
//#define USE_SPI_DMA // if you want to use SPI DMA, uncomment.
```

2. Configure network settings such as IP address in the 'w6x00_loopback.c' file. This file is part of the Loopback example and can be found in the 'RP2040-v6-HAT-C/examples/loopback/' directory.

Configure the IP and other network settings to align with your network environment.

```cpp
/* Network */
static wiz_NetInfo g_net_info =
    {
        .mac = {0x00, 0x08, 0xDC, 0x12, 0x34, 0x56}, // MAC address
        .ip = {192, 168, 11, 2},                     // IP address
        .sn = {255, 255, 255, 0},                    // Subnet Mask
        .gw = {192, 168, 11, 1},                     // Gateway
        .dns = {8, 8, 8, 8},                         // DNS server
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
        .dns6 = {0x20, 0x01, 0x48, 0x60,
                0x48, 0x60, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x88, 0x88},             // DNS6 server
        .ipmode = NETINFO_STATIC_ALL
};
```

3. Setup loopback configuration in the 'w6x00_loopback.c' file located in 'RP2040-v6-HAT-C/examples/loopback/' directory.

```cpp
/* Port */
#define PORT_TCP_SERVER         5000
#define PORT_TCP_CLIENT         5001
#define PORT_TCP_CLIENT_DEST    5002
#define PORT_UDP                5003

#define PORT_TCP_SERVER6        5004
#define PORT_TCP_CLIENT6        5005
#define PORT_TCP_CLIENT6_DEST   5006
#define PORT_UDP6               5007

#define PORT_TCP_SERVER_DUAL    5008
```



## Step 4: Build

1. After you have finished configuring the Loopback example, click on 'Build' located in the status bar at the bottom of Visual Studio Code. Alternatively, you can press the 'F7' key on your keyboard to commence the build process.

2. After the build process is successfully completed, the 'w6x00_loopback.uf2' file will be generated. You can locate this file in the 'RP2040-v6-HAT-C/build/examples/loopback/' directory.



## Step 5: Upload and Run

1. Press and hold the BOOTSEL button on the Raspberry Pi Pico. Then, power on the W6100-EVB-Pico board. Once done, the 'RPI-RP2' USB mass storage device will automatically mount.

![][link-raspberry_pi_pico_usb_mass_storage]

2. Drag and drop 'w6x00_loopback.uf2' into the 'RPI-RP2' USB mass storage device.

3. Connect to the serial COM port of Raspberry Pi Pico, W6100-EVB-Pico with Tera Term.

![][link-connect_to_serial_com_port]

4. Reset your board.

5. If your Raspberry Pi Pico and W6100-EVB-Pico's Loopback example is functioning correctly, you should be able to view the network information and verify that the loopback server is operational.



6. Connect to the open loopback server using a ScriptCommunicator TCP, UDP IPv4, or IPv6 client. Remember to enter the IP address configured in Step 3 when connecting to the loopback server.

![][link-connect_to_loopback_server_tcp_client_ipv4]

![][link-connect_to_loopback_server_tcp_client_ipv6]

7. Once you've established a connection, if you send data to the loopback server, you should be able to receive the same message back.




<!--
Link
-->

[link-tera_term]: https://osdn.net/projects/ttssh2/releases/
[link-hercules]: https://www.hw-group.com/software/hercules-setup-utility
[link-ScriptCommunicator]: https://sourceforge.net/projects/scriptcommunicator/

[link-raspberry_pi_pico_usb_mass_storage]: https://github.com/Wiznet/RP2040-v6-HAT-C/blob/main/static/images/raspberry_pi_pico_usb_mass_storage.png
[link-connect_to_serial_com_port]: https://github.com/Wiznet/RP2040-v6-HAT-C/blob/main/static/images/connect_to_serial_com_port.png

[link-connect_to_loopback_server_tcp_client_ipv4]: https://github.com/Wiznet/RP2040-v6-HAT-C/blob/main/static/images/connect_to_loopback_server_tcp_client_ipv4.png
[link-connect_to_loopback_server_tcp_client_ipv6]: https://github.com/Wiznet/RP2040-v6-HAT-C/blob/main/static/images/connect_to_loopback_server_tcp_client_ipv6.png
