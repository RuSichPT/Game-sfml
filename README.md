# Game-sfml

## Обзор
Тестовый проект представляет собой 2D игру.
### Cуть игры 
После расстановки фигур на шахматной доске по очереди ходит игрок и AI.  
Во время хода каждый может переместить одну фигуру. Фигуры можно перемещать только на одну клетку (вверх, вниз, влево, вправо).  
В одну клетку можно поставить только одну фигуру. Побеждает тот, кто первый расставит все свои фигуры на место фигур противника.

Расстановка фигур в начале игры:  
![Расстановка фигур в начале игры](https://lh3.googleusercontent.com/u/0/docs/ADP-6oEE_FhZSoFraNZegp2oUI692neK984BIE8S2KYvzByJ48LUeJjXnipXj1IJyBYjyooKxta6vbnjkPaPP3Y6z9Avn-P5_o58JIaPmuRm_JuSKC8Jxrb9UbREnUmqOTOCtcnke6pKHZBM1xjpXagOGNsrYRX03ec-odUlsNPPtMTLMJYGLJSgbnXv73ksq4pJCzJj9xJlLnHbgRR7GS3LVdAIjqyFO5iHVDbmc518LjUeRbbzd4ddS6H-Ahg5UOlCWOg-aSOIafqh9sbfgxh1IOD8K6B7Y32CM0pE4hNKLkqpG4AmYVoaSEbGE1OoN9uINLpdbVjWX5JZG5xxn5G4LZqHfrP0M3dUqpSnVTgK0NqxcSU4cWiYMcLaCxmd2RXiKcBhB41vEYjVDJLDbwmzkV7Q5gG9wcO1IV9ya7z2RvTaNy4mBW1LGCR9yQNMOeYNOzvM4ffSkbD5XgHS6OGx2UPYSa_0fRbAiezi6tLMBUVbhIEmFNBWI8WTDy63fCDZLqzKW4xg_jyxJQbq6pDKNfeQyuqD_mpXgr-jpy-vv-W-QhvS9WxPo-2IY-9gIpkqhLVCmRjQ4KU7lxLhX_B6-Xrl5Pc8eJV0-1vaZajfdvZSKvNMFoXML7kv8a898pPZT-AAoP5yKBiHnwZM4IAdbhZaLHVeaqOp-I-w9iNrN8Eso2qb_YIPyCSmfOoOQ9q51NX2Bind4Hbf5lKTbOkwxeGZV_Dk4suhyDvHHLCFMQAxSNNHXstREycgHPs16UaRiLhcsAVu6tCi36tudnAkQiJvpdHZXS1a51-lCCtRTNCfMhCP9fgVomp0uea0bqmfozs7QngjuAEQ-lRnXx6fk07j4Jj2fDQRIE24G1yNjEJKXw0ef1FIAjB48beNbepXO31n2JItacVgXRxYBUaTv9Xf7tnQAgdpB-r2JxrXwXSQOFJWjN-mMqAIbhQ=s800)  

Управление фигурами с помощью мыши.

### Использованные технологии
- С++ 17
- SFML

## Установка библиотеки SFML через пакетный менеджер vcpkg:
### 1. Установить vcpkg
#### Шаг 1. Клонируйте репозиторий vcpkg
    git clone https://github.com/Microsoft/vcpkg.git
#### Шаг 2. Запустите скрипт начальной загрузки для сборки vcpkg.
    .\vcpkg\bootstrap-vcpkg.bat
### 2. Установите библиотеку для вашего проекта x86 или x64 
x86:

    vcpkg install sfml    
x64:

    vcpkg install sfml:x64-windows
### 3. Использование vcpkg с MSBuild/Visual Studio (может потребоваться повышение прав)
    vcpkg integrate install
    
Более подробная инструкция здесь https://vcpkg.io/en/getting-started.html
