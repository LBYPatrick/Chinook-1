
#include "ChinookTest.h"
/* settings */
const static double global_speed_limit = 0.8;





class Robot: public frc::IterativeRobot {
public:

    DriveTrain drive;

    Servo servo;

    Robot() : drive( global_speed_limit ), servo(4) {}

    /**
     * @Override
     */
    void RobotInit()  {

        DriveTrain dt();
        std::cout << "Chinook: RobotInit VER " << VERSION << std::endl;
    }

    /**
     * @Override
     */
    void AutonomousInit() override {
        std::cout << "Chinook: Called AutonomousInit\nChinook: Warning: Autonomous is yet to be implemented." << std::endl;
    }

    /**
     * @Override
     */
    void AutonomousPeriodic() {
        std::cout << "Chinook: Called AutonomousPeriodic" << std::endl;
    }

    /**
     * @Override
     */
    void TeleopInit() {
        std::cout << "Chinook: Called TeleopInit" << std::endl;

    }

    /**
     * @Override
     */
    void TeleopPeriodic() {
       // std::cout << "Chinook: Called TeleopPeriodic" << std::endl;
        setOpState();
        if(OpState.gpIsRightBumperPressed) drive.ChangeBy(0.01);
        if(OpState.gpIsLeftBumperPressed) drive.ChangeBy(-0.01);
        drive.ArcadeDrive(OpState.gpRightStickX, OpState.gpRightStickY);
    }

    /**
     * @Override
     */
    void TestPeriodic() {
        reportMsg("servo test\n");
        servo.SetAngle(120);
        int i;
        for(i = 0; i <= 1000; i++); //wait
        servo.SetAngle(30);
    }


private:

};



START_ROBOT_CLASS(Robot)
