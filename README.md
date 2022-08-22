<div id="top"></div>

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/AndrewLaptev/ble_light_esp32">
    <img src="docs/images/logo.png" alt="Logo" width="125" height="125">
  </a>

<h3 align="center">BLightESP32</h3>

  <p align="center">
    Software module for normalization of the psycho-emotional state and personalization of the environment through artificial lighting
  </p>
</div>


<!-- ABOUT THE PROJECT -->
## About

This application allows you to control the color temperature and brightness of the LED lamp via PWM. Management is carried out through the mobile application [BLight](https://github.com/AndrewLaptev/ble_light_mobile) via Bluetooth Low Energy.

### Features:
* ensuring the work of several clients connected through the BLight mobile application at once
* control of the light mode based on the preferences of all connected clients (consensus)
* smooth brightness and color temperature control
* authorization via a token of GATT-connected clients to access the light mode management service

### Built With

* [![ESP-IDF][esp-idf-shield]][esp-idf-url]
* [![Cmake][cmake-shield]][cmake-url]
* [![PlatformIO][platformio-shield]][platformio-url]

### Requirements
* ESP32 WROOM DevKit v1 или ESP32 Wemods D1 mini
* OC Ubuntu/Windows
* VScode
* Platformio

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- GETTING STARTED -->
## Getting Started

To run the application, you need one or more ESP32 WROOM DevKit v1 (или ESP32 Wemods D1 mini) microcontrollers, as well as a PC running Ubuntu or Windows OS

The use of PlatformIO and ESP-IDF is possible both separately and as an integration with various IDE or text editors.

This guide will consider the option of installing **PlatformIO + ESP-IDF + VSCode на ОС Ubuntu**

### Prerequisites

1. Download and install [VScode](https://code.visualstudio.com/download)

2. In VSCode, go to the `Extensions` section and install PlatformIO

3. Open `PlatformIO->Platforms->Embedded` and specify `Expressif` in the search bar, select `Expressif 32` from the results, install version 4.2.0 (you can also install the newest one, but compatibility problems may arise)

4. Install [rules](https://docs.platformio.org/en/latest/core/installation/udev-rules.html) udev subsystems for supported PlatformIO devices

### Installation

1. Clone a repository
   ```sh
   git clone https://github.com/AndrewLaptev/ble_light_esp32
   ```
2. Open the downloaded repository in VSCode, the PlatformIO extension should detect the project and open additional functionality in the VSCode interface

3. If you need to configure the project for assembly, then open the `PlatformIO:New Terminal` and enter a command to open the project configuration menu
   ```sh
   pio run -t menuconfig
   ```
4. Connect the ESP 32 microcontroller to the computer and select `PlatformIO:Upload`. After compiling and downloading the firmware, the output of its operation will be displayed in the serial output monitor

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- DOCUMENTATION -->
## Documentation
This section describes the structure of the project, as well as the main functions of the functional modules and the logic of the application in general.

### Structure and setup
The application is made according to the modular principle. The main application startup code is contained in the file `src/main.c`, in this file there are functions from modules in the folder `lib`.

Файлы настройки:

* `Kconfig.projbuild` - contains application-specific settings that can be edited before compilation via the settings menu `pio run -t menuconfig`

* `partitions.csv` - it contains the memory layout in the microcontroller, in this case it is expanded from the standard 1 MB to 2 MB.

* `platformio.ini` - responsible for setting up the entire project, for a more detailed study, refer to the [manual](https://docs.platformio.org/page/projectconf.html)

* `sdkconfig.defaults` - contains the general ESP-IDF settings, which are set by default

### Modules
This section describes the basic functionality of all modules, without in-depth analysis of all structures and standard features of working with ESP-IDF, FreeRTOS and ESP-32.

#### common
Provides access to the main parameters of the application to other modules, implements the structures necessary for Bluetooth operation, as well as functions for working with GATT and GAP.

#### connections
Implements a database of multiple connections of mobile devices with a microcontroller. Provides full database management: creating and deleting records, changing the values of light modes (brightness and color temperature).

#### ledc_control
Provides interaction with the connected lamp via two PWM channels: one channel for controlling the cold temperature LED, the second channel for controlling the warm temperature LED. Implements a smooth transition between temperature and brightness values.

#### service_auth
Implements the GATT event handler function, which creates the GATT service `Authentication` with the characteristic `Authorization data`. This function processes all events related to reading/writing/indication/notification of authentication characteristics, and it also enters the connection into the database of connections of the `connections` module.

#### service_light
Implements the GATT event handler function, which creates the GATT service `Light manage` with the characteristic `Level of light`. This function processes all events related to reading/writing/indication/notification of authentication characteristics, and it also enters the connection into the database of connections of the `connections` module. The `consensus_light_set` function controls the consensus light mode, i.e. when several users with their own light modes connect to one microcontroller, this function finds the average value between all the consensus modes. When the user disconnects, the consensus is recalculated.


<!-- ACKNOWLEDGMENTS -->
## Acknowledgments
The application was developed within the framework of the research project "Development of mechanisms for designing the processes of users' vital activity into the ecosystem of their digital assistants" No. 621308

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[esp-idf-shield]: https://img.shields.io/badge/ESP--IDF-D5DDDF?style=for-the-badge&logo=espressif
[esp-idf-url]: https://github.com/espressif/esp-idf
[cmake-shield]: https://img.shields.io/badge/Cmake-000000?style=for-the-badge&logo=cmake
[cmake-url]: https://cmake.org
[platformio-shield]: https://img.shields.io/badge/Platformio-FE864C?style=for-the-badge
[platformio-url]: https://platformio.org
