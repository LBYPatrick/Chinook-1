//
// Created by explorer on 2/5/17.
//

#ifndef CHINOOKTEST1_DRIVETRAIN_H
#define CHINOOKTEST1_DRIVETRAIN_H
#include <iostream>
#include <memory>
#include <string>

#include "WPILib.h"
#include "IterativeRobot.h"
#include "DriverStation.h"
#include "RobotDrive.h"
#include "Victor.h"
#include "Joystick.h"
#include "HAL/HAL.h"
#include "FRC_NetworkCommunication/FRCComm.h"

#include "opState.h"
#include "DriveTrain.h"
#include "statics.h"
#include "utils.h"

class DriveTrain {
public:
    /**
     * Constructor for DriveTrain
     * @param speedLimit double The Speed Limit
     */

    explicit DriveTrain(double speedLimit) : speedLimit(speedLimit),
                                                         leftFront(LeftPortFront),
                                                         leftBack(LeftPortBack),
                                                         rightFront(RightPortFront),
                                                         rightBack(RightPortBack),
                                                         drive(leftFront, leftBack, rightFront, rightBack) {}

    /**
     * ArcadeDrive method
     * @param x double rotation
     * @param y double drive
     */
    void ArcadeDrive(double x, double y);

    /**
     * TankDrive method
     * @param left double left-stick
     * @param right double right-stick
     */
    void TankDrive(double left, double right);

    /**
     * Updates the speed limit
     * @param speedLimit double renews speed limit to a new one
     */
    void Update(double speedLimit);

    /**
     * Change by a speed limit
     * @param speedLimit  double increases/decreases speedLimit
     */
    void ChangeBy(double speedLimit);

private:
    double speedLimit;
    Victor leftFront, leftBack, rightFront, rightBack;
    RobotDrive drive;

    /**
     * The devised algorithm for limiting the speed.
     * @param a
     * @return
     */
    double limitSpeed(double a) { return a/std::abs(a) * (std::abs(a) > speedLimit ? speedLimit : std::abs(a)); }

};

#endif //CHINOOKTEST1_DRIVETRAIN_H
