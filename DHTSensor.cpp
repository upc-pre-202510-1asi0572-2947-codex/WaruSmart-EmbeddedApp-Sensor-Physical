#include "DHTSensor.h"
#include <Arduino.h>

DHTSensor::DHTSensor(int pin, EventHandler* handler)
    : Sensor(pin, handler), dht(pin, DHT11), lastTemp(NAN), lastHumidity(NAN) {
    dht.begin();
}
const Event DHTSensor::TEMP_READING_EVENT = Event(TEMP_READING_EVENT_ID);
const Event DHTSensor::HUM_READING_EVENT = Event(HUM_READING_EVENT_ID);


float DHTSensor::getTemp() const{
  return lastTemp;
}

float DHTSensor::getHum() const {
  return lastHumidity;
}

void DHTSensor::poll() {
    float t = dht.readTemperature();
    float h = dht.readHumidity();

    if (isnan(t)) {
        Serial.println("Error: No se pudo leer temperatura.");
        return;
    }

    lastTemp = t;

    if (handler != nullptr) {
        Event tempEvent(TEMP_READING_EVENT_ID);
        handler->on(tempEvent);
    }

    if (!isnan(h)) {
        lastHumidity = h;  // Store last valid humidity

        // Emit event for humidity reading if handler is provided
        if (handler != nullptr) {
            Event humEvent(HUM_READING_EVENT_ID);
            handler->on(humEvent);  // Pass the event to the handler
        }
    } else {
        Serial.println("Error: No se pudo leer humedad.");
    }
}
