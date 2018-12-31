/*
 * Copyright (c) 2018 pkjq
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

#ifndef GC9CAD201_29E4_488A_A310_E2D2B66FABAB
#define GC9CAD201_29E4_488A_A310_E2D2B66FABAB


#include "gpio_impl.h"


namespace gpio
{
namespace output
{
template <bool inverse>
class Unit
{
public:
    inline explicit Unit(Pin pin): pin(pin)
    {
        gpio::ConfidurePinAsOutput(pin, State2GpioLevel(false));
    }

    Unit(const Unit&) = delete;
    Unit(Unit&&) = delete;

public:
    inline void Turn(bool on)
    {
        gpio::SetPinLevel(pin, State2GpioLevel(on));
    }

    inline bool IsOn() const
    {
        return State2GpioLevel(gpio::GetOutputPinLevel(pin));
    }

private:
    static inline constexpr bool State2GpioLevel(bool on) { return on ^ inverse; }

private:
    const Pin pin;
};
}
}


#endif//GC9CAD201_29E4_488A_A310_E2D2B66FABAB
