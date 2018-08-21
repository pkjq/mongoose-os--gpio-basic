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

#ifndef G3B352D8E_8400_4478_86AE_6CBB414CAED2
#define G3B352D8E_8400_4478_86AE_6CBB414CAED2


#include <mgos_gpio.h>


namespace gpio
{
inline void SetPinLevel(Pin pin_, bool level)
{
    const auto pin = static_cast<int>(pin_);
    if (pin == -1)
        return;

    // 1 - enable
    // 0 - disable
    mgos_gpio_write(pin, level);
}

inline void ConfidurePinAsInput(Pin pin_, mgos_gpio_pull_type pull)
{
    const auto pin = static_cast<int>(pin_);
    if (pin == -1)
        return;

    mgos_gpio_set_pull(pin, pull);
    mgos_gpio_set_mode(pin, MGOS_GPIO_MODE_INPUT);
}

inline void ConfidurePinAsOutput(Pin pin_, bool level)
{
    const auto pin = static_cast<int>(pin_);
    if (pin == -1)
        return;

    mgos_gpio_set_mode(pin, MGOS_GPIO_MODE_OUTPUT);
    SetPinLevel(pin_, level);
}
}


#endif//G3B352D8E_8400_4478_86AE_6CBB414CAED2
