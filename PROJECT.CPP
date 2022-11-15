#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
#include<fstream.h>
#include<iomanip.h>
#include<stdio.h>

int i=0;

void startup();
int opening1();
void opening2();
void maketrfile();
void makehofile();
void places();


class travelagency
{
 private:

 char name[50],destination[30],hotel[30],add[80],date[20],flag1,flag2,trans[30];
 float price,price2;
 int not1,not2,nor,top,nod,noc,kor1,kor2,top2,choice;
 int fst1,fst2,tst1,tst2,nst1,nst2;
 int atr1,atr2,ttr1,ttr2,rtr1,rtr2;

 public:

 int toggle;

 void resho();
 void showhotel();
 void viewhorec();
 void showhotelrec();
 void delhotelrec();
 void searchhotrec();
 void transferhoteldata();
 void edithoteldata();
 void transferhoteldata1();

 void restr();
 void showtransport();
 void viewtrrec();
 void showtransportrec();
 void deltransportrec();
 void searchtransportrec();
 void transfertransportdata();
 void edittransportdata();
 void transfertransportdata1();

 void assignprice();                          //FUNTION TO CALCULATE PRICE

 void nindia(int ndes);
 void sindia(int sdes);
 void cindia(int cdes);

}user,user1[100];


void travelagency::resho()
{
 clrscr();
  flag1='N';
  while(flag1!='Y')
  {

   clrscr();
   gotoxy(20,5);cout<<"Please Enter Information For Hotel Reservation";
   gotoxy(20,7);cout<<"Please enter the choice of your hotel......";
   gotoxy(25,9);cout<<"1: 5 Star";
   gotoxy(25,10);cout<<"2: 3 Star";
   gotoxy(25,11);cout<<"3: Normal"<<endl;
   gotoxy(26,12);cout<<"......";cin>>top;
   clrscr();

   assignprice();

   clrscr();
   gotoxy(15,2);cout<<"PLEASE FILL IN THE DETAILS ...";
   gotoxy(25,5);cout<<"HOTEL RESERVATION FORM";
   gotoxy(5,8);cout<<"Name: ";
   gotoxy(5,10);cout<<"Address: ";
   gotoxy(5,12);cout<<"Destination: ";
   gotoxy(30,12);cout<<"Name of Hotel: ";
   gotoxy(5,14);cout<<"No. of days to stay: ";
   gotoxy(30,14);cout<<"Check in Date(dd-mm-yy) :";
   gotoxy(5,16);cout<<"Type of Rooms to be Reserved: Select 1 or 2 " ;
   gotoxy(10,18);cout<<"1. Deluxe ";
   gotoxy(30,18);cout<<"2. Non Deluxe ";
   gotoxy(10,20);cout<<" Your choice (1/2) : ";
   gotoxy(10,22);cout<<"Is the information correct(y/n)?? ";
   gotoxy(10,8);gets(name);
   gotoxy(13,10);gets(add);
   gotoxy(19,12);gets(destination);
   gotoxy(46,12);gets(hotel);
   gotoxy(27,14);cin>>nod;
   gotoxy(56,14);gets(date);
   gotoxy(34,20);cin>>choice;
   if(choice == 1)
   {
    kor1=1;kor2=0;
   }
   else if (choice == 2)
  {
  kor1=0;kor2=1;
  }
   gotoxy(45,22);cin>>flag1;
  flag1=toupper(flag1);
  }
 showhotel();
}

void travelagency::showhotel()
{
  int a,b;

  if(top==1)
    price=(fst1*kor1*nod)+(fst2*kor2*nod);
  else
    if(top==2)
      price=(tst1*kor1*nod)+(tst2*kor2*nod);
    else
      if(top==3)
	 price=(nst1*kor1*nod)+(nst2*kor2*nod);

   if(toggle==1)
 {
 clrscr();
 gotoxy(20,8);cout<<"Please wait while we make the Reservation";
 delay(50);
 toggle=0;
 }

   clrscr();
   gotoxy(25,5);cout<<"Hotel     Reservation  ";
   gotoxy(24,6);cout<<"-----------------------";
   gotoxy(15,8);cout<<"Name:"<<strupr(name);
   gotoxy(15,10);cout<<"Address:"<<strupr(add);
   gotoxy(15,12);cout<<"Name of the hotel:  "<<strupr(hotel)
		     <<" , "<<strupr(destination);
   gotoxy(15,14);cout<<"No. of Days to stay: "<<nod
			  <<"  ;  Check in date: "<<strupr(date);
   gotoxy(15,16);cout<<"No. of DELUXE rooms reserved: "<<kor1;
   gotoxy(15,18);cout<<"No. of NON-DELUXE rooms reserved: "<<kor2;
   gotoxy(15,20);cout<<"Your Reservations have been done"
			"Please pay the Amount!!!";
   gotoxy(25,22);cout<<"Amount: Rs."<<setprecision(2)<<price;
   getch();

}

void travelagency::viewhorec()
{

 int option;

  while(option!=5)
  {
   clrscr();
   gotoxy(24,5);cout<<"HOTEL RESERVATION INFORMATION";
   gotoxy(25,10);cout<<"choose.....";
   gotoxy(25,12);cout<<"1: View hotel reservation records";
   gotoxy(25,14);cout<<"2: Delete a particular record";
   gotoxy(25,16);cout<<"3: Search for a record";
   gotoxy(25,18);cout<<"4: Edit a record ";
   gotoxy(25,20);cout<<"5: Exit.....  ";
   cin>>option;

    switch(option)
    {
     case 1:showhotelrec();
	    break;
     case 2:delhotelrec();
	    break;
     case 3:searchhotrec();
	    break;
     case 4:edithoteldata();
	    break;
    }
  }
}

void travelagency::showhotelrec()
{

fstream fil1;

fil1.open("hotel.dat",ios::binary|ios::in);

 while(fil1.read((char*)&user,sizeof (user)))
 user.showhotel();

fil1.close();
}


void travelagency::delhotelrec()
{
clrscr();

char dname[20];
 gotoxy(20,5);cout<<"Enter name to delete record for...";
 gotoxy(30,7);gets(dname);
 strupr(dname);

   fstream  fil2,fil3;
   int del=0;

   fil2.open("hotel.dat",ios::binary | ios::in);
   fil3.open("temp.dat",ios::binary | ios::out);

     while(fil2.read ((char*)&user,sizeof (user)))
     {
       if ((strcmp(name,dname))!=0)
       fil3.write((char*)&user,sizeof (user));
       else
       del++;
     }
       if(del!=0)
       cout<<endl<<"                         ...Deleted...";
       else
       cout<<endl<<"                       Record not found..";
       getch();
   fil2.close();
   fil3.close();

   transferhoteldata();
}



void travelagency::transferhoteldata()
{

fstream oldfile,newfile;


oldfile.open("temp.dat",ios::binary | ios::in);
newfile.open("hotel.dat",ios::binary | ios::out);

  while(oldfile.read((char*)&user,sizeof(user)))
  newfile.write((char*)&user,sizeof (user));

oldfile.close();
newfile.close();
}

void travelagency::searchhotrec()
{
clrscr();

char sname[20];
  gotoxy(20,5);cout<<"Enter Name to search for..";
  gotoxy(25,7);gets(sname);
  strupr(sname);

   fstream fil4;
   fil4.open("hotel.dat",ios::binary | ios::in);

   int srch=0;

     while(fil4.read((char*)&user,sizeof (user)))
     {
       if(strcmp(name,sname)==0)
       {
       srch++;
       user.showhotel();
       }
     }
       if(srch==0)
       cout<<"                         No Record Exists";
    fil4.close();
getch();
}

void travelagency::edithoteldata()
{
clrscr();
char ename[30];int ede=0;
gotoxy(20,5);cout<<"Enter Name to Edit Record for...";
gotoxy(25,7);gets(ename);
strupr(ename);

fstream fil5,fil6;
fil5.open("hotel.dat",ios::binary | ios::in) ;
fil6.open("temp1.dat",ios::binary | ios::out ) ;

 while(fil5.read((char*)&user,sizeof(user)))
  {
   if (strcmp (ename,name)==0)
   {
    resho();
    ede++;
   }
   fil6.write((char*)&user,sizeof (user));
  }
  if(ede==0)
  {
  gotoxy(25,17);cout<<"RECORD DOESNT EXIST!!!!";
  }
getch();
fil5.close();
fil6.close();
transferhoteldata1();
}


void travelagency::transferhoteldata1()
{
fstream oldfile2,newfile2;

oldfile2.open("temp1.dat",ios::binary | ios::in);
newfile2.open("hotel.dat",ios::binary | ios::out);

  while(oldfile2.read((char*)&user,sizeof(user)))
  newfile2.write((char*)&user,sizeof (user));

oldfile2.close();
newfile2.close();
}


void travelagency::restr()
{
clrscr();
 flag2='N';
 while(flag2!='Y')
 {
 clrscr();
 gotoxy(20,5);cout<<"Please Enter Information For Transport Reservation";
 gotoxy(20,7);cout<<"Please enter the choice of your mode of transportaion......";
 gotoxy(25,9);cout<<"1: by Air";
 gotoxy(25,10);cout<<"2: by Train";
 gotoxy(25,11);cout<<"3: by Road"<<endl;
 gotoxy(26,12);cout<<"......";cin>>top2;
 clrscr();

 assignprice();

   clrscr();
   gotoxy(15,2);cout<<"PLEASE FILL IN THE DETAILS ...";
   gotoxy(25,5);cout<<"TRANSPORT RESERVATION FORM";
   gotoxy(5,8);cout<<"Name: ";
   gotoxy(5,10);cout<<"Address: ";
   gotoxy(5,12);cout<<"Destination: ";
   gotoxy(30,12);cout<<"Mode of Transport: ";
   gotoxy(5,14);cout<<"Travel Date (dd-mm-yy): ";
   gotoxy(5,16);cout<<"Type of Tickets to be Reserved: Select 1 or 2" ;
   gotoxy(10,18);cout<<"1. Executive ";
   gotoxy(30,18);cout<<"2. Economy ";
   gotoxy(10,20);cout<<" Your choice (1/2) : ";
   gotoxy(10,22);cout<<"Is the information correct(y/n)?? ";
   gotoxy(10,8);gets(name);
   gotoxy(13,10);gets(add);
   gotoxy(19,12);gets(destination);
   gotoxy(50,12);gets(trans);
   gotoxy(30,14);gets(date);
   gotoxy(34,20);cin>>choice;
   if(choice == 1)
   {
    not1=1;not2=0;
   }
   else if (choice == 2)
  {
  not1=0;not2=1;
  }
   gotoxy(45,22);cin>>flag2;
 flag2=toupper(flag2);
}
showtransport();
}

void travelagency::showtransport()
{
 if(top2==1)
  price2=(atr1*not1)+(atr2*not2);
 else
  if(top2==2)
   price2=(ttr1*not1)+(ttr2*not2);
  else
   if(top2==3)
    price2=(rtr1*not1)+(rtr2*not2);

 if(toggle==1)
 {
 clrscr();
 gotoxy(20,8);cout<<"Please wait while we make the Reservation";
 delay(50);
 toggle=0;
 }
 clrscr();
 gotoxy(25,5);cout<<"Transport   Reservation  ";
 gotoxy(24,6);cout<<"-----------------------";
 gotoxy(15,8);cout<<"Name:"<<strupr(name);
 gotoxy(15,10);cout<<"Address:"<<strupr(add);
 gotoxy(15,12);cout<<"Mode of transportation:    "<<trans
		   <<"   Destination:"<<destination;
 gotoxy(15,14);cout<<"Travel date:  "<<strupr(date);
 gotoxy(15,16);cout<<"No. of EXECUTIVE class tickets reserved: "<<not1;
 gotoxy(15,18);cout<<"No. of ECONOMY   class tickets reserved: "<<not2;
 gotoxy(15,22);cout<<"Your Reservations have been done Please pay the Amount!!!";
 gotoxy(25,24);cout<<"Amount: Rs."<<setprecision(2)<<price2;
 getch();
}

void travelagency::viewtrrec()
{
int option;
 while(option!=5)
 {
  clrscr();
  gotoxy(24,5);cout<<"TRANSPORT RESERVATION INFORMATION...";
  gotoxy(25,10);cout<<"choose.....";
  gotoxy(25,12);cout<<"1: View transport reservation records";
  gotoxy(25,14);cout<<"2: Delete a particular record";
  gotoxy(25,16);cout<<"3: Search for a record";
  gotoxy(25,18);cout<<"4: Edit a record ";
  gotoxy(25,20);cout<<"5: Exit...     ";
  cin>>option;
  switch(option)
   {
   case 1:showtransportrec();
	  break;
   case 2:deltransportrec();
	  break;
   case 3:searchtransportrec();
	  break;
   case 4:edittransportdata();
	  break;
   }
 }
}

void travelagency::showtransportrec()
{
fstream file1;
file1.open("transport.dat",ios::binary|ios::in);
 while(file1.read((char*)&user,sizeof (user)))
 user.showtransport();
file1.close();
}

void travelagency::deltransportrec()
{
clrscr();
  char delname[20];
  gotoxy(20,5);cout<<"Enter name to delete record for...";
  gotoxy(30,7);gets(delname);
  strupr(delname);
    fstream  file2,file3;
    int dele=0;
    file2.open("transport.dat",ios::binary | ios::in);
    file3.open("temp3.dat",ios::binary | ios::out );
       while(file2.read ((char*)&user,sizeof (user)))
       {
       if ((strcmp(name,delname))!=0)
       file3.write((char*)&user,sizeof (user));
       else
       dele++;
       }
       if(dele!=0)
       cout<<endl<<"                    ...Deleted...";
       else
       cout<<endl<<"                  Record not found..";
       getch();
       file2.close();
       file3.close();
       transfertransportdata();
}

void travelagency::transfertransportdata()
{
fstream oldfile1,newfile1;
oldfile1.open("temp3.dat",ios::binary | ios::in);
newfile1.open("transport.dat",ios::binary | ios::out);
     while(oldfile1.read((char*)&user,sizeof(user)))
     newfile1.write((char*)&user,sizeof (user));
oldfile1.close();
newfile1.close();
}

void travelagency::searchtransportrec()
{
clrscr();
 char sename[20];
 gotoxy(20,5);cout<<"Enter Name to search for..";
 gotoxy(25,7);gets(sename);
 strupr(sename);
    fstream file4;
    file4.open("transport.dat",ios::binary | ios::in);
    int serch=0;
       while(file4.read((char*)&user,sizeof (user)))
       {
	if(strcmp(name,sename)==0)
	{
	serch++;
	user.showtransport();
	}
       }
       if(serch==0)
       cout<<"                       No Record Exists";
       file4.close();
       getch();
}

void travelagency::edittransportdata()
{
clrscr();
  char edname[30];
  int ede1=0;
  gotoxy(20,5);cout<<"Enter Name to Edit Record for...";
  gotoxy(25,7);gets(edname);
  strupr(edname);
  fstream file5,file6;
  file5.open("transport.dat",ios::binary | ios::in) ;
  file6.open("temp2.dat",ios::binary | ios::out ) ;
   while(file5.read((char*)&user,sizeof(user)))
  {
   if (strcmp (edname,name)==0)
   {
    restr();
    ede1++;
   }
   file6.write((char*)&user,sizeof (user));
  }
if(ede1==0)
{
gotoxy(25,17);cout<<"RECORD DOESNT EXIST!!!!";
}
getch();
file5.close();
file6.close();

transfertransportdata1();
}

void travelagency::transfertransportdata1()
{
fstream oldfile3,newfile3;
oldfile3.open("temp2.dat",ios::binary | ios::in);
newfile3.open("transport.dat",ios::binary | ios::out);
  while(oldfile3.read((char*)&user,sizeof(user)))
  newfile3.write((char*)&user,sizeof (user));
oldfile3.close();
newfile3.close();
}


void main()
{
clrscr();
cout.setf(ios::fixed,ios::floatfield);
cout.setf(ios::showpoint);
startup();
int opt;
while(opt!=5)
{
opt=opening1();                  //FUNTION CALL TO DISPLAY MENU
 switch(opt)
 {
 case 1:places();                //FUNTION CALL TO VIEW PLACES
	break;
 case 2:                         //FUNTION CALL TO RESERVE TRANSPORT
	maketrfile();i++;
	break;
 case 3:                         //FUNTION CALL TO RESERVE HOTEL
	makehofile();i++;
	break;
 case 4:clrscr();
	int search1;
	gotoxy(25,15);cout<<"Enter 1 or 2";
	gotoxy(25,17);cout<<"1: Hotel Reservation Records";
	gotoxy(25,19);cout<<"2: Transport Reservation Records";
	gotoxy(25,21);cout<<"??.....";cin>>search1;

	switch(search1)
	{
	case 1:user.viewhorec();
	       break;
	case 2:user.viewtrrec();
	       break;
	}
	break;
 }
}
}


/**********************************************
FUNTION USED TO MAKE TRANSPORT RECORD.
**********************************************/
void maketrfile()
{
       fstream fil;
       fil.open("transport.dat",ios::binary | ios::out |ios::app);
       user1[i].toggle=1;
       user1[i].restr();
       fil.write((char*)&user1[i],sizeof (user1[i]));
       fil.close();
}


/**********************************************
FUNTION USED TO MAKE HOTEL RECORD.
**********************************************/
void makehofile()
{
       fstream fil;
       fil.open("hotel.dat",ios::binary | ios::out |ios::app );
       user1[i].toggle=1;
       user1[i].resho();
       fil.write((char*)&user1[i],sizeof (user1[i]));
       fil.close();
}


/**********************************************
FUNTION USED TO DISPLAY INTRODUCTION SCREEN
**********************************************/
void startup()
{
 int a;
  clrscr();
  gotoxy(25,10);cout<<"WELCOME TO INDIAN TRAVEL AGENCY";
  delay(50);
 for(a=42;a<52;a++)
  {
  gotoxy(27,18);cout<<"Please Wait";
  gotoxy(a,18);cout<<".";
  delay(200);
  }
gotoxy(24,24);
cout<<"press any key to continue...";
getch();
}
/**********************************************
FUNTION USED TO DISPLAY MENU.
**********************************************/
int opening1()
{
int pass;
clrscr();
gotoxy(10,6);cout<<"WELLCOME!!!!!!......"
		     "What would you like us to do for you";
gotoxy(15,9);cout<<"1: View Tourist Places";
gotoxy(15,11);cout<<"2: Reserve Transportation";
gotoxy(15,13);cout<<"3: Reserve Accomodation";
gotoxy(15,15);cout<<"4: View Existing Bookings";
gotoxy(15,17);cout<<"5: Exit";
gotoxy(13,20);cout<<"Enter the choice:- ";cin>>pass;
return(pass);
}

void opening2()     //function to display menu with places
{
int opt2;
 gotoxy(10,21);cout<<"1: Reserve Transportation";
 gotoxy(10,22);cout<<"2: Reserve Accomodation";
 gotoxy(10,23);cout<<"3: Reserve Transportation and Accomodation";
 gotoxy(10,24);cout<<"4: Exit :- ";cin>>opt2;
 if (opt2!=4)
 {
  switch(opt2)
  {
  case 1:maketrfile();i++;
	 break;
  case 2:makehofile();i++;
	 break;
  case 3:maketrfile();i++;
	 makehofile();i++;
	 break;
  }
 }
}


/**********************************************
FUNTION USED TO DISPLAY CHOICE OF DESTINATION.
**********************************************/
void places()
{
int des;
int j=19;
       clrscr();
       gotoxy(j+3,7);cout<<"Choose Destination"<<endl;
       gotoxy(j,11);cout<<"      1.NORTH INDIA             "<<endl;
       gotoxy(j,13);cout<<"      2.SOUTH INDIA             "<<endl;
       gotoxy(j,15);cout<<"      3.CENTRAL INDIA           "<<endl;
       gotoxy(j,17);cout<<"      4.EXIT                   "<<endl;
       gotoxy(j,19);cout<<"                      "<<endl;
       gotoxy(j,21);cout<<" ENTER YOUR CHOICE:- ";
       cin>>des;
       delay(50);

int des1;
if (des!=4)
{
 switch(des)
 {
  case 1:      clrscr();
	  gotoxy(j+3,5);cout<<"Where do you want go......";
	  gotoxy(j,11);cout<<"      1.JAMMU & KASHMIR "<<endl;
	  gotoxy(j,13);cout<<"      2.HARYANA  "<<endl;
	  gotoxy(j,15);cout<<"      3.PUNJAB     "<<endl;
	  gotoxy(j,17);cout<<"      4.HIMACHAL PRADESH  "<<endl;
	  gotoxy(j,19);cout<<"      5.EXIT     "<<endl;
	  gotoxy(j,20);cout<<"                      "<<endl;
	  gotoxy(j,21);cout<<" ENTER CHOICE:- ";cin>>des1;
	  if(des1!=5)
	  user.nindia(des1);
	  break;

case 2:  	  clrscr();
	  gotoxy(j+3,5);cout<<"Where do you want go......"<<endl;
	  gotoxy(j,11);cout<<"      1.KERALA                  "<<endl;
	  gotoxy(j,13);cout<<"      2.TAMIL NADU             "<<endl;
	  gotoxy(j,15);cout<<"      3.KARNATAKA         "<<endl;
	  gotoxy(j,17);cout<<"      4.TELANGANA             "<<endl;
	  gotoxy(j,19);cout<<"      5.EXIT                   "<<endl;
	  gotoxy(j,20);cout<<"                      "<<endl;
	  gotoxy(j,21);cout<<" ENTER CHOICE:- ";cin>>des1;
	  if(des1!=6)
	  user.sindia(des1);
	  break;
case 3:  	clrscr();
	gotoxy(j+3,5);cout<<"Where do you want go......"<<endl;;
	gotoxy(j,11);cout<<"         1.ODISHA              "<<endl;
	gotoxy(j,13);cout<<"         2.MADHYA PRADESH      "<<endl;
	gotoxy(j,15);cout<<"         3.EXIT                 "<<endl;
	gotoxy(j,16);cout<<"                               "<<endl;
	gotoxy(j,17);cout<<" ENTER CHOICE:- ";cin>>des1;
	if(des1!=3)
	user.cindia(des1);
	break;
 }
}
}


/**********************************************
FUNTION USED TO DISPLAY NORTH-INDIA INFORMATION.
**********************************************/
void travelagency::nindia(int ndes)
{
switch(ndes)
{
 case 1:clrscr();
gotoxy(25,1);cout<<"Jammu and Kashmir ";
gotoxy(24,2);cout<<"------------------";
gotoxy(20,3);cout<<"Places To Visit::        -KASHMIR-    -JAMMU- "<<"\n";
gotoxy(5,4);cout<<"Transportation Available::From Delhi)"<<"\n";
cout<<"   MODE    Place        NAME    Price:Executive   Economy   Timings         "<<"\n";
cout<<"  BY Air   KASH      041 I.A.     Rs 12000       Rs 9000  13:50-15:30"<<"\n";
cout<<"  BY Air   JAM       042 I.A.     Rs 12000       Rs 9000   8:00- 9:40"<<"\n";
cout<<"  BY Train Kash   Kashmir Express Rs  2500       Rs 2000  13:00-18:00"<<endl;
cout<<"  By Train JAM       Jammu Mail   Rs  2500       Rs 2000  15:00-16:30"<<"\n";
cout<<"  By Road  KASH      Bus          Rs   700       Rs  500  12:00-20:00"<<"\n";
cout<<"  By Road  JAM       Bus          Rs   700       Rs  500  14:00-15:00"<<"\n";
gotoxy(5,12);cout<<"Accomodation Available::"<<endl;
cout<<"   Star    Place      NAME Of Hotel       Tariff:  Deluxe     Non-deluxe   "<<"\n";
cout<<"    5      KASH        Raddison                  Rs 5000        Rs 3000     "<<"\n";
cout<<"    5      JAM         Marriot                   Rs 5000        Rs 3000     "<<"\n";
cout<<"    3      KASH        Royal Inn                 Rs 3000        Rs 1500     "<<endl;
cout<<"    3      JAM         Holiday Inn               Rs 3000        Rs 1500     "<<"\n";
cout<<"   normal  KASH        Park Hill                 Rs 1000        Rs  500      "<<endl;
cout<<"   normal  JAM         Swastik                   Rs 1000        Rs  500      "<<endl;
cout<<setw(15)<<"               NOTE::(Tariff includes GST charges and Breakfast only) ";

    atr1=12000;atr2=9000;ttr1=2500;ttr2=2000;rtr1=700;rtr2=500;
    fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
    opening2();
    break;

case 2:clrscr();
gotoxy(25,1);cout<<"     HARYANA";
gotoxy(24,2);cout<<"------------------";
gotoxy(20,3);cout<<"Places To Visit::         -CHANDIGARH-    -GURGAON- "<<endl;
gotoxy(5,4);cout<<"Transportation Available::(From Delhi)"<<endl;
cout<<"   MODE    Place        NAME    Price:Executive   Economy   Timings          "<<endl;
cout<<"  BY Air   CHAN       051 I.A.     Rs 10000       Rs 8000  12:50-13:30"<<endl;
cout<<"  BY Air   GUR        052 I.A.     Rs 10000       Rs 8000   7:00- 7:40"<<endl;
cout<<"  BY Train CHAN   Haryana Express  Rs  1500       Rs 1000  13:00-18:00"<<endl;
cout<<"  By Train GUR    Punjab Mail      Rs  1500       Rs 1000  14:00-14:30"<<endl;
cout<<"  By Road  CHAN      Bus           Rs   300       Rs  200  12:00-20:00"<<endl;
cout<<"  By Road  GUR       Bus           Rs   300       Rs  200  14:00-15:00"<<endl;
gotoxy(5,12);cout<<"Accomodation Available::"<<endl;
cout<<"   Star    Place       NAME Of Hotel      Tariff:  Deluxe     Non-deluxe   "<<endl;
cout<<"    5      CHAN         Taj                       Rs 5000    Rs 3000      "<<endl;
cout<<"    5      GUR          Ashoka                    Rs 5000    Rs 3000     "<<endl;
cout<<"    3      CHAN         Sunstar                   Rs 3000    Rs 1500     "<<endl;
cout<<"    3      GUR          Ambala                    Rs 3000    Rs 1500     "<<endl;
cout<<"   normal  CHAN         Rivoli                    Rs 1000    Rs  500      "<<endl;
cout<<"   normal  GUR          Platinum                  Rs 1000    Rs  500      "<<endl;
cout<<setw(15)<<"               NOTE::(Tariff includes GST charges and Breakfast only) ";
    atr1=10000;atr2=8000;ttr1=1500;ttr2=1000;rtr1=300;rtr2=200;
    fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
    opening2();
    break;

case 3:clrscr();
gotoxy(25,1);cout<<"     PUNJAB";
gotoxy(24,2);cout<<"------------------";
gotoxy(20,3);cout<<"Places To Visit::         -AMRITSAR-    -LUDHIANA- "<<endl;
gotoxy(5,4);cout<<"Transportation Available::(From Delhi)"<<endl;
cout<<"   MODE    Place        NAME    Price:Executive   Economy   Timings          "<<endl;
cout<<"  BY Air   AMR      051 I.A.      Rs 8000         Rs 6000   12:50-13:30"<<endl;
cout<<"  BY Air   LUD      052 I.A.      Rs 8000         Rs 6000    5:00- 5:40"<<endl;
cout<<"  BY Train AMR   Haryana Express  Rs 1200         Rs 1000   13:00-18:00"<<endl;
cout<<"  By Train LUD    Punjab Mail     Rs 1200         Rs 1000   14:00-14:30"<<endl;
cout<<"  By Road  AMR      Bus           Rs  300         Rs  200   12:00(d)-20:00"<<endl;
cout<<"  By Road  LUD      Bus           Rs  300         Rs  200   14:00-15:00"<<endl;
gotoxy(5,12);cout<<"Accomodation Available::"<<endl;
cout<<"   Star    Place        NAME Of Hotel     Tariff:  Deluxe     Non-deluxe   "<<endl;
cout<<"    5      AMR            Taj                     Rs 5000      Rs 3000     "<<endl;
cout<<"    5      LUD            Raddison                Rs 5000      Rs 3000     "<<endl;
cout<<"    3      AMR            Grand                   Rs 3000      Rs 1500     "<<endl;
cout<<"    3      LUD            Maharaja                Rs 3000      Rs 1500     "<<endl;
cout<<"   normal  AMR            Riyasat                 Rs 1000      Rs  500     "<<endl;
cout<<"   normal  LUD            Gulmor                  Rs 1000      Rs  500     "<<endl;
cout<<setw(15)<<"               NOTE::(Tariff includes GST and Breakfast only     ";
       atr1=8000;atr2=6000;ttr1=1200;ttr2=1000;rtr1=300;rtr2=200;
       fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
       opening2();
       break;

case 4:clrscr();
       gotoxy(25,1);cout<<" HIMACHAL PRADESH";
       gotoxy(24,2);cout<<"------------------";
       gotoxy(20,3);cout<<"Places To Visit::         -SHIMLA-    -MANALI- "<<endl;
       gotoxy(5,4);cout<<"Transportation Available::(from delhi)"<<endl;
       cout<<"   MODE    Place        NAME    Price:Executive   Economy   Timings          "<<endl;
       cout<<"  BY Air   SHI      151 I.A.      Rs 10000        Rs 8000  12:30-13:30"<<endl;
       cout<<"  BY Air   MAN      152 I.A.      Rs 10000        Rs 8000   6:50- 7:40"<<endl;
       cout<<"  BY Train SHI   Himachal Express Rs  2000        Rs 1000  13:00-19:00"<<endl;
       cout<<"  By Train MAN   Kalka Mail       Rs  2000        Rs 1000  14:00-19:30"<<endl;
       cout<<"  By Road  SHI      Bus           Rs   800        Rs  500  12:00-20:00"<<endl;
       cout<<"  By Road  MAN      Bus           Rs   800        Rs  500  14:00-20:00"<<endl;
       gotoxy(5,12);cout<<"Accomodation Available::"<<endl;
       cout<<"   Star    Place        NAME Of Hotel     Tariff:  Deluxe     Non-deluxe   "<<endl;
       cout<<"    5      SHI           Le Royale                Rs 4000    Rs 3000     "<<endl;
       cout<<"    5      MAN           Chanakya                 Rs 4000    Rs 3000     "<<endl;
       cout<<"    3      SHI           Geetanjali               Rs 3000    Rs 1500     "<<endl;
       cout<<"    3      MAN           Parkview                 Rs 3000    Rs 1500     "<<endl;
       cout<<"   normal  SHI           Mountview                Rs  800    Rs  500      "<<endl;
       cout<<"   normal  MAN           Surya                    Rs  800    Rs  500      "<<endl;
       cout<<setw(15)<<"               NOTE::(Tariff includes GST charges and Breakfast only) ";
       atr1=10000;atr2=8000;ttr1=2000;ttr2=1000;rtr1=800;rtr2=500;
       fst1=4000;fst2=3000;tst1=3000;tst2=1500;nst1=800;nst2=500;
       opening2();
       break;
}
}


/**********************************************
FUNTION USED TO DISPLAY SOUTH-INDIA INFORMATION.
**********************************************/
void travelagency::sindia(int sdes)
{
switch(sdes)
{
case 1:clrscr();
       gotoxy(25,1);cout<<"      KERALA ";
       gotoxy(24,2);cout<<"------------------";
       gotoxy(20,3);cout<<"Places To Visit::         -TRIVANDRUM-    -KOCHI- "<<endl;
       gotoxy(5,4);cout<<"Transportation Available::(from delhi)"<<endl;
       cout<<"   MODE    Place        NAME    Price:Executive   Economy   Timings          "<<endl;
       cout<<"  BY Air   TRI       141 I.A.     Rs 15000        Rs 12000  13:50-16:30"<<endl;
       cout<<"  BY Air   KOC       142 I.A.     Rs 15000        Rs 12000   8:00-11:40"<<endl;
       cout<<"  BY Train TRI   Kerala Express   Rs  3500        Rs  2000  06:00-18:00"<<endl;
       cout<<"  By Train KOC   Delhi Rajdhani   Rs  3500        Rs  2000  05:00-16:30"<<endl;
       cout<<"  By Road  TRI      Bus           Rs  1200        Rs   700  05:00-22:00"<<endl;
       cout<<"  By Road  KOC      Bus           Rs  1200        Rs   700  05:00-23:00"<<endl;
       gotoxy(5,12);cout<<"Accomodation Available::"<<endl;
       cout<<"   Star    Place      NAME Of Hotel      Tariff:   Deluxe     Non-deluxe   "<<endl;
       cout<<"    5      TRI         Hilton                     Rs 5000     Rs 3000     "<<endl;
       cout<<"    5      KOC         Raddison                   Rs 5000     Rs 3000     "<<endl;
       cout<<"    3      TRI         Ruby Arena                 Rs 3000     Rs 1500     "<<endl;
       cout<<"    3      KOC         Flamingo Inn               Rs 3000     Rs 1500     "<<endl;
       cout<<"   normal  TRI         Galaxy                     Rs 1000     Rs  500     "<<endl;
       cout<<"   normal  KOC         Ganesh                     Rs 1000     Rs  500     "<<endl;
       cout<<setw(15)<<"               NOTE::(Tariff includes GST charges and Breakfast only) ";
       atr1=15000;atr2=12000;ttr1=3500;ttr2=2000;rtr1=1200;rtr2=700;
       fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
       opening2();
       break;

case 2:clrscr();
       gotoxy(25,1);cout<<"    TAMIL NADU";
       gotoxy(24,2);cout<<"------------------";
       gotoxy(20,3);cout<<"Places To Visit::         -CHENNAI-    -MADURAI- "<<endl;
       gotoxy(5,4);cout<<"Transportation Available::(from delhi)"<<endl;
       cout<<"   MODE    Place        NAME    Price:Executive   Economy   Timings          "<<endl;
       cout<<"  BY Air   CHE       181 I.A.     Rs 12000         Rs 10000  12:50-13:30"<<endl;
       cout<<"  BY Air   MAD       182 I.A.     Rs 12000         Rs 10000   7:00- 7:40"<<endl;
       cout<<"  BY Train CHE    Chennai Express Rs  2500         Rs  1500  08:00-18:00"<<endl;
       cout<<"  By Train MAD    Navyug Express  Rs  2500         Rs  1500  09:00-14:30"<<endl;
       cout<<"  By Road  CHE       Bus          Rs   800         Rs   500  05:00-20:00"<<endl;
       cout<<"  By Road  MAD       Bus          Rs   800         Rs   500  06:00-22:00"<<endl;
       gotoxy(5,12);cout<<"Accomodation Available::"<<endl;
       cout<<"   Star    Place        NAME Of Hotel     Tariff:  Deluxe     Non-deluxe   "<<endl;
       cout<<"    5      CHE          Taj                        Rs 5000     Rs 3000     "<<endl;
       cout<<"    5      MAD          Marriot                    Rs 5000     Rs 3000     "<<endl;
       cout<<"    3      CHE          Supreme                    Rs 2500     Rs 1500     "<<endl;
       cout<<"    3      MAD          Presidency                 Rs 2500     Rs 1500     "<<endl;
       cout<<"   normal  CHE          Pandian                    Rs 1000     Rs  500      "<<endl;
       cout<<"   normal  MAD          Meenakshi                  Rs 1000     Rs  500      "<<endl;
       cout<<setw(15)<<"               NOTE::(Tariff includes GST charges and Breakfast only) ";
       atr1=12000;atr2=10000;ttr1=2500;ttr2=1500;rtr1=800;rtr2=500;
       fst1=5000;fst2=3000;tst1=2500;tst2=1500;nst1=1000;nst2=500;
       opening2();
       break;

case 3:clrscr();
       gotoxy(25,1);cout<<"  KARNATAKA";
       gotoxy(24,2);cout<<"------------------";
       gotoxy(20,3);cout<<"Places To Visit::         -BANGLORE-    -MYSORE- "<<endl;
       gotoxy(5,4);cout<<"Transportation Available::(from delhi)"<<endl;
       cout<<"   MODE    Place        NAME    Price:Executive   Economy   Timings          "<<endl;
       cout<<"  BY Air   BAN       081 I.A.       Rs 9000       Rs 7000  12:50-13:30"<<endl;
       cout<<"  BY Air   MYS       082 I.A.       Rs 9000       Rs 7000   5:00- 5:40"<<endl;
       cout<<"  BY Train BAN   Banglore Express   Rs 1200       Rs 1000  08:00-18:00"<<endl;
       cout<<"  By Train MYS   Swarna Jayanthi    Rs 1200       Rs 1000  09:00-14:30"<<endl;
       cout<<"  By Road  BAN      Bus             Rs  700       Rs  500  12:00-20:00"<<endl;
       cout<<"  By Road  MYS      Bus             Rs  700       Rs  500  06:00-15:00"<<endl;
       gotoxy(5,12);cout<<"Accomodation Available::"<<endl;
       cout<<"   Star    Place        NAME Of Hotel     Tariff:  Deluxe     Non-deluxe   "<<endl;
       cout<<"    5      BAN           Marriot                  Rs 5000    Rs 3000     "<<endl;
       cout<<"    5      MYS           Radisson                 Rs 5000    Rs 3000     "<<endl;
       cout<<"    3      BAN           Encore                   Rs 3000    Rs 1500     "<<endl;
       cout<<"    3      MYS           Green Park               Rs 3000    Rs 1500     "<<endl;
       cout<<"   normal  BAN           Daspalla                 Rs 1000    Rs  500     "<<endl;
       cout<<"   normal  MYS           Balaji                   Rs 1000    Rs  500     "<<endl;
       cout<<setw(15)<<"               NOTE::(Tariff includes GST charges and Breakfast only) ";
       atr1=9000;atr2=7000;ttr1=1200;ttr2=1000;rtr1=700;rtr2=500;
       fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
       opening2();
       break;

case 4:clrscr();
       gotoxy(25,1);cout<<"    TELANGANA";
       gotoxy(24,2);cout<<"------------------";
       gotoxy(20,3);cout<<"Places To Visit::         -HYDERABAD-    -WARANGAL- "<<endl;
       gotoxy(5,4);cout<<"Transportation Available::(from delhi)"<<endl;
       cout<<"   MODE    Place        NAME    Price:Executive   Economy   Timings          "<<endl;
       cout<<"  BY Air   HYD      351 I.A.     Rs 11000         Rs 9000   12:30-13:30"<<endl;
       cout<<"  BY Air   WAR      352 I.A.     Rs 11000         Rs 9000    6:50- 7:40"<<endl;
       cout<<"  BY Train HYD   Telangana Exp   Rs  2000         Rs 1000   10:00-19:00"<<endl;
       cout<<"  By Train WAR   Dakshin Exp     Rs  2000         Rs 1000   10:00-19:30"<<endl;
       cout<<"  By Road  HYD      Bus          Rs   800         Rs  500   09:00-20:00"<<endl;
       cout<<"  By Road  WAR      Bus          Rs   800         Rs  500   09:00-20:00"<<endl;
       gotoxy(5,12);cout<<"Accomodation Available::"<<endl;
       cout<<"   Star    Place        NAME Of Hotel     Tariff:  Deluxe     Non-deluxe   "<<endl;
       cout<<"    5      HYD           Marriot                  Rs 5000       Rs 4000       "<<endl;
       cout<<"    5      WAR           Holidaynn                Rs 5000       Rs 4000       "<<endl;
       cout<<"    3      HYD           Savera                   Rs 3000       Rs 1500       "<<endl;
       cout<<"    3      WAR           Seaview                  Rs 3000       Rs 1500       "<<endl;
       cout<<"   normal  HYD           Clarks                   Rs  800       Rs  500       "<<endl;
       cout<<"   normal  WAR           Amaravathy               Rs  800       Rs  500       "<<endl;
       cout<<setw(15)<<"               NOTE::(Tariff includes GST charges and Breakfast only) ";
       atr1=11000;atr2=9000;ttr1=2000;ttr2=1000;rtr1=800;rtr2=500;
       fst1=5000;fst2=4000;tst1=3000;tst2=1500;nst1=800;nst2=500;
       opening2();
       break;
}
}
/**********************************************
FUNTION USED TO DISPLAY CENTRAL-INDIA INFORMATION.
**********************************************/
void travelagency::cindia(int cdes)
{
switch(cdes)
{
case 1:clrscr();
       gotoxy(25,1);cout<<"      ODISHA ";
       gotoxy(24,2);cout<<"------------------";
       gotoxy(20,3);cout<<"Places To Visit::         -BHUBANESHWAR-    -CUTTACK- "<<endl;
       gotoxy(5,4);cout<<"Transportation Available::(from delhi)"<<endl;
       cout<<"   MODE    Place        NAME    Price:Executive   Economy   Timings          "<<endl;
       cout<<"  BY Air   BHUB       091 I.A.     Rs 13000       Rs 10000  13:50-17:30"<<endl;
       cout<<"  BY Air   CUTT       092 I.A.     Rs 13000       Rs 10000   8:00-11:40"<<endl;
       cout<<"  BY Train BHUB     Puri Express   Rs  2500       Rs  2000  04:00-18:00"<<endl;
       cout<<"  By Train CUTT     Mundu Mail     Rs  2500       Rs  2000  07:00-16:30"<<endl;
       cout<<"  By Road  BHUB      Bus           Rs   700       Rs   500  03:00-20:00"<<endl;
       cout<<"  By Road  CUTT      Bus           Rs   700       Rs   500  07:00-15:00"<<endl;
       gotoxy(5,12);cout<<"Accomodation Available::"<<endl;
       cout<<"   Star    Place        NAME Of Hotel     Tariff:  Deluxe     Non-deluxe   "<<endl;
       cout<<"    5      BHUB         Crown Plaza               Rs 5000     Rs 3000     "<<endl;
       cout<<"    5      CUTT         Presidency                Rs 5000     Rs 3000     "<<endl;
       cout<<"    3      BHUB         Prachi                    Rs 3000     Rs 1500     "<<endl;
       cout<<"    3      CUTT         Keshari                   Rs 3000     Rs 1500     "<<endl;
       cout<<"   normal  BHUB         Anarkali                  Rs 1000     Rs  500     "<<endl;
       cout<<"   normal  CUTT         Pushpak                   Rs 1000     Rs  500     "<<endl;
       cout<<setw(15)<<"               NOTE::(Tariff includes GST charges and Breakfast only) ";
       atr1=13000;atr2=10000;ttr1=2500;ttr2=2000;rtr1=700;rtr2=500;
       fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
       opening2();
       break;

case 2:clrscr();
       gotoxy(25,1);cout<<"   MADHYA PRADESH";
       gotoxy(24,2);cout<<"--------------------";
       gotoxy(20,3);cout<<"Places To Visit::         -BHOPAL-    -GWALIOR- "<<endl;
       gotoxy(5,4);cout<<"Transportation Available::(from delhi)"<<endl;
       cout<<"   MODE    Place        NAME    Price:Executive   Economy   Timings          "<<endl;
       cout<<"  BY Air   BHOP       061 I.A.     Rs 10000       Rs 8000  11:50-13:30"<<endl;
       cout<<"  BY Air   GWAL       062 I.A.     Rs 10000       Rs 8000   6:00- 7:40"<<endl;
       cout<<"  BY Train BHOP   Deccan Express   Rs  1500       Rs 1000  11:00-18:00"<<endl;
       cout<<"  By Train GWAL   Gwalior Mail     Rs  1500       Rs 1000  07:00-14:30"<<endl;
       cout<<"  By Road  BHOP       Bus          Rs   300       Rs  200  07:00-20:00"<<endl;
       cout<<"  By Road  GWAL       Bus          Rs   300       Rs  200  08:00-15:00"<<endl;
       gotoxy(5,12);cout<<"Accomodation Available::"<<endl;
       cout<<"   Star    Place        NAME Of Hotel     Tariff:  Deluxe     Non-deluxe   "<<endl;
       cout<<"    5      BHOP         Taj                       Rs 5000     Rs 3000      "<<endl;
       cout<<"    5      GWAL         Hyatt                     Rs 5000     Rs 3000     "<<endl;
       cout<<"    3      BHOP         Metro                     Rs 3000     Rs 1500     "<<endl;
       cout<<"    3      GWAL         President                 Rs 3000     Rs 1500     "<<endl;
       cout<<"   normal  BHOP         Stay Inn                  Rs 1000     Rs  500      "<<endl;
       cout<<"   normal  GWAL         Safari                    Rs 1000     Rs  500      "<<endl;
       cout<<setw(15)<<"               NOTE::(Tariff includes GST charges and Breakfast only) ";
       atr1=10000;atr2=8000;ttr1=1500;ttr2=1000;rtr1=300;rtr2=200;
       fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
       opening2();
       break;
}
}

/**********************************************
FUNTION USED TOASSIGN PRICE ACCORDING TO DESTINATION.
**********************************************/
void travelagency::assignprice()
{
clrscr();
int toasspri;
  gotoxy(20,2);cout<<"PLEASE CHOOSE YOUR DESTINATION..";
  gotoxy(5,5);cout<<"   1:Kashmir or Jammu                      2:Chandigarh or Gurgaon";
  gotoxy(5,7);cout<<"   3:Amritsar or Ludhiana                  4:Shimla or Manali";
  gotoxy(5,9);cout<<"   5:Trivandrum or Kochi                   6:Chennai or Madurai";
  gotoxy(5,11);cout<<"   7:Banglore or Mysore                    8.Hyderabad or Warangal";
  gotoxy(5,13);cout<< "   9:Bhubneshwar or Cuttack                10:Bhopal or Gwalior";
  gotoxy(5,23);cout<<"Enter (1-10) to Reserve ...";
  gotoxy(45,23);cin>>toasspri;
switch(toasspri)
{
 case 1:atr1=12000;atr2=9000;ttr1=2500;ttr2=2000;rtr1=700;rtr2=500;
	fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
	break;
 case 2:atr1=10000;atr2=8000;ttr1=1500;ttr2=1000;rtr1=300;rtr2=200;
	fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
	break;
 case 3:atr1=8000;atr2=6000;ttr1=1200;ttr2=1000;rtr1=300;rtr2=200;
	fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
	break;
 case 4:atr1=10000;atr2=8000;ttr1=2000;ttr2=1000;rtr1=800;rtr2=500;
	fst1=4000;fst2=3000;tst1=3000;tst2=1500;nst1=800;nst2=500;
	break;
 case 5:atr1=15000;atr2=12000;ttr1=3500;ttr2=2000;rtr1=1200;rtr2=700;
	fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
	break;
 case 6:atr1=12000;atr2=10000;ttr1=2500;ttr2=1500;rtr1=800;rtr2=500;
                fst1=5000;fst2=3000;tst1=2500;tst2=1500;nst1=1000;nst2=500;
                break;
 case 7:atr1=9000;atr2=7000;ttr1=1200;ttr2=1000;rtr1=700;rtr2=500;
	fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
	break;
 case 8:atr1=11000;atr2=9000;ttr1=2000;ttr2=1000;rtr1=800;rtr2=500;
      	fst1=5000;fst2=4000;tst1=3000;tst2=1500;nst1=800;nst2=500;
	break;
case 9:atr1=13000;atr2=10000;ttr1=2500;ttr2=2000;rtr1=700;rtr2=500;
	 fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
	 break;
case 10:atr1=10000;atr2=8000;ttr1=1500;ttr2=1000;rtr1=300;rtr2=200;
	 fst1=5000;fst2=3000;tst1=3000;tst2=1500;nst1=1000;nst2=500;
	 break;
}
}
