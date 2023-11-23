O projeto “Monitoramento de Temperatura e Umidade via WiFi” utilizando o módulo ESP8266 representa uma aplicação clássica da Internet das Coisas (IoT) que facilita o monitoramento e coleta de dados ambientais em tempo real. Utilizando o módulo ESP8266, sensor de temperatura e umidade DHT11 e conectividade WiFi, este projeto estabelece um sistema de medição das condições ambientais e transmissão desses dados para uma plataforma online. Consequentemente, isso permite o acesso remoto e a visualização de informações de temperatura e umidade de qualquer local com conectividade à Internet.

Este é um projeto MQTT, do qual manda informações recebidas pelo ESP para a plataforma online dweet, e a plataforma online freeboard recebe do dweet as informações transformando-as em gráficos vísiveis ao usuário, podendo ser acessado de qualquer lugar do mundo contanto que o ESP permaneça ligado e conectado à rede Wifi.

Materiais necessários:
1 - Módulo ESP8266 NodeMCU V3
2 - Sensor de Temperatura e Umidade DHT11
3 - Protoboard ou Placa de Circuito Impresso (PCI)
4 - Jumpers (fios de conexão)
5 - Fonte de Alimentação USB Micro-USB
6 - Resistor de 10 kΩ
7 - Computador com Acesso à Internet
8 - Plataforma dweet
9 - Plataforma Freeboard
10 - Arduino IDE

Bibliotecas necessárias para o Arduino IDE:
1 - DHT Sensor Library
2 - ESP8266WiFi.h Library

