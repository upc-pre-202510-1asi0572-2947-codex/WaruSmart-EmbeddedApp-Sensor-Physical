#include "SoilMoistureSensor.h"
#include <Arduino.h>

SoilMoistureSensor::SoilMoistureSensor(int pin, EventHandler* handler)
    : Sensor(pin, handler), lastSoilMoisture(NAN) {
    pinMode(pin, INPUT);
}

const Event SoilMoistureSensor::SOIL_MOISTURE_READING_EVENT = Event(SOIL_MOISTURE_READING_EVENT_ID);

float SoilMoistureSensor::getSoilMoisture() const {
    return lastSoilMoisture;
}

void SoilMoistureSensor::poll() {
    int soilMoistureValue = analogRead(pin);
    lastSoilMoisture = map(soilMoistureValue, 0, 4095, 0, 100);

    if (handler != nullptr) {
        Event soilMoistureEvent(SOIL_MOISTURE_READING_EVENT_ID);
        handler->on(soilMoistureEvent);
    }
}
