# Getting Started

These sections will guide you through a series of steps from configuring development environment to running RP2040 & W6x00 ethernet examples.

- [**Hardware Requirements**](#hardware_requirements)
- [**Development Environment Configuration**](#development_environment_configuration)
- [**Example Structure**](#example_structure)
- [**Example Testing**](#example_testing)



<a name="hardware_requirements"></a>
## Hardware Requirements

- **WIZnet W6x00 Series Evaluation Pico Board**
    - [**W6100-EVB-Pico**][link-w6100-evb-pico]
- **Desktop** or **Laptop**
- **USB Type-B Micro 5 Pin Cable**
- **Ethernet Cable**



<a name="development_environment_configuration"></a>
## Development Environment Configuration

To test the ethernet examples, the development environment must be configured to use W6100-EVB-Pico.

The ethernet examples were tested by configuring the development environment for **Windows**. Please refer to the '**9.2. Building on MS Windows**' section of '**Getting started with Raspberry Pi Pico**' document below and configure accordingly.

- [**Getting started with Raspberry Pi Pico**][link-getting_started_with_raspberry_pi_pico]

**Visual Studio Code** was used during development and testing of ethernet examples, the guide document in each directory was prepared also base on development with Visual Studio Code. Please refer to corresponding document.



<a name="example_structure"></a>
## Example Structure

Examples are available at '**RP2040-v6-HAT-C/examples/**' directory. As of now, following examples are provided.

- [**Loopback**][link-loopback]

Note that **io6Library**, **mbedtls**, **pico-sdk** are needed to run ethernet examples.

- **io6Library** library supports IPv4 and IPv6 and can be applied to WIZnet's W6x00 ethernet chip.
- **mbedtls** library supports additional algorithms and support related to SSL and TLS connections.
- **pico-sdk** is made available by Pico to enable developers to build software applications for the Pico platform.
- **pico-extras** has additional libraries that are not yet ready for inclusion the Pico SDK proper, or are just useful but don't necessarily belong in the Pico SDK.

Libraries are located in the '**RP2040-v6-HAT-C/libraries/**' directory.

- [**io6Library**][link-io6library]
- [**mbedtls**][link-mbedtls]
- [**pico-sdk**][link-pico_sdk]
- [**pico-extras**][link-pico_extras]

If you want to modify the code that MCU-dependent and use a MCU other than **RP2040**, you can modify it in the '**RP2040-v6-HAT-C/port/**' directory.

port is located in the '**RP2040-v6-HAT-C/port/**' directory.

- [**io6Library**][link-port_io6library]
- [**mbedtls**][link-port_mbedtls]
- [**timer**][link-port_timer]



<a name="example_testing"></a>
## Example Testing

1. Download

If the ethernet examples are cloned, the library set as a submodule is an empty directory. Therefore, if you want to download the library set as a submodule together, clone the ethernet examples with the following Git command.

```bash
/* Change directory */
// change to the directory to clone
cd [user path]

// e.g.
cd D:/RP2040

/* Clone */
git clone --recurse-submodules https://github.com/Wiznet/RP2040-v6-HAT-C.git
```

With Visual Studio Code, the library set as a submodule is automatically downloaded, so it doesn't matter whether the library set as a submodule is an empty directory or not, so refer to it.

2. Setup ethetnet chip

Setup the ethernet chip in '**CMakeLists.txt**' in '**RP2040-v6-HAT-C/**' directory according to the evaluation board to be used referring to the following.

**W5x00 series ethernet chips are not supported**, so be careful when setting ethernet chips.

- W6100-EVB-Pico : W6100

For example, when using W6100-EVB-Pico :

```bash
# Set ethernet chip
set(WIZNET_CHIP W6100)
```

3. Test

Please refer to 'README.md' in each example directory to find detail guide for testing ethernet examples.



<!--
Link
-->

[link-w6100-evb-pico]: https://docs.wiznet.io/Product/iEthernet/W6100/w6100-evb-pico
[link-getting_started_with_raspberry_pi_pico]: https://datasheets.raspberrypi.org/pico/getting-started-with-pico.pdf
[link-loopback]: https://github.com/Wiznet/RP2040-v6-HAT-C/tree/main/examples/loopback
[link-io6library]: https://github.com/Wiznet/io6Library
[link-mbedtls]: https://github.com/ARMmbed/mbedtls
[link-pico_sdk]: https://github.com/raspberrypi/pico-sdk
[link-pico_extras]: https://github.com/raspberrypi/pico-extras
[link-port_io6library]: https://github.com/Wiznet/RP2040-v6-HAT-C/tree/main/port/io6Library
[link-port_mbedtls]: https://github.com/Wiznet/RP2040-v6-HAT-C/tree/main/port/mbedtls
[link-port_timer]: https://github.com/Wiznet/RP2040-v6-HAT-C/tree/main/port/timer
