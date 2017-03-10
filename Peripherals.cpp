#include <iostream>
#include "Peripherals.h"
#include "miniat/miniat.h"

#define P_THROTTLE 0x4000
#define P_STEER 0x4001
#define P_SPEED 0x4002
#define P_COMPASS 0x4003


#define P_PLAYER_X 0x4010
#define P_PLAYER_Y 0x4011
#define P_PLAYER_XY 0x4012
#define P_PLAYER_DIR 0x4013

#define P_NEAREST_X 0x4020
#define P_NEAREST_Y 0x4021
#define P_NEAREST_XY 0x4022
#define P_NEAREST_DIR 0x4023
#define P_NEAREST_DIST 0x4024

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
				case P_THROTTLE:
					std::cout << "Stored" << (signed)bus.data << " to the P_THROTTLE peripheral" << std::endl;
					break;
				case P_STEER:
					std::cout <<"STORed " << (signed)bus.data << " to the P_STEER peripheral" << std::endl;
					break;
				case P_COMPASS:
					std::cout << "STORed " << (signed)bus.data << " to the P_COMPASS peripheral" << std::endl;
					break;
				case P_SPEED:
					std::cout << "STORed " << (signed)bus.data << " to the P_SPEED peripheral" << std::endl;
					break;
				case P_PLAYER_X:
					std::cout << "STORed " << (signed)bus.data << " to the P_PLAYER_X peripheral" << std::endl;
					break;
				case P_PLAYER_Y:
					std::cout << "STORed " << (signed)bus.data << " to the P_PLAYER_Y peripheral" << std::endl;
					break
				case P_PLAYER_XY:
					std::cout << "STORed " << (signed)bus.data << " to the P_PLAYER_XY peripheral" << std:endl;
					break;
				case P_PLAYER_DIR:
					std::cout << "STORed " << (signed)bus.data << " to the P_PLAYER_DIR peripheral" << std::endl;
					break;
				case P_NEAREST_X:
					std::cout << "STORed " << (signed)bus.data << " to the P_NEAREST_X peripheral" << std::endl;
					break;
				case P_NEAREST_Y:
					std::cout << "STORed " << (signed)bus.data << " to the P_NEAREST_Y peripheral" << std::endl;
					break
				case P_NEAREST_XY:
					std::cout << "STORed " << (signed)bus.data << " to the P_NEAREST_XY peripheral" << std::endl;
					break
				case P_NEAREST_DIR:
					std::cout << "STORed " << (signed)bus.data << " to the P_NEAREST_DIR peripheral" << std::endl;
					break
				case P_NEAREST_DIST:
					std::cout << "STORed " << (signed)bus.data << " to the P_NEAREST_DIST peripheral" << std::endl;
					break;
				default:
					std::cout << "There is no peripheral accepting writes at 0x" << bus.address << std::endl;
					break;


			}
		}else
		{
			/* LOAD from peripheral */

			switch(bus.address)
			{
				case P_THROTTLE:
					std::cout << "LOADed from P_THROTTLE" << std::endl;
					break;
				case P_STEER:
					std::cout << "LOADed from P_STEER" << std::endl;
					break;
				case P_SPEED:
					std::cout << "LOADed from P_SPEED" << std::endl;
					break;
				case P_COMPASS:
					std::cout << "LOADed from P_COMPASS" << std::endl;
					break;
				case P_PLAYER_X:
					std::cout << "LOADed from P_PLAYER_X" << std::endl;
					break;
				case P_PLAYER_Y:
					std::cout << "LOADed from P_PLAYER_Y" << std::endl;
					break;
				case P_PLAYER_XY:
					std::cout << "LOADed from P_PLAYER_XY" << std::endl;

				/*
				*
				* Please finish the case stuff before pushing
				*/
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