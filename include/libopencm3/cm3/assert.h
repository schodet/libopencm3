/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2012 Tomaz Solc <tomaz.solc@tablix.org>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENCM3_CM3_ASSERT_H
#define LIBOPENCM3_CM3_ASSERT_H

#include <libopencm3/cm3/common.h>

#ifdef NDEBUG
# define cm3_assert(expr) do { (void)0; } while(0)
# define cm3_assert_not_reached() do { (void)0; } while(0)
#else
# ifdef CM3_ASSERT_VERBOSE
#  define cm3_assert(expr) do { \
				if(expr) { (void)0 } else { \
					cm3_assert_failed_verbose( \
						__FILE__, __LINE__, \
						__func__, #expr); \
				} \
			} while(0)
#  define cm3_assert_not_reached() do { \
				cm3_assert_failed_verbose( \
					__FILE__, __LINE__, \
					__func__, 0); \
			} while(0)
# else
#  define cm3_assert(expr) do { \
				if(expr) { (void)0 } else { \
					cm3_assert_failed(); \
				} \
			} while(0)
#  define cm3_assert_not_reached() do { \
				cm3_assert_failed(); \
			} while(0)
# endif
#endif

BEGIN_DECLS

void cm3_assert_failed(void);
void cm3_assert_failed_verbose(const char *file, int line, const char *func,
		const char *assert_expr);

END_DECLS

#endif
