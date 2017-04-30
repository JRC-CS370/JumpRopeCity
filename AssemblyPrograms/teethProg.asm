# peripheral constants

.const P_PROX_SCAN 0x4000 # low 8 bits indicate NE E SE S SW W NW N rope

.const P_SCAN_N 0x4010
.const P_SCAN_NW 0x4011
.const P_SCAN_W 0x4012
.const P_SCAN_SW 0x4013
.const P_SCAN_S 0x4014
.const P_SCAN_SE 0x4015
.const P_SCAN_E 0x4016
.const P_SCAN_NE 0x4017

.const P_MOVE_N 0x4020
.const P_MOVE_NW 0x4021
.const P_MOVE_W 0x4022
.const P_MOVE_SW 0x4023
.const P_MOVE_S 0x4024
.const P_MOVE_SE 0x4025
.const P_MOVE_E 0x4026
.const P_MOVE_NE 0x4027

####################
# REGISTERS
#
# r1: proximity scan result
# r2: direction counter
# r3: bit test result
# r200: 1
#
# !rand
# r120: return address
# r121: returned random bit string
# r122--124: internal seed history
####################

movi r1 = 6
movi r2 = 2
movi r3 = 4
movi r4 = 2

!main
  movi r10 = 4

!first
  stor[r1 + P_MOVE_N] = r0
  dec r10
  brag[!first], r10 > r0
  movi r10 = 4

!second
  stor[r2+P_MOVE_N] = r0
  dec r10
  brag[!first], r10 > r0

!third
  stor[r3 + P_MOVE_N] = r0

!next
  movi r1 = 0
  movi r2 = 4
  movi r3 = 6
  brag [!main], r4 > r0

!inf
  bra[!inf]
