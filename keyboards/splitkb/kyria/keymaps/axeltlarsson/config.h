/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// Elite-C rev4: use USB detection to determine master/slave
#define SPLIT_USB_DETECT
// Auto-reboot slave if split communication drops (e.g. USB hub power cycles)
#define SPLIT_WATCHDOG_ENABLE

// Flash with `make splitkb/kyria/rev1:axeltlarsson:dfu-split-right/left` from root folder, for each
// half respectively
#define EE_HANDS

// Fix USB re-enumeration with Apple Studio Display:
// - 2s delay after wakeup gives the display's USB hub time to stabilise
// - Request only 100mA so the hub doesn't stall negotiating 500mA during hot-plug
#define USB_SUSPEND_WAKEUP_DELAY 2000
#define USB_MAX_POWER_CONSUMPTION 100

#define PERMISSIVE_HOLD
#define TAPPING_TERM 250
