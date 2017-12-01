################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/gpio.c \
../src/main.c \
../src/spi.c \
../src/stm32f4xx_it.c \
../src/syscalls.c \
../src/system_stm32f4xx.c \
../src/uart.c 

OBJS += \
./src/gpio.o \
./src/main.o \
./src/spi.o \
./src/stm32f4xx_it.o \
./src/syscalls.o \
./src/system_stm32f4xx.o \
./src/uart.o 

C_DEPS += \
./src/gpio.d \
./src/main.d \
./src/spi.d \
./src/stm32f4xx_it.d \
./src/syscalls.d \
./src/system_stm32f4xx.d \
./src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DSTM32F446xx -DUSE_HAL_DRIVER -I"C:/Users/Zsolt/stm_workspace/nucleo-f446re_hal_lib" -I"C:/Users/Zsolt/stm_workspace/nucleo-f446re_hal_lib/CMSIS/core" -I"C:/Users/Zsolt/stm_workspace/nucleo-f446re_hal_lib/CMSIS/device" -I"C:/Users/Zsolt/stm_workspace/nucleo-f446re_hal_lib/HAL_Driver/Inc/Legacy" -I"C:/Users/Zsolt/stm_workspace/nucleo-f446re_hal_lib/HAL_Driver/Inc" -I"C:/Users/Zsolt/stm_workspace/nucleo-f446re_hal_lib/Utilities/STM32F4xx-Nucleo" -I"C:/Users/Zsolt/stm_workspace/bluetooth/bluetooth/inc" -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


