<h1 align="center">
   <br>
	Простой робот для работы с openCV
  <br>
</h1>



## Основные детали тележки
* Raspberry Pi 4 2GB;
* веб-камера;
* приобразователь usb uart;  
* esp32 devkit v1;
* Драйвер двигателей L9110S;
* 4x желтые ардуино TT-мотор-редукторы;
* powerbank;


## Настройка Raspberry Pi

### Подключаемся к точке доступа
```shell
sudo armbian-config
```
Переходим в **Network->WiFi**, выбираем нужную точку доступа,
вводим пароль и подключаемся к ней.    
Чтобы узнать свой ip-адресс вводим 
```shell
ifconfig
```

### Установка зависимостей
Обновляемся:
```shell
sudo apt update; sudo apt upgrade
```
Загружаем питоновый менеджер пакетов и вспомогательные пакеты
```shell
sudo apt install python3-dev python3-pip python3-numpy
```
Загружаем еще немного зависимостей
```shell
pip3 install --upgrade pip setuptools wheel
pip3 install flask pyserial 
```
Загружаем openCV
```shell
sudo apt install python3-opencv
```

### Запуск приложения
Скачиваем репозиторий проекта
```shell
git clone https://github.com/hakgr1d/CVbot.git
```
и запускаем приложение
```shell
cd CVbot/python_app
python3 app.py -i (ip-адресс orange pi) -p (порт) -s (последовательный порт)
```
Открываем браузер и вводим в нем 
```shell
(ip-адресс orange pi):(порт)
```
Например так:
```shell
192.168.42.1:5000
```     
