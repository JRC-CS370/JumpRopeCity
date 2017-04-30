#include <iostream>
#include "Peripherals.h"
#include "miniat/miniat.h"
#include "Player.h"

//Proximity Scan; LOAD functions
#define P_PROX_SCAN 0x4000

//Direction Scan; LOAD functions
#define P_SCAN_N 0x4010
#define P_SCAN_NW 0x4011
#define P_SCAN_W 0x4012
#define P_SCAN_SW 0x4013
#define P_SCAN_S 0x4014
#define P_SCAN_SE 0x4015
#define P_SCAN_E 0x4016
#define P_SCAN_NE 0x4017

//Movement Stuff; STOR functions
#define P_MOVE_N 0x4020
#define P_MOVE_NW 0x4021
#define P_MOVE_W 0x4022
#define P_MOVE_SW 0x4023
#define P_MOVE_S 0x4024
#define P_MOVE_SE 0x4025
#define P_MOVE_E 0x4026
#define P_MOVE_NE 0x4027

void peripherals_cleanup()
{
	/* Nothing to do so far */
	return;
}

/**
 * [peripherals_clock runs throught the periphreals and executes commands
 * based on the current .asm file that is being run]
 * @param  m   [instance of the miniAT system]
 * @param  p   [instance of the current player]
 * @param  map [instance of the map class that contains the ropes]
 * @return     [The return returns the current player back to where
 *              it was called from, allowing the program to continue]
 */
void peripherals_clock(miniat *m, Player &p, Map &theMap)
{
	m_bus bus;

	if(!m)
	{
		std::cout << "NULL MiniAT on peripheral clock" << std::endl;
		exit(EXIT_FAILURE);
	}

	bus = miniat_pins_bus_get(m);

	if(bus.req == M_HIGH && bus.ack == M_LOW)
	{
		/*
		 * MiniAT waiting for peripheral ack
		 */

		bool handled = true;
		if(bus.rW == M_HIGH)
		{
			/* STOR to peripheral */

			switch(bus.address)
			{
				case P_MOVE_N:
					//std::cout << "STORed" << (signed)bus.data << " to the P_MOVE_N peripheral" << std::endl;
					p.movePlayerUp(theMap);
					std::cout << "Called movePlayerUp" << std::endl;
					break;
				case P_MOVE_NW:
					//std::cout << "STORed" << (signed)bus.data << " to the P_MOVE_NW peripheral" << std::endl;
					p.movePlayerNorthWest(theMap);
					std::cout << "Called movePlayerNorthWest" << std::endl;
					break;
				case P_MOVE_W:
					//std::cout << "STORed" << (signed)bus.data << " to the P_MOVE_W peripheral" << std::endl;
					p.movePlayerLeft(theMap);
					std::cout << "Called movePlayerLeft" << std::endl;
					break;
				case P_MOVE_SW:
					//std::cout << "STORed" << (signed)bus.data << " to the P_MOVE_SW peripheral" << std::endl;
					p.movePlayerSouthWest(theMap);
					std::cout << "Called movePlayerSouthWest" << std::endl;
					break;
				case P_MOVE_S:
					//std::cout << "STORed" << (signed)bus.data << " to the P_MOVE_S peripheral" << std::endl;
					p.movePlayerDown(theMap);
					std::cout << "Called movePlayerDown" << std::endl;
					break;
				case P_MOVE_SE:
					//std::cout << "STORed" << (signed)bus.data << " to the P_MOVE_SE peripheral" << std::endl;
					p.movePlayerSouthEast(theMap);
					std::cout << "Called movePlayerSouthEast" << std::endl;
					break;
				case P_MOVE_E:
					p.movePlayerRight(theMap);
					std::cout << "Called movePlayerRight" << std::endl;
					//std::cout << "STORed" << (signed)bus.data << " to the P_MOVE_E peripheral" << std::endl;
					break;
				case P_MOVE_NE:
					p.movePlayerNorthEast(theMap);
					std::cout << "Called movePlayerNorthEast" << std::endl;
					break;
					//std::cout << "STORed" << (signed)bus.data << " to the P_MOVE_NE peripheral" << std::endl;
				default:
					std::cout << "There is no peripheral accepting writes at 0x" << bus.address << std::endl;
					break;
			}
		}else
		{
			/* LOAD from peripheral */

			switch(bus.address)
			{
				case P_PROX_SCAN:
					std::cout << "LOADed from P_PROX_SCAN" << std::endl;
				case P_SCAN_N:
					std::cout << "LOADed from P_SCAN_N" << std::endl;
					//bus.data = p.scanNorth(map);
					break;
				case P_SCAN_NW:
					std::cout << "LOADed from P_SCAN_NW" << std::endl;
					break;
				case P_SCAN_W:
					std::cout << "LOADed from P_SCAN_W" << std::endl;
					//bus.data = p.scanWest(map);
					break;
				case P_SCAN_SW:
					std::cout << "LOADed from P_SCAN_SW" << std::endl;
					break;
				case P_SCAN_S:
					std::cout << "LOADed from P_SCAN_S" << std::endl;
					//bus.data = p.scanSouth(map);
					break;
				case P_SCAN_SE:
					std::cout << "LOADed from P_SCAN_SE" << std::endl;
					break;
				case P_SCAN_E:
					std::cout << "LOADed from P_SCAN_E" << std::endl;
					//bus.data = p.scanEast(map);
					break;
				case P_SCAN_NE:
					std::cout << "LOADed from P_SCAN_NE" << std::endl;
				default:
					std::cout << "There is no peripheral accepting reads at 0x" << bus.address << std::endl;
					break;
			}
		}

		if(handled)
		{
			bus.ack = M_HIGH;
		}
	}else if(bus.ack)
	{
		/*
		* The MiniAT is waiting for the peripheral to lower the ACK pin.
		* Devices intended to take longer than normal should add delay
		* "cases's here.
		*/

		switch(bus.address)
		{
			default:
				bus.ack = M_LOW;
				break;
		}
	}

	miniat_pins_bus_set(m, bus);


}
