#ifndef SOIL_MOISTURE_SENSOR_H
#define SOIL_MOISTURE_SENSOR_H

#include "Sensor.h"
#include "EventHandler.h"

class SoilMoistureSensor : public Sensor {
private:
    float lastSoilMoisture;

public:
    static const int SOIL_MOISTURE_READING_EVENT_ID = 3; 
    static const Event SOIL_MOISTURE_READING_EVENT;

    /**
     * @brief Constructor del sensor de humedad del suelo.
     * @param pin GPIO del sensor de humedad del suelo.
     * @param handler Event handler opcional.
     */
    SoilMoistureSensor(int pin, EventHandler* handler = nullptr);

    float getSoilMoisture() const;

    /**
     * @brief Realiza una lectura del sensor y emite un evento.
     */
    void poll();
};

#endif
