################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/BT.c \
../Src/app.c \
../Src/audio.c \
../Src/images.c \
../Src/main.c \
../Src/oled.c \
../Src/oledRetrieve.c \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_it.c \
../Src/syscalls.c \
../Src/system_stm32f4xx.c 

OBJS += \
./Src/BT.o \
./Src/app.o \
./Src/audio.o \
./Src/images.o \
./Src/main.o \
./Src/oled.o \
./Src/oledRetrieve.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_it.o \
./Src/syscalls.o \
./Src/system_stm32f4xx.o 

C_DEPS += \
./Src/BT.d \
./Src/app.d \
./Src/audio.d \
./Src/images.d \
./Src/main.d \
./Src/oled.d \
./Src/oledRetrieve.d \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_it.d \
./Src/syscalls.d \
./Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F405xx -I"/Users/sophiagould/Documents/Spring2019/ECE49022micro/micro/Inc" -I"/Users/sophiagould/Documents/Spring2019/ECE49022micro/micro/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/Users/sophiagould/Documents/Spring2019/ECE49022micro/micro/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/Users/sophiagould/Documents/Spring2019/ECE49022micro/micro/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/Users/sophiagould/Documents/Spring2019/ECE49022micro/micro/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


