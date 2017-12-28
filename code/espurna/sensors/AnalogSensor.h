// -----------------------------------------------------------------------------
// Analog Sensor (maps to an analogRead)
// Copyright (C) 2017 by Xose Pérez <xose dot perez at gmail dot com>
// -----------------------------------------------------------------------------

#if SENSOR_SUPPORT && ANALOG_SUPPORT

#pragma once

#include "Arduino.h"
#include "BaseSensor.h"

class AnalogSensor : public BaseSensor {

    public:

        // ---------------------------------------------------------------------
        // Public
        // ---------------------------------------------------------------------

        AnalogSensor(): BaseSensor() {
            _count = 1;
            _sensor_id = SENSOR_ANALOG_ID;
        }

        // ---------------------------------------------------------------------
        // Sensor API
        // ---------------------------------------------------------------------

        // Initialization method, must be idempotent
        void begin() {
            pinMode(0, INPUT);
        }

        // Descriptive name of the sensor
        String description() {
            return String("ANALOG @ GPIO0");
        }

        // Type for slot # index
        unsigned char type(unsigned char index) {
            _error = SENSOR_ERROR_OK;
            if (index == 0) return MAGNITUDE_ANALOG;
            _error = SENSOR_ERROR_OUT_OF_RANGE;
            return MAGNITUDE_NONE;
        }

        // Current value for slot # index
        double value(unsigned char index) {
            _error = SENSOR_ERROR_OK;
            if (index == 0) return analogRead(0);
            _error = SENSOR_ERROR_OUT_OF_RANGE;
            return 0;
        }


};

#endif // SENSOR_SUPPORT && ANALOG_SUPPORT
