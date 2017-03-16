#include <iostream>
#include "Peripherals.h"
#include "miniat/miniat.h"

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

void peripherals_clock(miniat *m)
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
					std::cout << "STORed" << (signed)bus.data << " to the P_MOVE_N peripheral" << std::endl;
					break;
				case P_MOVE_NW:
					std::cout << "STORed" << (signed)bus.data << " to the P_MOVE_NW peripheral" << std::endl;
					break;
				case P_MOVE_W:
					std::cout << "STORed" << (signed)bus.data << " to the P_MOVE_W peripheral" << std::endl;
					break;
				case P_MOVE_SW:
					std::cout << "STORed" << (signed)bus.data << " to the P_MOVE_SW peripheral" << std::endl;
					break;
				case P_MOVE_S:
					std::cout << "STORed" << (signed)bus.data << " to the P_MOVE_S peripheral" << std::endl;
					break;
				case P_MOVE_SE:
					std::cout << "STORed" << (signed)bus.data << " to the P_MOVE_SE peripheral" << std::endl;
					break;
				case P_MOVE_E:
					std::cout << "STORed" << (signed)bus.data << " to the P_MOVE_E peripheral" << std::endl;
					break;
				case P_MOVE_NE:
					std::cout << "STORed" << (signed)bus.data << " to the P_MOVE_NE peripheral" << std::endl;
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
					break;
				case P_SCAN_NW:
					std::cout << "LOADed from P_SCAN_NW" << std::endl;
					break;
				case P_SCAN_W:
					std::cout << "LOADed from P_SCAN_W" << std::endl;
					break;
				case P_SCAN_SW:
					std::cout << "LOADed from P_SCAN_SW" << std::endl;
					break;
				case P_SCAN_S:
					std::cout << "LOADed from P_SCAN_S" << std::endl;
					break;
				case P_SCAN_SE:
					std::cout << "LOADed from P_SCAN_SE" << std::endl;
					break;
				case P_SCAN_E:
					std::cout << "LOADed from P_SCAN_E" << std::endl;
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

	return;

}