/**
 * @file posixclock.c
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
#include <fcntl.h>
#include "missing.h"

#include "posixclock.h"

clockid_t posix_clock_open(const char *device_path)
{
	clockid_t clkid;
	struct timespec ts;
	int fd;

	if (!device_path)
		return CLOCK_INVALID;
	fd = open(device_path, O_RDWR);
	if (fd < 0)
		return CLOCK_INVALID;

	clkid = FD_TO_CLOCKID(fd);
	/* did we actually open a clock? */
	if (clock_gettime(clkid, &ts)) {
		close(fd);
		return CLOCK_INVALID;
	}
	return clkid;
}

void posix_clock_close(clockid_t clkid)
{
	if ((clkid < 0) && (clkid & CLOCKFD_MASK) != CLOCKFD)
		return;

	close(CLOCKID_TO_FD(clkid));
}

