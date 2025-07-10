#include <Arduino.h>
#include "WiFiManager.h"
#include "DHTSensor.h"
#include "SoilMoistureSensor.h"
#include "DataSender.h"
#include "EventHandler.h"
#include "MyEventHandler.h"

// Definiciones de pines y parámetros
#define DHTPIN 14
#define DHTTYPE DHT11
#define SOIL_MOISTURE_PIN 34
const char* ssid = "Galaxy A12 313E";
const char* password = "jpvm6020";
const char* serverUrl = "http://10.146.252.109:5000/api/v1/monitoring/device-metrics";
const char* api_key = "test-api-key-123";
const char* device_id = "waru-smart-001";
const char* zone = "A";

// Instanciación de objetos
WiFiManager wifiManager(ssid, password);
DHTSensor dhtSensor(DHTPIN, nullptr);
SoilMoistureSensor soilSensor(SOIL_MOISTURE_PIN, nullptr);
DataSender dataSender(serverUrl, api_key, device_id, zone);

MyEventHandler myHandler;

void setup() {
    Serial.begin(115200);
    wifiManager.connect();
    Serial.print("IP del ESP32: ");
    Serial.println(wifiManager.getLocalIP());

    // Asignamos el EventHandler
    dhtSensor = DHTSensor(DHTPIN, &myHandler);  // Le asignamos el manejador de eventos
    soilSensor = SoilMoistureSensor(SOIL_MOISTURE_PIN, &myHandler);  // Igualmente para humedad del suelo
}

void loop() {
    // Llama a la función poll() para leer los sensores
    dhtSensor.poll();
    soilSensor.poll();

    // Leer los datos de los sensores
    float temperatura = dhtSensor.getTemp();
    float humedad = dhtSensor.getHum();
    float soilMoisture = soilSensor.getSoilMoisture();

    // Imprimir los valores
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.print(" °C\t");
    Serial.print("Humedad: ");
    Serial.print(humedad);
    Serial.print(" %\t");
    Serial.print("Humedad del suelo: ");
    Serial.println(soilMoisture);

    // Enviar los datos al backend
    dataSender.sendData(soilMoisture, temperatura, humedad);

    // Espera antes de la próxima lectura
    delay(30000);  // Espera 5 segundos entre lecturas
}
