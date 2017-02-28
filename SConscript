#Scons Testing
Import('*')
import os

##Include statments, added /system/JumpRopeCity/include
INC = [ '#/vm/inc', '#/peripherals/simple_kb', '#/peripherals/simple_term', '#/system/JumpRopeCity/include', '#/system/JumpRopeCity/images' ]

##Detectes the Librarys
LIBS = [ 'libminiat', 'libsimple_kb', 'libsimple_term', 'SDL2', 'SDL2_image' ]

##Required CPP Files
CPPFILES = ['main.cpp', 'Rope.cpp', 'Scene.cpp']

#print "\t\t\t\t\t@@@@@@@", os.getcwd()
rootdir = os.getcwd()
print "\t\t\t\t\t@@@@@@@", rootdir
imageDir = os.path.join(rootdir, '..', '..', 'system', 'JumpRopeCity')

print "\t\t\t\t\t@@@@@@@", imageDir

##Building process
buildProgram("JumpRopeCity", CPPFILES, CPPPATH = INC, LIBS = LIBS, CPPDEFINES=[ 'JR_HOME=\\"%s\\"' % imageDir])


##These are for the assmebly Programs####
#buildMash('simple_term.asm')           #
#buildMash('simple_term_flash_demo.asm')#
#########################################
