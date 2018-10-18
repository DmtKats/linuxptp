/**
 * @file posixclock.h
 * @brief Wraps clock character device functionality.
 * @note Copyright (C) 2018 Dimitrios Katsaros <patcherwork@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#ifndef HAVE_POSIX_CLOCK_H
#define HAVE_POSIX_CLOCK_H

#include <time.h>

/**
 * Tries to open a posix clock device using the passed device path
 * @param devpath The clock device path.
 */
clockid_t posix_clock_open(const char *device_path);

/**
 * Closes a posix clock. It checks that the clock id passed is a valid clock fd
 * @param clkid The clock identifier.
 */
void posix_clock_close(clockid_t clkid);

#endif
