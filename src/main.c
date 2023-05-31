/* Copyright 2022, Laboratorio de Microprocesadores
 * Facultad de Ciencias Exactas y Tecnología
 * Universidad Nacional de Tucuman
 * http://www.microprocesadores.unt.edu.ar/
 * Copyright 2023, Guillermo Nicolás Brito <guillermonbrito@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/** \brief Ejemplo del uso de HAL y board support.
 *
 * En este trabajo pŕactico se crea e implementa una HAL y Board Support diseñada para la placa
 *EDU-CIAA_NXP
 *
 ** \addtogroup main MAIN
 ** \brief Ejemplo del uso de entradas y salidas digitales de la placa EDU-CIAA-NXP
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include "digital.h"
#include "chip.h"
#include "bsp.h"
#include <stdbool.h>

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================= */

int main(void)
{
    int divisor = 0;

    board_t board = BoardCreate();

    /******************/

    while (true)
    {
        if (DigitalInputGetState(board->tec_1))
        {
            DigitalOutputActivate(board->led_b);
        }
        else
        {
            DigitalOutputDeactivate(board->led_b);
        }

        if (DigitalInputHasActivated(board->tec_2))
        {
            DigitalOutputToggle(board->led_1);
        }

        if (DigitalInputGetState(board->tec_3))
        {
            DigitalOutputActivate(board->led_2);
        }
        if (DigitalInputGetState(board->tec_4))
        {
            DigitalOutputDeactivate(board->led_2);
        }

        divisor++;
        if (divisor == 5)
        {
            divisor = 0;
            DigitalOutputToggle(board->led_3);
        }

        for (int index = 0; index < 100; index++)
        {
            for (int delay = 0; delay < 25000; delay++)
            {
                __asm("NOP");
            }
        }
    }
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
