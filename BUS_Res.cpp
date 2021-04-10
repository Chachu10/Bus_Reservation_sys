#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
#include<graphics.h>


char TUname[20];
class User
{
	public:
	char Name[20];
	char Email[30];
	char UserName[20];
	char PassWord[20];
};

class Admin
{

	public:
	char ADMIN_NAME[20];
	char ADMIN_PASS[20];
	Admin()
	{
		strcpy(ADMIN_NAME,"admin123");
		strcpy(ADMIN_PASS,"admin123");

	}

};
class TRAVEL
{
    public:
    void INFORMATION( void );
	void RESERVATION( void );
    int  RESERVED( int , int , int , int , int );
	int  AVAIL( int , int , int , int );
    int  SEAT_NO( int , int , int , int);
    void DELETION( void );
    void MODIFICATION( void );
    void LIST_OF_PASS( void );
	void LIST_OF_PASS1( void );
    void TKT_PRINT( void );
    void MAINMENU( void );


private:
	int  busno,
	 seatno,
	 book_id1;

	char name[ 26 ],
	 sex;
	char UserName[20];
	int  age,
	 fare;
	int  dd,
	 mm,
	 yy;
};
char *place[6]={"Mumbai","Pune","Hyderabad","Vizag","Goa","Chennai"};
int price[6]={2100,2000,920,175,500,730};
char *ptime[6]={"10:30AM","11:30AM","12:30PM","1:30PM","2:30PM"};

int book_idgen()
{
	clrscr();
	rand:
	int id,a;
	randomize();
	id=rand()%10 + (10*(rand()%10)) + (100*(rand()%10))+1000;

	fstream file("bookingid.txt",ios::out,ios::in);
	file>>a;
	if(a==id)
	{
		goto rand;
	}
	else
	{
		file<<id;
	}
	file.close();
	return id;

}

/char U_Name( char uname[30])
{

	char username[30];

	strcpy(username,uname);

	return  username;
}
*/

void password(char pass[])
{ //renaming the input variable to avoid confusion
    int i=0; //loop counter
	char temp; //a Temp char
    for(i=0; ; )
    { //infinite loop
	temp=getch(); //stores char typed in temp
	if((temp>='a'&&temp<='z')||(temp>='A'&&temp<='Z')||(temp>='0'&&temp<='9'))
	{
	//check if a is numeric or alphabet
	    pass[i]=temp; //stores temp in pass
	    ++i;
	    cout<<"*";
	}
	if(temp=='\b'&& i>=1)
	{//if user typed backspace
	//i should be greater than 1.
	    cout<<"\b \b"; //delete the character behind the cursor.
	    --i;
	}
	if(temp=='\r')
	{//if enter is pressed
	    pass[i]='\0'; //null means end of string.
	     break; //break the loop
	}
    }
} //end of password function

//THIS FUNCTION DISPLAY THE PASSENGER INFORMATION
void  TRAVEL::TKT_PRINT( void )
{
    clrscr( );
    int bookid,
	found  = 0;

    LIST_OF_PASS();
    cout<<"PLEASE ENTER THE BOOKING ID OF THE TICKET YOU WANT TO PRINT : ";
    cin>>bookid;


	fstream  file;
    file.open( "INFO1.DAT", ios::in );
	while( file.read( ( char * )this, sizeof( TRAVEL ) ) )
    {
	if(bookid==book_id1)
	{
	    found = 1;
		clrscr( );
	    gotoxy( 5, 5 );

	    cout << "************************";
	    gotoxy( 28, 7 );
	    cout << "DPS Travels Pvt Ltd";
		gotoxy( 10, 9 );
	    cout << "BUS NO." << busno << "\t\t\tDATE:" << dd << "/" << mm << "/" << yy;
		gotoxy( 10, 10 );
	    cout << "SEAT NO.:" << seatno << "\t\t\tTIME:" << ptime[ busno - 1 ];
	    gotoxy( 10, 12 );
	    cout << "FROM:Bangalore" << "\t\t\tTO:" << place[ busno - 1 ];
	    gotoxy( 10, 14 );
		cout << "PASSENGER NAME:" << name;
	    gotoxy( 10, 16 );
	    cout << "PASSENGER AGE:  " << age << "\t\t\tGender:" << sex;
	    gotoxy( 10, 18 );
	    cout << "TOTAL FARE  :" << price[ busno - 1 ];
	    gotoxy( 10, 20 );
		cout<<"BOOKING ID: "<<book_id1;
	    gotoxy( 5, 22 );
		cout << "************************";
	    gotoxy( 1, 25 );
	    cout << "Press any key to continue...";
	    getch( );
	    break;
	}
    }
    file.close( );
    if( !found )
    {
	cout << "\n Passenger record not found";
	getch( );
    }
}
//This function gives the list of all the passenger
void  TRAVEL::LIST_OF_PASS1( void )
{

	bmenu:
    clrscr( );

    int  bno    = 0,
	 found  = 0,
	 row    = 8;
	char ch;
    cout << "\n\t\t\t DPS TRAVELS PVT LTD.";
	cout << "\n Bus 1:Bangalore to Mumbai      <fare Rs.100>";
    cout << "\n Bus 2:Bangalore to Pune        <fare Rs.220>";
    cout << "\n Bus 3:Bangalore to Hyderabad   <fare Rs.175>";
	cout << "\n Bus 4:Bangalore to Vizag      <fare Rs.1000>";
    cout << "\n Bus 5:Bangalore to Goa         <fare Rs.500>";
	cout << "\n Bus 6:Bangalore to Chennai     <fare Rs.730>";
    do
    {
	cout << "\n\nEnter the Bus no.(1/2/3/4/5/6):";
	cin >> bno;
	if(bno<1||bno>6)
	{
		cout<<"PLEASE ENTER A VALID BUS NO!! ";
		getch();
		goto bmenu;
	}
    } while( bno < 1 || bno > 6 );
    do
	{
	cout << "\n Do you want date wise report(y/n):";
	cin >> ch;
    }
	while( toupper( ch ) != 'N' && toupper( ch ) != 'Y' );
    int d  = 0,
	m  = 0,
	y  = 0;
	if( toupper( ch ) == 'Y' )
    {
	cout << "\nEnter date(dd):";
	cin >> d;
	cout << "\nEnter month(mm):";
	cin >> m;
	cout << "\nEnter year(yy):";
	cin >> y;
    }
    clrscr( );
    gotoxy( 25, 1 );
	cout << "LIST OF THE PASSENGERS ";
    gotoxy( 24, 2 );
	cout << "\n*************************"
     << endl;
    gotoxy( 1, 3 );
    cout << " BUS NO.:" << bno << "\tFrom: Bangalore  TO:" << place[ bno - 1 ];
    gotoxy( 2, 5 );
	cout << "SEAT NO.   PASSENGER NAME               GENDER    AGE    DATE ";
    gotoxy( 2, 6 );
    cout << "**************************"
     << endl;
    fstream  file;
    file.open( "INFO1.DAT", ios::in );
	while( file.read( ( char * )this, sizeof( TRAVEL ) ) )
    {
	if( busno == bno )
	{
	    if( ( toupper( ch ) == 'N' )
		 || ( ( toupper( ch ) == 'Y' ) && ( dd == d && mm == m && yy == y ) ) )
	    {
		found = 1;
		gotoxy( 5, row );
		cout << seatno;
		gotoxy( 14, row );
		cout << name;
		gotoxy( 43, row );
		cout << sex;
		gotoxy( 50, row );
		cout << age;
		gotoxy( 61, row );
		cout << dd << "/" << mm << "/" << yy;
		row++;
		if( row == 25 )
		{
		    getch( );
		    for( int  i  = 8; i <= 24; i++ )            //          < >
		    {
			gotoxy( 1, i );
			clreol( );
			}
		    row = 8;
		}
	    }
	}
    }
    file.close( );
	if( !found )
    {
	cout << "\n\No reservation for the bus no. " << bno;
	getch( );
	return;
    }
	gotoxy(23,25);
    cout << "\nPress any key to continue..............";
	getch( );
}

void  TRAVEL::LIST_OF_PASS( void )
{
	clrscr( );
	int	 found  = 0,
	 row    = 8;

   clrscr( );
	gotoxy( 25, 1 );
	cout << "LIST OF THE BOOKINGS ";

	 fstream  file;
	file.open( "INFO1.DAT", ios::in );
	while( file.read( ( char * )this, sizeof( TRAVEL ) ) )
	{

	if( strcmp(UserName,TUname)==0 )
	{

		found = 1;
		gotoxy( 5, row );
		cout << book_id1;
		gotoxy( 17, row );
		cout << name;
		gotoxy( 39, row );
		cout << sex;
		gotoxy( 48, row );
		cout << age;
		gotoxy( 54 , row );
		cout << dd << "/" << mm << "/" << yy;
		gotoxy( 67, row );
		cout << place[ busno - 1];
		row++;
		if( row == 25 )
		{
			getch( );
			for( int  i  = 8; i <= 24; i++ )            //          < >
			{
			gotoxy( 1, i );
			clreol( );
			}
			row = 8;
		}
	}
	}

	gotoxy( 24, 2 );
	cout << "\n*************************"
	 << endl;
	gotoxy( 1, 3 );
	cout <<  "\t \t  ** LIST OF TICKETS BOOKED ** " ;
	gotoxy( 2, 5 );
	cout << "BOOKING ID   PASSENGER NAME        GENDER    AGE     DATE    DESTINATION";
	gotoxy( 2, 6 );
	cout << "**************************"
	 << endl;

	if( !found )
	{
	cout << "\n\No reservations " ;
	getch( );
	return;
	}
	file.close();
	gotoxy(23,25);
	cout << "\nPress any key to continue..............";
	getch( );

}


int  TRAVEL::AVAIL( int  bno, int  d, int  m, int  y )
{
	fstream  file;
	file.open( "INFO1.DAT", ios::in );
	int avail  = 0,
	count  = 0;
	while( file.read( ( char * )this, sizeof( TRAVEL ) ) )
	{
	if( dd == d && mm == m && yy == y && bno == busno )
		count++;
	}
	if( count < 60 )
	avail = 1;
	file.close( );
	return avail;
}

int  TRAVEL::RESERVED( int  bno, int  d, int  m, int  y, int  sno )
{
	fstream  file;
	file.open( "INFO1.DAT", ios::in );
	int reserved  = 0;
	while( file.read( ( char * )this, sizeof( TRAVEL ) ) )
	{
	if( dd == d && mm == m && yy == y && busno==bno && seatno == sno )
	{
		reserved = 1;
		break;
	}
	}
	file.close( );
	return reserved;
}




/* FUNCTION TO RESERVE TICKET
 This function takes bus no, date of reservation and checks the ticket availability
 Each bus has a seating capacity of 60 seats
 The fucntion checks if the age of passenger is less than 5. No tickets are issued if the age is less than 5
 once the tickets are reserved, it will prompt the user to save the record */

void  TRAVEL::RESERVATION( void )
{
	clrscr( );
	int  bno,
	 sno,
	 pfare,
	 bookid,
	 page;
	char ch,
	 pname[ 26 ],
	 Uname[26],
	 psex;
	bookid=book_idgen();
	cout << "\n\t\t\t DPS TRAVELS";
	cout << "\n Bus 1:Bangalore to Mumbai 	<fare Rs.100>";
	cout << "\n Bus 2:Bangalore to Pune        	<fare Rs.220>";
	cout << "\n Bus 3:Bangalore to Hyderabad   	<fare Rs.175>";
	cout << "\n Bus 4:Bangalore to Vizag 	<fare Rs.1000>";
	cout << "\n Bus 5:Bangalore to Goa         	<fare Rs.500>";
	cout << "\n Bus 6:Bangalore to Chennai     	<fare Rs.730>";
	do
	{
	cout << "\n\nEnter the Bus no.(1/2/3/4/5/6):";
	cin >> bno;

	} while( bno < 1 || bno > 6 );
	int d,
	m,
	y;
	cout << "\nEnter the date for reservation(dd) :";
	cin >> d;
	cout << "\nEnter month:(mm)";
	cin >> m;
	cout << "\nEnter year(yy):";
	cin >> y;
	if( !AVAIL( bno, d, m, y ) )
	{
	cout << "\n\n\nsorry! seat not available";
	getch( );
	return;
	}
	int notick;
	do
	{
		cout<<"PLEASE ENTER NO OF TICKETS (MAX : 4 || MIN : 1) : ";
		cin>>notick;
	}
	while(notick<1||notick>4);

	for(int i=0;i<notick;i++)
	{
	cout<<"Enter The Seat no (1-20 : Window)(30-60 : Aisle) :  ";
	cin>>sno;


	if( (sno < 60 || sno > 1 ) && RESERVED( bno, d, m, y, sno )==1 )
	{
	cout << "\n\n\nsorry! seat already reserved";
	getch( );
	return;
	}
	if (sno > 60 || sno < 1 )
	{
	cout << "\n\n\nsorry! seat already reserved";
	getch( );
	return;
	}
	cout << "\n Enter name of passenger:";
	gets( pname );
	do
	{
	cout << "Enter Gender of passenger(M/F):";
	cin >> psex;
	}
	while( toupper( psex ) != 'M' && toupper( psex ) != 'F' );

	cout << "Enter age:";
	cin >> page;

	if( page <= 5 )
	{
	cout << "\n No ticket is required upto the age of 5";
	getch( );
	return;
	}
	clrscr( );
	gotoxy( 5, 5 );
	cout << "************************" << endl;
	gotoxy( 28, 7 );
	cout << "DPS Travels Pvt Ltd.";
	gotoxy( 10, 9 );
	cout << "BUS NO." << bno << "\t\t\tDATE:" << d << "/" << m << "/" << y;
	gotoxy( 10, 10 );
	cout << "SEAT NO.:" << sno << "\t\t\tTIME:" << ptime[ bno - 1 ];
	gotoxy( 10, 12 );
	cout << "FROM: Bangalore" << "\t\t\tTo:" << place[ bno - 1 ];
	gotoxy( 10, 14 );
	cout << "Passenger Name:" << pname;
	gotoxy( 10, 16 );
	cout << "Passenger Age:  " << page << "\t\tGender:" << psex;
	gotoxy( 10, 18 );
	cout << "Total Fare:" << price[ bno - 1 ];
	gotoxy( 10, 20 );
	cout << "Booking ID : "<<bookid;
	gotoxy( 5 , 22 );
	cout << "************************";
	cout << "\n\n\n";
	do
	{
	cout << "Do you want to save ticket(y/n)";
	cin >> ch;
	cout<<ch;
	}while( toupper( ch ) != 'N' && toupper( ch ) != 'Y' );

	if( toupper( ch ) == 'N' )
	   {
		return;
	   }
	else
   { fstream  file;

	file.open( "INFO1.DAT",ios::out | ios::app );
	busno  = bno;
	seatno = sno;
	book_id1=bookid;
	strcpy( name, pname );
	strcpy(UserName,::TUname);
	sex  = psex;
	age  = page;
	fare = pfare;
	dd   = d;
	mm   = m;
	yy   = y;

	cout<<"\n"<<name<<" "<<UserName;  //TO BE REMOVED

	file.write( ( char * )this, sizeof( TRAVEL ) );
	file.close( );
	getch();
	clrscr();
   }
   }
}


/*FUNCTION TO DELETE RECORD OF THE PASSENGER */

void  TRAVEL::DELETION( void )
{
	clrscr( );
	char s;
	int	 found  = 0,
	 bookid = 0;
	char ch;
	LIST_OF_PASS();

	cout<<"\nPLEASE ENTER THE BOOKING ID OF THE TICKET TO DELETE: ";
	cin>>bookid;

	fstream  file,
		 temp;
	file.open( "INFO1.DAT", ios::in );
	temp.open( "TEMP.DAT", ios::out );
	while( file.read( ( char * )this, sizeof( TRAVEL ) ) )
	{
	if( bookid==book_id1 && strcmp(UserName,TUname)==0 )
	{
		found = 1;
		clrscr( );
		gotoxy( 5, 5 );
		cout << "************************";
		gotoxy( 28, 7 );
		cout << "DPS Travels Pvt Ltd";
		gotoxy( 10, 9 );
		cout << "BUS NO." << busno << "\t\t\tDATE:" << dd << "/" << mm << "/" << yy;
		gotoxy( 10, 10 );
		cout << "SEAT NO.:" << seatno << "\t\t\tTIME:" << ptime[ busno - 1 ];
		gotoxy( 10, 12 );
		cout << "FROM:Bangalore" << "\t\t\tTo:" << place[ busno - 1 ];
		gotoxy( 10, 14 );
		cout << "Passenger Name:" << name;
		gotoxy( 10, 16 );
		cout << "Passenger Age:  " << age << "\t\tGender:" << sex;
		gotoxy( 10, 18 );
		cout << "Total Fare   :  " << price[ busno - 1 ];
		cout << "\t\t Booking ID : "<<bookid;
		gotoxy( 5, 22 );
		cout << "***********************";
		do
		{
		gotoxy( 1, 25 );
		clreol( );
		cout << "Do you want to delete(y/n)";
		cin >> ch;
		}
		while( toupper( ch ) != 'N' && toupper( ch ) != 'Y' );
		if( toupper( ch ) == 'N' )
		temp.write( ( char * )this, sizeof( TRAVEL ) );
	}
	else
		temp.write( ( char * )this, sizeof( TRAVEL ) );
	}
	file.close( );
	temp.close( );
	if( !found )
	{
	cout << "\nPassenger record not found";
	getch( );
	return;
	}

	if( toupper( ch ) == 'N' )
	return;
	file.open( "INFO1.DAT", ios::out );
	temp.open( "TEMP.DAT", ios::in );
	while( temp.read( ( char * )this, sizeof( TRAVEL ) ) )      //  ##### write & ; error
	file.write( ( char * )this, sizeof( TRAVEL ) );
	file.close( );
	temp.close( );
}


void  TRAVEL::MODIFICATION( void )
{
	clrscr( );
	char s;
	int	 found  = 0,
	 bookid = 0;
	TRAVEL t;
	char modname[26];
	char ch;
	LIST_OF_PASS();

	cout<<"\nPLEASE ENTER THE BOOKING ID OF THE TICKET TO MODIFY: ";
	cin>>bookid;

	fstream  file,
		 temp;
	file.open( "INFO1.DAT", ios::in );
	temp.open( "TEMP.DAT", ios::out );
	while( file.read( ( char * )this, sizeof( TRAVEL ) ) )
	{
	if( bookid==book_id1 )
	{
		found = 1;
		clrscr( );
		gotoxy( 5, 5 );
		cout << "************************";
		gotoxy( 28, 7 );
		cout << "DPS Travels Pvt Ltd";
		gotoxy( 10, 9 );
		cout << "BUS NO." << busno << "\t\t\tDATE:" << dd << "/" << mm << "/" << yy;
		gotoxy( 10, 10 );
		cout << "SEAT NO.:" << seatno << "\t\t\tTIME:" << ptime[ busno - 1 ];
		gotoxy( 10, 12 );
		cout << "FROM:Bangalore" << "\t\t\tTo:" << place[ busno - 1 ];
		gotoxy( 10, 14 );
		cout << "Passenger Name:" << name;
		gotoxy( 10, 16 );
		cout << "Passenger Age:  " << age << "\t\tGender:" << sex;
		gotoxy( 10, 18 );
		cout << "Total Fare   :  " << price[ busno - 1 ];
		cout << "\t\t Booking ID : "<<bookid;
		gotoxy( 5, 22 );
		cout << "***********************";
		do
		{
		gotoxy( 1, 25 );
		clreol( );
		cout << "Do you want to modify(y/n)";
		cin >> ch;
		}while( toupper( ch ) != 'N' && toupper( ch ) != 'Y' );

		if( toupper( ch ) == 'Y' )
		{
		cout<<"Please Enter NEW Name: ";
		gets(modname);
		strcpy(name,modname);
		dd=dd;
		mm=mm;
		yy=yy;
		book_id1=book_id1;
		strcpy(UserName,TUname);
		age=age;
		sex=sex;
		temp.write( ( char * )this, sizeof( TRAVEL ) );
		}
		else
		{
			temp.write( ( char * )this, sizeof( TRAVEL ) );
		}
	}
	else
	{
		temp.write( ( char * )this, sizeof( TRAVEL ) );
	}

	}
	file.close( );
	temp.close( );
	if( !found )
	{
	cout << "\nPassenger record not found";
	getch( );
	return;
	}

	if( toupper( ch ) == 'N' )
	return;
	file.open( "INFO1.DAT", ios::out );
	temp.open( "TEMP.DAT", ios::in );
	while( temp.read( ( char * )this, sizeof( TRAVEL ) ) )      //  ##### write & ; error
	file.write( ( char * )this, sizeof( TRAVEL ) );
	file.close( );
	temp.close( );
}


void  TRAVEL::INFORMATION( void )
{
	clrscr( );
	gotoxy( 20, 8 );
	cout << "\n\t\t\t DPS TRAVELS PVT LTD.";
	gotoxy( 4, 10 );
	cout << " There are six buses whose routes , timings and Fare are displayed below:";
	gotoxy( 4, 12 );
	cout << "\n Bus 1:Bangalore to Mumbai\t<fare Rs.100>\tDep Time :12:30PM Arrival 1.30PM";
	gotoxy( 4, 13 );
	cout << "\n Bus 2:Bangalore to Pune\t<fare Rs.220>\tDep Time :12:30PM Arrival 1.30PM";
	gotoxy( 4, 14 );
	cout
	 << "\n Bus 3:Bangalore to Hyderabad\t<fare Rs.175>\tDep Time :12:30PM Arrival 1.30PM";
	gotoxy( 4, 15 );
	cout << "\n Bus 4:Bangalore to Vizag\t<fare Rs.1000>\tDep Time :12:30PM Arrival 1.30PM";
    gotoxy( 4, 16 );
	cout << "\n Bus 5:Bangalore to Goa\t<fare Rs.500>\tDep Time :12:30PM Arrival 1.30PM";
    gotoxy( 4, 17 );
	cout << "\n Bus 6:Bangalore to Chennai\t<fare Rs.730>\tDep Time :12:30PM Arrival 1.30PM";

	cout << "\n you can reserve ticket of any date and later on cancel the same also.";
	gotoxy( 28, 23 );
	cout << "Press any key to continue.......";
	getch( );
}
/*   MAIN FUNCTION WHICH DISPLAY MAIN MENU & CALL ALL OTHER FUNCTIONS */

void  MAINMENU( void )
{
	TRAVEL  travel;
	char    ch;
	while( 1 )
	{

	clrscr( );
	gotoxy( 15, 4 );
	cout << "******************";
	gotoxy( 26, 5 );
	cout << "D";
	delay( 100 );
	cout << "p";
	delay( 100 );
	cout << "s";
	delay( 100 );
	cout << " ";
	delay( 100 );
	cout << "T";
	delay( 100 );
	cout << "r";
	delay( 100 );
	cout << "a";
	delay( 100 );
	cout << "v";
	delay( 100 );
	cout << "e";
	delay( 100 );
	cout << "l";
	delay( 100 );
	cout << "s";
	delay( 100 );
	cout << " ";
	delay( 100 );
	cout << "P";
	delay( 100 );
	cout << "v";
	delay( 100 );
	cout << "t";
	delay( 100 );
	cout << " ";
	delay( 100 );
	cout << "L";
	delay( 100 );
	cout << "t";
	delay( 100 );
	cout << "d";
	delay( 100 );
	cout << ".";
	cout << endl;
	cout << endl;
	delay( 100 );
	gotoxy( 15, 6 );
	cout << "******************";

	gotoxy( 29, 13 );
	cout << "1::INTRODUCTION";
	gotoxy( 29, 14 );
	cout << "2::RESERVATION";
	gotoxy( 29, 15 );
	cout << "3::TICKET CANCELLATION";
	gotoxy( 29, 16 );
	cout << "4::PASSENGER LIST";
	gotoxy( 29, 17 );
	cout<<  "5::TICKET MODIFICATION";
	gotoxy( 29, 18 );
	cout << "6::TICKET PRINTING";
	gotoxy( 29, 19 );
	cout << "7::QUIT";
	gotoxy( 29, 21 );
	cout << "Enter your choice::";
	ch = getch( );
	  if( ch == 27 || ch == '7' )
	{
		clrscr( );

	int gd  = DETECT,gm;

	initgraph( &gd, &gm, "c:/tc/bgi" );
		int midx,
		midy,
		ht;
		initgraph( &gd, &gm, "c:/tc/bgi" );
		midx = getmaxx( ) / 2;
		midy = getmaxy( ) / 2;
		setcolor( 1 );
		settextstyle( TRIPLEX_FONT, 0, 3 );
		settextjustify( CENTER_TEXT, CENTER_TEXT );
		outtextxy( midx, midy, "THANK YOU PLEASE VISIT US AGAIN" );
		delay(3000);
		cout << " \n \n Press any key to continue...";
		getch();
		closegraph();
		break;
	}
	else
		if( ch == '1' )
		travel.INFORMATION( );
		else
		if( ch == '2' )
			travel.RESERVATION( );
		else
			if( ch == '3' )
			travel.DELETION( );
			else
			if( ch == '4' )
				travel.LIST_OF_PASS( );
			else
				if( ch== '5')
				travel.MODIFICATION();
				else
				if( ch == '6' )
					travel.TKT_PRINT( );
	}


}

void ADMIN_MENU()
{

	clrscr();
	TRAVEL  travel;
	int    ch;

	adminmenu:
	gotoxy( 15, 4 );
	cout << "******************";
	gotoxy( 26, 5 );
	cout << "D";
	delay( 100 );
	cout << "p";
	delay( 100 );
	cout << "s";
	delay( 100 );
	cout << " ";
	delay( 100 );
	cout << "T";
	delay( 100 );
	cout << "r";
	delay( 100 );
	cout << "a";
	delay( 100 );
	cout << "v";
	delay( 100 );
	cout << "e";
	delay( 100 );
	cout << "l";
	delay( 100 );
	cout << "s";
	delay( 100 );
	cout << " ";
	delay( 100 );
	cout << "P";
	delay( 100 );
	cout << "v";
	delay( 100 );
	cout << "t";
	delay( 100 );
	cout << " ";
	delay( 100 );
	cout << "L";
	delay( 100 );
	cout << "t";
	delay( 100 );
	cout << "d";
	delay( 100 );
	cout << ".";
	cout << endl;
	cout << endl;
	delay( 100 );

	gotoxy( 15, 6 );
	cout << "******************";
	gotoxy( 29, 7 );
	cout<<"ADMIN MENU:";
	gotoxy( 15 , 8);
	cout << "******************";
	gotoxy( 29, 13 );
	cout << "1::INTRODUCTION";
	gotoxy( 29, 14 );
	cout << "2::TICKET CANCELLATION";
	gotoxy( 29, 15 );
	cout << "3::PASSENGER LIST";
	gotoxy( 29, 16);
	cout << "4::TICKET MODIFICATION";
	gotoxy( 29, 17 );
	cout << "5::TICKET PRINTING";
	gotoxy(	29, 18 );
	cout << "0::QUIT";
	gotoxy( 29, 19 );
	cout << "Enter your choice::";
	cin>>ch;

	switch(ch)
	{
		  case 1 :	travel.INFORMATION();
			break;

		  case 2 :  travel.DELETION();
			break;

		  case 3 :	travel.LIST_OF_PASS1();
			break;

		  case 4 : 	travel.MODIFICATION();
			break;

		  case 5 :	travel.TKT_PRINT();
			break;

		  case 0 :  clrscr();
			return;

		  default: 	cout<<"CHOICE ENTERED DOESNT EXIST PLEASE RETRY!!";
			break;

	}
	getch();
	clrscr();
	goto adminmenu;

}

void signup()
{

	clrscr();
	User s,r;
	char t[20];
	int flag;
	sup:
	cout<<"\t \t \t \t WELCOME TO THE SIGNUP PAGE @:@ \n \n";
	ofstream fout("userd.dat",ios::app|ios::binary);
	ifstream fin("userd.dat",ios::binary);
	cout<<"PLEASE ENTER THE FOLLOWING DETAILS : \n ";

	cout<<"NAME => ";
	gets(s.Name);
	cout<<"EMAIL-ID => ";
	gets(s.Email);

	uname:
	cout<<"\nUSERNAME(No Space,no special characters) => ";
	cin>>s.UserName;
	strcpy(t,s.UserName);
	while(!fin.eof())
	{
		fin.read((char*)&r,sizeof(r)) ;
		if(strcmp(r.UserName,t)==0)
		{
			cout<<"USERNAME ALREADY TAKEN!! PLEASE RE-ENTER A NEW USERNAME";
			goto uname;
		}
	}
	upass:
	cout<<"\nPASSWORD(length should be 8-15 characters) => ";
	gets(s.PassWord);
	if(strlen(s.PassWord)<8||strlen(s.PassWord)>15)
	{
		cout<<"SIZE OF PASSWORD INCORRECT PLEASE RE-ENTER PASSWORD !!";
		goto upass;
	}


	fout.write((char*)&s,sizeof(s));
	fout.close();
	fin.close();
	clrscr();
}

void usersignin()
{
	clrscr();
	int flag1=0;
	start:
	ifstream fin("userd.dat",ios::binary);
	char u[20];
	char p[20];
	User s;
	char c;
	cout<<"PLEASE ENTER THE : "<<endl;
	cout<<"  USERNAME => ";
	cin>>u;

	cout<<"  PASSWORD => ";
	password(p);
	int flag=0;
	while(fin.read((char*)&s,sizeof(s)))
	{
	;
		if(strcmp(s.UserName,u)==0&&strcmp(s.PassWord,p)==0)
		{
			flag++;
			strcpy(::TUname,u);
			cout<<"WElCOME TO THE PORTAL "<<u<<" :)"<<endl;
			MAINMENU( );

		}
	}
	if(flag==0)
	{
		cout<<"INCORRECT LOGIN DETAILS TRY AGAIN !!"<<endl;
		flag1++;
		if(flag1==3)
		{
			cout<<"MAXIMUN LOGINN ATTEMPTS REACHED!! REDIRECTING TO MENU!!";
			delay(1000);
			return;
		}
		goto start;
	}
	if(flag1==3)
	{
		cout<<"MAXIMUN LOGINN ATTEMPTS REACHED!! REDIRECTING TO MENU!!";
		delay(1000);
		return;
	}

	fin.close();
}

void adminsignin()
{

	Admin s;
	char u[20];
	char p[20];

	cout<<"PLEASE ENTER THE ADMIN ID => ";
	cin>>u;

	cout<<"PLEASE ENTER THE ADMIN PASSWORD => ";
	password(p);


	if(strcmp(u,s.ADMIN_NAME)==0&&strcmp(u,s.ADMIN_PASS)==0)
	{
		cout<<"WELCOME ADMIN! ";
		ADMIN_MENU();
	}
	else
	{
		cout<<"INCORRECT ADMIN DETAILS. REDIRECTING TO FRONT PAGE ";
		return;
	}
}

void signin()
{

	sin:


	clrscr();

	int choice;

	cout<<"\t \t \t \t WELCOME TO THE SIGN-IN PAGE : \n \n \n";
	cout<<"SIGN-IN AS USER OR ADMIN ? \n PRESS 1.USER | 2.ADMIN | 0.EXIT \n => ";
	cin>>choice;
	switch(choice)
	{
		case 1	: 	usersignin();
				break;

		case 2  :	adminsignin();
				break;

		case 0  :	return;

		default	: 	cout<<"WRONG ENTRY PLEASE RETRY!! ";
				goto sin;
	}


}


int main()
{


	menu:
	clrscr();
       cout<<"\t \t \t MENU:!!!!!! \n \n "<<endl;
       //int gd  = DETECT,gm;

	//initgraph( &gd, &gm, "c:/tc/bgi" );
	//cout<<"PRESS \n1. SIGN-UP \n 2. SIGN-IN \n 0. EXIT \n=> ";

	settextstyle(0,0,4);
	outtextxy(170,10,"MENU");
	gotoxy( 29, 13 );
	cout << "1::SIGN-UP";
	gotoxy( 29, 14 );
	cout << "2::SIGN-IN";
	gotoxy( 29, 15 );
	cout << "0::EXIT";
	int ch;
	cin>>ch;
	switch(ch)
	{
		case 1 :  signup();
			  break;

		case 2 :  signin();
			  break;

		case 0 :  exit(0);

	}

	goto menu;
}

