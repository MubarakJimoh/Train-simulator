void setup() {
  // put your setup code here, to run once:

}

void loop() {
  //SECTION A: Declare Structures

 #include <Ethernet.h>
 #include <SPI.h>
 #include <string.h>[
 #include <Statistic.h>
//#include <wire.h>
#include <time.h>

// Statistic tunervoltage;
 #define panell_ID 0 
 #define DI_size 18
 #define DO_size 4
//byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
//byte ip[] = { 10, 10, 10, 5 };        //IP Address of Arduino PLC
//byte server[] = { 10, 10, 10, 1};     // IP Adress of Vessel Work Station
struct pin_Range { int from;int to;};
struct pin_Alloc { int type;
               int pin_Range[5];
                              };

//EthernetClient client;
int Volt_Val[10];
/*struct Pushbuttons {                  //for pushbuttons
                    int sigID;
                    int sigNO;
                    };   
      */
 //define all push buttons                    
struct twowaysw   {                  //for non-latch two-way switch
                   int sigID;
                   int sigNO;
                   bool swflag;
                    };
//define all 2 way switch 
struct multiwaysw  {                  //for latching 4-way switch
                    int sigID;
                    int No_of_ways;  
                   
                    };
multiwaysw currswitch;
/*struct DAQ_AI      {
                    int sigID;
                    int sigNO;
                    int currPosition;
                    float m,c; 
                    int iteration;      //averaged readings
                    bool outputType;    //high = absolute, low = delta         
                    };
*/
//define all AI here
int analogPin0 = A0;
int analogPin1 = A1;
int analogPin2 = A2;
int analogPin3 = A3;
int analogPin4 = A4;
int analogPin5 = A5;
int analogPin6 = A6;
int analogPin7 = A7;
int analogPin8 = A8;
int analogPin9 = A9;
int analogPin10 = A10;
int analogPin11 = A11;
int analogPin12 = A12;
int analogPin13 = A13;
int analogPin14 = A14;
int analogPin15 = A15;
/*struct DAQ_DO       {
                      int sigNO;
                      int ActivityType;
                     };
struct All_Lamps     {
                       int sigID;
                       int sigNO;
                      };
*/
//Define all DO here
 pinMode(1,OUTPUT);
 pinMode(14,OUTPUT);
 pinMode(15,OUTPUT);
 pinMode(16,OUTPUT);
 pinMode(17,OUTPUT);
 pinMode(18,OUTPUT);
 pinMode(19,OUTPUT);
 pinMode(20,OUTPUT);
 pinMode(21,OUTPUT);
 pinMode(22,OUTPUT);
 pinMode(23,OUTPUT);
 pinMode(24,OUTPUT);
 pinMode(25,OUTPUT);
 pinMode(26,OUTPUT);
 pinMode(27,OUTPUT);
 pinMode(28,OUTPUT);
 pinMode(29,OUTPUT);
 pinMode(30,OUTPUT);
 
struct DO_Input   {
                   int DO_Instr;
                   int DO_Param;
                    };

char nextchar, tableIndex = 0;
int currval= 0,buf_size, Input_data[10];
void get_input ();

int DI_List[20],
    DI_Kounter;

     
     
//SECTION B: Prepare database for signals
        
 
                       
 //void get_do_command(){}
void lampTestStop();
 int LAMPLIST[50];
  void lampTestStart();
int DAQ_AI;
int DAQ_DO;
//int DAQ_AI Voltage_Feedback = {I2_9,3,0,0,0};
//int DAQ_DO ActiveDO [20];
int DO_Kounter = 0;
int DAQ_Position(DAQ_AI);
 int i,j,k,l;              //global variables
 bool flag,blinkflag=false;
 /*void DAQ_OUT(int,int);
 void DAQ_PB();
 void DAQ_DPDT();
 void DAQ_SW();
 void DAQ_Tuners();
 void DAQ_DO(); 
 void DAQ_Tuners();*/
int arraySearch(int);

int arraySearch( int sigNo)
{ int y = 0;
 
  do
   {
   }
    while(ActiveDO[y++].sigNO!=sigNo&&y<DO_Kounter);
if (y > DO_Kounter)
    return -99;
else return y-1;
}

 void get_Input()
 {
  tableIndex = 0;
  do
  {
    if(nextchar== ',')
    {
      Input_data[tableIndex++] = currval;
      currval = 0;
    }
    else currval = currval*10+ nextchar - 48;
    nextchar = client.read();  
      }
      while (client.available()&&nextchar>-1);
    }
Void send12C(int Addr, int Event, bool Eventparam)
{ int data_out[2];
data_out[0] = Event;
data_out[1] = Eventparams;
wire.beginTransmission(Addr);
wire.unite(Event);
wire.endTransmission();
}
/*void DAQ_OUT(int DAQ_Type, int sigNO)
{
char str_each[20],str_each1[20];
char char_out[50];
itoa(sigNO,str_each,10);
buf_size = 20;  // sizeof (str_each)/sizeof(str_each[0]) + 5;    //1 comme+event type
 itoa(buf_size+1000,char_out,10);
 
itoa (DAQ_Type, str_each1, 10);

 strcat(char_out,str_each1);
 strcat(char_out,",");
 strcat(char_out,str_each);
 strcat(char_out,",   ");
 client.write(char_out,15);
} 
 */
//SECTION E4: LAMP CONTROL
/*
void lampTestStart();
void lampTestStop();
 
DO_Input LAMP;


void get_do_command();
  Pushbuttons PbInterrupt[] = {
      {I0_5,11},
    };
void LAMP_ONOFF(int,int);
void auto_connect()
{
do
{ 
digitalWrite(Q1_0,HIGH);
delay(200);
digitalWrite(Q1_0,LOW);
client.connect(server,6000);
delay(200);
}

while(!client.connected());
}
*/
void setup()
{
  Ethernet.begin(mac, ip);
 for (i=0;i<DO_size;i++)
     LAMPLIST[DO[i].sigNO] = DO[i].sigID;

 for (i=0; i<dpdt_size; i++)
     {
      //if (dpdt[i].swflag)
         DAQ_OUT(1100,dpdt[i].sigNO);
       
     }
     

 for (i=0; i<latching_size; i++)
     {
      //if (latching[i].currPosition==0)
         DAQ_OUT(1100,latching[i].sigNO);
         delay(50);
     }
*/}
void loop () 

{
//if (!client.connected())
  auto_connect();
 

DAQ_PB();
DAQ_DPDT();
DAQ_SW();
DAQ_Tuners();
DAQ_DO();
*/delay(1000); 
  }

 //SECTION E1: PushButton
 void DAQ_PB()
  {
 for (i=0; i<Pb_Size; i++)
    {
  delay(10);   
  bool flag = digitalRead(Pb[i].sigID);
  if (flag == true)
  {
   I2Csend(1100,Pb[i].sigNO);
    }   
  }
  }

 //SECTION E2: DPDT
  void DAQ_DPDT()

  {
    for (i=0; i<dpdt_size; i++)
  {
    flag = digitalRead(dpdt[i].sigID);
    if (flag != dpdt[i].swflag)
    {
     dpdt[i].swflag = flag;
     I2Csend(1100,dpdt[i].sigNO+!flag);
    }
  }  
  }   

   //SECTION E3: LATCHING SWITCHES
  
 /* void DAQ_SW()
     {
      for (i=0;i<latching_size;i++)
      {
        currswitch= latching[i];
        flag= digitalRead(currswitch.sigID[currswitch.currPosition]);
        
        if (!flag)
        {
          for ( k=0;k<No_of_ways[I];k++)
          {
          if (k !=currswitch.currPosition)
           {
            flag= digitalRead(currswitch.sigID[k]);
            
            if (flag)
            {
              latching[i].currPosition= k;
               DAQ_OUT(1100,currswitch.sigNO+k);
              return;
              }
           }
        }
      }
     }
     }*/
    /*
  //SECTION E4: Get Throttle and Wheel Position


 int DAQ_Position(DAQ_AI Potentiometer)
   {
     tunervoltage.clear();
     for (int ii=0; ii<Potentiometer.iteration;ii++)
     {
     tunervoltage.add(analogRead(Potentiometer.sigID));
     delay(50);
      float Volt_In = tunervoltage.average()*100.0/Voltage_Feedback.m + 0.3;
      
      
      int newPosition = (int) (Potentiometer.m*Volt_In + Potentiometer.c);

   
    if ( newPosition!=Potentiometer.currPosition)
       {
        if (Potentiometer.outputType)
            DAQ_OUT(1200+Potentiometer.sigNO,newPosition);
         else   DAQ_OUT(1200+Potentiometer.sigNO,newPosition-Potentiometer.currPosition);
     //delay(200);
      }
      
      return newPosition;
    }
 
   
    void DAQ_Tuners()
   {
    Voltage_Feedback.m = analogRead(Voltage_Feedback.sigID);// store reference voltage here

   for (i=0; i< Tuner_Kounter; i++)
               Tuner[i].currPosition = DAQ_Position(Tuner[i]);
    }
*/
/* void LAMP_ONOFF(int index,int ACTION)
    {
      /*Action is as follows
       0 = OFF
       1 = ON
       2 = Test Lamp
       3 = Blink
       starts
       4 = Blink Stops
       5 = Blink Once 
        */

   /* if (ACTION >0)
      {
        ActiveDO[DO_Kounter].sigNO=index;
        ActiveDO[DO_Kounter++].ActivityType=ACTION;
        digitalWrite(LAMPLIST[index],HIGH);
       }
    else   
        ActiveDO[arraySearch(index)].ActivityType= 0;
         
      }  
   void lampTestStop()
{
  for (j=0;j<DO_Kounter;j++)
     {
      if (ActiveDO[j].ActivityType==2)
       ActiveDO[j].ActivityType=0;
     } 
  }*/

 /* void lampTestStart()
 {
  
  
  for (j=0;j<DO_size;j++)
     
     {
      l=DO[j].sigNO;
     
      int m =arraySearch(l);
          DAQ_OUT(1440+j, m);
          DAQ_OUT(1640+j, ActiveDO[m].ActivityType); 
      if ( m > -1 && ActiveDO[m].ActivityType == 1)
         {
         }
         else 
             {
              
              LAMP_ONOFF(l,2); 
              delay(50);   
             }
     }
 }*/

 // SECTION E5: LAMPS
 //Temporary generation of Test Data

/* void get_do_command()
 {
 nextchar = client.read();

 if (nextchar>-1) 
  {
    get_Input();
 
   LAMP.DO_Instr = Input_data[0];
   LAMP.DO_Param = Input_data[1];
 }
 
 else LAMP.DO_Instr = 0;
 
 }*/



 


 
/* void DAQ_DO();
  {
 
   get_do_command();
   switch(LAMP.DO_Instr)
      {
  case 1205://switch Lamp ON
       LAMP_ONOFF(LAMP.DO_Param,1);
      break;

  case 1206: //Switch OFF/ON
      LAMP_ONOFF(LAMP.DO_Param/100,0);
      LAMP_ONOFF(LAMP.DO_Param%100,1);
      break;

  case 1207: //Blink once
      LAMP_ONOFF(LAMP.DO_Param,4);
      break;

  case 1208: //Test LamP
        

        DAQ_OUT(1420,LAMP.DO_Param);
        
         if (LAMP.DO_Param)
             lampTestStart();
        else lampTestStop();
     
        break;

  case 1210:  //Blink Continuous
             LAMP_ONOFF(LAMP.DO_Param,3);
             break;
   case 1215:  //switch Lamp OFF
            LAMP_ONOFF(LAMP.DO_Param,0);
            break;

  default:break;
      }*/
 
 
 //Handle Blink and other Clean- Ups
int ActiveDO;
 blinkflag = !blinkflag;

 
 for(j=0;j<DO_Kounter;j++)
 {int DO_pin =LAMPLIST[ActiveDO[j].sigNO];
 switch (ActiveDO[j].ActivityType)
 {case 0:  //Remove from Register
  
      digitalWrite(14 ,LOW);
  
      ActiveDO[j--]= ActiveDO[DO_Kounter--];  
      break;
  
 case 3: //Blink Lamp
     digitalWrite(15 ,blinkflag);
    break;

 case 4: //Queue for Removal
     ActiveDO[j].ActivityType = 0;
     break;

 default: break;
    }
    }
    }


}
