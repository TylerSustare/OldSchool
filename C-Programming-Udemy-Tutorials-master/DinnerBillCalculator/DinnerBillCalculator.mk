##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=DinnerBillCalculator
ConfigurationName      :=Debug
WorkspacePath          := "/Users/tyler/Documents/C-Programming-Udemy-Tutorials"
ProjectPath            := "/Users/tyler/Documents/C-Programming-Udemy-Tutorials/DinnerBillCalculator"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Tyler
Date                   :=03/10/2015
CodeLitePath           :="/Users/tyler/Library/Application Support/codelite"
LinkerName             :=/Applications/Xcode.app/Contents/Developer/usr/bin/g++
SharedObjectLinkerName :=/Applications/Xcode.app/Contents/Developer/usr/bin/g++ -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="DinnerBillCalculator.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /Applications/Xcode.app/Contents/Developer/usr/bin/g++
CC       := /Applications/Xcode.app/Contents/Developer/usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/Users/tyler/Downloads/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/sandbox.c$(ObjectSuffix) $(IntermediateDirectory)/multi-dimentional-arrays.c$(ObjectSuffix) $(IntermediateDirectory)/restaurant.c$(ObjectSuffix) 



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

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c 
	$(CC) $(SourceSwitch) "/Users/tyler/Documents/C-Programming-Udemy-Tutorials/DinnerBillCalculator/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) "main.c"

$(IntermediateDirectory)/sandbox.c$(ObjectSuffix): sandbox.c 
	$(CC) $(SourceSwitch) "/Users/tyler/Documents/C-Programming-Udemy-Tutorials/DinnerBillCalculator/sandbox.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sandbox.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sandbox.c$(PreprocessSuffix): sandbox.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sandbox.c$(PreprocessSuffix) "sandbox.c"

$(IntermediateDirectory)/multi-dimentional-arrays.c$(ObjectSuffix): multi-dimentional-arrays.c 
	$(CC) $(SourceSwitch) "/Users/tyler/Documents/C-Programming-Udemy-Tutorials/DinnerBillCalculator/multi-dimentional-arrays.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/multi-dimentional-arrays.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/multi-dimentional-arrays.c$(PreprocessSuffix): multi-dimentional-arrays.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/multi-dimentional-arrays.c$(PreprocessSuffix) "multi-dimentional-arrays.c"

$(IntermediateDirectory)/restaurant.c$(ObjectSuffix): restaurant.c 
	$(CC) $(SourceSwitch) "/Users/tyler/Documents/C-Programming-Udemy-Tutorials/DinnerBillCalculator/restaurant.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/restaurant.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/restaurant.c$(PreprocessSuffix): restaurant.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/restaurant.c$(PreprocessSuffix) "restaurant.c"

##
## Clean
##
clean:
	$(RM) -r ./Debug/


