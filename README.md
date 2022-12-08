# RP2040 & W6x00 Ethernet Examples

- [**Overview**](#overview)
- [**Getting Started**](#getting_started)
- [**Directory Structure**](#directory_structure)
- [**Appendix**](#appendix)
    - [**Other Examples**](#other_examples)



<a name="overview"></a>
## Overview

The RP2040 & W6x00 ethernet examples use **W6100-EVB-Pico** - ethernet I/O module built on [**RP2040**][link-rp2040] and WIZnet's [**W6100**][link-w6100] ethernet chip.

- [**W6100-EVB-Pico**][link-w6100-evb-pico]

![][link-w6100-evb-pico_main]



<a name="getting_started"></a>
## Getting Started

Please refer to [**Getting Started**][link-getting_started] for how to configure development environment or examples usage.



<a name="directory_structure"></a>
## Directory Structure

```
RP2040-v6-HAT-C
┣ examples
┃   ┣ AddressAutoConfiguration
┃   ┗ loopback
┣ libraries
┃   ┣ io6Library
┃   ┣ mbedtls
┃   ┣ pico-extras
┃   ┗ pico-sdk
┣ port
┃   ┣ io6Library
┃   ┣ mbedtls
┃   ┗ timer
┗ static
    ┣ documents
    ┗ images
```



<a name="appendix"></a>
## Appendix



<a name="other_examples"></a>
### Other Examples

- C/C++
    - [**RP2040-v6-HAT-FREERTOS-C**][link-rp2040-v6-hat-freertos-c]



<!--
Link
-->

[link-rp2040]: https://www.raspberrypi.org/products/rp2040/
[link-w6100]: https://docs.wiznet.io/Product/iEthernet/W6100/overview
[link-w6100-evb-pico]: https://docs.wiznet.io/Product/iEthernet/W6100/w6100-evb-pico
[link-w6100-evb-pico_main]: https://github.com/Wiznet/RP2040-v6-HAT-C/blob/main/static/images/w6100-evb-pico_main.png
[link-getting_started]: https://github.com/Wiznet/RP2040-v6-HAT-C/blob/main/static/documents/getting_started.md
[link-rp2040-v6-hat-freertos-c]: https://github.com/Wiznet/RP2040-v6-HAT-FREERTOS-C
