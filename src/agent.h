/*****************************************************************************
 *  agent.h                                                                  *
 *                                                                           *
 *  Created on:   Jul 17, 2014                                               *
 *  Author:       Dennis Goldschmidt                                         *
 *  Email:        goldschmidtd@ini.phys.ethz.ch                              *
 *                                                                           *
 *                                                                           *
 *  Copyright (C) 2014 by Dennis Goldschmidt                                 *
 *                                                                           *
 *  This file is part of the program NaviSim                                 *
 *                                                                           *
 *  NaviSim is free software: you can redistribute it and/or modify          *
 *  it under the terms of the GNU General Public License as published by     *
 *  the Free Software Foundation, either version 3 of the License, or        *
 *  (at your option) any later version.                                      *
 *                                                                           *
 *  This program is distributed in the hope that it will be useful,          *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
 *  GNU General Public License for more details.                             *
 *                                                                           *
 *  You should have received a copy of the GNU General Public License        *
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.    *
 *                                                                           *
 ****************************************************************************/

#ifndef AGENT_H_
#define AGENT_H_

#include <iostream>
#include <fstream>
//#include "controller.h"
using namespace std;


/**
 * Agent Class
 *
 *	This class creates agents, which are defined by x & y
 *	coordinates in a 2D plane. Agents are updated inside the
 *	environment class.
 *
 */

class Agent {
public:

	/**
	 * Constructor
	 *
	 * @param (double) start_x: initial x position of agent (default: 0.0)
	 * @param (double) start_y: initial y position of agent (default: 0.0)
	 * @param (bool) in_verbose: debugging
	 * @return (class object)
	 */
	Agent(bool in_verbose=false, double start_x=0.0, double start_y=0.0);

	/**
	 * Destructor
	 */
	~Agent();


	//************ Class functions ************//

	/**
	 * Returns angle within bounds [-PI,PI]
	 *
	 * @param (double) angle: input angle
	 * @return (double)
	 */
	double bound(double angle);

	/**
	 * Returns distance to home
	 *
	 * @return (double)
	 */
	double d();

	/**
	 * Returns difference in heading direction of agent
	 *
	 * @return (double)
	 */
	double dphi();

	/**
	 * Returns estimated home vector of the agent (0 == x, 1 == y)
	 *
	 * @param (int) index of home vector
	 * @return (bool)
	 */
	//double HV(int index);

	/**
	 * Returns the foraging state of the agent (TRUE, if inward)
	 *
	 * @return (bool)
	 */
	bool in();

	/**
	 * Initializes internal controller
	 *
	 *  @return (void)
	 */
	//void init(Controller* control);

	/**
	 * Sets write option to false -> no writing to file
	 *
	 *  @return (void)
	 */
	void no_write();

	/**
	 * Returns heading direction of agent
	 *
	 * @return (double)
	 */
	double phi();

	/**
	 * Returns a random number drawn from a uniform distribution
	 *
	 * @param (double) min: lower bound of the distribution (default: 0.0)
	 * @param (double) max: upper bound of the distribution (default: 1.0)
	 * @return (double)
	 */
	double rand(double min, double max);

	/**
	 * Resets the agent to the home position at (0.,0.)
	 *
	 * @return (void)
	 */
	void reset();

	/**
	 * Sets the difference in heading direction of the agent
	 *
	 * @param (double) input: difference in heading
	 * @return (void)
	 */
	void set_dphi(double input);

	/**
	 * Sets the heading direction of the agent
	 *
	 * @param (double) input: new heading
	 * @return (void)
	 */
	void set_phi(double input);

	/**
	 * Sets the foraging state of agent
	 *
	 * @param (bool) input: foraging state (TRUE, if inward)
	 * @return (void)
	 */
	void set_inward(bool input);

	/**
	 * Sets the x position of the agent
	 *
	 * @param (double) input: new x position
	 * @return (void)
	 */
	void set_x(double input);

	/**
	 * Sets the y position of the agent
	 *
	 * @param (double) input: new y position
	 * @return (void)
	 */
	void set_y(double input);

	/**
	 * Returns global time
	 *
	 * @return (double)
	 */
	double t();

	/**
	 * Returns angle of home vector w.r.t. x-axis
	 *
	 * @return (double)
	 */
	double th();

	/**
	 * Transposes the agent to a new position given by (x_new, y_new)
	 *
	 * @param (double) x_new: new x position
	 * @param (double) y_new: new y position
	 * @return (void)
	 */
	void to(double x_new, double y_new);

	/**
	 * Returns trial time
	 *
	 * @return (double)
	 */
	double trial_t();

	/**
	 * Updates the kinematics of agent based on the motor command from the controller
	 *
	 * @param (double) command: motor command
	 * @param (double) speed_command: motor speed command
	 * @return (void)
	 */
	void update();

	/**
	 * Returns the linear speed of the agent
	 *
	 * @return (double)
	 */
	double v();

	/**
	 * Returns the x coordinate of the agent
	 *
	 * @return (double)
	 */
	double x();

	/**
	 * Returns the y coordinate of the agent
	 *
	 * @return (double)
	 */
	double y();


	//************ Public class parameters ************//

	bool in_pipe;			// status if agent is in pipe [TRUE = agent is in a pipe; FALSE = it's free!]
	double test;


private:

	//************ Class object ************//
	//Controller* control;

	//************ Kinematics parameters ************//

	double control_output;
	double x_position;      // X position of agent
	double y_position;      // Y position of agent
	double heading;         // Angle of heading direction (in rad; ccw from x-axis)
	double speed;           // Walking speed of agent
	double k_phi;           // Steering constant
	double k_s;             // Acceleration constant
	double diff_heading;    // Change in heading direction (in rad)
	double external;		// External change in heading direction (in rad)
	double diff_speed;      // Change in walking speed of agent
	double theta;			// Angle of direction to home position (in rad)
	double distance;		// Distance to home position
	const double dt = 0.1;	// Integration time
	int type;               // Goal type
	bool inward;			// State of foraging (TRUE = towards home)

	//************ debugging ************//
	bool VERBOSE;
};

#endif /* AGENT_H_ */
