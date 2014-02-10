/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_n801x.h"

#define STRCONV_(x)      #x
#define STRCONV(x)       "%" STRCONV_(x) "s"

static char bootloader[PROP_VALUE_MAX];

void vendor_load_properties()
{
    int rc;
    rc = property_get("ro.boot.bootloader", bootloader);

    if (!rc)
        return;
    /* Collect N801X info */
    NOTICE("Bootloader string %s", bootloader);
    if (strncmp(bootloader, "N8013", 5) == 0) {
        NOTICE("Detected N8013\n");
        property_set("ro.product.device", "GT-N8013");
        property_set("ro.product.model", "GT-N8013");
        property_set("ro.product.name", "GT-N8013");
    }else if(strncmp(bootloader, "N8010", 5) == 0) {
        NOTICE("Detected N8010\n");
        property_set("ro.product.device", "GT-N8010");
        property_set("ro.product.model", "GT-N8010");
        property_set("ro.product.name", "GT-N8010");
    }else {
        ERROR("Could not detect N801x variant\n");
    }
}
