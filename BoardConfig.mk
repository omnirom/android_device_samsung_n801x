#
# Copyright (C) 2013 OmniROM Project
# Copyright (C) 2013 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# Include n80xx BoardConfigCommon
-include device/samsung/n80xx-common/BoardConfigCommon.mk

# Kernel building
TARGET_KERNEL_SOURCE := kernel/samsung/smdk4412
TARGET_KERNEL_CONFIG := custom_n801x_defconfig

# Assert
TARGET_OTA_ASSERT_DEVICE := c0,p4notewifi,p4notewifiww,n8013,GT-N8013,n8010,GT-N8010,n801x,GT-N801x

# Bluetooth
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := device/samsung/n801x/bluetooth
