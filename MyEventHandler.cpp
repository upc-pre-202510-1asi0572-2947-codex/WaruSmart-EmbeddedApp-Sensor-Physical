#include "MyEventHandler.h"
#include <Arduino.h>
#include "DHTSensor.h"
#include "SoilMoistureSensor.h" 

MyEventHandler::MyEventHandler() {
    // Aquí puedes realizar alguna inicialización si es necesario
}

void MyEventHandler::on(const Event& event) {
    // Manejo del evento de lectura de temperatura
    if (event == DHTSensor::TEMP_READING_EVENT) {
        Serial.println("Evento: Lectura de temperatura realizada");
    }
    // Manejo del evento de lectura de humedad
    if (event == DHTSensor::HUM_READING_EVENT) {
        Serial.println("Evento: Lectura de humedad realizada");
    }
    // Manejo del evento de lectura de humedad del suelo
    if (event == SoilMoistureSensor::SOIL_MOISTURE_READING_EVENT) {
        Serial.println("Evento: Lectura de humedad del suelo realizada");
    }
}
