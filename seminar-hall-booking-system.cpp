#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <cstdlib>
#include <ctime>

using namespace std;

// Class

class Admin
{
	public:
		int user, admin_pass, admin, fac_pass, faculty, available, nos_stud, nos_fac,total;
    	int date,month,year;
    	std::string fac_name;
    	char gen;
		
    public:
        void DisplayHalls()
        {
            std::cout << " 1. MBA MINI SEMINAR HALL \n";
            std::cout << " 2. MBA SEMINAR HALL \n";
            std::cout << " 3. S&H SEMINAR HALL \n";
            std::cout << " 4. IT PARK SEMINAR HALL \n";
            std::cout << " 5. KEC CONVENTION CENTER \n";
        }
        void Capacity()
        {
        	std::cout << "\n Enter Details to Book Seminar Hall : \n";

                std::cout << "\n Enter Number of Students : ";
                std::cin >> nos_stud;
                std::cout << "\n Enter Number of Faculty : ";
                std::cin >> nos_fac;
                std::cout << "\n";
                total = nos_stud + nos_fac;
                std::cout << " Your Requirement for Hall : " << total;
                std::cout << "\n";

                if (total < 50)
                {
                    std::cout << " Can't able to Book Seminar Hall ! \n";
                    std::cout << " Low Capacity ! \n";
                }
                else if (total >= 50 && total <= 100)
                {
                    std::cout << "\n ( MBA Mini Seminar Hall ) is suitable for your Requirements \n";
                }
                else if (total > 100 && total <= 200)
                {
                    std::cout << "\n ( S&H Seminar Hall ) is suitable for your Requirements \n";
                }
                else if (total > 200 && total <= 300)
                {
                    std::cout << "\n ( MBA Seminar Hall ) is suitable for your Requirements \n";
                }
                else if (total > 300 && total <= 400)
                {
                    std::cout << "\n ( IT PARK Seminar Hall ) is suitable for your Requirements \n";
                }
                else if (total > 400 && total <= 5000)
                {
                    std::cout << "\n ( KEC Convention Center ) is suitable for your Requirements \n";
                }
                else
                {
                    std::cout << " Invalid input \n";
                    std::cout << " Too Much Capacity !\n Enter capacity between (50-5000) \n";
                }
		}
			void Events()
			{
				std::cout << " 1. Dance \n";
           		std::cout << " 2. Quiz \n";
            	std::cout << " 3. Singing \n";
            	std::cout << " 4. Drama \n";
            	std::cout << " 5. Presentation \n";
            	std::cout << " 6. Talent Show \n";
            	std::cout << " 7. Debate \n";
            	std::cout << " 8. Music \n";
            	std::cout << " 9. Guest Lecture \n";
            	std::cout << " 10. Club Events \n";
			}
};
 
// Others class

class Others : public Admin
{
	public:
		std::string others_name;
	public:
		void welcome()
		{
			std::cout<<" Enter Your Name : ";
			std::cin>>others_name;
			std::cout<<"\n Welcome "+ others_name +" to Seminar Hall Booking Application ! \n";
		}
};


// MySQL Database Details : 

const char HOST[] = "localhost";
const char USER[] = "root";
const char PASS[] = "Akil_02";
const char DB[] = "KEC";
const char T[] = "hall";

int main()
{
	// Object for HallNames class
	Admin h;
	Others o;
	
	int user, admin_pass, admin, fac_pass, faculty, available, nos_stud, nos_fac,total,randomNumber,others_opt,a_pass;
    int date,month,year;
    std::string fac_name,dept_name,others_name;;
    char gen,fac_permission;

    MYSQL* obj;

    int sno;
    char hall_name[100];
    char event[100];
    char event_date[11];

    bool ProgramIsOpened = true;
    int answer;

    char* consult;
    char* sentence;
    string sentence_aux;

	//Password Details : 
	
    admin = 12345;
	faculty = 67890;
	
	std::cout << " \t\t\t\t\t\t ********** SEMINAR HALL BOOKING SYSTEM FOR KEC ********** \n";
	std::cout << " 1 -> Admin Login\n";
	std::cout << " 2 -> Faculty Login\n";
	std::cout << " 3 -> Others Login\n";
	std::cout << "\n";
	std::cout << " Enter User option : ";
	std::cin >> user;
	std::cout << "\n";
	
	
	switch (user)
	{
	case 1:
    std::cout << "\n\n";
    std::cout << "\t\t\t\t\t\t\t ********** ADMINISTRATOR LOGIN ********** ";
    std::cout << "\n\n";
    std::cout << "You Entered as an Admin\n";
    std::cout << "\n";
    std::cout << "Enter Admin Password : ";
    std::cin >> admin_pass;
    std::cout << "\n";
    if (admin_pass == admin)
        std::cout << "Permission Granted !\n";
    else
	{
    std::cout << "Permission Denied !\n";
    std::cout << "Check Password or Login Details\n";
    return 0;
	}
    // MySQL Connection Establishment 

    if (!(obj = mysql_init(0)))
    {
        cout << "ERROR : MySQL can't able to connect \n";
    }
    else
    {
        if (!mysql_real_connect(obj,HOST,USER,PASS,DB,0,T,0))
        {
            cout << "ERROR : Something went wrong in Database connectivity !\n";
            cout << mysql_error(obj) << "\n";
        }
        else
        {
        while (1)
        {
            std::cout << "\n\t\t\t\t\t\t\t ********** SEMINAR HALL OPTIONS  ********** \n";
            std::cout << "\n 1 -> Display List of Seminar Halls Available at KEC \n";
            std::cout << "\n 2 -> Enter Capacity \n";
            std::cout << "\n 3 -> Type of Events \n";
            std::cout << "\n 4 -> Enter Date Details \n";
            std::cout << "\n 5 -> Book Hall \n";
            std::cout << "\n";
            std::cout << " Enter option : ";
            std::cin >> available;


            if (available == 1)
            {

                std::cout << "\n\t\t\t\t\t\t\t ********** LIST OF SEMINAR HALLS AT KEC ********** \n";
                h.DisplayHalls();
            }

            if (available == 2)
            {
                h.Capacity();
            }

            if (available == 3)
            {
                std::cout << "\n\t\t\t\t\t\t ********* LIST OF EVENTS ********* \n";
                h.Events();
            }

            if (available == 4)
            {
                std::cout << "\n Enter Date of Event - (DD/MM/YY) \n\n";
                std::cout << " Enter Date : ";
                std::cin >> date;
                if (date < 1 && date > 31)
                {
                    std::cout << " Invalid input\n";
                    std::cout << " Date must bteween (1-31) \n";
                    break;
                }
                std::cout << " Enter Month : ";
                std::cin >> month;
                if (month < 0 && month > 12)
                {
                    std::cout << " Invalid input\n";
                    std::cout << " Month must bteween (1-12) \n";
                    break;
                }
                std::cout << " Enter Year : ";
                std::cin >> year;
                
                if (year != 24 && year != 25)
                {
                    std::cout << " Invalid input\n";
                    std::cout << " Year must between (24-25) \n";
                    break;
                }
        	}
        	if (available == 5)
        	{
        	//cout << "\n Successfully Logged in ! \n";

            while (ProgramIsOpened)
            {
            	
				//Genrate random number
				std::srand(std::time(0));
    			randomNumber = std::rand() % 9999 + 1;
    			std::cout << "\n Your Hall ID is : " << randomNumber << std::endl;
				
                cout << "\n Enter ID : ";
                cin >> sno;
                cin.ignore(100, '\n');

                cout << "\n Enter Hall Name : ";
                cin.getline(hall_name, 100, '\n');

                cout << "\n Enter Event Name : ";
                cin.getline(event, 100, '\n');

                cout << "\n Enter Date (YYYY-MM-DD) : ";
                cin.getline(event_date, 11, '\n');

                // inserting values into database

                sentence_aux = "INSERT INTO hall(hall_id, hall_name, event, event_date) VALUES (%d, '%s', '%s', '%s');";
                sentence = new char[sentence_aux.length() + 1];
                strcpy(sentence, sentence_aux.c_str());

                consult = new char[strlen(sentence) + sizeof(int) + strlen(hall_name) + strlen(event) + strlen(event_date)];
                sprintf(consult, sentence, sno, hall_name, event, event_date);

                if (!mysql_ping(obj))
                {
                    if (mysql_query(obj, consult))
                    {
                        cout << "ERROR : " << mysql_error(obj) << "\n";
                        rewind(stdin);
                        getchar();
                    }
                    else
                    {
                        cout << "\n Data Added Successfully !\n";
                        cout << " THANK YOU ! \n";
                    }
                    mysql_store_result(obj);

                    cout << "\n" << " Book Another Hall ? \n";
                    cout << " [1] - Continue \n";
                    cout << " [0] - Exit \n";
                    cout << " Enter Option :  ";
                    cin >> answer;
                    cin.ignore(100, '\n');

                    if (answer == 0)
                    {
                        ProgramIsOpened = false;
                    }
                    cout << "\n";
                }
                else
                {
                    cout << " ERROR : Impossible to connect ! \n";
                    cout << mysql_error(obj) << "\n";
                }
            }
        			std::cout << "\n\t\t\t\t\t\t ~~~~~~~~~~ Seminar Hall Successfully Booked ! ~~~~~~~~~~ \n";
                	std::cout << "\n\t\t\t\t\t\t\t Hall Booked Date Details : "<<date <<"/" << month <<"/" << year << "\n";
                	std::cout << "\n\t\t\t\t\t\t\t\t  THANKING YOU ! ";
                	exit(1);
				} 
       		}
    	}
	}	
	break;
    case 2:
        std::cout << "\n\n";
        std::cout << "\t\t\t\t\t\t\t ********** FACULTY LOGIN ********** ";
        std::cout << "\n\n";
        std::cout << " You Entered as a Faculty\n";
        std::cout << "\n";
        std::cout << " Enter Faculty Password : ";
        std::cin >> fac_pass;
        std::cout << "\n";
        if (fac_pass == faculty)
        {
            std::cout << " Permission Granted !\n";
            std::cout << "\n Enter Name : ";
            std::cin >> fac_name;
            std::cout << "\n Enter Department Name : ";
            std::cin >> dept_name;
            std::cout << "\n Enter Gender (m/f) : ";
            std::cin >> gen;
            if(gen=='m'||gen=='M')
                std::cout << "\n Welcome " + fac_name + " Sir !";
            else if (gen == 'f' || gen == 'F')
                std::cout << "\n Welcome " + fac_name + " Ma'am ! \n";
            else
                std::cout << " Invalid input ! \n";
        }
        else
        {
            std::cout << "\n Permission Denied !\n";
            std::cout << "\n Check Password or Login Details\n";
            return 0;
        }
        std::cout << "\n Want to Access Database (Y/N) : ";
        std::cin >> fac_permission;
        if(fac_permission == 'y'||fac_permission =='Y')
        {
        	std::cout<<"\n Enter Admin Password to access Database : ";
        	std::cin>>a_pass;
        	if(a_pass==admin)
        	{
        		std::cout << "\n Permission Granted to access Database !\n";
			}
			else
			{
				std::cout << "\n Permission Denied to access Database ! \n";
			}
		}
        else
        {
            std::cout << "\n\t\t\t\t\t\t ~~~~~~~~~~ THANKING YOU ~~~~~~~~~~ ";
            std::cout << "\n For Visiting Seminar Hall Booking Application ! \n";
            return 0;
        }
        break;
    case 3:
        std::cout << "\t\t\t\t\t\t\t ********** OTHERS LOGIN ********** \n";
        o.welcome();
        while(1)
    {
        std::cout << "\n 1 -> View List of Halls at KEC \n";
        std::cout << "\n 2 -> View List of Events \n";
        std::cout << "\n Enter option : ";
        std::cin >> others_opt;
        std::cout<<"\n";
        switch(others_opt)
        {
        	case 1:
        		o.DisplayHalls();
        	break;
			case 2:
				o.Events();
			break;
			case -1:
				break;
			default:
				std::cout << " Invalid Input ! \n";
			break;	
		}
	}
			std::cout << "\n\t\t\t\t\t\t ~~~~~~~~~~ THANKING YOU ~~~~~~~~~~ ";
            std::cout << "\n For Visiting Seminar Hall Booking Application ! \n";
        break;
    }
    return 0;
}
