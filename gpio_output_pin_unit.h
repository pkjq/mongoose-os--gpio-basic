/*
 * Copyright (c) 2019 pkjq
 * All rights reserved
 *
 * Licensed under the Apache License, Version 2.0 (the ""License"");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an ""AS IS"" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef GEE2E8589_7D3F_4E98_BE7E_263B8295D3F2
#define GEE2E8589_7D3F_4E98_BE7E_263B8295D3F2


#include "gpio.h"

#include <mgos.h>


namespace gpio
{
namespace output
{
template <bool GpioState_At_StateOn>
class PinUnit
{
private:
    virtual void Turned(bool on)
    {
        (void) on;
    }

public:
    inline explicit PinUnit(Pin pin): pin(pin)
    {
        gpio::ConfidurePinAsOutput(pin, State2GpioLevel(false));
    }

    PinUnit(const PinUnit&) = delete;
    PinUnit(PinUnit&&) = delete;

public:
    inline void Turn(bool on)
    {
        gpio::SetPinLevel(pin, State2GpioLevel(on));
        Turned(on);
    }

    inline bool SheduleTurn(bool on)
    {
        return mgos_invoke_cb(on ? ScheduledTurn_On : ScheduledTurn_Off, this, false);
    }

    inline bool IsOn() const
    {
        return gpio::GetOutputPinLevel(pin);
    }

private:
    static void ScheduledTurn_On(void *ctx)  { static_cast<PinUnit*>(ctx)->TurnOn();  }
    static void ScheduledTurn_Off(void *ctx) { static_cast<PinUnit*>(ctx)->TurnOff(); }

    void TurnOn()   { Turn(true);  }
    void TurnOff()  { Turn(false); }

private:
    static inline constexpr bool State2GpioLevel(bool on);

private:
    const Pin pin;
};


template<>
inline constexpr bool PinUnit<true>::State2GpioLevel(bool on)    { return  on; }
template<>
inline constexpr bool PinUnit<false>::State2GpioLevel(bool on)   { return !on; }
}
}


#endif//GEE2E8589_7D3F_4E98_BE7E_263B8295D3F2
