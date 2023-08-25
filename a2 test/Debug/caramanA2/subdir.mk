################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../caramanA2/main.cpp 

OBJS += \
./caramanA2/main.o 

CPP_DEPS += \
./caramanA2/main.d 


# Each subdirectory must supply rules for building sources it contributes
caramanA2/%.o: ../caramanA2/%.cpp caramanA2/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


