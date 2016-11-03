##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=CPC_STM32F1
ConfigurationName      :=Debug
WorkspacePath          :=/home/gusenkovs/stm32hc
ProjectPath            :=/home/gusenkovs/stm32hc/CPC_STM32F1
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=gusenkovs
Date                   :=03.11.2016
CodeLitePath           :=/home/gusenkovs/.codelite
LinkerName             :=/usr/bin/arm-none-eabi-g++
SharedObjectLinkerName :=/usr/bin/arm-none-eabi-g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName).elf
Preprocessors          :=$(PreprocessorSwitch)STM32F10X_MD 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="CPC_STM32F1.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            := -nostartfiles -mcpu=cortex-m3 -mthumb -TSTM32F103C8T6.ld -Wl,-Map=$(ProjectName).map -Wl,-gc-sections -g
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)CMSIS/CM3/DeviceSupport/ST/STM32F10x/ $(IncludeSwitch)CMSIS/CM3/CoreSupport/ 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/arm-none-eabi-ar rcu
CXX      := /usr/bin/arm-none-eabi-g++
CC       := /usr/bin/arm-none-eabi-gcc
CXXFLAGS := -g -O0 -Wall $(Preprocessors)
CFLAGS   := -mthumb -mcpu=cortex-m3 -Wall -Werror -O0 -nostartfiles -g $(Preprocessors)
ASFLAGS  := -mthumb -mcpu=cortex-m3 -g
AS       := /usr/bin/arm-none-eabi-as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/CMSIS_CM3_DeviceSupport_ST_STM32F10x_system_stm32f10x.c$(ObjectSuffix) $(IntermediateDirectory)/sturtup.s$(ObjectSuffix) $(IntermediateDirectory)/stm32f10x_it.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

PostBuild:
	@echo Executing Post Build commands ...
	arm-none-eabi-size Debug/CPC_STM32F1.elf
	arm-none-eabi-objcopy -Obinary Debug/CPC_STM32F1.elf Debug/CPC_STM32F1.bin
	arm-none-eabi-objcopy -Oihex Debug/CPC_STM32F1.elf Debug/CPC_STM32F1.hex
	xfce4-terminal -e "killall -9 openocd"
	xfce4-terminal -e openocd --working-directory="/home/gusenkovs/stm32hc/CPC_STM32F1/"
	@echo Done

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:
	@echo Executing Pre Build commands ...
	
	@echo Done


##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/gusenkovs/stm32hc/CPC_STM32F1/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix)main.c

$(IntermediateDirectory)/CMSIS_CM3_DeviceSupport_ST_STM32F10x_system_stm32f10x.c$(ObjectSuffix): CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.c $(IntermediateDirectory)/CMSIS_CM3_DeviceSupport_ST_STM32F10x_system_stm32f10x.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/gusenkovs/stm32hc/CPC_STM32F1/CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CMSIS_CM3_DeviceSupport_ST_STM32F10x_system_stm32f10x.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CMSIS_CM3_DeviceSupport_ST_STM32F10x_system_stm32f10x.c$(DependSuffix): CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CMSIS_CM3_DeviceSupport_ST_STM32F10x_system_stm32f10x.c$(ObjectSuffix) -MF$(IntermediateDirectory)/CMSIS_CM3_DeviceSupport_ST_STM32F10x_system_stm32f10x.c$(DependSuffix) -MM CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.c

$(IntermediateDirectory)/CMSIS_CM3_DeviceSupport_ST_STM32F10x_system_stm32f10x.c$(PreprocessSuffix): CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CMSIS_CM3_DeviceSupport_ST_STM32F10x_system_stm32f10x.c$(PreprocessSuffix)CMSIS/CM3/DeviceSupport/ST/STM32F10x/system_stm32f10x.c

$(IntermediateDirectory)/sturtup.s$(ObjectSuffix): sturtup.s $(IntermediateDirectory)/sturtup.s$(DependSuffix)
	$(AS) "/home/gusenkovs/stm32hc/CPC_STM32F1/sturtup.s" $(ASFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sturtup.s$(ObjectSuffix) -I$(IncludePath)
$(IntermediateDirectory)/sturtup.s$(DependSuffix): sturtup.s
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sturtup.s$(ObjectSuffix) -MF$(IntermediateDirectory)/sturtup.s$(DependSuffix) -MM sturtup.s

$(IntermediateDirectory)/sturtup.s$(PreprocessSuffix): sturtup.s
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sturtup.s$(PreprocessSuffix)sturtup.s

$(IntermediateDirectory)/stm32f10x_it.c$(ObjectSuffix): stm32f10x_it.c $(IntermediateDirectory)/stm32f10x_it.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/gusenkovs/stm32hc/CPC_STM32F1/stm32f10x_it.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/stm32f10x_it.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/stm32f10x_it.c$(DependSuffix): stm32f10x_it.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/stm32f10x_it.c$(ObjectSuffix) -MF$(IntermediateDirectory)/stm32f10x_it.c$(DependSuffix) -MM stm32f10x_it.c

$(IntermediateDirectory)/stm32f10x_it.c$(PreprocessSuffix): stm32f10x_it.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/stm32f10x_it.c$(PreprocessSuffix)stm32f10x_it.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


