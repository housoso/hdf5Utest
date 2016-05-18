################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../target/CMakeFiles/CompilerIdC/CMakeCCompilerId.c 

OBJS += \
./target/CMakeFiles/CompilerIdC/CMakeCCompilerId.o 

C_DEPS += \
./target/CMakeFiles/CompilerIdC/CMakeCCompilerId.d 


# Each subdirectory must supply rules for building sources it contributes
target/CMakeFiles/CompilerIdC/%.o: ../target/CMakeFiles/CompilerIdC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/opt/gc/include -I/opt/gc/include/modules/uc -I/opt/gc/include/base -I/usr/include -I/opt/vs/include -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


