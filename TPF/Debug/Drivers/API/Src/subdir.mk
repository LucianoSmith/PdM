################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API/Src/API_delay.c \
../Drivers/API/Src/API_mef.c \
../Drivers/API/Src/API_motor.c \
../Drivers/API/Src/API_osensor.c \
../Drivers/API/Src/API_psensor.c \
../Drivers/API/Src/API_uart.c 

OBJS += \
./Drivers/API/Src/API_delay.o \
./Drivers/API/Src/API_mef.o \
./Drivers/API/Src/API_motor.o \
./Drivers/API/Src/API_osensor.o \
./Drivers/API/Src/API_psensor.o \
./Drivers/API/Src/API_uart.o 

C_DEPS += \
./Drivers/API/Src/API_delay.d \
./Drivers/API/Src/API_mef.d \
./Drivers/API/Src/API_motor.d \
./Drivers/API/Src/API_osensor.d \
./Drivers/API/Src/API_psensor.d \
./Drivers/API/Src/API_uart.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API/Src/%.o Drivers/API/Src/%.su Drivers/API/Src/%.cyclo: ../Drivers/API/Src/%.c Drivers/API/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DNUCLEO_F429ZI -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Inc -I"/Users/lucianosmith/Documents/STM32CubeIDE/workspace_1.12.1/TPF/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/Users/lucianosmith/Documents/STM32CubeIDE/workspace_1.12.1/TPF/Drivers/CMSIS/Include" -I"/Users/lucianosmith/Documents/STM32CubeIDE/workspace_1.12.1/TPF/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/Users/lucianosmith/Documents/STM32CubeIDE/workspace_1.12.1/TPF/Drivers/BSP/STM32F4xx_Nucleo_144" -I"/Users/lucianosmith/Documents/STM32CubeIDE/workspace_1.12.1/TPF/Drivers/Core/Inc" -I"/Users/lucianosmith/Documents/STM32CubeIDE/workspace_1.12.1/TPF/Drivers/API/Inc" -I"/Users/lucianosmith/Documents/STM32CubeIDE/workspace_1.12.1/TPF/Drivers/API/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-API-2f-Src

clean-Drivers-2f-API-2f-Src:
	-$(RM) ./Drivers/API/Src/API_delay.cyclo ./Drivers/API/Src/API_delay.d ./Drivers/API/Src/API_delay.o ./Drivers/API/Src/API_delay.su ./Drivers/API/Src/API_mef.cyclo ./Drivers/API/Src/API_mef.d ./Drivers/API/Src/API_mef.o ./Drivers/API/Src/API_mef.su ./Drivers/API/Src/API_motor.cyclo ./Drivers/API/Src/API_motor.d ./Drivers/API/Src/API_motor.o ./Drivers/API/Src/API_motor.su ./Drivers/API/Src/API_osensor.cyclo ./Drivers/API/Src/API_osensor.d ./Drivers/API/Src/API_osensor.o ./Drivers/API/Src/API_osensor.su ./Drivers/API/Src/API_psensor.cyclo ./Drivers/API/Src/API_psensor.d ./Drivers/API/Src/API_psensor.o ./Drivers/API/Src/API_psensor.su ./Drivers/API/Src/API_uart.cyclo ./Drivers/API/Src/API_uart.d ./Drivers/API/Src/API_uart.o ./Drivers/API/Src/API_uart.su

.PHONY: clean-Drivers-2f-API-2f-Src

