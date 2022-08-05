/************************************************************/
/*    NAME:                                               */
/*    ORGN: MIT                                             */
/*    FILE: Behavior.h                                          */
/*    DATE:                                                 */
/************************************************************/

#ifndef Behavior_HEADER
#define Behavior_HEADER

#include "MOOS/libMOOS/MOOSLib.h"

class Behavior : public CMOOSApp
{
 public:
  Behavior();
  ~Behavior();

  void SetXDestination(double);
  void SetYDestination(double);

 protected: // Standard MOOSApp functions to overload  
  bool OnNewMail(MOOSMSG_LIST &NewMail);
  bool Iterate();
  bool OnConnectToServer();
  bool OnStartUp();

 protected:
  void RegisterVariables();

 private: // Configuration variables
  double x, y;

 private: // State variables
};

#endif 
