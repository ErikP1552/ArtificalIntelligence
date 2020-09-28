// Project 1 - Artificial Intelligence - Erik Pantoja - Spring 2020

//Included libraries
#include <iostream>
#include <string>
#include <conio.h>
#include <stack>
using namespace std;

// Forward and Backward Inference Engines - Required Names
int Profession_BW();
void Area_FW(int a);

//KnowledgeBases for Forward and backward
void createKnowledgeBase();
void createKnowledgeBaseForward(int a);

//Data Structures to hold data for knowledgeBases - Queue / Stack
string queueBackward[75];   // Stack for Backward Chaining
stack<string> stackForward; // Stack for Forward Chaining

//Helper Function for Queue / No global Variables
void insertVal(string value, int front, int back);
void runAgain();
void introduction();
void conclusion();
int main()
{
    introduction();                 // For neatness

    createKnowledgeBase();          // Knowledge Base for Backward Chaining
    int a = Profession_BW();        // Running backward chaining - Inference Engine


    createKnowledgeBaseForward(a);  // Knowledge Base for Forward Chaining
    Area_FW(a);                     // Running Forward Chaining - Inference Engine

    runAgain();                     // To Run program again quickly

    conclusion();                   // For neatness

    return 0;
}

void createKnowledgeBase(){
//Knowledge Base Creation

int front = - 1, rear = - 1; // may have to modify later from global - temp for now
string gpa, buildingSkill, skilledComputers, social,socialMedia, helpOthers, teachOthers, skilledBuilding, handWorking, mathCredits, scienceCredits, experienceTeaching, experienceVehicles, mechProblems,probSolving,patience,adaptable,innovation,attnDetail,emotionalStab,teamSkills,negotiating,bizWork, perspectives,experienceArts;
rear++;
cout << "Is your GPA higher then 3.0? (Yes, or No)" <<endl;
cin >> gpa; // Filters to ENGR
insertVal(gpa, front, rear);
rear++; //Queue 0
cout << " Are you skilled in Building? (yes, or no)"<<endl;
cin >> buildingSkill; // Filters to Construction
insertVal(buildingSkill, front, rear);
rear++; //Queue 1
cout << " Are you skilled in computers?(yes or no)" <<endl;
cin >> skilledComputers; // Filters to Tech
insertVal(skilledComputers, front, rear);
rear++; // Queue 2
cout << "Are you experienced in social interaction? (yes or no)"<<endl;
cin >> social; // Filters to communications
insertVal(social, front, rear);
rear++; //Queue 3
cout << " Do you have experience working with social media? (yes or no) "<<endl;
cin >> socialMedia; //Filters to sub fields of communications
insertVal(socialMedia, front, rear);
rear++; //Queue 4
cout << "Are you skilled at helping other people? (yes or no)" <<endl;
cin >> helpOthers; // Filters to medical
insertVal(helpOthers, front, rear);
rear++; // Queue 5
cout << "Are you skilled at teaching others? (yes or no)" <<endl;
cin >> teachOthers; // Education
insertVal(teachOthers, front, rear);
rear++; //Queue 6
cout << " Do you have experience in Building? (yes, or no)" <<endl;
cin >> skilledBuilding; // Construction
insertVal(skilledBuilding, front, rear);
rear++; // Queue 7
cout << "Do you have experience working with hands? (yes or no)"<<endl;
cin >> handWorking; // Construction
insertVal(handWorking, front, rear);
rear++; // Queue 8
cout << "Do you have math credits? "<<endl;
cin >> mathCredits; // MathField
insertVal(mathCredits, front, rear);
rear++; //Queue 9
cout << "Do you have science credits? "<<endl;
cin >> scienceCredits; // Science Field
insertVal(scienceCredits, front, rear);
rear++; // Queue 10
cout << "Do you have experience teaching others? "<<endl;
cin >> experienceTeaching; // EDU field
insertVal(experienceTeaching, front, rear);
rear++; //Queue 11
cout << "Do you have experience with vehicles? "<<endl;
cin >> experienceVehicles; // Mechanic Field
insertVal(experienceVehicles, front, rear);
rear++; //Queue 12
cout << "Do you have experience with diagnosing mechanical problems? " <<endl;
cin >> mechProblems; // Mechanic Field
insertVal(mechProblems, front, rear);
rear++; // Queue 13
cout << "Are you good at problem solving ? " <<endl;
cin >> probSolving; //Mechanic Field
insertVal(probSolving, front, rear);
rear++; // Queue 14
cout << "Do you have patience when working with others? " <<endl;
cin >> patience ; // Used for EDU field
insertVal(patience, front, rear);
rear++; // Queue 15
cout << "Are you adaptable ? " <<endl;
cin >> adaptable; // Can be used for EDU field
insertVal(adaptable, front, rear);
rear++; // Queue 16
cout << " Do you have skills in creativity and innovation ? " <<endl;
cin >> innovation;  // Can be used for Engineering field
insertVal(innovation, front, rear);
rear++; //Queue 17
cout << " Do you have attention to detail? " <<endl;
cin >> attnDetail; // Can be used for the Engineering Field
insertVal(attnDetail, front, rear);
rear++; // Queue 18
cout << " Do you have emotional stability in medical emergencies ? " <<endl;
cin >> emotionalStab; // can be used for health care field
insertVal(emotionalStab, front, rear);
rear++; //Queue 19
cout << " Do you have experience working in a team? " <<endl;
cin >> teamSkills; // Can be used in health care
insertVal(teamSkills, front, rear);
rear++; //Queue 20
cout << " Are you good at negotiating or making deals with others ? "<<endl;
cin >> negotiating; // For the Biz Field
insertVal(negotiating, front, rear);
rear++; // Queue 21
cout << " Do you have experience working with any businesses? " <<endl;
cin >> bizWork; // for the Biz Field
insertVal(bizWork, front, rear);
rear++; //Queue 22
// Fine arts, or Liberal Arts
cout << " Do you have experience viewing different perspectives of others? "<<endl;
cin >> perspectives; // Liberal Arts
insertVal(perspectives, front, rear);
rear++; //Queue 23
cout << " Do you have experience in painting, sculpture, architecture, music, poetry? " <<endl;
cin >> experienceArts; // Fine arts
insertVal(experienceArts, front, rear);
rear++; // Queue 24 - (question 25)

}

int Profession_BW(){
int x =0;
//Inference Engine
//Engineering
if((queueBackward[0] == "yes") && (queueBackward[9]== "yes") && (queueBackward[10]== "yes") && (queueBackward[13]=="yes") && (queueBackward[14]== "yes"))
   {
    cout << endl  <<" Advising Engineering Field";
    cout << endl;
    x=1;
}
// Communications
else if(queueBackward[3] == "yes" && queueBackward[4] == "yes" && queueBackward[16] == "yes" ){
    cout <<endl<< "Advising Communications Field";
    cout << endl;
    x=7;
}
// Liberal Arts
else if(queueBackward[3] == "yes" && queueBackward[5] == "yes" && queueBackward[23] == "yes" ){
    cout <<endl<< "Advising Liberal Arts Field";
    cout << endl;
    x=5;
}
// Fine Arts
else if(queueBackward[24] == "yes"){
    cout <<endl<< "Advising Fine Arts Field";
    cout <<endl;
    x=6;
}
// Health Care
else if(queueBackward[5] == "yes" && queueBackward[3] == "yes" && queueBackward[15] == "yes" && queueBackward[16] == "yes" && queueBackward[18] == "yes" && queueBackward[19] == "yes" && queueBackward[20] == "yes"){
    cout << "Advising Health Care Field";
    cout <<endl;
    x=8;
}
// Technology
else if(queueBackward[0] == "yes" && queueBackward[2] == "yes" && queueBackward[9] == "yes" && queueBackward[14] == "yes"){
    cout <<endl<< "Advising Technology Field";
    cout << endl;
    x=10;
}
// Construction
else if(queueBackward[1] == "yes" && queueBackward[7] == "yes" && queueBackward[8] == "yes"){
    cout <<endl<< "Advising Construction Field";
    cout <<endl;
    x=4;
}
// Education
else if(queueBackward[3] == "yes" && queueBackward[5] == "yes" && queueBackward[6] == "yes" && queueBackward[11] == "yes" && queueBackward[15] == "yes" && queueBackward[16] == "yes" ){
    cout <<endl<< "Advising Education Field";
    cout <<endl;
    x=9;
}
// Business
else if(queueBackward[3] == "yes" && queueBackward[16] == "yes" && queueBackward[20] == "yes" && queueBackward[21] == "yes" && queueBackward[22] == "yes"){
    cout <<endl<< "Advising Business Field";
    cout <<endl;
    x=3;
}
// Science
else if(queueBackward[0] == "yes" && queueBackward[9] == "yes" && queueBackward[10] == "yes" && queueBackward[14] == "yes" && queueBackward[18] == "yes"){
    cout <<endl<< "Advising Science Field";
    cout <<endl;
    x=2;
}
// Mechanic
else if(queueBackward[1] == "yes" && queueBackward[8] == "yes" && queueBackward[13] == "yes" && queueBackward[14] == "yes"){
    cout <<endl<< "Advising Mechanic Field";
    cout << endl;
    x=11;
}
else {
    cout <<endl<< " Did not meet requirements for any career path" <<endl;
    cout <<endl;
    x=12;
}
return x;
   }


void createKnowledgeBaseForward(int x){

    // Subfield List
cout <<endl;
cout << "*** Now Advising of a Subfield to choose from ***" <<endl<<endl;


if (x==1){
    //Engineering
    cout << " Do you enjoy working with electronics? (yes or no)"<<endl;
    string electro;
    cin >> electro;

    cout << "Would you prefer working on things of larger or smaller scale? (small or big)" <<endl;
    string smallOrBig;
    cin >>smallOrBig;

    cout << " Would you be interested in machines that fly? (yes or no)" <<endl;
    string fly;
    cin >> fly;

    cout << "Are you able to work with blood or other bodily fluids? (yes or no)"<<endl;
    string blood;
    cin >>blood;

    stackForward.push(blood);
    stackForward.push(fly);
    stackForward.push(smallOrBig);
    stackForward.push(electro);

} else if (x==2){

    //Science
    cout << "Do you enjoying working with things that are alive? (Yes or No)" <<endl;
    string alive;
    cin >>alive;

    cout << "Would you prefer to work with humans or plants, or undecided? (humans, plants, undecided)" <<endl;
    string humanOrPlants;
    cin >> humanOrPlants;

    cout << "Would you prefer doing research in space or on earth or both?(space, earth, both)? " <<endl;
    string earth;
    cin >> earth;

    stackForward.push(earth);
    stackForward.push(humanOrPlants);
    stackForward.push(alive);

} else if (x==3){

    //Business
    cout << " Would you be more interested in Business related to money?(yes, no)"<<endl;
    string money;
    cin >>money;

    cout << "Would you prefer to deal with money on large or small scale(large, small)?"<<endl;
    string small;
    cin >>small;

    cout << "Would you rather manage, start, or work for a business(manage,start,work)"<<endl;
    string manage;
    cin >>manage;

    stackForward.push(manage);
    stackForward.push(small);
    stackForward.push(money);

} else if (x==4){
    //Construction

    cout << "Would you prefer to manage different projects? (yes or no)"<<endl;
    string projects;
    cin >> projects;

    cout << "Would you prefer to work privately, for government, or both (privately, government, both)"<<endl;
    string privatei;
    cin >>privatei;

    cout << "Would you enjoy designing projects? (yes,no)"<<endl;
    string projects1;
    cin>>projects1;

    stackForward.push(projects1);
    stackForward.push(privatei);
    stackForward.push(projects);

} else if (x==5){
    //Liberal Arts

    cout <<"Do you enjoy working with individuals or groups? (individuals or groups)?"<<endl;
    string groups;
    cin >>groups;

    cout <<"Do you enjoy politics?(yes, no)" <<endl;
    string politics;
    cin  >>politics;

    cout << "Do you prefer working with people, numbers, or events? (people,numbers,events)"<<endl;
    string people;
    cin >>people;

    stackForward.push(people);
    stackForward.push(politics);
    stackForward.push(groups);


} else if (x==6){
    //Fine Arts

    cout << "Do you prefer sounds or images? (sounds, images)"<<endl;
    string image;
    cin >>image;

    cout << " Would you prefer working on computers, homes, or paper?(computers,homes,paper)"<<endl;
    string working;
    cin >> working;

    cout << "Are you skilled at drawing? (yes,no)"<<endl;
    string drawing;
    cin >>drawing;

    stackForward.push(drawing);
    stackForward.push(working);
    stackForward.push(image);


    } else if (x==7){
    //Communications

    cout << "Would you enjoy working for a private business or government? (private,government)" <<endl;
    string biz;
    cin >>biz;

    cout << "Would you rather work following stories, TV, or other? (stories, tv, other)"<<endl;
    string stories;
    cin >> stories;

    cout << "Would you rather work domestically or internationally?(domestically, internationally)"<<endl;
    string location;
    cin >> location;


    stackForward.push(location);
    stackForward.push(stories);
    stackForward.push(biz);

    } else if (x==8){
    //HealthCare

    cout << "Would you prefer to be hands on with patients? (yes,no)"<<endl;
    string hands;
    cin >>hands;

    cout <<"Would you prefer being in charge of procedures, supporting, or other?(charge,supporting,other)"<<endl;
    string charge;
    cin >> charge;

    cout << " Would you prefer to work for families, or admin?(families, admin)" <<endl;
    string admin;
    cin >> admin;

    stackForward.push(admin);
    stackForward.push(charge);
    stackForward.push(hands);

    } else if (x==9){
    //Education

    cout << "Would you prefer to work with young adults or children?(adults, children)"<<endl;
    string type;
    cin >>type;

    cout << " Would you rather manage a school or teach? (manage, teach)"<<endl;
    string manage;
    cin >> manage;

    cout << " Would you rather teach special needs, regular students, or sports? (special,regular,sports)"<<endl;
    string typestudent;
    cin >>typestudent;

    stackForward.push(typestudent);
    stackForward.push(manage);
    stackForward.push(type);


    } else if (x==10){
    //Technology

    cout << "Would you rather create computer programs, or maintain programs? (create,maintain)" <<endl;
    string create;
    cin >>create;

    cout << "Would you prefer to create computer code or no? (yes, no)"<<endl;
    string code;
    cin >>code;

    cout << " Would you prefer working with databases, numbers, or Information technology? (databases,numbers,it)"<<endl;
    string databases;
    cin>>databases;

    stackForward.push(databases);
    stackForward.push(code);
    stackForward.push(create);

    } else if (x==11){
    //Mechanic

    cout << " Do you prefer to work on larger or smaller vehicles? (large,small)"<<endl;
    string largeSmall;
    cin >> largeSmall;

    cout << " Would you prefer foreign, domestic, or water vehicles?(foreign,domestic,water)"<<endl;
    string typeVec;
    cin >> typeVec;
    stackForward.push(typeVec);

    cout << " Would you enjoy working on flying vehicles?(yes,no)"<<endl;
    string fly;
    cin >>fly;

    stackForward.push(typeVec);
    stackForward.push(fly);
    stackForward.push(largeSmall);
} else {
cout << "Did not pass a valid field to forward chaining" <<endl;
}

}


void Area_FW(int x)
{

    if (x == 1){
    // Engineering
    if(stackForward.top() =="yes"){
    stackForward.pop();
    cout << " Advising Electrical field "<<endl;
    }
    else {
    stackForward.pop();
    if(stackForward.top() =="big"){
    // Mechanical or Aerospace
    stackForward.pop();
    if(stackForward.top() == "yes"){
    cout << " Advising Aerospace field "<<endl;
    } else {
    cout << " Advising Mechanical field "<<endl;
    stackForward.pop();
    }
    }
    else {
    //Medical or Chemical
    if(stackForward.top() =="yes"){
    cout << " Advising Medical field "<<endl;
    }
    else {
    cout << " Advising Chemical field "<<endl;
    stackForward.pop();
    }
    }
    }
    }


    if (x == 2){
    // Science

    if(stackForward.top() == "yes"){

    if(stackForward.top() == "humans"){
    cout << " Advising Geneticist field "<<endl;
    }
    else if(stackForward.top() == "plants"){
    cout << " Advising Botanist field "<<endl;
    }
    else{
    cout << " Advising Biologist field "<<endl;
    }
    }
    else{
    stackForward.pop();
    if(stackForward.top()=="earth"){
    cout << " Advising Geologist field "<<endl;
    }
    else if(stackForward.top() == "space"){
    cout << " Advising Astro-biologist field "<<endl;
    }
    else{
    cout << " Advising Physicist field "<<endl;
    }
    } stackForward.pop();
    }


    if (x == 3){

    // Business
    if(stackForward.top()=="yes"){
    stackForward.pop();
    if(stackForward.top()=="small"){
    cout << " Advising Accounting field "<<endl;
    } else {
    cout << " Advising Economics field "<<endl;
    }
     } else {
    stackForward.pop();
    if(stackForward.top() =="manage"){
    cout << " Advising Management field "<<endl;
    }
    else if(stackForward.top() =="start"){
    cout << " Advising Entrepreneurial Studies field "<<endl;
    }
    else{
    cout << " Advising Business Administration field "<<endl;
    }
    }
    stackForward.pop();
    }


    if (x == 4){
    // Construction
    if(stackForward.top()=="yes"){
    cout << " Advising Project Management field "<<endl;
    }
    else {
    stackForward.pop();
    if(stackForward.top() =="privately"){
    cout << " Advising Residential field "<<endl;
    }
    else if(stackForward.top() =="government"){
    cout << " Advising Civil field "<<endl;
    }
    else{
    stackForward.pop();
    if(stackForward.top()=="yes"){
    cout << " Advising Architecture field "<<endl;
    }
    else{
    cout << " Advising Commercial field "<<endl;
    }
    }
    }
    stackForward.pop();
    }

    if (x == 5){
    // Liberal Arts
    if(stackForward.top()=="groups"){
    stackForward.pop();
    if(stackForward.top() =="yes"){
    cout << " Advising Political Science field "<<endl;
    } else {
    cout << " Advising Sociologist field "<<endl;
    }
    }
    else {
    stackForward.pop();
    if(stackForward.top() =="people"){
    cout << " Advising Psychologist field "<<endl;
    }
    else if (stackForward.top()=="numbers"){
    cout << " Advising Mathematical field "<<endl;
    } else {
    cout << " Advising Historian field "<<endl;
    }
    }
    stackForward.pop();
    }

    if (x == 6){

    // Fine Arts
    if(stackForward.top()=="sounds"){
    cout << " Advising Musician field "<<endl;
    }
    else {
    stackForward.pop();
    if(stackForward.top() =="computers"){
    cout << " Advising Graphic Designer field "<<endl;
    }
    else if(stackForward.top() =="homes"){
    cout << " Advising Interior Designer field "<<endl;
    }
    else {
    stackForward.pop();
    if(stackForward.top() =="yes"){
    cout << " Advising Artist field "<<endl;
    }else {
    cout << " Advising Writer field "<<endl;
    }
    }
    }
    }

    if (x == 7){
    // Communications
    if(stackForward.top() == "private"){
    stackForward.pop();
    if(stackForward.top() == "tv"){
    cout << " Advising TV and Radio Broadcasting field "<<endl;
    }else if (stackForward.top()=="stories"){
    cout << " Advising Journalism field "<<endl;
    } else{
    cout << " Advising Publicist field "<<endl;
    }
    }
    else{
    stackForward.pop();
    if(stackForward.top()=="domestically"){
    cout << " Advising Public Relations field "<<endl;
    }else{
    cout << " Advising International Relations field "<<endl;
    }
    }
    stackForward.pop();
    }

    if (x == 8){
    // Health Care
    if(stackForward.top() =="yes"){
    stackForward.pop();
    if(stackForward.top()=="charge"){
    cout << " Advising Physician field "<<endl;
    }
    else if(stackForward.top() =="supporting"){
    cout << " Advising Nurse field "<<endl;
    }else{
    cout << " Advising Therapist field "<<endl;
    }
    }
    else{
    stackForward.pop();
    if(stackForward.top()=="admin"){
    cout << " Advising Administration Clerk field "<<endl;
    } else {
    cout << " Advising Social Worker field "<<endl;
    }
    }
    }

    if (x == 9){
    // Education
    if (stackForward.top() =="adults"){
    cout << " Advising College Professor field "<<endl;
    }
    else {
    stackForward.pop();
    if(stackForward.top()=="manage"){
    cout << " Advising Principle field "<<endl;
    } else {
    stackForward.pop();
    if(stackForward.top() =="special"){
    cout << " Advising Special Educator field "<<endl;
    } else if(stackForward.top()=="regular"){
    cout << " Advising Teacher field "<<endl;
    } else{
    cout << " Advising Coach field "<<endl;
    }
    }
    }
    stackForward.pop();
    }


    if (x == 10){
    // Technology
    if(stackForward.top()=="create"){
    stackForward.pop();
    if(stackForward.top()=="yes"){
    cout << " Advising Computer Science field "<<endl;
    } else{
    cout << " Advising Computer Information Systems field "<<endl;
    }
   }else{
    stackForward.pop();
    if(stackForward.top() =="databases"){
    cout << " Advising Database Management field "<<endl;
    } else if(stackForward.top()=="numbers"){
    cout << " Advising Analysis field "<<endl;
    }else{
    cout << " Advising IT management field "<<endl;
    }
    }
    stackForward.pop();
    }

    if (x == 11){
    // Mechanic
    if(stackForward.top()=="large"){
    stackForward.pop();
    if(stackForward.top()=="yes"){
    cout << " Advising Aircraft field "<<endl;
    } else{
    cout << " Advising Large Vehicle field "<<endl;
    }
    }else{
    stackForward.pop();
    if(stackForward.top() =="water"){
    cout << " Advising Boat/ Watercraft field "<<endl;
    } else if (stackForward.top() =="domestic"){
    cout << " Advising Domestic Vehicle field "<<endl;
    } else{
    cout << " Advising Foreign Vehicle field "<<endl;
    }
    }
    stackForward.pop();
    }
}

// Helper functions
void insertVal(string value, int front, int rear) {
    int n = 50;
   if (rear == n - 1)
      cout<< "Over Limit" <<endl<<endl;
   else {
      if (front == - 1)
      front = 0;
      queueBackward[rear] = value;
   }
}


void runAgain(){

cout << " Would you like to run this program again? (yes, no)" <<endl;
string runAgain;
cin >> runAgain;
while(runAgain=="yes"){

    createKnowledgeBase();          // Knowledge Base for Backward Chaining
    int a = Profession_BW();        // Running backward chaining - Inference Engine
    createKnowledgeBaseForward(a);  // Knowledge Base for Forward Chaining
    Area_FW(a);

    cout << " Would you like to run this program again? (yes, no)" <<endl;
    cin >> runAgain;
}


}

void introduction(){
    cout << "Welcome to Career Advising Program" <<endl<<endl<<endl;
    cout << "You will be asked a series of questions to help evaluate your interests, and help you select a field that best suits you "<<endl<<endl;
}

void conclusion(){
cout <<endl<<endl << " Program has been completed " <<endl<<endl;
cout << " Implemented by Erik Pantoja - for Artificial Intelligence Spring 2020" <<endl;
}
