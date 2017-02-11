
#include "ChinookTest.h"
/* settings */
const static double global_speed_limit = 0.8;





class Robot: public frc::IterativeRobot {
public:

    DriveTrain drive;

    Servo servo;

    Robot() : drive( global_speed_limit ), servo(8) {}

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
    void TestInit() {
        servo.Set(1);

    }

    /**
     * @Override
     */
    void TestPeriodic() {


        std::cout << ("servo test\n");
        //double currentAngle = servo.GetAngle();
        //std::cout << "The current angle is " << servo.Get() << "\n" << std::endl;



        //The two extreme angles the servo will turn to.
        double min = 0;
        double max = 1;

        //for loop ensures servo has time to reach designated angle (Starts moving once every 9,999 frames.)
        long i;
        for (i=0; i<9999; i++)
        {
            int set;
            if (i == 0) {

                //servo.SetAngle() does NOT work when used in this loop. servo.Set and servo.SetSpeed both work.
                if (servo.Get() > 0.95) {
                   // servo.Set(min);
                    servo.SetSpeed(-1);
                    set = 1;
                } else {
                    set = 0;
                }
                if (servo.Get() < 0.05 && set == 0) {
                   // servo.Set(max);
                    servo.SetSpeed(1);
                }
            }
            std::cout << "Set angle is " << servo.Get() << "       Cycle: " << i << "\n";
        }




     }

    //Untested function for moving servo below. Should move serve to angle pre-specified by "goal". Servo goes from 0 to 170, the side w/ red tape is the 170. -Liam

    //global var
    double goal = 150;

    void MoveServo()
    {
        //Limits input value to valid range of 0 to 170
        if (goal > 170)
        {
            goal = 170;
        }
        if (goal < 0)
        {
            goal = 0;
        }

        //Converts goal to a double usable by servo.Set()
        double goalSetting = goal/170.0;

        int done = 0;
        do {
            if (servo.Get() < goalSetting) {
                servo.SetSpeed(1);
            }
            if (servo.Get() > goalSetting)
            {
                servo.SetSpeed(-1);
            }
            if (servo.Get() == goalSetting)
            {
                done = 1;
            }
        } while (done == 0);
    }



        //std::cin >> goalAngle;
        /*
        if (!isGoingRight){
            if (servo.Get() > 0.95) {
                isGoingRight = true;
                servo.Set(0);
            }
        }
        if (isGoingRight){
            if (servo.Get() < 0.05) {
                isGoingRight = false;
                servo.Set(1);
            }
        }

         */
        /*
        servo.Set(1);
        while (servo.Get() < 0.95);
        servo.Set(0);
        while (servo.Get() > 0.05);

        cycle:
        if (currentAngle < goalAngle)
        {
            servo.Set(1.0);
            goto cycle;
        }
        if (currentAngle > goalAngle)
        {
            servo.Set(0);
            goto cycle;
        }
        if (currentAngle == goalAngle)
        {
            goto start;
        }


    }


private:
    bool isGoingRight = false;
         */
};




START_ROBOT_CLASS(Robot)
