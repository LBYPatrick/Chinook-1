#include "DriveTrain.h"


/**
 * ArcadeDrive method
 * @param x double rotation
 * @param y double drive
 */
void DriveTrain::ArcadeDrive(double x, double y) { drive.ArcadeDrive(-limitSpeed(y), -(limitSpeed(std::abs(y) >= 0.5 ? x * 0.6 : x))); }

/**
 * TankDrive method
 * @param left double left-stick
 * @param right double right-stick
 */
void DriveTrain::TankDrive(double left, double right) { drive.TankDrive(limitSpeed(left), limitSpeed(right)); }

/**
 * Updates the speed limit
 * @param speedLimit double renews speed limit to a new one
 */
void DriveTrain::Update(double speedLimit) { this->speedLimit = speedLimit; }

/**
 * Change by a speed limit
 * @param speedLimit  double increases/decreases speedLimit
 */
void DriveTrain::ChangeBy(double speedLimit) {
    this->speedLimit += ((this->speedLimit + speedLimit > 1.0000000001) ||
                         (this->speedLimit + speedLimit < -0.0000000001) ) ? 0: speedLimit;
    reportMsg("\rNewSpeedLimit" + std::to_string(this->speedLimit) + "     ");
    std::cout << "New Limit: " << this->speedLimit << std::endl;
}
