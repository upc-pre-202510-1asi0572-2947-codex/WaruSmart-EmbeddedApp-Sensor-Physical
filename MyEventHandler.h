#ifndef MY_EVENT_HANDLER_H
#define MY_EVENT_HANDLER_H

#include "EventHandler.h"

/**
 * @brief Clase que implementa la interfaz `EventHandler` para manejar los eventos.
 */
class MyEventHandler : public EventHandler {
public:
    // Constructor
    MyEventHandler();

    // Implementación del método 'on' para manejar eventos
    void on(const Event& event) override;
};

#endif // MY_EVENT_HANDLER_H
