#Scons Testing
Import('*')
import os

##Include statments, added /system/JumpRopeCity/include
INC = [ '#/vm/inc', '#/peripherals/simple_kb', '#/peripherals/simple_term', '#/system/JumpRopeCity/include', '#/system/JumpRopeCity/images' ]

##Detectes the Librarys
LIBS = [ 'libminiat', 'libsimple_kb', 'libsimple_term', 'SDL2', 'SDL2_image' ]

##Required CPP Files

CPPFILES = ['main.cpp', 'Rope.cpp', 'Scene.cpp', 'Player.cpp', 'Peripherals.cpp', 'Map.cpp']

#print "\t\t\t\t\t@@@@@@@", os.getcwd()
rootdir = os.getcwd()

##Used for testing rootdir
print "@@@@@@@", rootdir

#Combining rootdir with ../../../system/JumpRopeCity/
imageDir = os.path.join(rootdir, '..', '..', '..', 'system', 'JumpRopeCity')

executableDir = os.path.join(rootdir, '..', '..', '..', 'out', 'bin')

##Testing the imgageDir to make sure it works
print "@@@@@@@", imageDir
print "executableDir = ", executableDir

##Building process
buildProgram("JumpRopeCity", CPPFILES, CPPPATH = INC, LIBS = LIBS, CPPDEFINES=[ 'JR_HOME=\\"%s\\"' % imageDir, 'EXECUTABLE=\\"%s\\"' % executableDir ])


##These are for the assembly Programs####
#buildMash('move.asm')
buildMash('AssemblyPrograms/MovementTest.asm')
buildMash('AssemblyPrograms/TileRunner.asm')
buildMash('AssemblyPrograms/teethProg.asm')  
#buildMash('simple_term_flash_demo.asm')#
#########################################
