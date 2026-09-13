# Information

During build at DTS it complains about undefined node labels `&xspim`, `usbotg_hs` and `usbphyc`.

Commenting them out lead to a successful build with the custom board definition.

To investigate why this behavior (probably requires active configuration options such as `STM32 XSPI Manager`).

```
- Found devicetree overlay: C:/Users/stoia/workspace/zephyr-course/app/app.overlay
devicetree error: C:/Users/stoia/workspace/zephyr-course/app/boards/my_nucleo_h7s3l8/my_nucleo_h7s3l8-common.dtsi:249 (column 14): parse error: undefined node label 'usbotg_hs'
```

# Build

```
(.venv) PS C:\Users\stoia\workspace\zephyr-course> west build -p always --board my_nucleo_h7s3l8/stm32h7s3xx app
-- west build: making build dir C:\Users\stoia\workspace\zephyr-course\build pristine
-- west build: generating a build system
Loading Zephyr default modules (Zephyr base).
-- Application: C:/Users/stoia/workspace/zephyr-course/app
-- CMake version: 4.4.2
-- Found Python3: C:/Users/stoia/zephyrproject/.venv/Scripts/python.exe (found suitable version "3.12.10", minimum required is "3.12") found components: Interpreter
-- Cache files will be written to: C:/Users/stoia/workspace/deps/zephyr/.cache
-- Zephyr version: 4.4.2 (C:/Users/stoia/workspace/deps/zephyr)
-- Found west (found suitable version "1.5.0", minimum required is "0.14.0")
-- Board: my_nucleo_h7s3l8, qualifiers: stm32h7s3xx
-- Found host-tools: zephyr 1.0.1 (C:/Users/stoia/zephyr-sdk-1.0.1)                                                                           
-- Found toolchain: zephyr 1.0.1 (C:/Users/stoia/zephyr-sdk-1.0.1)                                                                            
-- Found Dtc: C:/Users/stoia/AppData/Local/Microsoft/WinGet/Packages/oss-winget.dtc_Microsoft.Winget.Source_8wekyb3d8bbwe/usr/bin/dtc.exe (found suitable version "1.6.1", minimum required is "1.4.6")                                                                                     
-- Found BOARD.dts: C:/Users/stoia/workspace/zephyr-course/app/boards/my_nucleo_h7s3l8/my_nucleo_h7s3l8.dts                                   
-- Found devicetree overlay: C:/Users/stoia/workspace/zephyr-course/app/app.overlay                                                           
-- Generated zephyr.dts: C:/Users/stoia/workspace/zephyr-course/build/zephyr/zephyr.dts                                                       
-- Generated pickled edt: C:/Users/stoia/workspace/zephyr-course/build/zephyr/edt.pickle                                                      
-- Generated devicetree_generated.h: C:/Users/stoia/workspace/zephyr-course/build/zephyr/include/generated/zephyr/devicetree_generated.h      
Parsing C:/Users/stoia/workspace/zephyr-course/app/Kconfig                                                                                    
Loaded configuration 'C:/Users/stoia/workspace/zephyr-course/app/boards/my_nucleo_h7s3l8/my_nucleo_h7s3l8_defconfig'                          
Merged configuration 'C:/Users/stoia/workspace/zephyr-course/app/prj.conf'                                                                    
Configuration saved to 'C:/Users/stoia/workspace/zephyr-course/build/zephyr/.config'                                                          
Kconfig header saved to 'C:/Users/stoia/workspace/zephyr-course/build/zephyr/include/generated/zephyr/autoconf.h'                             
-- Found GnuLd: C:/Users/stoia/zephyr-sdk-1.0.1/gnu/arm-zephyr-eabi/arm-zephyr-eabi/bin/ld.bfd.exe (found version "2.43.1")                   
-- The C compiler identification is GNU 14.3.0                                                                                                
-- The CXX compiler identification is GNU 14.3.0
-- The ASM compiler identification is GNU
-- Found assembler: C:/Users/stoia/zephyr-sdk-1.0.1/gnu/arm-zephyr-eabi/bin/arm-zephyr-eabi-gcc.exe
-- Found gen_kobject_list: C:/Users/stoia/workspace/deps/zephyr/scripts/build/gen_kobject_list.py
-- Configuring done (103.5s)
-- Generating done (0.5s)
-- Build files have been written to: C:/Users/stoia/workspace/zephyr-course/build
-- west build: building application
[1/163] Generating include/generated/zephyr/version.h
-- Zephyr version: 4.4.2 (C:/Users/stoia/workspace/deps/zephyr), build: v4.4.2
[36/163] Building CXX object CMakeFiles/app.dir/src/main.cpp.obj
In file included from C:/Users/stoia/workspace/deps/modules/hal/stm32/stm32cube/stm32h7rsxx/drivers/include/stm32h7rsxx_hal_i3c.h:30,
                 from C:/Users/stoia/workspace/deps/modules/hal/stm32/stm32cube/stm32h7rsxx/drivers/include/stm32h7rsxx_hal_conf.h:364,
                 from C:/Users/stoia/workspace/deps/modules/hal/stm32/stm32cube/stm32h7rsxx/drivers/include/stm32h7rsxx_hal.h:30,
                 from C:/Users/stoia/workspace/deps/modules/hal/stm32/stm32cube/stm32h7rsxx/soc/stm32h7rsxx.h:220,
                 from C:/Users/stoia/workspace/deps/zephyr/soc/st/stm32/stm32h7rsx/soc.h:12,
                 from C:/Users/stoia/workspace/deps/zephyr/modules/cmsis_6/cmsis_core_m.h:24,
                 from C:/Users/stoia/workspace/deps/zephyr/modules/cmsis_6/cmsis_core.h:10,
                 from C:/Users/stoia/workspace/deps/zephyr/include/zephyr/arch/arm/asm_inline_gcc.h:24,
                 from C:/Users/stoia/workspace/deps/zephyr/include/zephyr/arch/arm/asm_inline.h:18,
                 from C:/Users/stoia/workspace/deps/zephyr/include/zephyr/arch/arm/arch.h:30,
                 from C:/Users/stoia/workspace/deps/zephyr/include/zephyr/arch/cpu.h:19,
                 from C:/Users/stoia/workspace/deps/zephyr/include/zephyr/kernel_includes.h:36,
                 from C:/Users/stoia/workspace/deps/zephyr/include/zephyr/kernel.h:17,
                 from C:/Users/stoia/workspace/deps/zephyr/include/zephyr/tracing/tracking.h:16,
                 from C:/Users/stoia/workspace/deps/zephyr/include/zephyr/tracing/tracing.h:17,
                 from C:/Users/stoia/workspace/deps/zephyr/include/zephyr/drivers/gpio.h:23,
                 from C:/Users/stoia/workspace/zephyr-course/app/src/main.cpp:1:
C:/Users/stoia/workspace/deps/modules/hal/stm32/stm32cube/stm32h7rsxx/drivers/include/stm32h7rsxx_ll_i3c.h: In function 'uint32_t LL_I3C_DMA_GetRegAddr(const I3C_TypeDef*, uint32_t)':
C:/Users/stoia/workspace/deps/modules/hal/stm32/stm32cube/stm32h7rsxx/drivers/include/stm32h7rsxx_ll_i3c.h:924:21: warning: ISO C++17 does not allow 'register' storage class specifier [-Wregister]
  924 |   register uint32_t data_reg_addr;
      |                     ^~~~~~~~~~~~~
[163/163] Linking CXX executable zephyr\zephyr.elf
Memory region         Used Size  Region Size  %age Used
           FLASH:       30764 B        64 KB     46.94%
             RAM:        6784 B       456 KB      1.45%
           SRAM0:           0 B       456 KB      0.00%
           SRAM1:         16 KB        16 KB    100.00%
            DTCM:           0 B       128 KB      0.00%
            ITCM:           0 B        64 KB      0.00%
          EXTMEM:           0 B        32 MB      0.00%
        IDT_LIST:           0 B        32 KB      0.00%
Generating files from C:/Users/stoia/workspace/zephyr-course/build/zephyr/zephyr.elf for board: my_nucleo_h7s3l8/stm32h7s3xx
```

# Flashing

```
(.venv) PS C:\Users\stoia\workspace\zephyr-course> west flash
-- west flash: rebuilding
ninja: no work to do.
-- west flash: using runner stm32cubeprogrammer
      -------------------------------------------------------------------
                       STM32CubeProgrammer v2.23.0                  
      -------------------------------------------------------------------

ST-LINK SN  : 003000443433511930343835
ST-LINK FW  : V3J17M10
Board       : NUCLEO-H7S3L8
Voltage     : 3.27V
SWD freq    : 8000 KHz
Connect mode: Under Reset
Reset mode  : Hardware reset
Device ID   : 0x485
Revision ID : Rev B
Device name : STM32H7RSxx
NVM size    : 64 KBytes (default)
Device type : MCU
Device CPU  : Cortex-M7
BL Version  : 0xE4



Opening and parsing file: zephyr.hex


Memory Programming ...
  File          : zephyr.hex
  Size          : 30.04 KB 
  Address       : 0x08000000


Erasing memory corresponding to segment 0:
Erasing internal memory sectors [0 3]
Download in Progress:
██████████████████████████████████████████████████ 100%

File download complete
Time elapsed during download operation: 00:00:00.197

RUNNING Program ... 
  Address:      : 0x8000000
Application is running, Please Hold on...
Start operation achieved successfully
```
