<div id="top"></div>

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/AndrewLaptev/ble_light_esp32">
    <img src="docs/images/logo.png" alt="Logo" width="125" height="125">
  </a>

<h3 align="center">BLightESP32</h3>

  <p align="center">
    Программный модуль нормализации психоэмоционального состояния и персонализации окружающей среды через искусственное освещение
  </p>
</div>


<!-- ABOUT THE PROJECT -->
## About

Данное приложение позволяет управлять цветовой температурой и яркостью светодидодной лампы через ШИМ. Управление осуществляется через мобильное приложение [BLight](https://github.com/AndrewLaptev/ble_light_mobile) по Bluetooth Low Energy.

### Features:
* обеспечение работы сразу нескольких клиентов, подключенных через мобильное приложение BLight
* управление режимом света исходя из предпочтений всех подключенных клиентов (консенсус)
* плавное управление яркостью и цветовой температурой
* авторизация через токен подключенных по GATT клиентов для доступа к сервису управления световыми режимами

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

Для запуска приложения необходимо один или несколько микроконтроллеров ESP32 WROOM DevKit v1 (или ESP32 Wemods D1 mini), а также ПК под управлением ОС Ubuntu или Windows

Использование PlatformIO и ESP-IDF возможно как отдельно, так и в качестве интеграции с различными IDE или текстовыми редакторами. 

В данном руководстве будет рассмотрен вариант установки **PlatformIO + ESP-IDF + VSCode на ОС Ubuntu**

### Prerequisites

1. Скачать и установить [VScode](https://code.visualstudio.com/download)

2. В VScode перейти в раздел `Extensions` (расширения), и установить PlatformIO

3. Открыть `PlatformIO->Platforms->Embedded` и в строке поиска указать `Espressif`, из результатов выбрать `Espressif 32`, установить версию 4.2.0 (можно и самую новую, но могут возникнуть проблемы с совместимостью)

4. Установвить [правила](https://docs.platformio.org/en/latest/core/installation/udev-rules.html) подсистемы udev для поддерживаемых устройств PlatformIO

### Installation

1. Клонировать репозиторий
   ```sh
   git clone https://github.com/AndrewLaptev/ble_light_esp32
   ```
2. Открыть скачанный репозиторий в VScode, расширение PlatformIO должно обнаружить проект и открыть доп.функционал в интерфейсе VScode

3. Если нужно настроить проект для сборки, то открыть терминал `PlatformIO:New Terminal` и ввести команду для открытия меню конфигурации проекта
   ```sh
   pio run -t menuconfig
   ```
4. Подключить микроконтроллер ESP32 к компьютеру и выбрать `PlatformIO:Upload`. После компиляции и загрузки прошивки вывод ее работы будет отображаться в мониторе последовательного вывода

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- ACKNOWLEDGMENTS -->
## Acknowledgments
Приложение разработано в рамках НИР "Разработка механизмов проекцирования процессов жизнедеятельности пользователей в экосистему их цифровых ассистентов" №621308

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[esp-idf-shield]: https://img.shields.io/badge/ESP--IDF-D5DDDF?style=for-the-badge&logo=espressif
[esp-idf-url]: https://github.com/espressif/esp-idf
[cmake-shield]: https://img.shields.io/badge/Cmake-000000?style=for-the-badge&logo=cmake
[cmake-url]: https://cmake.org
[platformio-shield]: https://img.shields.io/badge/Platformio-FE864C?style=for-the-badge
[platformio-url]: https://platformio.org
