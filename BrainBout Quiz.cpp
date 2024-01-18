//team Techloom(2023761,2023408,2023669,2023683)
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

int Q_NO = 1;
int correct = 0;//counts correct answers
int wrong = 0;//counts wrong answers
bool ask[10] = {true, true, true, true, true, true, true, true, true, true};// makes sure that no question is repeated again

void question(string question, string a, string b, string c, string d, char correct_ans);// used to enter the questions with correct answer
void disp_ez_qs();// displays easy questions
void disp_mid_mt_qs();// displays medium questions
void disp_adv_mt_qs();
void disp_ez_eng_qs();
void disp_mid_eng_qs();
void disp_adv_eng_qs();
void disp_ez_code_qs();
void disp_mid_code_qs();
void disp_adv_code_qs();
void disp_ez_gk_qs();
void disp_mid_gk_qs();
void disp_adv_gk_qs();

void results();// displays results box
bool isLoggedIn(string& user_name, string& pass_word);// makes sure the person logs in correctly
void registerUser();// used to register a person
void startQuiz(int sub_choice, int diff_choice);// calls upon the start of quiz
void display();// displays result counter
void chooseSubject();

int main() {
    int choice;
    bool loggedIn = false;// set to false so user is initially prompted to log in
    string user_name;

    while (true) {
        cout << "Welcome to BrainBout Quiz App!" << endl;
        cout << "\n---------------------------" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();// calls upon user registration
                break;
            case 2: {
                string pass_word;
                bool status = isLoggedIn(user_name, pass_word); //makes sure the user correctly logs in.
                if (!status) {
                    cout << "Invalid login" << endl;
                } else {
                    cout << "Login successful" << endl;
                    loggedIn = true;
                }
                break;
            }
            case 3:
                cout << "Exiting the app..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        if (loggedIn) {
            int choiceTwo;
            cout << "Welcome back, " << user_name << "!" << endl;
            cout << endl;
            cout << "1. Sign out" << endl;
            cout << endl;
            cout << "2. Start Quiz" << endl << endl;
            cout << "3. Back to Main Menu" << endl << endl;
            cout << "Choose: ";
            cin >> choiceTwo;

            switch (choiceTwo) {
                case 1:
                    loggedIn = false;
                    cout << "Signing out..." << endl;
                    break;
                case 2:
                    chooseSubject(); // Choose subject and difficulty
                    break;
                case 3:
                    loggedIn = false;
                    break; // Continue to the main menu
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }
        }
    }

    return 0;
}
// Add these function implementations to your code

void registerUser() {
    string username, password;
    cout << "Registration: " << endl;
    cout << "Select a username: " << endl;
    cin >> username;
    cout << "Password: " << endl;
    cin >> password;
    ofstream file(username + ".txt"); // creates a file to hold un and pw
    file << username << endl << password;// puts the username and password into the text file created
    file.close();// closes file to stop further editing
    cout << "Welcome " << username << endl;
}

bool isLoggedIn(string& user_name, string& pass_word) {//pointer variables to store the username and password safely
    string un, pw;
    cout << "Enter your username: ";
    cin >> user_name;
    cout << "Enter your password: ";
    cin >> pass_word;

    ifstream read(user_name + ".txt"); // ifstream reads a file
    getline(read, un);                 // reads username
    getline(read, pw);                 // reads password

    if (un == user_name && pw == pass_word) {
        return true;
    } else {
        return false;
    }
}

void chooseSubject() {
    int sub_choice, diff_choice;
    cout << "Choose the subject you want to practice\n"
         << "1. Math\n"
         << "2. C++\n"
         << "3. English\n"
         << "4. General Knowledge" << endl;
    cout << "Enter your choice: ";
    cin >> sub_choice;
    startQuiz(sub_choice, diff_choice);
}

void startQuiz(int sub_choice, int diff_choice) {
    // Perform actions based on subject and difficulty choices
    cout << "Starting quiz with subject: " << sub_choice<< endl<<endl;
    switch (sub_choice) {
        case 1 : // Math
            cout << "Please choose difficulty level\n"
                << "1. Easy\n"
                << "2. Medium\n"
                << "3. Advanced\n";
            cin >> diff_choice;
            if(diff_choice == 1) {
                cout<<"Loading easy questions..."<<endl<<endl;
                disp_ez_qs();
            }
            else if(diff_choice == 2) {
                cout<<"Loading medium questions..."<<endl<<endl;
                disp_mid_mt_qs();
                //call function for medium questions
            }
            else if(diff_choice == 3) {
                cout<<"Loading advanced questions..."<<endl<<endl;
                disp_adv_mt_qs();
                //call function for advanced questions
            }
            break;
        case 2: // C++
            cout << "Please choose difficulty level\n"
                << "1. Easy\n"
                << "2. Medium\n"
                << "3. Advanced\n";
            cin >> diff_choice;
            if(diff_choice == 1) {
                cout<<"Loading easy questions..."<<endl<<endl;
                disp_ez_code_qs();
            }
            else if(diff_choice == 2) {
                cout<<"Loading medium questions..."<<endl<<endl;
                disp_mid_code_qs();
                //call function for medium questions
            }
            else if(diff_choice == 3) {
                cout<<"Loading advanced questions..."<<endl<<endl;
                disp_adv_code_qs();
                //call function for advanced questions
            }
            break;
        case 3: // English
            cout << "Please choose difficulty level\n"
                << "1. Easy\n"
                << "2. Medium\n"
                << "3. Advanced\n";
            cin >> diff_choice;
            if(diff_choice == 1) {
                cout<<"Loading easy questions..."<<endl<<endl;
                disp_ez_eng_qs();
            }
            else if(diff_choice == 2) {
                cout<<"Loading medium questions..."<<endl<<endl;
                disp_mid_eng_qs();
                //call function for medium questions
            }
            else if(diff_choice == 3) {
                cout<<"Loading advanced questions..."<<endl<<endl;
                disp_adv_eng_qs();
                //call function for advanced questions
            }
            break;
        case 4: // Engineering Exams
            cout << "Please choose difficulty level\n"
                << "1. Easy\n"
                << "2. Medium\n"
                << "3. Advanced\n";
            cin >> diff_choice;
            if(diff_choice == 1) {
                cout<<"Loading easy questions..."<<endl<<endl;
             disp_ez_gk_qs();
               //call function for easy questions
            }
            else if(diff_choice == 2) {
                cout<<"Loading medium questions..."<<endl<<endl;
                 disp_mid_gk_qs();
                //call function for medium questions
            }
            else if(diff_choice == 3) {
                cout<<"Loading advanced questions..."<<endl<<endl;
                 disp_adv_gk_qs(); 
                 //call function for advanced questions
            }
            break;
        default:
            cout << "Invalid subject choice." << endl<<endl;
            return;
    }
}

void display() {
    cout << "Question NO: " << Q_NO << "\t\tCorrect answers: " << correct << "\t\tWrong answers: " << wrong << endl<<endl;
    
}

void disp_ez_qs() {

    for (int i = 0; i < 10; i++) {
        if (ask[i]) {
            int no = i;

            if (ask[no]) {
                ask[no] = false;

                switch (no) {
                    case 0: 
					question("What is 4*4?",
					         "16",
					         "8",
					         "12",
				             "0", 'a');
                        break;
                    case 1: 
					question("What is sqrt(81)?",
					         "5", 
					         "3", 
					         "10",
					         "9", 'd');
                        break;
                    case 2:
                    	question("In a certain class the ratio of men to women is 3:5. If the class has 24 people in it, how many are women?",
						         "9",
						         "12",
						         "15",
						         "18",'c');
                    	break;
                    case 3:
                    	question("a number exceeds another number by 5.the sum of the numbers is 19. find the smaller number ?",
						         "5",
								 "6",
								 "7",
								 "14",'d');
                    	break;
                    case 4: 
					question("What is the Arithmetic Mean of the following data 3,6,9,12,15.",
					         "7",
							 "9",
							 "12",
							 "18",'b');
					    break;
					case 5:
					question("complete the series: 4.8.9.13.14.18.___?",
					         "22",
							 "32",
							 "11",
							 "19",'d');
				         break;
					case 6: 
					question("A student can solve q questions in 1/h hour. At this rate how many questions can she solve in q hours?",
					         "hq",
							 "hq2",
							 "1/hq",
							 "h/q",'b');
					    break;
					case 7:
					question("Find two number whose sum is 28 and the difference is 4 _____?",
					         "12,16",
							 "18,10",
							 "15,13",
							 "14,12",'a');
					    break;
					case 8:
					question("What is the Sum of First 70 Odd Numbers?",
					         "4900",
							 "4970",
							 "4960",
							 "none of these",'a');
					    break;
					case 9:
					question("What is the Sum of First 70 even Numbers?",
					         "4970",
							 "4950",
							 "4900",
							 "4980",'a');
					    break;
                    // Add more cases for additional questions...
                }
            }
        }
    }

    results();
}

//disp_med_questions(); for medium questions
void disp_mid_mt_qs()
{
	
	
	for (int i=0; i<10; i++)
	{
		if (ask[i])
		{
			int no= i;
			
			if (ask[no])
			{
				ask [no]=false;
				
				switch (no)
				{
					case 0: 
					question("What is the value of x2+14x+24? when x=854?",
					         "10,000 ",
							 "100,000 ",
							 "741,296",
							 "742398", 'c');
					    break;
                    case 1: 
					question("The average of the polynomials 2x^2 + 5x - 6, 5x^2 – 5x – 6, and 30 – 7x^2 is:",
					         "14", 
							 "6",
							 "18",
							 "5x", 'B');
                        break;
                    // Question 2
                    case 2:
                     question("What is the result of the expression: 2 * (5 + 3) / 4?", 
                              "A. 4", 
                              "B. 5", 
                              "C. 6", 
                              "D. 8", 'C');
                        break;

                    case 3:
					 question("The value x^2 + 5x + 6 at x=2?",
					          "2",
							  "10",
							  "15",
							  "20", 'D');
                        break;                        
					case 4: 
					question("What is the solution set of the equation: x^2 + 4x + 3 = 0",
					         "{1, 3}",
							 "{–1, 3}",
							 "{1, –3}",
							 "{–1, –3}", 'D');
                        break;
                    case 5: 
					question("The value of the function f(x)=x^2-6x+7 at x=2 is?",
					         "1",
							 "-1",
							 "2",
							 "-2", 'B');
                        break;
                    case 6: 
					question("An algebraic expression that contains only one term is called:",
					         "Monomial",
							 "Binomial",
							 "Trinomial",
							 "None of the above", 'A');
                        break;
                    case 7:
					question("5x+6y is a:",
					         "Monomial",
							 "Binomial",
							 "Trinomial",
							 "None of the above", 'B');
                        break;
                    case 8:
					question("The algebraic expression 3x+2y+6 is a:",
					         "Monomial",
							 "Binomial",
							 "Trinomial",
							 "None of the above", 'C');
                        break;
                    case 9:
					question("A polynomial contains ___ number of terms:",
					         "One",
							 "Two",
							 "Three",
							 "Any", 'D');
                        break;
				}
			}
		}
	}
	results();
}
void disp_adv_mt_qs()
{
	
	for (int i=0; i<10; i++)
	{
		if (ask[i])
		{
			int no= i;
			
			if (ask[no])
			{
				ask [no]=false;
				
				switch (no)
				{
				

                case 0: 
				question("What is the limit of sin(?)/? when ? approaches zero?", 
				         " 1",
						 " sin(?)",
						 " 0",
						 " None of these", 'a');
                     break;
                case 1: 
				question("What will be the condition for L’Hôpital’s Rule to work?",
				         " The function must possess at least three non-zero derivatives",
						 " The function must be determinate.",
						 " The function must be indeterminate.",
						 " The function must be inconsistent.", 'c');
                     break;

                case 2:
				 question("What’s mean when we say that f ”(k) = 0 @ (13, -2)?",
				          " There definitely is not an inflection point at that location.",
						  " There’s no way to tell without first knowing what the specific function is.",
						  " There is definitely an inflection point at that location.",
						  " There might be an inflection point at that location.", 'd');
                     break;
                case 3: 
				question("What will be the second step when we performing anti-differentiation?", 
				         " Multiply the coefficient by the new exponential value.",
						 " Divide the coefficient by the new exponential value.",
						 " Divide the coefficient by the old exponential value.",
						 " Subtract the new exponential value from the coefficient.", 'b');
                     break;

                 case 4: 
				 question("When f(x) = 3x^2, then F(x) is equals to?", 
				          " x^3 + C",
						  " 6x + C",
						  " 6x",
						  " x^3", 'a');
                      break;

                 case 5: 
				 question("What will be the types of errors that are related to differentials?", 
				          " Relative, Controllable.",
						  " Controllable, Natural.",
						  " Human, Absolute",
						  " Absolute, Relative", 'd');
                      break;

                  case 6: 
				  question("What is meant by the differential?", 
				           " A word used a lot on a popular medical television series.",
						   " A method of directly relating how changes in a dependent variable affect changes in an independent variable.",
						   " A gearbox on the back end of your car.",
						   " None of these", 'd');
                      break;

                  case 7: 
				  question("What is required for full determination of an anti-differentiated function?",
				           " Its real-world application",
						   " What its value is at (0, 0).",
						   " A boundary condition.",
						   " A lot of luck", 'c');
                       break;

                  case 8: 
				  question("If G(d) is determined to 3d + C; then C is called:",
				           " the constant of integration.",
						   " the constant of death and taxes.",
						   " the constant of differentiation.",
						   " the constant of anti-differentiation.", 'a');
                       break;

                  case 9: 
				  question("What is the answer to ?(1/x) dx?", 
				           " loge(x)",
						   " Undefined because you cannot divide by zero",
						   " ln(x) + C",
						   " ln(x)", 'c');
                         break;
                    }

				}
			}
		}
			results();
	}


//disp_advanced_questions(); for advanced questions
//disp_ez_eng_questions(); for

void disp_ez_eng_qs() {
   

    for (int i = 0; i < 10; i++) {
        if (ask[i]) {
            int yes = i;
            if (ask[yes]) {
                ask[yes] = false;

                switch (yes) {
                    case 0:
                        question("I came _____ America.",
						 "from",
						  "at", 
						  "in", 
						  "on", 'a');
                        break;
                    case 1:
                        question("I ____ cold.",
						 "am", 
						 "have", 
						 "had", 
						 "is", 'a');
                        break;
                    case 2:
                        question("_______ car is very old fashioned.", 
						"Fatima’s", 
						"Fatima is", 
						"Fatimas", 
						"Fatimas’", 'a');
                        break;
                    case 3:
                        question("I speak English but he_______.", 
						"doesn’t speaks", 
						"doesn’t speak", 
						"speaks",
					    "don’t speak", 'b');
                        break;
                    case 4:
                        question("Nowadays everyone ______ internet.", 
						"had used", 
						"uses", 
						"used", 
						"use", 'b');
                        break;
                    case 5:
                        question("____ there anybody in the room?", 
						"Are", 
						"is", 
						"am", 
						"if", 
						'a');
                        break;
                    case 6:
                        question("How many siblings ________?", 
						"do you have", 
						"have you gotten", 
						"did you had", 
						"both (A, B)", 'd');
                        break;
                    case 7:
                        question("What___ you doing?", 
						"is", 
						"are", 
						"am", 
						"if", 'b');
                        break;
                    case 8:
                        question("Which book is ______?",
						 "your", 
						 "your’s", 
						 "yours", 
						 "your is", 'c');
                        break;
                    case 9:
                        question("She is____ home.", 
						"at", 
						"in", 
						"on", 
						"from", 'a');
                        break;
                }
            }
        }
    }
      results();
}


void disp_mid_eng_qs() {
    

    for (int i = 0; i < 10; i++) {
        if (ask[i]) {
            int no = i;
            if (ask[no]) {
                ask[no] = false;

                switch (no) {
                    case 0:
                        question("I understand that you've sent him an e-mail message. I think you ............... him instead.", 
                                  " ought to have phoned", 
								  " should phone", 
								  " couldn't have phoned", 
								  " had phoned", 'a');
                        break;
                    case 1:
                        question("I promise that I will be here when you come back, but I'm afraid everyone else .............. by then.", 
                                  " were leaving", 
								  " leave", 
								  " are leaving", 
								  " will have left", 'd'); // Fixed the correct answer letter
                        break;
                    case 2:
                        question("Do you have any idea what she .............. at this time tomorrow?", 
                                  " has done", 
								  " will be doing", 
								  " was doing", 
								  " is doing", 'b'); // Fixed the correct answer letter
                        break;
                    case 3:
                        question("We ............... an interesting program before they came.", 
                                  " have been watching", 
								  " have watched", 
								  " are going to watch", 
								  " had been watching", 'c'); // Fixed the correct answer letter
                        break;
                    case 4:
                        question("He ............... from the university in 1995. Then, he ............... two years in the army.", 
                                  " has graduated / has spent", 
								  " had graduated / has spent", 
								  " graduated / spent", 
								  " has graduated / spent", 'c'); // Fixed the correct answer letter
                        break;
                    case 5:
                        question("They .............. together for almost a year at the time.", 
                                  " had been going out", 
								  " are going out", 
								  " have been going out", 
								  " have gone out", 'a');
                        break;
                    case 6:
                        question("They ............. each other for a long time before they finally decided to get married.", 
                                  " have known", 
								  " had been knowing", 
								  " were knowing", 
								  " had known", 'd'); // Fixed the correct answer letter
                        break;
                    case 7:
                        question("Nobody ............... him for weeks. I wonder where he ............... these days.", 
                                  " saw / is hanging about", 
								  " has seen / was hanging about", 
								  " has seen / is hanging about", 
								  " saw / was hanging about", 'c'); // Fixed the correct answer letter
                        break;
                    case 8:
                        question("Nobody ............... him for weeks. I wonder where he ............... all this time.", 
                                  " saw / had been hanging about", 
								  " had seen / had hung about", 
								  "has seen / has been hanging about", 
								  " had saw / had been hanging about", 'a'); // Fixed the correct answer letter
                        break;
                    case 9:
                        question("You ............... when I ............... on you that early, ............... you?", 
                                  " won't be sleeping / call / will", 
								  " were sleeping / had called / hadn't", 
								  " are sleeping / am calling / weren't", 
								  " have slept / have called / haven't", 'b'); // Fixed the correct answer letter
                        break;
                }
            }
        }
    }
    results();
}
void disp_adv_eng_qs()
{

    for (int i = 0; i < 10; i++)
    {
        if (ask[i])
        {
            int yes = i;

            if (ask[yes])
            {
                ask[yes] = false;

                switch (yes)
                {

                case 0:
                    question("In 1619 the first African slaves ____ in Virginia USA and by 1790 their numbers ____ nearly 700,000.",
					" were arriving / have been reaching", 
					" arrived / had reached", 
					" have arrived / were reaching", 
					" were going to arrive / reach", 'b');
                    break;
                case 1:
                    question("We ____ a lovely view of the Bosphorus and the bridges over it while the plane ____ over Istanbul.",
                             " are getting / flies", 
							 " had got / is flying", 
							 " got / was flying", 
							 " get / has flown",  'c');
                    break;
                case 2:
                    question("When they ____ in Sydney Harbour, they ____ nonstop for three months.",
                             " anchor / will have been sailing", 
							 " were anchoring / sailed", 
							 " have anchored / were sailing", 
							 " are anchoring / have been sailing", 'a');
                    break;
                case 3:
                    question("According to the new schedule, the whole team have accepted, we ____ every Monday and Wednesday next term, but I’m sure we ____ back to our normal routine of once a week before long.",
                             " had trained / revert", 
							 " train / have reverted", 
							 " are training / reverted", 
							 " are going to train / will revert", 'd');
                    break;
                case 4:
                    question("The prospector ran into town in excitement because, at last, he ____ some gold at the site which he ____ for months.",
                             " was finding / was panning", 
							 " will find / is going to pan", 
							 " will have found / has panned", 
							 " had found / had been panning", 'd');
                    break;
                case 5:
                    question("I expect you ____ bored with working at the Post Office by this time next year and ____ for a more interesting job.",
                             " have become / will have looked", 
							 " were becoming / are going to look", 
							 " will have become / will be looking", 
							 " had found / had been panning", 'c');
                    break;
                case 6:
                    question("Listen! The coach ____ the strengths of our opponents because our team ____ against them before.",
                             " has explained / weren’t playing", 
							 " explains / won’t play", 
							 " is explaining / haven’t played", 
							 " was explaining / don’t play",'c');
                    break;
                case 7:
                    question("When I ____ the alterations to the company accounts, I was left in no doubt that the accountant ____ money from the firm.",
                             " saw / had been stealing",
							 " am seeing / has stolen", 
							 " was seeing / was stealing", 
							 " have seen / will have stolen", 'a');
                    break;
                case 8:
                    question("According to the doctor, this time next week, I ____ around as normal and the cut on my foot ____ completely.",
                             " am walking / healed", 
							 " will be walking / will have healed", 
							 " walked / was healing",  
							 " have been walking / heals", 'b');
                    break;
                case 9:
                    question("Shadow puppets ____ in China and ____ as far as Turkey and Greece today.",
                             " will originate / have been spreading", 
							 " are originating / will be spreading", 
							 " originate / had spread", 
							 " originated / have spread", 'd');
                    break;
                }
            }
        }
    }
    results();
}
//disp_advanced_cpp;
void disp_ez_code_qs() {
    for (int i = 1; i < 11; i++) {
        if (ask[i]) {
            int no = i;
            if (ask[no]) {
                ask[no] = false;

                switch (no) {
                    case 1:
                        question("Who created C++?",
                                 " Bjarne Stroustrup", 
								 " Dennis Ritchie", 
								 " Ken Thompson", 
								 " Brian Kernighan", 'A');
                        break;
                    
                    case 2:
                        question("C++ Language developed at _________?",
                                 " AT & T's Bell Laboratories of USA in 1972",
                                 " Sun Microsystems in 1973",
                                 " Cambridge University in 1972",
                                 " AT & T's Bell Laboratories of USA in 1979", 'D');
                        break;

                    case 3:
                       question("Which one of the following is a keyword?",
                                " Size", 
								" Key", 
								" Jump", 
								" Switch", 'D');
                         break;

                    case 4:
                         question("____ is the smallest individual unit in a program.",
                                  " Variable", 
								  " Control", 
								  " Character", 
								  " Token", 'D');
                          break;

                    case 5:
                         question("Which of the following is the correct syntax for including user-defined header files in C++?",
                                  " #include <userdefined.h>", 
								  " #include <userdefined>", 
								  " #include “userdefined”", 
								  " #include [userdefined]", 'C');
                         break;

                    case 6:
                         question("Which of the following is a correct identifier in C++?",
                                   " 7var_name", 
								   " 7VARNAME", 
								   " VAR_1234", 
								   " $var_name", 'C');
                         break;

                    case 7:
                         question("Which of the following is called the address operator?",
                                   " *", 
								   " &", 
								   " _", 
								   " %", 'B');
                         break;

                     case 8:
                          question("C++ is _______ type of programming language.",
                                   " Object Oriented", 
								   " Procedural", 
								   "Bit level language",
								   " Functional", 'A');
                         break;

                     case 9:
                          question("Which of the following is used for comments in C++?",
                                    " // comment", 
									" /* comment /", 
									 "both // comment or / comment */"
									," // comment */", 'C');
                        break;
                    case 10:
                        question("What are the actual parameters in C++?",
                                 " Parameters with which functions are called",
                                 " Parameters which are used in the definition of a function",
                                 " Variables other than passed parameters in a function",
                                 " Variables that are never used in the function", 'A');
                        break;
                }
            }
        }
    }
    results();
}
void disp_mid_code_qs() {
    for (int i = 1; i < 11; i++) {
        if (ask[i]) {
            int yes = i;

            if (ask[yes]) {
                ask[yes] = false;

                switch (yes) {
                    case 1:
                        question("Where does the execution of the program start?",
                                 " user-defined function", 
								 " main function", 
								 " void function", 
								 " else function", 'B');
                        break;

                    case 2:
                        question("What are the mandatory parts in the function declaration?",
                                 " return type, function name", 
								 " return type, function name, parameters", 
								 " parameters, function name", 
								 " parameters, variables", 'A');
                        break;

                    case 3:
                        question("Which of the following is used to terminate the function declaration?",
                                 " :", 
								 " )", 
								 " ;", 
								 " ]", 'C');
                        break;

                    case 4:
                        question("How many can the max number of arguments present in a function in the C99 compiler?",
                                 " 99", 
								 " 90", 
								 " 102", 
								 " 127", 'D');
                        break;

                    case 5:
                        question("Which is more effective while calling the functions?",
                                 " call by value", 
								 " call by reference",
								 " call by pointer", 
								 " call by object", 'B');
                        break;

                    case 6:
                        question("What will be the output of the following C++ code?\n#include <iostream>\nusing namespace std;\nvoid car{\n    cout << \"Audi R8\";\n}\nint main() {\n    car();\n    return 0;\n}",
                                 " Audi R8", 
								 " Audi R8Audi R8", 
								 " compile time error", 
								 " runtime error", 'C');
                        break;

                    case 7:
                        question("What will be the output of the following C++ code?\n#include <iostream>\nusing namespace std;\nvoid fun(int x, int y){\n    x = 20;\n    y = 10;\n}\nint main() {\n    int x = 10;\n    fun (x, x);\n    cout << x;\n    return 0;\n}",
                                 " 10", 
								 " 20", 
								 " compile time error", 
								 " 30", 'A');
                        break;

                    case 8:
                        question("What is the scope of the variable declared in the user-defined function?",
                                 " whole program", 
								 " only inside the {} block", 
								 " the main function", 
								 " header section", 'B');
                        break;

                    case 9:
                        question("How many minimum numbers of functions should be present in a C++ program for its execution?",
                                 " 0", 
								 " 1", 
								 " 2", 
								 " 3", 'B');
                        break;

                    case 10:
                        question("Which of the following is the default return value of functions in C++?",
                                 " int", 
								 " char", 
								 " float", 
								 " void", 'A');
                        break;
                }
            }
        }
    }
    results();
}
void disp_adv_code_qs() {
    for (int i = 1; i < 11; i++) {
        if (ask[i]) {
            int no = i;
            if (ask[no]) {
                ask[no] = false;

                switch (no) {
                    case 1:
                        question("Which of the following correctly declares an array?",
                                 " int array[10];", 
								 " int array;", 
								 " array{10};", 
								 " array array[10];", 'A');
                        break;

                    case 2:
                        question("What is the index number of the last element of an array with 9 elements?",
                                 " 9", 
								 " 8", 
								 " 0", 
								 " Programmer-defined", 'B');
                        break;

                    case 4:
                        question("Which of the following gives the memory address of the first element in the array?",
                                 " array[0];", 
								 " array[1];", 
								 " array(2);", 
								 " array;", 'D');
                        break;

                    case 5:
                        question("What will be the output of the following C++ code?\n#include <iostream>\nusing namespace std;\nint array1[] = {1200, 200, 2300, 1230, 1543};\nint array2[] = {12, 14, 16, 18, 20};\nint temp, result = 0;\nint main() {\n    for (temp = 0; temp < 5; temp++){\n        result += array1[temp];\n    }\n    for (temp = 0; temp < 4; temp++){\n        result += array2[temp];\n    }\n    cout << result;\n    return 0;\n}",
                                 " 6553", 
								 " 6533", 
								 " 6522", 
								 " 12200", 'B');
                        break;

                    case 6:
                        question("What does the following statement mean?\nint (fp) (char);",
                                 " pointer to a pointer", 
								 " pointer to an array of chars", 
								 " pointer to function taking a char* argument and returns an int", 
								 " function taking a char* argument and returning a pointer to int", 'C');
                        break;

                    case 7:
                        question("The operator used for dereferencing or indirection is ____",
                                 " *", 
								 " &", 
								 " ->", 
								 " –>>", 'A');
                        break;

                    case 8:
                        question("Choose the right option.\nstring* x, y;",
                                 " x is a pointer to a string, y is a string",
								 " y is a pointer to a string, x is a string", 
								 " both x and y are pointers to string types", 
								 " y is a pointer to a string", 'A');
                        break;

                    case 9:
                        question("Which of the following is illegal?",
                                 " int ip;", 
								 " string s, *sp = 0;", 
								 " int i; double dp = &i;", 
								 " int *pi = 0;", 'C');
                        break;

                    case 10:
                        question("What will be the output of the following C++ code?\n#include <iostream>\nusing namespace std;\nint main() {\n    int a = 5, b = 10, c = 15;\n    int *arr[] = {&a, &b, &c};\n    cout << arr[1];\n    return 0;\n}",
                                 " 5", 
								 " 10", 
								 " 15", 
								 " it will return some random number", 'D');
                        break;
                }
            }
        }
    }
    results();
}
void disp_ez_gk_qs() {
    for (int i = 0; i < 10; i++) {
        if (ask[i]) {
            int no = i;
            if (ask[no]) {
                ask[no] = false;

                switch (no) {
                    case 1:
                        question("Who is the first Asian American to feature on US currency?",
                                 " Anna May Wong ", 
								 " Elizabeth Sung", 
								 " Jadin Wong", 
								 " Vera Wong", 'A');
                        break;

                    case 2:
                        question("“The Amazon Fund” is maintained by which financial institution?",
                                 " World Bank", 
								 " IMF", 
								 " New Development Bank", 
								 " Brazilian Development Bank", 'D');
                        break;

                    case 3:
                        question("“Gateway to the Underworld” is an artefact belonging to which country?",
                                 " India", 
								 " Sri Lanka", 
								 " Mexico ", 
								 " USA", 'C');
                        break;

                    case 4:
                        question("Grasslands found in Africa are called?",
                                 " Prairies", 
								 " Steppes", 
								 " Savannah", 
								 " Pampass", 'C');
                        break;

                    case 5:
                        question("What is the underwater mountain system formed by plate tectonic spreading called?",
                                 " Mid-oceanic Ridge ", 
								 " Oceanic Trench", 
								 " Continental Slope", 
								 " Abyssal Plains", 'A');
                        break;

                    case 6:
                        question("Which is the southernmost active volcano on earth?",
                                 " Mount Dukono", 
								 " Mount Rainier", 
								 " Mount Semeru", 
								 " Mount Erebus", 'D');
                        break;

                    case 7:
                        question("Which forests act as barriers against cyclones?",
                                 " Alpine forests", 
								 " Mangrove forests", 
								 " Evergreen forests", 
								 " Monsoon forests", 'B');
                        break;

                    case 8:
                        question("Which country is the largest producer of desalinated sea water?",
                                 " Kuwait", 
								 " Iran", 
								 " Saudi Arabia "
								 , " Iraq", 'C');
                        break;

                    case 9:
                        question("Continent which has no active volcanic regions is ___________?",
                                 " North America", 
								 " Europe", 
								 " Australia ", 
								 " Africa", 'C');
                        break;

                    case 10:
                        question("Autobiography “Daughter of Destiny” is written by__________?",
                                 " Benazir Bhutto ", 
								 " Mumtaz Bhutto", 
								 " Waheed Rehman", 
								 " Aslam Memon", 'A');
                        break;
                }
            }
        }
    }
    results();
}
void disp_mid_gk_qs() {
    for (int i = 0; i < 10; i++) {
        if (ask[i]) {
            int no = i;
            if (ask[no]) {
                ask[no] = false;

                switch (no) {
                    // Question 0
                    case 0:
                        question("Which planet is known as the 'Red Planet'?", 
						" Venus", 
						" Mars", 
						" Jupiter", 
						" Saturn", 'B');
                        break;

                    // Question 1
                    case 1:
                        question("Who wrote the play 'Romeo and Juliet'?", 
						" William Shakespeare ", 
						" Jane Austen", 
						" Charles Dickens", 
						" Mark Twain", 'A');
                        break;

                    // Question 2
                    case 2:
                        question("What is the capital city of Australia?", 
						" Sydney", 
						" Melbourne", 
						" Canberra ", 
						" Brisbane", 'C');
                        break;

                    // Question 3
                    case 3:
                        question("In which year did the Titanic sink?", 
						" 1905", 
						" 1912 ", 
						" 1920", 
						" 1931", 'B');
                        break;

                    // Question 4
                    case 4:
                        question("Who is the author of 'To Kill a Mockingbird'?", 
						" F. Scott Fitzgerald", 
						" J.K. Rowling", 
						" Harper Lee ", 
						" George Orwell", 'C');
                        break;

                    // Question 5
                    case 5:
                        question("Which ocean is the largest on Earth?", 
						" Indian Ocean", 
						" Atlantic Ocean", 
						" Southern Ocean", 
						" Pacific Ocean ", 'D');
                        break;

                    // Question 6
                    case 6:
                        question("What is the currency of Japan?", 
						" Yuan", 
						" Won", 
						" Yen ", 
						" Ringgit", 'C');
                        break;

                    // Question 7
                    case 7:
                        question("Who developed the theory of relativity?", 
						" Isaac Newton", 
						" Albert Einstein ", 
						" Galileo Galilei", 
						" Nikola Tesla", 'B');
                        break;

                    // Question 8
                    case 8:
                        question("Which country is known as the 'Land of the Rising Sun'?", 
						" China", 
						" Japan ", 
						" South Korea", 
						" Vietnam", 'B');
                        break;

                    // Question 9
                    case 9:
                        question("What is the largest mammal in the world?", 
						" Elephant", 
						" Blue Whale ", 
						" Giraffe", 
						" Gorilla", 'B');
                        break;
                }
            }
        }
    }
    results();
}
void disp_adv_gk_qs() {
    for (int i = 0; i < 10; i++) {
        if (ask[i]) {
            int no = i;
            if (ask[no]) {
                ask[no] = false;

                switch (no) {
                    // Question 1
                    case 0:
                        question("In Greek mythology, who is the goddess of wisdom and warfare?",
                            " Hera",
                            " Athena",
                            " Artemis",
                            " Demeter", 'B');
                        break;

                    // Question 1
                    case 1:
                        question("Which African country is the most populous?",
                            " Nigeria",
                            " Ethiopia",
                            " Egypt",
                            " South Africa", 'A');
                        break;

                    // Question 2
                    case 2:
                        question("What is the largest desert in the world by area?",
                            " Sahara Desert",
                            " Gobi Desert",
                            " Antarctic Desert",
                            " Arabian Desert", 'C');
                        break;

                    // Question 3
                    case 3:
                        question("Who is the author of the classic novel 'One Hundred Years of Solitude'?",
                            " Gabriel Garcia Marquez",
                            " Salman Rushdie",
                            " Haruki Murakami",
                            " Isabel Allende", 'A');
                        break;

                    // Question 4
                    case 4:
                        question("Which two elements are the primary components of water?",
                            " Oxygen and Nitrogen",
                            " Hydrogen and Helium",
                            " Oxygen and Hydrogen",
                            " Carbon and Oxygen", 'C');
                        break;

                    // Question 5
                    case 5:
                        question("Which composer is famous for his 'Symphony No. 9' and 'Ode to Joy'?",
                            " Ludwig van Beethoven",
                            " Wolfgang Amadeus Mozart",
                            " Johann Sebastian Bach",
                            " Franz Schubert", 'A');
                        break;

                    // Question 6
                    case 6:
                        question("What is the smallest prime number?",
                            " 0",
                            " 1",
                            " 2",
                            " 3", 'C');
                        break;

                    // Question 7
                    case 7:
                        question("Which ancient wonder was located in the city of Babylon?",
                            " Hanging Gardens",
                            " Statue of Zeus at Olympia",
                            " Lighthouse of Alexandria",
                            " Colossus of Rhodes", 'A');
                        break;

                    // Question 8
                    case 8:
                        question("In which year did the Berlin Wall fall, leading to the reunification of Germany?",
                            " 1985",
                            " 1989",
                            " 1991",
                            " 1995", 'B');
                        break;

                    // Question 9
                    case 9:
                        question("What is the official language of Brazil?",
                            " Spanish",
                            " Portuguese",
                            " Italian",
                            " French", 'B');
                        break;
                }
            }
        }
    }
    results();
}


void results() {
    cout << "Total Questions = " << Q_NO - 1 << endl<<endl;
    cout << "Correct answers = " << correct << endl<<endl;
    cout << "Wrong answers = " << wrong << endl<<endl;

    if (correct > wrong) {
        cout << "Good job!" << endl<<endl;
    } else if (correct < wrong) {
        cout << "Do better!" << endl<<endl;
    } else {
        cout << "Average performance";
    }
}

void question(string q, string a, string b, string c, string d, char correct_ans) {
    cout << q << endl;
    cout << "A.\t" << a << endl;
    cout << "B.\t" << b << endl;
    cout << "C.\t" << c << endl;
    cout << "D.\t" << d << endl;

    char answer;
    cout << "Enter your choice (a/b/c/d): ";
    cin >> answer;

    if (answer == correct_ans) {
        correct++;
    } else {
        wrong++;
    }

    Q_NO++;
    display();
}
