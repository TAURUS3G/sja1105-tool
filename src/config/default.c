/******************************************************************************
 * Copyright (c) 2016, NXP Semiconductors
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from this
 * software without specific prior written permission.
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
 *****************************************************************************/
#include "internal.h"
#include "external.h"

int config_default(struct sja1105_config *config, char *config_name)
{
	uint8_t ls1021atsn_buf[] = {
		/* L2 Policing Table, length 320 bytes (80 x 32-bit words), CRC 216F256B */
		/* Header: */
		0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x21, 0x6F, 0x25, 0x6B,
		/* 40 Entries (one per line): */
		0x02, 0xF7, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x07, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x0B, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x13, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x17, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x1B, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x1F, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x23, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x27, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x2B, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x2F, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x33, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x37, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x3B, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x3F, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x43, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x47, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x4B, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x4F, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x53, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x57, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x5B, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x5F, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x63, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x67, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x6B, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x6F, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x73, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x77, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x7B, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x83, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x87, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x8B, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x8F, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x93, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x97, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x9B, 0xFF, 0xFF, 0xE8,
		0x02, 0xF7, 0x00, 0x00, 0x9F, 0xFF, 0xFF, 0xE8,
		/* Table Data CRC: */
		0xFC, 0x1A, 0xE4, 0x16,
		/* VLAN Lookup Table, length 8 bytes (2 x 32-bit words), CRC 7D0BCBF2 */
		/* Header */
		0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x7D, 0x0B, 0xCB, 0xF2,
		/* Entry */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xF0, 0x00,
		/* Table Data CRC */
		0x88, 0x38, 0x86, 0x85,
		/* MAC Configuration Table */
		0x08, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x1A,
		0x6A, 0xF6, 0x23, 0x53,
		0x10, 0x00, 0x00, 0x00,
		0xF7, 0xBD, 0xF5, 0x8D,
		0x10, 0x00, 0x00, 0x00,
		0xEF, 0x7B, 0xF5, 0x8D,
		0x10, 0x00, 0x00, 0x00,
		0xDE, 0xF7, 0xF5, 0x8D,
		0x10, 0x00, 0x00, 0x00,
		0xBD, 0xEF, 0xF5, 0x8D,
		0x10, 0x00, 0x00, 0x00,
		0x7B, 0xDF, 0xF5, 0x8D,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x92, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x24,
		0x24, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x49,
		0xB6, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x6D,
		0x48, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x92,
		0xDA, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xB6,
		0x6C, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xDB,
		0xFE, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xFF,
		0x67, 0x42, 0xE0, 0x06,
		/* MAC Configuration Table, length 140 bytes (35 x 32-bit words), CRC DAB5BDC8 */
		/* Header: */
		0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x23, 0xDA, 0xB5, 0xBD, 0xC8,
		/*Entry (28 bytes):*/
		0xFE, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x01,
		0x08, 0xFC, 0x01, 0x02, 0xBF, 0x40, 0x4F, 0xE4,
		0xE0, 0x17, 0xFB, 0x02, 0x06, 0xFF, 0x40, 0xCF,
		0xFF, 0xF0, 0x3B, 0xFC,
		/*Entry (28 bytes):*/
		0xFE, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x01,
		0x08, 0xFC, 0x01, 0x02, 0xBF, 0x40, 0x4F, 0xE4,
		0xE0, 0x17, 0xFB, 0x02, 0x06, 0xFF, 0x40, 0xCF,
		0xFF, 0xF0, 0x3B, 0xFC,
		/*Entry (28 bytes):*/
		0xFE, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x01,
		0x08, 0xFC, 0x01, 0x02, 0xBF, 0x40, 0x4F, 0xE4,
		0xE0, 0x17, 0xFB, 0x02, 0x06, 0xFF, 0x40, 0xCF,
		0xFF, 0xF0, 0x3B, 0xFC,
		/*Entry (28 bytes):*/
		0xFE, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x01,
		0x08, 0xFC, 0x01, 0x02, 0xBF, 0x40, 0x4F, 0xE4,
		0xE0, 0x17, 0xFB, 0x02, 0x06, 0xFF, 0x40, 0xCF,
		0xFF, 0xF0, 0x3B, 0xFC,
		/*Entry (28 bytes):*/
		0xFE, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x01,
		0x08, 0xFC, 0x01, 0x02, 0xBF, 0x40, 0x4F, 0xE4,
		0xE0, 0x17, 0xFB, 0x02, 0x06, 0xFF, 0x40, 0xCF,
		0xFF, 0xF0, 0x3B, 0xFC,
		/*Table Data CRC:*/
		0xFC, 0xE2, 0x5E, 0xA3,

		0x0D, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x01,
		0x25, 0x0E, 0x7C, 0xBD,
		0x00, 0x01, 0x25, 0xE0,
		0xD0, 0xA6, 0x2B, 0x6E,
		0x0E, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x03,
		0xC8, 0xA7, 0xCE, 0xE6,
		0x00, 0x76, 0xA0, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x71, 0xFF, 0x89, 0xF8,
		0x11, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x0A,
		0x57, 0x1F, 0x81, 0x3F,
		0x06, 0x44, 0x00, 0x00,
		0x00, 0x00, 0x04, 0x08,
		0x00, 0x00, 0x00, 0x00,
		0xFF, 0x0D, 0xA0, 0x00,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0x00, 0xFF, 0xFF, 0xFF,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x58, 0x00, 0x00, 0x00,
		0x04, 0xE8, 0x9C, 0x75,
		0x4E, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x01,
		0x3A, 0x5D, 0x5E, 0x24,
		0x5B, 0x6C, 0x00, 0x00,
		0x14, 0xB5, 0x73, 0xCB,
		0x00, 0x00, 0x00, 0x00,
		/*0x80, 0x20, 0x0C, 0x00,*/
		0x00, 0x00, 0x00, 0x00,
		0x37, 0x6E, 0x02, 0x8B,
	};
	const char *options[] = {
		"ls1021atsn",
	};
	void *config_buffers[] = {
		ls1021atsn_buf,
	};
	int match = get_match(config_name, options, ARRAY_SIZE(options));
	if (match < 0) {
		goto error;
	}
	return sja1105_config_get(config_buffers[match], config);
error:
	return -1;
}

