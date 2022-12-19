################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RTG/Src/ADC.c \
../RTG/Src/Client.c \
../RTG/Src/I2C.c \
../RTG/Src/Interapts.c \
../RTG/Src/RTG.c \
../RTG/Src/SPI.c \
../RTG/Src/Server.c \
../RTG/Src/Timer.c \
../RTG/Src/Tools.c \
../RTG/Src/TransferFunctions.c \
../RTG/Src/UART.c 

OBJS += \
./RTG/Src/ADC.o \
./RTG/Src/Client.o \
./RTG/Src/I2C.o \
./RTG/Src/Interapts.o \
./RTG/Src/RTG.o \
./RTG/Src/SPI.o \
./RTG/Src/Server.o \
./RTG/Src/Timer.o \
./RTG/Src/Tools.o \
./RTG/Src/TransferFunctions.o \
./RTG/Src/UART.o 

C_DEPS += \
./RTG/Src/ADC.d \
./RTG/Src/Client.d \
./RTG/Src/I2C.d \
./RTG/Src/Interapts.d \
./RTG/Src/RTG.d \
./RTG/Src/SPI.d \
./RTG/Src/Server.d \
./RTG/Src/Timer.d \
./RTG/Src/Tools.d \
./RTG/Src/TransferFunctions.d \
./RTG/Src/UART.d 


# Each subdirectory must supply rules for building sources it contributes
RTG/Src/%.o RTG/Src/%.su: ../RTG/Src/%.c RTG/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I"C:/Users/danya/STM32CubeIDE/workspace_1.10.1/ARM_FINAL_PROJECT/RTG/Inc" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../LWIP/App -I../LWIP/Target -I../Middlewares/Third_Party/LwIP/src/include -I../Middlewares/Third_Party/LwIP/system -I../Drivers/BSP/Components/lan8742 -I../Middlewares/Third_Party/LwIP/src/include/netif/ppp -I../Middlewares/Third_Party/LwIP/src/include/lwip -I../Middlewares/Third_Party/LwIP/src/include/lwip/apps -I../Middlewares/Third_Party/LwIP/src/include/lwip/priv -I../Middlewares/Third_Party/LwIP/src/include/lwip/prot -I../Middlewares/Third_Party/LwIP/src/include/netif -I../Middlewares/Third_Party/LwIP/src/include/compat/posix -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/net -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/sys -I../Middlewares/Third_Party/LwIP/src/include/compat/stdc -I../Middlewares/Third_Party/LwIP/system/arch -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-RTG-2f-Src

clean-RTG-2f-Src:
	-$(RM) ./RTG/Src/ADC.d ./RTG/Src/ADC.o ./RTG/Src/ADC.su ./RTG/Src/Client.d ./RTG/Src/Client.o ./RTG/Src/Client.su ./RTG/Src/I2C.d ./RTG/Src/I2C.o ./RTG/Src/I2C.su ./RTG/Src/Interapts.d ./RTG/Src/Interapts.o ./RTG/Src/Interapts.su ./RTG/Src/RTG.d ./RTG/Src/RTG.o ./RTG/Src/RTG.su ./RTG/Src/SPI.d ./RTG/Src/SPI.o ./RTG/Src/SPI.su ./RTG/Src/Server.d ./RTG/Src/Server.o ./RTG/Src/Server.su ./RTG/Src/Timer.d ./RTG/Src/Timer.o ./RTG/Src/Timer.su ./RTG/Src/Tools.d ./RTG/Src/Tools.o ./RTG/Src/Tools.su ./RTG/Src/TransferFunctions.d ./RTG/Src/TransferFunctions.o ./RTG/Src/TransferFunctions.su ./RTG/Src/UART.d ./RTG/Src/UART.o ./RTG/Src/UART.su

.PHONY: clean-RTG-2f-Src

