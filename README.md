<div id="top"></div>

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/AndrewLaptev/ble_light_esp32">
    <img src="docs/images/logo.png" alt="Logo" width="125" height="125">
  </a>

<h3 align="center">BLightESP32</h3>

  <p align="center">
    Приложение для управления лампой через микроконтроллер ESP32 по Bluetooth с помощью мобильного приложения
    <br />
    <a href="https://github.com/AndrewLaptev/ble_light_mobile"><strong>ble_light_mobile</strong></a>
    <br />
  </p>
</div>


<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>


<!-- ABOUT THE PROJECT -->
## About

Данное приложение позволяет управлять цветовой температурой и яркостью светодидодной лампы через ШИМ. Управление осуществляется через мобильное приложение [BLight](https://github.com/AndrewLaptev/ble_light_mobile) по Bluetooth Low Energy.

Возможности:
* обеспечение работы сразу нескольких клиентов, подключенных через мобильное приложение BLight
* управление режимом света исходя из предпочтений всех подключенных клиентов (консенсус)
* плавное управление яркостью и цветовой температурой
* авторизация через токен подключенных по GATT клиентов для доступа к сервису управления световыми режимами

### Built With

* [![ESP-IDF][esp-idf-shield]][esp-idf-url]
* [![Cmake][cmake-shield]][cmake-url]
* [![PlatformIO][platformio-shield]][platformio-url]

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- GETTING STARTED -->
## Getting Started

Для запуска приложения необходимо один или несколько микроконтроллеров ESP32 WROOM DevKit v1 (или ESP32 Wemods D1 mini), а также ПК под управлением ОС Ubuntu или Windows

Использование PlatformIO и ESP-IDF возможно как отдельно, так и в качестве интеграции с различными IDE или текстовыми редакторами. 

В данном руководстве будет рассмотрен вариант установки **PlatformIO + ESP-IDF + VSCode на ОС Ubuntu**

### Prerequisites

1. Скачиваем и устанавливаем [VScode](https://code.visualstudio.com/download)

2. В VScode переходим в раздел `Extensions` (расширения), находим PlatformIO и устанавливаем

3. Открываем `PlatformIO->Platforms->Embedded` и в строке поиска пишем `Espressif` и из результатов выбираем `Espressif 32`, устанавливаем версию 4.2.0 (можно и самую новую, но могут возникнуть проблемы с совместимостью)

4. Устанавливаем [правила](https://docs.platformio.org/en/latest/core/installation/udev-rules.html) подсистемы udev для поддерживаемых устройств PlatformIO  

### Installation

1. Клонируем репозиторий
   ```sh
   git clone https://github.com/AndrewLaptev/ble_light_esp32
   ```

2. Открываем скачанный репозиторий в VScode, расширение PlatformIO должно обнаружить проект и открыть доп.функционал в интерфейсе VScode

3. Если нужно настроить проект для сборки, то открываем терминал `PlatformIO:New Terminal` и вводим команду для открытия меню конфигурации проекта
   ```sh
   pio run -t menuconfig
   ```
4. Подключаем микроконтроллер ESP32 к компьютеру и выбираем `PlatformIO:Upload`. После компиляции и загрузки прошивки вывод ее работы будет отображаться в мониторе последовательного вывода

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- USAGE EXAMPLES -->
## Usage

Use this space to show useful examples of how a project can be used. Additional screenshots, code examples and demos work well in this space. You may also link to more resources.

_For more examples, please refer to the [Documentation](https://example.com)_

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- ROADMAP -->
## Roadmap

- [ ] Feature 1
- [ ] Feature 2
- [ ] Feature 3
    - [ ] Nested Feature

See the [open issues](https://github.com/github_username/repo_name/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Your Name - [@twitter_handle](https://twitter.com/twitter_handle) - email@email_client.com

Project Link: [https://github.com/github_username/repo_name](https://github.com/github_username/repo_name)

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* []()
* []()
* []()

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[esp-idf-shield]: https://img.shields.io/badge/ESP--IDF-D5DDDF?style=for-the-badge&logo=espressif
[esp-idf-url]: https://github.com/espressif/esp-idf
[cmake-shield]: https://img.shields.io/badge/Cmake-000000?style=for-the-badge&logo=cmake
[cmake-url]: https://cmake.org
[platformio-shield]: https://img.shields.io/badge/Platformio-FE864C?style=for-the-badge
[platformio-url]: https://platformio.org
