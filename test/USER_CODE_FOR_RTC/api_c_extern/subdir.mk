################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../api_c_extern/Thread.cc \
../api_c_extern/hdf.cc 

OBJS += \
./api_c_extern/Thread.o \
./api_c_extern/hdf.o 

CC_DEPS += \
./api_c_extern/Thread.d \
./api_c_extern/hdf.d 


# Each subdirectory must supply rules for building sources it contributes
api_c_extern/%.o: ../api_c_extern/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/opt/gc/include -I/opt/gc/include/modules/uc -I/opt/gc/include/base -I/usr/include -I/opt/vs/include -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


