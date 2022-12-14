/************************************************************/
/*    NAME:                                               */
/*    ORGN: MIT                                             */
/*    FILE: Behavior.cpp                                        */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include "MBUtils.h"
#include "Behavior.h"

using namespace std;

//---------------------------------------------------------
// Constructor

Behavior::Behavior()
{
}

//---------------------------------------------------------
// Destructor

Behavior::~Behavior()
{
}

//---------------------------------------------------------
// Set X coordinate

void Behavior::SetXDestination(double x_dest)
{
  x = x_dest;
}

//---------------------------------------------------------
// Set Y coordinate

void Behavior::SetYDestination(double y_dest)
{
  y = y_dest;
}


//---------------------------------------------------------
// Procedure: OnNewMail

bool Behavior::OnNewMail(MOOSMSG_LIST &NewMail)
{
  MOOSMSG_LIST::iterator p;
   
  for(p=NewMail.begin(); p!=NewMail.end(); p++) {
    CMOOSMsg &msg = *p;

#if 0 // Keep these around just for template
    string key   = msg.GetKey();
    string comm  = msg.GetCommunity();
    double dval  = msg.GetDouble();
    string sval  = msg.GetString(); 
    string msrc  = msg.GetSource();
    double mtime = msg.GetTime();
    bool   mdbl  = msg.IsDouble();
    bool   mstr  = msg.IsString();
#endif
   }
	
   return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer

bool Behavior::OnConnectToServer()
{
  RegisterVariables();

  Notify("GOTO", "true");
  Notify("GOTO_UPDATES", "points=" + doubleToString(x) + "," + doubleToString(y));

  return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool Behavior::Iterate()
{

  

  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool Behavior::OnStartUp()
{
  list<string> sParams;
  m_MissionReader.EnableVerbatimQuoting(false);
  if(m_MissionReader.GetConfiguration(GetAppName(), sParams)) {
    list<string>::iterator p;
    for(p=sParams.begin(); p!=sParams.end(); p++) {
      string line  = *p;
      string param = tolower(biteStringX(line, '='));
      string value = line;
      
      if(param == "foo") {
        //handled
      }
      else if(param == "bar") {
        //handled
      }
    }
  }
  
  RegisterVariables();	
  return(true);
}

//---------------------------------------------------------
// Procedure: RegisterVariables

void Behavior::RegisterVariables()
{
  //Register("WPT_UPDATES");
}

