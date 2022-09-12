//  Copyright 2022 Google LLC
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#pragma once

#include <stdbool.h>

// wifi_init initializes the WiFi in STA mode with the credentials specified in "secrets.h", and connects asychronously.
bool wifi_init(void);

// wifi_tick calls the internal polling function to allow the network stack to make progress.
void wifi_tick(void);

// wifi_connected returns true if the WiFi is connected.
bool wifi_connected(void);