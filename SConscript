#Scons Testing
Import('*')
import os

##Include statments, added /system/JumpRopeCity/include
INC = [ '#/vm/inc', '#/peripherals/simple_kb', '#/peripherals/simple_term', '#/system/JumpRopeCity/include', '#/system/JumpRopeCity/images' ]

##Detectes the Librarys
LIBS = [ 'libminiat', 'libsimple_kb', 'libsimple_term', 'SDL2', 'SDL2_image' ]

##Required CPP Files
CPPFILES = ['main.cpp', 'Rope.cpp', 'Scene.cpp', 'Peripherals.cpp']

#print "\t\t\t\t\t@@@@@@@", os.getcwd()
rootdir = os.getcwd()

##Used for testing rootdir
print "@@@@@@@", rootdir

#Combining rootdir with ../../../system/JumpRopeCity/
imageDir = os.path.join(rootdir, '..', '..', '..', 'system', 'JumpRopeCity')

##Testing the imgageDir to make sure it works
print "@@@@@@@", imageDir

##Building process
buildProgram("JumpRopeCity", CPPFILES, CPPPATH = INC, LIBS = LIBS, CPPDEFINES=[ 'JR_HOME=\\"%s\\"' % imageDir])


##These are for the assembly Programs####
buildMash('jump2.asm')           
#buildMash('simple_term_flash_demo.asm')#
#########################################
