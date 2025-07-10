#include "DataSender.h"

DataSender::DataSender(const char* serverUrl, const char* apiKey, const char* deviceId, const char* zone)
    : serverUrl(serverUrl), apiKey(apiKey), deviceId(deviceId), zone(zone) {}

void DataSender::sendData(float soilMoisture, float temperature, float humidity) {
    String jsonPayload = "{\"device_id\": \"" + String(deviceId) + "\", "
                         "\"soil_moisture\": " + String(soilMoisture, 1) + ", "
                         "\"temperature\": " + String(temperature, 1) + ", "
                         "\"humidity\": " + String(humidity, 1) + ", "
                         "\"zone\": \"" + String(zone) + "\"}";

    HTTPClient http;
    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/json");
    http.addHeader("x-api-key", apiKey);

    int httpResponseCode = http.POST(jsonPayload);
    if (httpResponseCode > 0) {
        Serial.print("Código de respuesta HTTP: ");
        Serial.println(httpResponseCode);
    } else {
        Serial.print("Error en la solicitud HTTP: ");
        Serial.println(httpResponseCode);
    }
    http.end();
}
