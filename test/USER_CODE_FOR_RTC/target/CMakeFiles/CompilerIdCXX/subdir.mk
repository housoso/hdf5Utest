################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../target/CMakeFiles/CompilerIdCXX/CMakeCXXCompilerId.cpp 

OBJS += \
./target/CMakeFiles/CompilerIdCXX/CMakeCXXCompilerId.o 

CPP_DEPS += \
./target/CMakeFiles/CompilerIdCXX/CMakeCXXCompilerId.d 


# Each subdirectory must supply rules for building sources it contributes
target/CMakeFiles/CompilerIdCXX/%.o: ../target/CMakeFiles/CompilerIdCXX/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/opt/gc/include -I/opt/gc/include/modules/uc -I/opt/gc/include/base -I/usr/include -I/opt/vs/include -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


